# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -Iinclude -static-libstdc++ -static-libgcc

# Source and build directories
SRC_DIR := src
TESTS_DIR := tests
OBJ_DIR := obj
BIN := app
TEST_BIN := tests_main

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TEST_SRCS := $(wildcard $(TESTS_DIR)/*.cpp)

# Default target
all: $(BIN)

# Link the final binary
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Test target
test: $(TEST_BIN)
	./$(TEST_BIN)

# Compile and link the test binary
TEST_OBJS := $(filter-out $(SRC_DIR)/main.cpp, $(SRCS))

$(TEST_BIN): $(TEST_OBJS) $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Optional: phony targets to avoid conflicts with files of the same name
.PHONY: all clean test
