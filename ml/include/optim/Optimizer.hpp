#ifndef OPTIMIZER_HPP
#define OPTIMIZER_HPP

#include <vector>
#include "layers/Linear.hpp"

namespace ml {

class Optimizer {
protected:
    double lr;
public:
    Optimizer(double learning_rate) : lr(learning_rate) {}
    virtual ~Optimizer() = default;
    
    // Every optimizer must implement this
    virtual void step(std::vector<Linear*>& layers) = 0;
};

} // namespace ml

#endif
