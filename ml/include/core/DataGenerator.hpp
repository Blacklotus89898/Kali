#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include <fstream>
#include <iostream>

namespace ml {

class DataGenerator {
public:
    static void generateXOR(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not create data file." << std::endl;
            return;
        }

        // CSV Header
        file << "x1,x2,y\n";
        // XOR Truth Table
        file << "0,0,0\n";
        file << "0,1,1\n";
        file << "1,0,1\n";
        file << "1,1,0\n";

        file.close();
        std::cout << "Successfully generated " << filename << "\n";
    }
};

}
#endif
