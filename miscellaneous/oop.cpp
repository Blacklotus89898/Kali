#include <iostream>
#include <vector>
#include <string>

class Rectangle {
private:
    int width;
    int height;

public:
    // Constructor with initialization list
    Rectangle(int w, int h) : width(w), height(h) {}

    ~Rectangle() {
    std::cout << "Destructor called for rectangle" << std::endl;
    }

    void display() {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};


class PracticeClass {

    private:
    int classId;
    int number;
    std::string className;

    public:
        // constructor
        PracticeClass(std::string str) {
            std::vector<std::string> v;
            std::string curr = "";
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] != ' ') {
                    curr += str[i];
                } else {
                    v.push_back(curr);
                    curr = "";
                }
            }

            classId = std::stoi(v[0]);            
            number = std::stoi(v[1]);            

            for (const std::string& s: v) {
                std::cout << s ;
            }
            std::cout << std::endl;


        }
};

int main() {
    Rectangle rect(10, 20);  // Now passing arguments to the constructor
    rect.display();          // This will display the initialized values
    return 0;
}



