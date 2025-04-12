# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = my_program

# Source files
SRCS = my_program.cpp

# Build rule
$(TARGET): $(SRCS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule to remove compiled files
clean:
    rm -f $(TARGET)