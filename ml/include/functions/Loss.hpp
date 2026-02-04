// ml/include/functions/Loss.hpp
namespace ml {

class MSE {
public:
    static double compute(const Matrix& y_pred, const Matrix& y_true) {
        double loss = 0;
        for (int i = 0; i < y_pred.data.size(); ++i) {
            double diff = y_pred.data[i] - y_true.data[i];
            loss += diff * diff;
        }
        return loss / y_pred.data.size();
    }

    static Matrix backward(const Matrix& y_pred, const Matrix& y_true) {
        Matrix grad(y_pred.rows, y_pred.cols);
        double n = static_cast<double>(y_pred.data.size());
        for (int i = 0; i < y_pred.data.size(); ++i) {
            grad.data[i] = (2.0 / n) * (y_pred.data[i] - y_true.data[i]);
        }
        return grad;
    }
};

class CrossEntropy {
public:
    static double compute(const Matrix& y_pred, const Matrix& y_true) {
        double loss = 0;
        for (int i = 0; i < y_pred.data.size(); ++i) {
            // Add epsilon to avoid log(0)
            loss -= y_true.data[i] * std::log(y_pred.data[i] + 1e-9);
        }
        return loss / y_pred.rows;
    }

    // This assumes y_pred has already gone through Softmax
    static Matrix backward(const Matrix& y_pred, const Matrix& y_true) {
        Matrix grad(y_pred.rows, y_pred.cols);
        for (int i = 0; i < y_pred.data.size(); ++i) {
            grad.data[i] = (y_pred.data[i] - y_true.data[i]) / y_pred.rows;
        }
        return grad;
    }
};

}
