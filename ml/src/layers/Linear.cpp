#include "layers/Linear.hpp"
#include "core/Autograd.hpp"
#include <cmath>
#include <random>

namespace ml {

  Linear::Linear(int in_dim, int out_dim) 
    : weights(out_dim, in_dim), bias(1, out_dim), 
    grad_weights(out_dim, in_dim), grad_bias(1, out_dim) 
  {
    // He Initialization
    double limit = std::sqrt(2.0 / in_dim); 
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(-limit, limit);

    for (auto& w : weights.data) w = dist(gen);
    bias.fill(0.0);
  }

  VarPtr Linear::forward_autograd(VarPtr input) {
    Matrix weights_T = weights.transpose();
    Matrix out_data = Matrix::multiply(input->data, weights_T);

    // Apply Bias
    for (int i = 0; i < out_data.rows; ++i) {
      for (int j = 0; j < out_data.cols; ++j) out_data(i, j) += bias(0, j);
    }

    auto output = std::make_shared<Variable>(out_data);
    output->parents = {input};

    output->backward_op = [this, input, output]() {
      // dL/dW
      Matrix gW = Matrix::multiply(output->grad.transpose(), input->data);
      for(size_t i = 0; i < grad_weights.data.size(); ++i) grad_weights.data[i] += gW.data[i];

      // dL/dB
      for (int j = 0; j < output->grad.cols; ++j) {
        double sum = 0;
        for (int i = 0; i < output->grad.rows; ++i) sum += output->grad(i, j);
        grad_bias(0, j) += sum;
      }

      // dL/dX
      Matrix gX = Matrix::multiply(output->grad, weights);
      for(size_t i = 0; i < input->grad.data.size(); ++i) input->grad.data[i] += gX.data[i];
    };
    return output;
  }

  void Linear::zero_grad() {
    grad_weights.fill(0.0);
    grad_bias.fill(0.0);
  }

  // Simple wrappers for inference
  Matrix Linear::forward(const Matrix& input) { return Matrix::multiply(input, weights.transpose()); }
  Matrix Linear::backward(const Matrix& grad_output) { return Matrix::multiply(grad_output, weights); }

}
