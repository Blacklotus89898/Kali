#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem> // For std::filesystem::current_path()
#include "helper.h"

int main() {
    // Output current working directory to help debug path issues
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Read the CSV file with relative path
    Data d = readCSV("data\\data.csv"); //windows path working

    // Print the headers
    std::cout << "Headers: ";
    for (const auto& header : d.headers) {
        std::cout << header << " ";
    }
    std::cout << std::endl;

    // Print the rows
    std::cout << "Rows:" << std::endl;
    for (const auto& row : d.rows) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
