CXX = g++
CXXFLAGS = -Wall -Iinclude
SRC = src/main.cpp src/myClass1.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = myProjectName

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
