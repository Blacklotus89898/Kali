// helper.h
#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>

struct Data {
    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> rows;
};

Data readCSV(const std::string& filename);  // Just the declaration

#endif // HELPER_H
