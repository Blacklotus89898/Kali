#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "layers/Layer.hpp"
#include <cmath>
#include <random>

namespace ml {

  class Linear : public Layer {
    public:
      // Member variables
      Matrix weights;
      Matrix bias;
      Matrix last_input;
      Matrix grad_weights;
      Matrix grad_bias;
      Matrix sq_grad_w; // Squared gradient cache for weights
      Matrix sq_grad_b; // Squared gradient cache for bias
      double beta = 0.9;
      double epsilon = 1e-8;

      // Constructor: Just the signature
      Linear(int in_dim, int out_dim);

      // Methods: Just the signatures
      Matrix forward(const Matrix& input) override;
      Matrix backward(const Matrix& grad_output) override;
      void update(double lr);
      void updateRMSProp(double lr);
  };

} // namespace ml

#endif
