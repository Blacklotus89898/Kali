#include <iostream>

using namespace std;



int factorial(int num) {
    if (num == 1) return 1;
    return num * factorial(num-1);
}

int factorial2(int num, int acc = 1) {

    if (num > 1) {

        return factorial2(num-1, acc * num);

    } else {

        return acc;

    }

}




int main() {

    int num;

    cin >> num;

    cout << factorial(num) << endl;
    cout << factorial2(num) << endl;
    //cout << factorial2(num, 1) << endl;



    return 0;



}
