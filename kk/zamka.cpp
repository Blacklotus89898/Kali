#include <iostream>

using namespace std;

int sumOfDigit(int num) {
    int sum = 0;

    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}


int main() {
    int L, D, X;
    int N, M;

    cin >> L >> D >> X;

    //N = minimal -- substract by nine or greatest possible with bounds, start from min
    //M = maximal


    if (sumOfDigit(L) == X) {
        N = L;

    } else {
        while(sumOfDigit(L) != X) {
            L++;
        }
        N = L;
    }

    if (sumOfDigit(D) == X) {


        M = D;

    } else {
        while(sumOfDigit(D) != X) {

            D--;

        }
        M = D;

    }

    cout << N << endl;
    cout << M << endl;

    return 0;
}

