#include <iostream>
#include <memory>
#include <vector>

#include <grpcpp/grpcpp.h>
#include "gradient.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using gradient::GradientService;
using gradient::GradientRequest;
using gradient::GradientReply;

class WorkerClient {
public:
    WorkerClient(std::shared_ptr<Channel> channel)
        : stub_(GradientService::NewStub(channel)) {}

    void SendGradients() {
        GradientRequest request;
        request.set_worker_id("worker-1");
        for (float val : {0.1f, 0.2f, 0.3f}) {
            request.add_gradients(val);
        }

        GradientReply reply;
        ClientContext context;

        Status status = stub_->SendGradient(&context, request, &reply);

        if (status.ok()) {
            std::cout << "Server reply: " << reply.status() << std::endl;
        } else {
            std::cout << "gRPC failed: " << status.error_message() << std::endl;
        }
    }

private:
    std::unique_ptr<GradientService::Stub> stub_;
};

int main() {
    WorkerClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.SendGradients();
    return 0;
}
