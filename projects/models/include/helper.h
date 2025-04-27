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

Data cleanData(const Data& data); // Just the declaration

std::vector<Data> splitData(const Data& data, float train_ratio, float val_ratio); // Just the declaration

void generateConfusionMatrix (const std::vector<std::string>& actual, const std::vector<std::string>& predicted); // Just the declaration

#endif // HELPER_H
