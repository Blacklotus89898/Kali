# ML + Deep Learning


## 🎯 Project Goals

The objective is to implement the fundamental building blocks of Deep Learning without heavy external dependencies to master the interaction between hardware and algorithms.

* **Memory Management**: Implementation of contiguous memory storage and efficient pointer arithmetic.
* **Performance**: Optimized matrix multiplication (GEMM) and vectorization strategies.
* **Modularity**: An extensible architecture designed for adding new layers, optimizers, and activation functions seamlessly.

## 🏗️ Project Architecture

The project follows a modular, industrial-standard structure:

```text
ml/
├── include/           # Public Headers (.hpp)
│   ├── core/          # Tensor engine and linear algebra
│   ├── layers/        # NN Layers (Linear, Dropout, Conv2D)
│   ├── optim/         # Optimizers (SGD, Adam)
│   ├── functions/     # Activations (ReLU, Softmax) & Loss (NLL, MSE)
│   └── initializers/  # Weight Initialization (Xavier, He)
├── src/               # Implementation (.cpp)
├── examples/          # Sample programs (e.g., MNIST training)
└── tests/             # Unit tests and Gradient Checking

```

## 🚀 Implemented Features

### Core Engine

* [ ] **Tensor Class**: Multi-dimensional array wrapper with contiguous memory.
* [ ] **Linear Algebra**: Optimized matrix multiplication, addition, and transposition.

### Neural Network Layers

* [ ] **Fully Connected (Linear)**: Support for custom weight initialization and backpropagation.
* [ ] **Inverted Dropout**: Training-time scaling for faster inference.
* [ ] **Activation Functions**: High-performance ReLU, Tanh, and Sigmoid.

### Training & Optimization

* [ ] **Optimizers**: Stochastic Gradient Descent (SGD) with momentum.
* [ ] **Initializers**: Xavier/Glorot for symmetric activations and He/Kaiming for ReLU.

## 🛠️ Build & Installation

This project uses **CMake** for cross-platform build management.

```bash
# Build the project
mkdir build && cd build
cmake ..
make

# Run the examples
./run_ml

