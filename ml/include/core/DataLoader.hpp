#ifndef DATALOADER_HPP
#define DATALOADER_HPP

#include <fstream>
#include <sstream>
#include <string>
#include "Tensor.hpp"

namespace ml {

class DataLoader {
public:
    static std::pair<Matrix, Matrix> loadCSV(std::string filename, int num_samples, int x_dim, int y_dim) {
        Matrix X(num_samples, x_dim);
        Matrix Y(num_samples, y_dim);

        std::ifstream file(filename);
        std::string line;
        
        // Skip header
        std::getline(file, line);

        int row = 0;
        while (std::getline(file, line) && row < num_samples) {
            std::stringstream ss(line);
            std::string val;
            
            // Read X values
            for (int j = 0; j < x_dim; ++j) {
                std::getline(ss, val, ',');
                X(row, j) = std::stod(val);
            }
            // Read Y values
            for (int j = 0; j < y_dim; ++j) {
                std::getline(ss, val, ',');
                Y(row, j) = std::stod(val);
            }
            row++;
        }
        return {X, Y};
    }
};

}
#endif
