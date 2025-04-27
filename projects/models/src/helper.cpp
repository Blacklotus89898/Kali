// helper.cpp
#include "helper.h"
#include <fstream>
#include <sstream>
#include <iostream>

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
