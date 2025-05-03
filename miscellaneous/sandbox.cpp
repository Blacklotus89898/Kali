#include <iostream> // For std::cout, std::cin
#include <string> // For std::string
#include <vector> // For std::vector
#include <map> // For std::map
#include <cmath> // For std::abs, std::sqrt, std::pow
#include <numeric> // For std::accumulate
#include <algorithm> // Include this for std::max_element, std::min_element, and std::find
#include <filesystem> // For std::filesystem
#include <fstream> // For file operations



int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;
    
    // Arguments passed to the program
    std::cout << "Arguments passed: " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    // Cin and getline
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input; // This will only read until the first space
    std::cout << "You entered: " << input << std::endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);
    std::cout << "You entered this sentence: " << input << std::endl;

    // String manipulation 
    /*
    1. Length and size
    2. Append and insert
    3. Erase and clear
    4. Find and replace
    5. Substring
    6. Compare
    7. Convert to upper/lower case
    8. Split and join
    9. Reverse
    10. Trim (remove leading and trailing spaces)
    11. Check if empty
    12. To integer/float
    13. To char array
    14. To string from char array
    15. To string from int/float
    16. iterate
    */

    std::string str = "Hello, World!";
    std::cout << "Length of string: " << str.length() << std::endl;
    std::cout << "Size of string: " << str.size() << std::endl;
    std::cout << "First character: " << str[0] << std::endl;
    std::cout << "Last character: " << str[str.length() - 1] << std::endl;
    std::cout << "Substring (0, 5): " << str.substr(0, 5) << std::endl;
    auto toUpper = [](const std::string& s) {
        std::string result = s;
        for (char& c : result) {
            c = std::toupper(c);
        }
        return result;
    };
    std::cout << "String in uppercase: " << toUpper(str) << std::endl;

    // std::cout << "String in lowercase: " <<  << std::endl;
    
    if (str.empty()) {
        std::cout << "String is empty" << std::endl;
    } else {
        std::cout << "String is not empty" << std::endl;
    }

    str.find("World") != std::string::npos ? std::cout << "Found 'World' in string" << std::endl : std::cout << "Not found" << std::endl;
    str.replace(str.find("World"), 5, "Universe");
    std::cout << "Replaced string: " << str << std::endl;

    str.erase(0, 5); // Erase first 5 characters
    std::cout << "After erasing first 5 characters: " << str << std::endl;
    str.clear(); // Clear the string
    std::cout << "After clearing: " << str << std::endl;
    str = "  Hello, World!"; // Reset the string
    auto trim = [](std::string& s) {
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\r") + 1);
    };

    trim(str); // Trim leading and trailing spaces
    std::cout << "After trimming: " << str << std::endl;
    str = "12345";
    int num = std::stoi(str); // Convert string to integer
    std::cout << "Converted to integer: " << num << std::endl;
    str = std::to_string(num); // Convert integer to string
    std::cout << "Converted back to string: " << str << std::endl;

    std::vector<char> charArray;
    for(char c : str) {
        charArray.push_back(c); // Convert string to char array
    }
    std::cout << "Converted to char array: ";
    for(char c : charArray) {
        std::cout << c << " ";
    }
    std::cout << std::endl;


    // STL 
    // Vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector elements: ";
    for (const auto& i : vec) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    std::cout << "Vector sum: " << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
    std::cout << "Vector max: " << *std::max_element(vec.begin(), vec.end()) << std::endl;

    std::cout << "Vector min: " << *std::min_element(vec.begin(), vec.end()) << std::endl;

    std::cout << "Vector average: " << (std::accumulate(vec.begin(), vec.end(), 0) / static_cast<double>(vec.size())) << std::endl;


    std::cout << "Is 3 in the vector: " << (std::find(vec.begin(), vec.end(), 3) != vec.end() ? "Yes" : "No") << std::endl; 

    // Map
    std::map<std::string, int> myMap = {{"one", 1}, {"two", 2}, {"three", 3}};
    std::cout << "Map size: " << myMap.size() << std::endl;
    std::cout << "Map elements: ";
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << ", "; //only accessible this way
    }

    std::cout << std::endl;

    std::cout << "Map value for 'two': " << myMap["two"] << std::endl;
    myMap["two"] = 22; // Update value

    std::cout << "Exists in map: " << (myMap.find("two") != myMap.end() ? "Yes" : "No") << std::endl;
    
    std::cout << "Exists in map" << myMap.count("two")  << std::endl;
    

    // Filesystem


    namespace fs = std::filesystem;

    // Create a file, directory, and check if it exists
    std::string dirName = "example_dir";
    if (!fs::exists(dirName)) {
        fs::create_directory(dirName);
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cout << "Directory already exists: " << dirName << std::endl;
    }

    std::string filePath = dirName + "/example_file.txt";
    if (!fs::exists(filePath)) {
        std::ofstream newFile(filePath);
        if (newFile.is_open()) {
            newFile << "This is a test file." << std::endl;
            newFile.close();
            std::cout << "File created: " << filePath << std::endl;
        } else {
            std::cerr << "Unable to create file: " << filePath << std::endl;
        }
    } else {
        std::cout << "File already exists: " << filePath << std::endl;
    }

    // Read a file
    std::ifstream inFile(filePath);
    if (inFile.is_open()) {
        std::cout << "Reading from file: " << filePath << std::endl;
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filePath << std::endl;
    }

    // Write to a file
    std::ofstream outFile(filePath, std::ios::trunc); // Truncate the file
    if (outFile.is_open()) {
        outFile << "Overwriting the file with new content." << std::endl;
        outFile.close();
        std::cout << "File overwritten: " << filePath << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
    }

    // Append to a file
    std::ofstream appendFile(filePath, std::ios::app); // Append mode
    if (appendFile.is_open()) {
        appendFile << "Appending this line to the file." << std::endl;
        appendFile.close();
        std::cout << "Content appended to file: " << filePath << std::endl;
    } else {
        std::cerr << "Unable to open file for appending: " << filePath << std::endl;
    }



    // Iterators
    // Iterators with vector
    std::cout << "Iterating through vector using iterators: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Reverse iterator
    std::cout << "Iterating in reverse order: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Const iterator
    std::cout << "Using const iterator: ";
    for (std::vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Map iterators
    std::cout << "Iterating through map: ";
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << ", ";
    }
    std::cout << std::endl;

    // Range-based for loop (uses iterators internally)
    std::cout << "Range-based for loop: ";
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Iterator with std::advance
    auto it = vec.begin();
    std::advance(it, 2); // Move iterator forward by 2 positions
    std::cout << "Element at 3rd position using std::advance: " << *it << std::endl;

    // Iterator with std::next and std::prev
    auto nextIt = std::next(vec.begin(), 3); // Get iterator to 4th element
    std::cout << "4th element using std::next: " << *nextIt << std::endl;

    auto prevIt = std::prev(vec.end(), 2); // Get iterator to 2nd last element
    std::cout << "2nd last element using std::prev: " << *prevIt << std::endl;

    // DSA and algorithms
    
    return 0;
}