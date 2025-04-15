#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <stdexcept>
#include <numeric>

/**
 * @class KNN
 * @brief A simple implementation of the k-Nearest Neighbors (k-NN) algorithm.
 *
 * This class provides functionality to fit a dataset and predict the label of a query point
 * using the k-Nearest Neighbors algorithm. It supports both weighted and unweighted voting.
 */
class KNN {
public:
    enum class DistanceMetric {
        EUCLIDEAN,
        MANHATTAN,
        COSINE,
        HAMMING
    };

    /**
     * @brief Constructor for the KNN class.
     * 
     * @param k The number of nearest neighbors to consider. Must be greater than 0.
     * @param weighted Whether to use weighted voting based on the inverse of distances. Default is false.
     * @param metric The distance metric to use. Default is Euclidean.
     * @throws std::invalid_argument if k is less than or equal to 0.
     */
    KNN(int k, bool weighted = false, DistanceMetric metric = DistanceMetric::EUCLIDEAN)
        : k(k), weighted(weighted), metric(metric) {
        if (k <= 0) {
            throw std::invalid_argument("k must be greater than 0");
        }
    }

    void fit(const std::vector<std::vector<float>>& data, const std::vector<int>& labels) {
        if (data.size() != labels.size()) {
            throw std::invalid_argument("Data and labels size mismatch");
        }
        this->data = data;
        this->labels = labels;
    }

    int predict(const std::vector<float>& query_point) const {
        if (data.empty() || labels.empty()) {
            throw std::runtime_error("Model has not been fitted with data");
        }
        if (k > data.size()) {
            throw std::invalid_argument("k cannot be greater than the number of data points");
        }

        std::vector<std::pair<float, int>> distances;
        for (size_t i = 0; i < data.size(); ++i) {
            float distance = compute_distance(query_point, data[i]);
            distances.emplace_back(distance, labels[i]);
        }

        std::sort(distances.begin(), distances.end());

        return combined_vote({distances.begin(), distances.begin() + k});
    }

private:
    float compute_distance(const std::vector<float>& a, const std::vector<float>& b) const {
        switch (metric) {
            case DistanceMetric::EUCLIDEAN:
                return euclidean_distance(a, b);
            case DistanceMetric::MANHATTAN:
                return manhattan_distance(a, b);
            case DistanceMetric::COSINE:
                return cosine_similarity(a, b);
            case DistanceMetric::HAMMING:
                return hamming_distance(a, b);
            default:
                throw std::invalid_argument("Unsupported distance metric");
        }
    }

    float euclidean_distance(const std::vector<float>& a, const std::vector<float>& b) const {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Dimensionality mismatch between points");
        }
        float sum = 0.0f;
        for (size_t i = 0; i < a.size(); ++i) {
            sum += std::pow(a[i] - b[i], 2);
        }
        return std::sqrt(sum);
    }

    float manhattan_distance(const std::vector<float>& a, const std::vector<float>& b) const {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Dimensionality mismatch between points");
        }
        float sum = 0.0f;
        for (size_t i = 0; i < a.size(); ++i) {
            sum += std::abs(a[i] - b[i]);
        }
        return sum;
    }

    float cosine_similarity(const std::vector<float>& a, const std::vector<float>& b) const {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Dimensionality mismatch between points");
        }
        float dot_product = 0.0f;
        float norm_a = 0.0f;
        float norm_b = 0.0f;
        for (size_t i = 0; i < a.size(); ++i) {
            dot_product += a[i] * b[i];
            norm_a += a[i] * a[i];
            norm_b += b[i] * b[i];
        }
        return 1.0f - (dot_product / (std::sqrt(norm_a) * std::sqrt(norm_b) + std::numeric_limits<float>::epsilon()));
    }

    float hamming_distance(const std::vector<float>& a, const std::vector<float>& b) const {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Dimensionality mismatch between points");
        }
        int count = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++count;
            }
        }
        return static_cast<float>(count);
    }

    int combined_vote(const std::vector<std::pair<float, int>>& distances) const {
        std::unordered_map<int, float> vote_count;
        for (const auto& [distance, label] : distances) {
            float weight = weighted ? 1.0f / (distance + std::numeric_limits<float>::epsilon()) : 1.0f;
            vote_count[label] += weight;
        }

        int majority_label = -1;
        float max_votes = 0.0f;
        for (const auto& [label, votes] : vote_count) {
            if (votes > max_votes) {
                max_votes = votes;
                majority_label = label;
            }
        }
        return majority_label;
    }

    int k;
    bool weighted;
    DistanceMetric metric;
    std::vector<std::vector<float>> data;
    std::vector<int> labels;
};