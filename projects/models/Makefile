# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN := app.exe
INCLUDE_DIR := include
DATA_DIR := data  # You mentioned 'data' but it's not used in compilation, just here for reference

# Source and object files
SRCS := $(SRC_DIR)/main.cpp $(SRC_DIR)/helper.cpp
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Link the final binary
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Clean build files
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(BIN) del /q $(BIN)
	@if exist $(OBJ_DIR)\*.o del /q $(OBJ_DIR)\*.o

# Optional: phony targets to avoid conflicts with files of the same name
.PHONY: all clean
