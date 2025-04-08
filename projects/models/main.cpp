#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem> // For std::filesystem::current_path()

// Data structure to hold CSV data
struct Data {
    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> rows;
};

// Function to read a CSV file and store its contents in a Data structure
Data readCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return {};
    }

    Data data;
    std::string line;

    // Read the header line
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            data.headers.push_back(cell);
        }
    }

    // Read the remaining lines as rows
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.rows.push_back(row);
    }

    file.close();
    return data;
}



int main() {
    
    // Windows reqquire the use of absolute path
    // std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
    Data data = readCSV("C:\\Users\\songy\\McGill\\Kali\\projects\\models\\data.csv");
    

    // Print the contents of the 2D vector
    std::cout << "Headers: ";
    for (const auto& header : data.headers) {
        std::cout << header << " ";
    }
    std::cout << std::endl;

    for (const auto& row : data.rows) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    // TODO:
    // Extract the labels and features from the data
    // Preprocess the data (e.g., normalization, encoding categorical variables)
    // Train models: knn, dt,  using the extracted data
    // Evaluate the model's performance


    return 0;
}