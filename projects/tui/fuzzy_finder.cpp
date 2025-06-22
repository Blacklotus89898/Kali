#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <algorithm>
#include <cctype>
#include <termios.h>
#include <unistd.h>
#include <csignal>

namespace fs = std::filesystem;

std::vector<std::string> files;

// Disable canonical input buffering
struct Terminal {
    termios oldt;

    Terminal() {
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);  // Disable buffering and echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }

    ~Terminal() {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore on exit
    }
};

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

void render(const std::string& query) {
    std::vector<std::pair<int, std::string>> scored;
    for (const auto& file : files) {
        int score = fuzzy_score(file, query);
        if (score > 0)
            scored.emplace_back(score, file);
    }

    std::sort(scored.begin(), scored.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });

    std::cout << "\033[2J\033[H";  // Clear screen
    std::cout << "Query: " << query << "\n";
    std::cout << "Matches:\n";
    for (size_t i = 0; i < std::min(scored.size(), size_t(10)); ++i) {
        std::cout << scored[i].second << "\n";
    }
}

int main() {
    collect_files(".", files);

    Terminal t;
    std::string query;
    char c;

    render(query);

    while (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == 127 || c == '\b') { // Backspace
            if (!query.empty()) query.pop_back();
        } else if (c == '\n') {
            break;
        } else if (std::isprint(c)) {
            query += c;
        }

        render(query);
    }

    std::cout << "\nFinal query: " << query << "\n";
    return 0;
}
