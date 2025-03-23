#include <iostream>

using namespace std;

int add(int a, int b) {
return a + b;
}

// pass by ref
void add2(int& a, int& b, int& c) {
    c = a + b;
}

// pass by pointers values
void add3(int* a, int* b, int* c) {
    *c = *a + *b;
}

int main() {
    int a, b, c;

    cin >> a >> b;

    cout << add(a, b) << endl;

    add2(a, b, c);

    cout << c << endl;
    
// pointers 
    int* pa;

    pa = &a;

    cout << pa << "address"  << endl;

    cout << *pa << "vs " << a << endl;
    

    int c2, c3;
    add2(a,b,c2);

    //int* pa = &a;
    int* pb = &b;
    int* pc = &c3;
    add3(pa, &b, pc);

    cout << add(a,b) << c2 << *pc << c3 << endl;


return 0;
}
