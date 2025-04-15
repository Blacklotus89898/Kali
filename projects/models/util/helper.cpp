#ifndef HELPER_HPP
#define HELPER_HPP

#include <vector>
#include <stdexcept>

template <typename T>
double calculateAccuracy(const std::vector<T>& predictions, const std::vector<T>& labels) {
    if (predictions.size() != labels.size()) {
        throw std::invalid_argument("Predictions and labels must have the same size.");
    }

    size_t correctCount = 0;
    for (size_t i = 0; i < predictions.size(); ++i) {
        if (predictions[i] == labels[i]) {
            ++correctCount;
        }
    }

    return static_cast<double>(correctCount) / predictions.size();
}

/**
 * @brief Computes the confusion matrix metrics: True Positive Rate (TPR), True Negative Rate (TNR),
 * False Positive Rate (FPR), and False Negative Rate (FNR).
 *
 * @tparam T The type of the elements in the predictions and labels vectors (e.g., int).
 * @param predictions A vector containing the predicted labels (0 or 1).
 * @param labels A vector containing the ground truth labels (0 or 1).
 * @return A vector of doubles containing the metrics in the following order:
 *         {True Positive Rate (TPR), True Negative Rate (TNR), 
 *          False Positive Rate (FPR), False Negative Rate (FNR)}.
 * @throws std::invalid_argument If the size of predictions and labels vectors do not match.
 */
template <typename T>
std::vector<double> confusionMatrix(const std::vector<T>& predictions, const std::vector<T>& labels) {
    if (predictions.size() != labels.size()) {
        throw std::invalid_argument("Predictions and labels must have the same size.");
    }

    double tp = 0, tn = 0, fp = 0, fn = 0;

    for (size_t i = 0; i < predictions.size(); ++i) {
        if (predictions[i] == 1 && labels[i] == 1) {
            ++tp;
        } else if (predictions[i] == 0 && labels[i] == 0) {
            ++tn;
        } else if (predictions[i] == 1 && labels[i] == 0) {
            ++fp;
        } else if (predictions[i] == 0 && labels[i] == 1) {
            ++fn;
        }
    }

    double tpr = tp / (tp + fn); // True Positive Rate
    double tnr = tn / (tn + fp); // True Negative Rate
    double fpr = fp / (fp + tn); // False Positive Rate
    double fnr = fn / (fn + tp); // False Negative Rate

    return {tpr, tnr, fpr, fnr};
}


/**
 * @brief Computes the Mean Squared Error (MSE) between predictions and labels.
 *
 * @tparam T The type of the elements in the predictions and labels vectors (e.g., double).
 * @param predictions A vector containing the predicted values.
 * @param labels A vector containing the ground truth values.
 * @return The Mean Squared Error (MSE) as a double.
 * @throws std::invalid_argument If the size of predictions and labels vectors do not match.
 */
template <typename T>
double meanSquaredError(const std::vector<T>& predictions, const std::vector<T>& labels) {
    if (predictions.size() != labels.size()) {
        throw std::invalid_argument("Predictions and labels must have the same size.");
    }

    double mse = 0.0;
    for (size_t i = 0; i < predictions.size(); ++i) {
        double error = predictions[i] - labels[i];
        mse += error * error;
    }
    return mse / predictions.size();
}

// K-fold cross-validation function
template <typename T>
std::vector<std::vector<T>> kFoldCrossValidation(const std::vector<T>& data, int k) {
    std::vector<std::vector<T>> folds(k);
    int foldSize = data.size() / k;
    for (int i = 0; i < k; ++i) {
        int start = i * foldSize;
        int end = (i == k - 1) ? data.size() : start + foldSize;
        folds[i] = std::vector<T>(data.begin() + start, data.begin() + end);
    }
    return folds;
}

// precsion and recall curve
/**
 * @brief Computes the precision-recall curve for a set of predictions and labels.
 * 
 * This function calculates the precision and recall values for each prediction-label pair
 * and returns a vector containing the precision and recall values in an alternating sequence.
 * 
 * @tparam T The type of the elements in the predictions and labels vectors. Typically, this
 *           would be an integer or boolean type.
 * @param predictions A vector of predicted values (e.g., 0 or 1 for binary classification).
 * @param labels A vector of ground truth labels (e.g., 0 or 1 for binary classification).
 *               Must have the same size as the predictions vector.
 * @return A vector of doubles containing the precision and recall values in an alternating
 *         sequence. For example, the vector will contain [precision1, recall1, precision2, recall2, ...].
 * 
 * @throws std::invalid_argument If the size of the predictions vector does not match the size
 *                                of the labels vector.
 */
template <typename T>
std::vector<double> precisionRecallCurve(const std::vector<T>& predictions, const std::vector<T>& labels) {
    if (predictions.size() != labels.size()) {
        throw std::invalid_argument("Predictions and labels must have the same size.");
    }

    double tp = 0, fp = 0, fn = 0;
    std::vector<double> precisionRecallCurve;

    for (size_t i = 0; i < predictions.size(); ++i) {
        if (predictions[i] == 1 && labels[i] == 1) {
            ++tp;
        } else if (predictions[i] == 1 && labels[i] == 0) {
            ++fp;
        } else if (predictions[i] == 0 && labels[i] == 1) {
            ++fn;
        }

        double precision = tp / (tp + fp);
        double recall = tp / (tp + fn);
        precisionRecallCurve.push_back(precision);
        precisionRecallCurve.push_back(recall);
    }

    return precisionRecallCurve;
}




#endif // HELPER_HPP