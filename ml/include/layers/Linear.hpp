#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "layers/Layer.hpp"
#include <memory>

namespace ml {

class Variable;
using VarPtr = std::shared_ptr<Variable>;

class Linear : public Layer {
public:
    Matrix weights, bias, grad_weights, grad_bias;

    Linear(int in_dim, int out_dim);
    Matrix forward(const Matrix& input) override;
    Matrix backward(const Matrix& grad_output) override;
    
    // Autograd support
    VarPtr forward_autograd(VarPtr input);
    
    void update(double lr);
    void zero_grad();
};

} 
#endif
