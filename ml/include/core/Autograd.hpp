#ifndef AUTOGRAD_HPP
#define AUTOGRAD_HPP

#include "core/Tensor.hpp"
#include <memory>
#include <functional>
#include <vector>
#include <set>

namespace ml {

class Variable;
using VarPtr = std::shared_ptr<Variable>;

class Variable : public std::enable_shared_from_this<Variable> {
public:
    Matrix data;
    Matrix grad;
    std::function<void()> backward_op;
    std::vector<VarPtr> parents;

    Variable(Matrix d) : data(d), grad(d.rows, d.cols) {
        grad.fill(0.0);
    }

    void backward() {
        std::vector<Variable*> topo;
        std::set<Variable*> visited;
        
        std::function<void(Variable*)> build_topo = [&](Variable* v) {
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                for (auto& parent : v->parents) build_topo(parent.get());
                topo.push_back(v);
            }
        };

        build_topo(this);
        if (grad.rows == 1 && grad.cols == 1) grad.data[0] = 1.0;

        for (auto it = topo.rbegin(); it != topo.rend(); ++it) {
            if ((*it)->backward_op) (*it)->backward_op();
        }
    }
};

// Global Autograd Operations
inline VarPtr multiply(VarPtr a, VarPtr b) {
    auto res = std::make_shared<Variable>(Matrix::multiply(a->data, b->data));
    res->parents = {a, b};
    res->backward_op = [res, a, b]() {
        Matrix b_T = b->data.transpose();
        Matrix grad_a = Matrix::multiply(res->grad, b_T);
        for(size_t i=0; i < a->grad.data.size(); ++i) a->grad.data[i] += grad_a.data[i];

        Matrix a_T = a->data.transpose();
        Matrix grad_b = Matrix::multiply(a_T, res->grad);
        for(size_t i=0; i < b->grad.data.size(); ++i) b->grad.data[i] += grad_b.data[i];
    };
    return res;
}

inline VarPtr MSE_Autograd(VarPtr y_pred, VarPtr y_true) {
    double scalar_loss = 0;
    size_t n = y_pred->data.data.size();
    for (size_t i = 0; i < n; ++i) {
        double diff = y_pred->data.data[i] - y_true->data.data[i];
        scalar_loss += diff * diff;
    }
    scalar_loss /= y_pred->data.rows; 

    Matrix loss_mat(1, 1);
    loss_mat.data[0] = scalar_loss;
    auto res = std::make_shared<Variable>(loss_mat);
    res->parents = {y_pred};
    res->backward_op = [res, y_pred, y_true, n]() {
        double loss_grad = res->grad.data[0];
        for (size_t i = 0; i < n; ++i) {
            double g = (2.0 / y_pred->data.rows) * (y_pred->data.data[i] - y_true->data.data[i]);
            y_pred->grad.data[i] += loss_grad * g;
        }
    };
    return res;
}

} 
#endif
