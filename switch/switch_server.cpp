#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <grpcpp/grpcpp.h>
#include "gradient.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using gradient::GradientRequest;
using gradient::GradientReply;
using gradient::GradientService;

class GradientServiceImpl final : public GradientService::Service {
    std::vector<float> buffer;

    Status SendGradient(ServerContext* context, const GradientRequest* request,
                        GradientReply* reply) override {
        std::cout << "Received gradient from " << request->worker_id() << std::endl;

        for (float val : request->gradients()) {
            buffer.push_back(val);
        }

        std::cout << "Current buffer size: " << buffer.size() << std::endl;

        reply->set_status("Received");
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    GradientServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Switch server listening on " << server_address << std::endl;

    server->Wait();
}

int main() {
    RunServer();
    return 0;
}
