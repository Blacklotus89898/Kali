#ifndef KNN_H
#define KNN_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <stdexcept>
#include <numeric>

/**
 * @file knn.h
 * @brief Header file for the KNN class implementing the k-Nearest Neighbors algorithm.
 */

/**
 * @class KNN
 * @brief A simple implementation of the k-Nearest Neighbors (k-NN) algorithm.
 *
 * This class provides functionality to fit a dataset and predict the label of a query point
 * using the k-Nearest Neighbors algorithm. It supports both weighted and unweighted voting.
 */
template <typename FeatureType, typename LabelType>
class KNN {
public:
    /**
     * @enum DistanceMetric
     * @brief Enum for supported distance metrics.
     */
    enum class DistanceMetric {
        Euclidean,
        // Manhattan,
        // Chebyshev
    };

    /**
     * @brief Constructor for the KNN class.
     * @param k Number of neighbors to consider.
     * @param metric Distance metric to use.
     * @param weighted Whether to use weighted voting.
     */
    KNN(int k = 3, DistanceMetric metric = DistanceMetric::Euclidean, bool weighted = false);

    /**
     * @brief Fit the model with training data.
     * @param X Training data features.
     * @param y Training data labels.
     */
    void fit(const std::vector<std::vector<FeatureType>>& X, const std::vector<LabelType>& y);

    /**
     * @brief Predict labels for a set of test data.
     * @param X_test Test data features.
     * @return Predicted labels for the test data.
     */
    std::vector<LabelType> predict(const std::vector<std::vector<FeatureType>>& X_test);

private:
    int k; ///< Number of neighbors to consider.
    DistanceMetric metric; ///< Distance metric to use.
    bool weighted; ///< Whether to use weighted voting.
    std::vector<std::vector<FeatureType>> X_train; ///< Training data features.
    std::vector<LabelType> y_train; ///< Training data labels.

    /**
     * @brief Compute the Euclidean distance between two points.
     * @param a First point.
     * @param b Second point.
     * @return Euclidean distance between the two points.
     */
    FeatureType euclidean_distance(const std::vector<FeatureType>& a, const std::vector<FeatureType>& b);

    /**
     * @brief Predict the label for a single data point.
     * @param x Data point to predict.
     * @return Predicted label for the data point.
     */
    LabelType predict_single(const std::vector<FeatureType>& x);
};

#endif // KNN_H
