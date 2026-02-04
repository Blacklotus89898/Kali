#include "layers/Linear.hpp"

namespace ml {

// Implementation of the Constructor
Linear::Linear(int in_dim, int out_dim) 
    : weights(out_dim, in_dim), 
      bias(1, out_dim), 
      last_input(0, 0), 
      grad_weights(out_dim, in_dim), 
      grad_bias(1, out_dim),
      sq_grad_w(out_dim, in_dim), // Initialize RMSProp caches
      sq_grad_b(1, out_dim) 
{
    // He Initialization (Better for LeakyReLU/ReLU)
    double limit = std::sqrt(2.0 / in_dim); 
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(-limit, limit);

    for (auto& w : weights.data) w = dist(gen);
    for (auto& b : bias.data) b = 0.0;
    
    // RMSProp caches start at 0
    for (auto& sw : sq_grad_w.data) sw = 0.0;
    for (auto& sb : sq_grad_b.data) sb = 0.0;
}

Matrix Linear::forward(const Matrix& input) {
    last_input = input; 
    Matrix weights_T = weights.transpose();
    Matrix output = Matrix::multiply(input, weights_T);

    for (int i = 0; i < output.rows; ++i) {
        for (int j = 0; j < output.cols; ++j) {
            output(i, j) += bias(0, j);
        }
    }
    return output;
}

Matrix Linear::backward(const Matrix& grad_output) {
    Matrix grad_output_T = grad_output.transpose();
    
    // dL/dW = grad_output^T * last_input
    grad_weights = Matrix::multiply(grad_output_T, last_input);

    // dL/dB = sum over batch
    for (int j = 0; j < grad_output.cols; ++j) {
        double sum = 0;
        for (int i = 0; i < grad_output.rows; ++i) {
            sum += grad_output(i, j);
        }
        grad_bias(0, j) = sum;
    }

    // dL/dX = grad_output * weights
    return Matrix::multiply(grad_output, weights);
}

void Linear::update(double lr) {
    const double epsilon = 1e-8;
    const double beta = 0.9; // Decay rate for RMSProp

    // Update Weights with RMSProp
    for (size_t i = 0; i < weights.data.size(); ++i)  {
        // 1. Accumulate squared gradients
        sq_grad_w.data[i] = beta * sq_grad_w.data[i] + (1.0 - beta) * (grad_weights.data[i] * grad_weights.data[i]);
        
        // 2. Update weights: grad / sqrt(cache + eps)
        weights.data[i] -= (lr / (std::sqrt(sq_grad_w.data[i]) + epsilon)) * grad_weights.data[i];
    }

    // Update Bias with RMSProp
    for (size_t i = 0; i < bias.data.size(); ++i) {
        sq_grad_b.data[i] = beta * sq_grad_b.data[i] + (1.0 - beta) * (grad_bias.data[i] * grad_bias.data[i]);
        bias.data[i] -= (lr / (std::sqrt(sq_grad_b.data[i]) + epsilon)) * grad_bias.data[i];
    }
}

} // namespace ml
