// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: gradient.proto
#ifndef GRPC_gradient_2eproto__INCLUDED
#define GRPC_gradient_2eproto__INCLUDED

#include "gradient.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace gradient {

class GradientService final {
 public:
  static constexpr char const* service_full_name() {
    return "gradient.GradientService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientWriterInterface< ::gradient::GradientRequest>> StreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::gradient::GradientRequest>>(StreamGradientsRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::gradient::GradientRequest>> AsyncStreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::gradient::GradientRequest>>(AsyncStreamGradientsRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::gradient::GradientRequest>> PrepareAsyncStreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::gradient::GradientRequest>>(PrepareAsyncStreamGradientsRaw(context, response, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void StreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::ClientWriteReactor< ::gradient::GradientRequest>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientWriterInterface< ::gradient::GradientRequest>* StreamGradientsRaw(::grpc::ClientContext* context, ::gradient::GradientReply* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::gradient::GradientRequest>* AsyncStreamGradientsRaw(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::gradient::GradientRequest>* PrepareAsyncStreamGradientsRaw(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    std::unique_ptr< ::grpc::ClientWriter< ::gradient::GradientRequest>> StreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::gradient::GradientRequest>>(StreamGradientsRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::gradient::GradientRequest>> AsyncStreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::gradient::GradientRequest>>(AsyncStreamGradientsRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::gradient::GradientRequest>> PrepareAsyncStreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::gradient::GradientRequest>>(PrepareAsyncStreamGradientsRaw(context, response, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void StreamGradients(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::ClientWriteReactor< ::gradient::GradientRequest>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientWriter< ::gradient::GradientRequest>* StreamGradientsRaw(::grpc::ClientContext* context, ::gradient::GradientReply* response) override;
    ::grpc::ClientAsyncWriter< ::gradient::GradientRequest>* AsyncStreamGradientsRaw(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncWriter< ::gradient::GradientRequest>* PrepareAsyncStreamGradientsRaw(::grpc::ClientContext* context, ::gradient::GradientReply* response, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_StreamGradients_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status StreamGradients(::grpc::ServerContext* context, ::grpc::ServerReader< ::gradient::GradientRequest>* reader, ::gradient::GradientReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_StreamGradients : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_StreamGradients() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_StreamGradients() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamGradients(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::gradient::GradientRequest>* /*reader*/, ::gradient::GradientReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestStreamGradients(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::gradient::GradientReply, ::gradient::GradientRequest>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_StreamGradients<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_StreamGradients : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_StreamGradients() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::gradient::GradientRequest, ::gradient::GradientReply>(
            [this](
                   ::grpc::CallbackServerContext* context, ::gradient::GradientReply* response) { return this->StreamGradients(context, response); }));
    }
    ~WithCallbackMethod_StreamGradients() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamGradients(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::gradient::GradientRequest>* /*reader*/, ::gradient::GradientReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::gradient::GradientRequest>* StreamGradients(
      ::grpc::CallbackServerContext* /*context*/, ::gradient::GradientReply* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_StreamGradients<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_StreamGradients : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_StreamGradients() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_StreamGradients() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamGradients(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::gradient::GradientRequest>* /*reader*/, ::gradient::GradientReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_StreamGradients : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_StreamGradients() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_StreamGradients() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamGradients(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::gradient::GradientRequest>* /*reader*/, ::gradient::GradientReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestStreamGradients(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_StreamGradients : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_StreamGradients() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, ::grpc::ByteBuffer* response) { return this->StreamGradients(context, response); }));
    }
    ~WithRawCallbackMethod_StreamGradients() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status StreamGradients(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::gradient::GradientRequest>* /*reader*/, ::gradient::GradientReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::grpc::ByteBuffer>* StreamGradients(
      ::grpc::CallbackServerContext* /*context*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

}  // namespace gradient


#endif  // GRPC_gradient_2eproto__INCLUDED
