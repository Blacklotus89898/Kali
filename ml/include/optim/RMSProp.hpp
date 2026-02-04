#ifndef RMSPROP_HPP
#define RMSPROP_HPP

#include "optim/Optimizer.hpp"
#include <cmath>

namespace ml {

class RMSProp : public Optimizer {
private:
    double beta;
    double epsilon;
    
    // We need to keep track of caches for each layer
    // Index 0 = Layer 1, Index 1 = Layer 2, etc.
    std::vector<Matrix> weight_caches;
    std::vector<Matrix> bias_caches;

public:
    RMSProp(double learning_rate, double b = 0.9, double eps = 1e-8) 
        : Optimizer(learning_rate), beta(b), epsilon(eps) {}

    void step(std::vector<Linear*>& layers) override {
        // Initialize caches if this is the first step
        if (weight_caches.empty()) {
            for (auto* layer : layers) {
                weight_caches.push_back(Matrix(layer->weights.rows, layer->weights.cols));
                bias_caches.push_back(Matrix(layer->bias.rows, layer->bias.cols));
                weight_caches.back().fill(0.0);
                bias_caches.back().fill(0.0);
            }
        }

        for (size_t l = 0; l < layers.size(); ++l) {
            Linear* layer = layers[l];

            // Update Weights
            for (size_t i = 0; i < layer->weights.data.size(); ++i) {
                weight_caches[l].data[i] = beta * weight_caches[l].data[i] + 
                                           (1.0 - beta) * std::pow(layer->grad_weights.data[i], 2);
                
                layer->weights.data[i] -= (lr / (std::sqrt(weight_caches[l].data[i]) + epsilon)) * layer->grad_weights.data[i];
            }

            // Update Bias
            for (size_t i = 0; i < layer->bias.data.size(); ++i) {
                bias_caches[l].data[i] = beta * bias_caches[l].data[i] + 
                                         (1.0 - beta) * std::pow(layer->grad_bias.data[i], 2);
                
                layer->bias.data[i] -= (lr / (std::sqrt(bias_caches[l].data[i]) + epsilon)) * layer->grad_bias.data[i];
            }
        }
    }
};

} // namespace ml

#endif
