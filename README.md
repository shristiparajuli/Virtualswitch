# Distributed Gradient Aggregation with gRPC in C++

## Overview

This project implements a distributed system where multiple worker nodes send gradient vectors to a central switch server. The server aggregates these gradients and returns updated model parameters. It uses **gRPC streaming** and **PyTorch C++ (LibTorch)** for aggregation.

---

## Features

- **gRPC-based streaming** between workers and switch  
- **Gradient collection and aggregation**  
- **Single/multi-client architecture** support  
- Uses **LibTorch (PyTorch C++ API)** for tensor operations  

---

## Dependencies

- gRPC  
- Protobuf  
- Abseil-cpp  
- LibTorch (PyTorch C++ API)  

---

## Setup Steps

1. **Install LibTorch** (PyTorch C++ API)  
2. **Build and install gRPC and Protobuf**  
3. **Build and install Abseil**  
4. **Generate gRPC code from `.proto` file**  
5. **Build and run the switch server**  
6. **Build and run the worker client**  

---

## What’s Implemented

- gRPC streaming from workers to switch  
- Gradient aggregation logic on the server  
- Return of updated parameters to clients  
- Basic single-client test completed  

---

## Next Steps

- Add support for multiple worker clients  
- Implement proper aggregation (e.g., averaging)  
- Integrate logging and metrics  
- Optimize for large-scale distributed training  

