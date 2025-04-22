#include <iostream>
#include <string>
#include "myClass1.h"

MyClass1::MyClass1(int n, std::string s) {
  name = s;
  num = n;
}

void MyClass1::setValue(int n, std::string s) {
  name = s;
  num = n;
}

int MyClass1::getNum() {
  return num;
}

void MyClass1::displayInfo() {
  std::cout << "MyClass1 name: " << name << " num" << num << std::endl;
}

MyClass1::MyClass1() {
}

MyClass1::~MyClass1() {
  std::cout << "Class instance destroyed" << std::endl;
}
