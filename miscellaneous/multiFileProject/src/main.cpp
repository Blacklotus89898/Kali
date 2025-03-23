#include <iostream>
#include "myClass1.h"

//Entry point of the application
using namespace std;


int main() {
  MyClass1 c1(1, "C1Name");

  c1.displayInfo();

  c1.setValue(1, "NewName");
  
  c1.displayInfo();



  return 0;
}

