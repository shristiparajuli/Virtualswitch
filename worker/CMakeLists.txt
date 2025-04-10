cmake_minimum_required(VERSION 3.10)
project(worker_client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-D_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_PREFIX_PATH "$ENV{HOME}/grpc/install;$ENV{HOME}/abseil-cpp/install")

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(
    ../grpc
)

add_executable(worker_client
    worker_client.cpp
    ../grpc/gradient.pb.cc
    ../grpc/gradient.grpc.pb.cc
)

target_link_libraries(worker_client
    PRIVATE
      gRPC::grpc++
      protobuf::libprotobuf
      OpenSSL::SSL
      pthread
)
