# Multi file project template

## Building and running project
### Command line
```bash 
g++ src/main.cpp src/myClass1.cpp -Iinclude -o execName
```

### Makefile
```bash
# To build executable
make 

# To cleanup
make clean
```

### CMakeLists.txt
```bash
mkdir build && cd build
cmake ..
make
./myProjectName

# For cleanup
rm -r build
```

## Testing
```bash
make tests
./runTests
```

