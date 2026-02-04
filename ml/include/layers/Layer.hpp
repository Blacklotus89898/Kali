#ifndef LAYER_HPP
#define LAYER_HPP

#include "core/Tensor.hpp"

namespace ml {

class Layer {
public:
    virtual ~Layer() = default;

    // input (batch_size x input_dim) -> output (batch_size x output_dim)
    virtual Matrix forward(const Matrix& input) = 0;

    // grad_output (batch_size x output_dim) -> grad_input (batch_size x input_dim)
    virtual Matrix backward(const Matrix& grad_output) = 0;
};

} // namespace ml

#endif
