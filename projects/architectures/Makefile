# Compiler and flags
CXX := g++
# CXXFLAGS := -std=c++17 -Wall -Wextra -g -Iinclude

# Windows static linking to aoid dll conflict
CXXFLAGS := -std=c++17 -Wall -Wextra -g -Iinclude -static-libstdc++ -static-libgcc


# Source and build directories
SRC_DIR := src
OBJ_DIR := obj
BIN := app

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

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

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Optional: phony targets to avoid conflicts with files of the same name
.PHONY: all clean

