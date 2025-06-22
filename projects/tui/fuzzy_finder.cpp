#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

// Simple fuzzy score: how many characters from query are found in order
int fuzzy_score(const std::string& filename, const std::string& query) {
    size_t j = 0;
    for (char c : filename) {
        if (j < query.size() && std::tolower(c) == std::tolower(query[j])) {
            ++j;
        }
    }
    return static_cast<int>(j);
}

void collect_files(const fs::path& dir, std::vector<std::string>& files) {
    for (auto& p : fs::recursive_directory_iterator(dir)) {
        if (fs::is_regular_file(p)) {
            files.push_back(p.path().string());
        }
    }
}

int main(int argc, char* argv[]) {
    std::string query;
    std::cout << "Enter search query: ";
    std::getline(std::cin, query);

    std::vector<std::string> files;
    collect_files(".", files);  // or pass root directory as arg

    // Score and sort files
    std::vector<std::pair<int, std::string>> scored;
    for (const auto& file : files) {
        int score = fuzzy_score(file, query);
        if (score > 0)
            scored.emplace_back(score, file);
    }

    std::sort(scored.begin(), scored.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });

    std::cout << "\nTop Matches:\n";
    for (size_t i = 0; i < std::min(scored.size(), size_t(10)); ++i) {
        std::cout << scored[i].second << "\n";
    }

    return 0;
}
