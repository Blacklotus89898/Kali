#include "knn.h"

/**
 * @brief Constructor for the KNN class.
 * @param k Number of neighbors to consider.
 * @param metric Distance metric to use.
 * @param weighted Whether to use weighted voting.
 */
template <typename FeatureType, typename LabelType>
KNN<FeatureType, LabelType>::KNN(int k, DistanceMetric metric, bool weighted)
    : k(k), metric(metric), weighted(weighted) {}

/**
 * @brief Fit the model with training data.
 * @param X Training data features.
 * @param y Training data labels.
 */
template <typename FeatureType, typename LabelType>
void KNN<FeatureType, LabelType>::fit(const std::vector<std::vector<FeatureType>>& X, const std::vector<LabelType>& y) {
    this->X_train = X;
    this->y_train = y;
}

/**
 * @brief Predict labels for a set of test data.
 * @param X_test Test data features.
 * @return Predicted labels for the test data.
 */
template <typename FeatureType, typename LabelType>
std::vector<LabelType> KNN<FeatureType, LabelType>::predict(const std::vector<std::vector<FeatureType>>& X_test) {
    std::vector<LabelType> predictions;
    for (const auto& x : X_test) {
        predictions.push_back(predict_single(x));
    }
    return predictions;
}

/**
 * @brief Compute the Euclidean distance between two points.
 * @param a First point.
 * @param b Second point.
 * @return Euclidean distance between the two points.
 */
template <typename FeatureType, typename LabelType>
FeatureType KNN<FeatureType, LabelType>::euclidean_distance(const std::vector<FeatureType>& a, const std::vector<FeatureType>& b) {
    FeatureType sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return std::sqrt(sum);
}

/**
 * @brief Predict the label for a single data point.
 * @param x Data point to predict.
 * @return Predicted label for the data point.
 */
template <typename FeatureType, typename LabelType>
LabelType KNN<FeatureType, LabelType>::predict_single(const std::vector<FeatureType>& x) {
    std::vector<std::pair<FeatureType, LabelType>> distances; // Pair of distance and label

    for (size_t i = 0; i < X_train.size(); ++i) {
        FeatureType dist = euclidean_distance(X_train[i], x);
        distances.emplace_back(dist, y_train[i]);
    }

    // Sort by distance
    std::sort(distances.begin(), distances.end());

    // Get the k nearest neighbors
    std::unordered_map<LabelType, FeatureType> class_votes; // Class label and its corresponding vote count or weight

    for (size_t i = 0; i < static_cast<size_t>(k) && i < distances.size(); ++i) {
        LabelType label = distances[i].second;
        FeatureType weight = weighted ? 1.0 / (distances[i].first + 1e-9) : 1.0; // Avoid division by zero

        class_votes[label] += weight;
    }

    // Find the class with the maximum votes
    return std::max_element(class_votes.begin(), class_votes.end(),
                             [](const auto& a, const auto& b) { return a.second < b.second; })->first;
}

// Explicit template instantiations (you can choose specific types you want to support here)
template class KNN<float, std::string>;
