#include  <iostream>
#include  <vector>

void brute_force(int& n);

int main() {


    int n = 0;
    std::cin >> n;

    // brute force
    brute_force(n);

    // try all compbinations of 4 and 7 since n is <= 1000



    return 0;
}



void brute_force(int& n) {
    // brute force
    std::vector<int> lucky_number = {4, 7, 47, 74, 77, 447, 474, 477,  747, 774, 777};

    for (const auto& lucky : lucky_number) {
        if (n % lucky == 0) {
            std::cout << "YES" << std::endl;
            return;
        }
    }

 
    std::cout << "NO" << std::endl;
}


// Can also use backtracking