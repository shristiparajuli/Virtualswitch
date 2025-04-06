#include <iostream>
#include <memory>
#include <vector>

#include <grpcpp/grpcpp.h>
#include "gradient.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using grpc::ClientReaderWriter;
using gradient::GradientService;
using gradient::GradientRequest;
using gradient::GradientReply;

class WorkerClient {
public:
    WorkerClient(std::shared_ptr<Channel> channel)
        : stub_(GradientService::NewStub(channel)) {}

    void StreamGradients() {
        // Create a client writer for streaming
        ClientContext context;
        GradientReply reply;
        auto stream = stub_->StreamGradients(&context, &reply);  // StreamGradients creates the stream

        // Send a stream of gradients
        for (int i = 0; i < 5; ++i) {
            GradientRequest request;
            request.set_worker_id("worker-1");

            // Example: Sending gradients in batches
            for (float val : {0.1f * (i + 1), 0.2f * (i + 1), 0.3f * (i + 1)}) {
                request.add_gradients(val);
            }

            std::cout << "Sending gradient from worker: " << request.worker_id() << std::endl;
            stream->Write(request);
        }

        // Signal the end of the stream
        stream->WritesDone();

        // Receive the response
        Status status = stream->Finish();

        if (status.ok()) {
            std::cout << "Server reply: " << reply.status() << std::endl;
            std::cout << "Updated model parameters received:" << std::endl;
            for (auto param : reply.updated_params()) {
                std::cout << param << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "gRPC failed: " << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<GradientService::Stub> stub_;
};

int main() {
    WorkerClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.StreamGradients();
    return 0;
}
