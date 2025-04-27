#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include "helper.h"
#include "knn.h" 

int main() {
    // Output current working directory to help debug path issues
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Read the CSV file with relative path
    Data d = readCSV("data\\data.csv"); // Windows path working

    d = cleanData(d); // Clean the data

    // Split data into train, validation, and test sets
    std::vector<Data> split = splitData(d, 0.8, 0.1); 
    std::cout << "Train data size: " << split[0].rows.size() << std::endl;
    std::cout << "Validation data size: " << split[1].rows.size() << std::endl;
    std::cout << "Test data size: " << split[2].rows.size() << std::endl;

    // Extract the labels (y_train) from the first element of split
    std::vector<std::string> y_train;
    for (const auto& row : split[0].rows) {
        y_train.push_back(row.front()); // Assuming the label is the first column
    }

    // Extract the features (x_train) from the third element of split, only columns 3 to 6
    std::vector<std::vector<float>> x_train;
    for (const auto& row : split[0].rows) {
        std::vector<float> features;
        for (size_t i = 2; i < 6; ++i) { // Columns 3 to 6 (0-based index: 2 to 5)
            features.push_back(std::stof(row[i]));
        }
        x_train.push_back(features);
    }

    // Instantiate the KNN classifier (float features and string labels)
    KNN<float, std::string> knn(3, KNN<float, std::string>::DistanceMetric::Euclidean, true);

    // Train the KNN model
    knn.fit(x_train, y_train);


    // 
    // Prepare test data (x_test) similarly (this should be done for test data)
    std::vector<std::vector<float>> x_test;
    std::vector<std::string> y_test; // To hold the actual labels for evaluation

    // Assuming you are using the third data split (test data)
    for (const auto& row : split[2].rows) {
        std::vector<float> features;
        for (size_t i = 2; i < 6; ++i) { // Columns 3 to 6 (0-based index: 2 to 5)
            features.push_back(std::stof(row[i]));
        }
        x_test.push_back(features);
        y_test.push_back(row.front()); // Assuming the label is the first column
    }

    // Predict labels for the test data
    std::vector<std::string> predictions = knn.predict(x_test);

    // Print the predictions and actual labels for evaluation
    std::cout << "Predictions vs Actual Labels:" << std::endl;
    for (size_t i = 0; i < predictions.size(); ++i) {
        std::cout << "Prediction: " << predictions[i] << ", Actual: " << y_test[i] << std::endl;
    }

    // Function to generate and print confusion matrix
  

    // Call the function
    generateConfusionMatrix(y_test, predictions);

    return 0;
}
