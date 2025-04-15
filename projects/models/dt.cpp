#include <vector>
#include <cmath>
#include <stdexcept>

class DecisionTreeClassifier {
public:
    enum class CostFunctionType {
        CrossEntropy
    };

    DecisionTreeClassifier(int max_depth = 10, CostFunctionType cost_function_type = CostFunctionType::CrossEntropy) 
        : max_depth(max_depth), cost_function_type(cost_function_type) {}

    void fit(const std::vector<std::vector<float>>& X, const std::vector<int>& y) {
        // Implementation of the fit method
    }

    std::vector<int> predict(const std::vector<std::vector<float>>& X) {
        // Implementation of the predict method
        return {};
    }

private:
    int max_depth;
    CostFunctionType cost_function_type;

    float compute_cost(const std::vector<int>& y_true, const std::vector<int>& y_pred) {
        switch (cost_function_type) {
            case CostFunctionType::CrossEntropy:
                return cross_entropy(y_true, y_pred);
            default:
                throw std::invalid_argument("Unsupported cost function type");
        }
    }

    float cross_entropy(const std::vector<int>& y_true, const std::vector<int>& y_pred) {
        float cost = 0.0f;
        for (size_t i = 0; i < y_true.size(); ++i) {
            if (y_pred[i] == 0 || y_pred[i] == 1) {
                cost -= y_true[i] * std::log(y_pred[i] + 1e-9f) + (1 - y_true[i]) * std::log(1 - y_pred[i] + 1e-9f);
            }
        }
        return cost / y_true.size();
    }
};