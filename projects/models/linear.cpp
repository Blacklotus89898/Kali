#ifndef LINEAR_MODEL_H
#define LINEAR_MODEL_H

#include <vector>
#include <iostream>

template <typename T>
class LinearModel {
public:
    LinearModel() : weight(0), bias(0) {}

    void train(const std::vector<T>& x, const std::vector<T>& y, T learning_rate, int epochs) {
        size_t n = x.size();
        for (int epoch = 0; epoch < epochs; ++epoch) {
            T weight_gradient = 0;
            T bias_gradient = 0;

            for (size_t i = 0; i < n; ++i) {
                T prediction = predict(x[i]);
                T error = prediction - y[i];
                weight_gradient += error * x[i];
                bias_gradient += error;
            }

            weight -= learning_rate * weight_gradient / n;
            bias -= learning_rate * bias_gradient / n;
        }
    }

    T predict(T x) const {
        return weight * x + bias;
    }

    void print_parameters() const {
        std::cout << "Weight: " << weight << ", Bias: " << bias << std::endl;
    }

private:
    T weight;
    T bias;
};

#endif // LINEAR_MODEL_H