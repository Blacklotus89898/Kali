#include "helper.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include <map>       // For std::map

Data readCSV(const std::string& filename) {
    Data data;
    std::ifstream file(filename);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cout << "Error: File '" << filename << "' not found or could not be opened." << std::endl;
        return data; // Return empty data
    }

    std::string line;

    // Read the headers
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string header;
        while (std::getline(ss, header, ',')) {
            data.headers.push_back(header);
        }
    }

    // Read the rows
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.rows.push_back(row);
    }

    return data;
}

Data cleanData(const Data& data) {
    Data cleaned_data;
    cleaned_data.headers = data.headers; // Copy headers

    // Iterate through rows and keep only valid rows
    for (const auto& row : data.rows) {
        bool valid_row = true;
        for (const auto& cell : row) {
            if (cell.empty() || cell == "NA") { // Check for empty or "NA" cells
                valid_row = false;
                break;
            }
        }
        if (valid_row) {
            cleaned_data.rows.push_back(row); // Add valid row to cleaned data
        }
    }

    return cleaned_data;
}


std::vector<Data> splitData(const Data& data, float train_ratio, float val_ratio) {
    std::vector<Data> splits(3); // 0: train, 1: validation, 2: test
    int total_rows = data.rows.size();
    int train_size = static_cast<int>(total_rows * train_ratio);
    int val_size = static_cast<int>(total_rows * val_ratio);

    // Create a shuffled index vector
    std::vector<int> indices(total_rows);
    for (int i = 0; i < total_rows; ++i) {
        indices[i] = i;
    }
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(indices.begin(), indices.end(), rng);

    // Fill the training set
    splits[0].headers = data.headers;
    for (int i = 0; i < train_size; ++i) {
        splits[0].rows.push_back(data.rows[indices[i]]);
    }

    // Fill the validation set
    splits[1].headers = data.headers;
    for (int i = train_size; i < train_size + val_size; ++i) {
        splits[1].rows.push_back(data.rows[indices[i]]);
    }

    // Fill the testing set
    splits[2].headers = data.headers;
    for (int i = train_size + val_size; i < total_rows; ++i) {
        splits[2].rows.push_back(data.rows[indices[i]]);
    }

    return splits;
}


void generateConfusionMatrix(const std::vector<std::string>& actual, const std::vector<std::string>& predicted) {
    std::map<std::string, std::map<std::string, size_t>> confusion_matrix;
    std::map<std::string, size_t> actual_counts;
    std::map<std::string, size_t> predicted_counts;
    size_t total_samples = actual.size();

    // Populate the confusion matrix and count occurrences
    for (size_t i = 0; i < predicted.size(); ++i) {
        confusion_matrix[actual[i]][predicted[i]]++;
        actual_counts[actual[i]]++;
        predicted_counts[predicted[i]]++;
    }

    // Print the confusion matrix
    std::cout << "Confusion Matrix:" << std::endl;
    std::cout << "Actual \\ Predicted" << std::endl;
    for (const auto& actual_pair : confusion_matrix) {
        std::cout << actual_pair.first << ":\t";
        for (const auto& predicted_pair : confusion_matrix) {
            std::cout << predicted_pair.first << "=" << confusion_matrix[actual_pair.first][predicted_pair.first] << "\t";
        }
        std::cout << std::endl;
    }

    // Calculate and print metrics
    size_t correct_predictions = 0;
    for (const auto& actual_pair : confusion_matrix) {
        correct_predictions += confusion_matrix[actual_pair.first][actual_pair.first];
    }
    double accuracy = static_cast<double>(correct_predictions) / total_samples;

    std::cout << "\nMetrics:" << std::endl;
    std::cout << "Accuracy: " << accuracy << std::endl;
}

// Additional helper functions can be added 

/*
- standardizign data
- one hot encoding
- normalization
- data cleaning

*/
