#include <iostream>

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

int main() {
    Rectangle rect(10, 20);  // Now passing arguments to the constructor
    rect.display();          // This will display the initialized values
    return 0;
}

