
#ifndef myClass1
#define myClass1

#include <string>

using namespace std;

class MyClass1 {
public:
  MyClass1();
  MyClass1(int n, string s);
  MyClass1(MyClass1 &&) = default;
  MyClass1(const MyClass1 &) = default;
  MyClass1 &operator=(MyClass1 &&) = default;
  MyClass1 &operator=(const MyClass1 &) = default;
  ~MyClass1();
  void setValue(int n, string s);
  void displayInfo();


private:
  string name;
  int num;
};

#endif
