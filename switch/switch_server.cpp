#include <iostream>
#include <memory>
#include <vector>
#include <grpcpp/grpcpp.h>
#include "gradient.grpc.pb.h"
#include <torch/torch.h> 

using grpc::Server;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::Status;
using gradient::GradientService;
using gradient::GradientRequest;
using gradient::GradientReply;

class GradientServiceImpl final : public GradientService::Service {
public:
    Status StreamGradients(ServerContext* context, grpc::ServerReader<GradientRequest>* reader, GradientReply* reply) override {
        // Hold the aggregated gradient
        std::vector<float> aggregated_gradient;

        GradientRequest request;
        // Read the stream of gradients from the client
        while (reader->Read(&request)) {
            std::cout << "Received gradient from worker: " << request.worker_id() << std::endl;

            // Aggregate gradients here (e.g., sum)
            for (float grad : request.gradients()) {
                aggregated_gradient.push_back(grad); // For simplicity, just pushing in this case
            }
        }

        // Here, aggregate the gradients using PyTorch (if needed) or any other method
        std::cout << "Aggregated gradient size: " << aggregated_gradient.size() << std::endl;

        // Optionally: Apply aggregation logic, such as mean or all-reduce
        // torch::Tensor tensor = torch::tensor(aggregated_gradient);
        // torch::Tensor mean_tensor = tensor.mean();

        // Prepare the response: sending back an acknowledgment and updated parameters (optional)
        reply->set_status("Received and Aggregated");
        
        // Example: Send back aggregated parameters (just returning the same ones for now)
        for (auto grad : aggregated_gradient) {
            reply->add_updated_params(grad);
        }

        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    GradientServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
