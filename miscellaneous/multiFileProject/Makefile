CXX = g++
CXXFLAGS = -Wall -Iinclude -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread

SRC = src/main.cpp src/myClass1.cpp
OBJ = $(SRC:.cpp=.o)

TEST_SRC = tests/test_myClass1.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

TARGET = myProjectName
TEST_TARGET = runTests

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) src/myClass1.o
	$(CXX) $(TEST_OBJ) src/myClass1.o -o $(TEST_TARGET) $(LDFLAGS)

clean:
	rm -f src/*.o tests/*.o $(TARGET) $(TEST_TARGET)
