#ifndef ACTIVATIONS_HPP
#define ACTIVATIONS_HPP

#include "core/Autograd.hpp"

namespace ml {

class LeakyReLU : public Layer {
public:
    double alpha;
    LeakyReLU(double a = 0.01) : alpha(a) {}

    VarPtr forward_autograd(VarPtr input) {
        Matrix out_data(input->data.rows, input->data.cols);
        for(size_t i=0; i<input->data.data.size(); ++i) {
            out_data.data[i] = (input->data.data[i] > 0) ? input->data.data[i] : alpha * input->data.data[i];
        }
        
        auto output = std::make_shared<Variable>(out_data);
        output->parents = {input};
        output->backward_op = [this, input, output]() {
            for(size_t i=0; i<input->grad.data.size(); ++i) {
                double deriv = (input->data.data[i] > 0) ? 1.0 : this->alpha;
                input->grad.data[i] += output->grad.data[i] * deriv;
            }
        };
        return output;
    }

    Matrix forward(const Matrix& input) override { return input; } // Stub
    Matrix backward(const Matrix& grad_output) override { return grad_output; } // Stub
};

}
#endif
