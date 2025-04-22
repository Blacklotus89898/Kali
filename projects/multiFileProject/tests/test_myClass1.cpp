
#include "myClass1.h"
#include <gtest/gtest.h>

// Sample function in MyClass1 for demonstration
int addNumbers(int a, int b) {
    return a + b;
}



// Google Test case
TEST(MyClass1Test, AdditionTest) {
    EXPECT_EQ(addNumbers(2, 3), 5);  // Pass
    EXPECT_EQ(addNumbers(-1, 1), 0); // Pass
    EXPECT_NE(addNumbers(2, 2), 5);  // Pass
}

TEST(MyClass1Test, setValueTest) {
  MyClass1 c1(1, "NewName");
  EXPECT_EQ(1, c1.getNum());
  c1.setValue(3, "name");
  EXPECT_EQ(3, c1.getNum());
}

// Main function for GTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
