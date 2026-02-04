#ifndef ACTIVATIONS_HPP
#define ACTIVATIONS_HPP

#include "layers/Layer.hpp"

namespace ml {

  class LeakyReLU : public Layer {
    public:
      double alpha;
      Matrix last_input;

      LeakyReLU(double a = 0.01) : alpha(a), last_input(0, 0) {}

      Matrix forward(const Matrix& input) override {
        last_input = input;
        Matrix output(input.rows, input.cols);
        for (int i = 0; i < input.data.size(); ++i) {
          output.data[i] = (input.data[i] > 0) ? input.data[i] : alpha * input.data[i];
        }
        return output;
      }

      Matrix backward(const Matrix& grad_output) override {
        Matrix grad_input(grad_output.rows, grad_output.cols);
        for (int i = 0; i < grad_output.data.size(); ++i) {
          // Gradient is 1 if x > 0, else alpha
          double deriv = (last_input.data[i] > 0) ? 1.0 : alpha;
          grad_input.data[i] = grad_output.data[i] * deriv;
        }
        return grad_input;
      }
  };

  class ReLU : public Layer {
    public:
      Matrix last_input_mask; // Stores 1 if input > 0, else 0

      ReLU() : last_input_mask(0, 0) {}

      Matrix forward(const Matrix& input) override {
        last_input_mask = Matrix(input.rows, input.cols);
        Matrix output(input.rows, input.cols);

        for (int i = 0; i < input.data.size(); ++i) {
          if (input.data[i] > 0) {
            output.data[i] = input.data[i];
            last_input_mask.data[i] = 1.0;
          } else {
            output.data[i] = 0.0;
            last_input_mask.data[i] = 0.0;
          }
        }
        return output;
      }

      Matrix backward(const Matrix& grad_output) override {
        Matrix grad_input(grad_output.rows, grad_output.cols);

        // Chain Rule: dL/dx = dL/dy * dy/dx
        // dy/dx is 1 if x > 0, else 0 (our mask)
        for (int i = 0; i < grad_output.data.size(); ++i) {
          grad_input.data[i] = grad_output.data[i] * last_input_mask.data[i];
        }
        return grad_input;
      }
  };

} // namespace ml

#endif
