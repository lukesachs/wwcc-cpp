# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++17

# Target executable name
TARGET = makefile_demo.exe

# Source files
SOURCES = makefile_demo.cpp

# Default target
all: $(TARGET)

# Link and compile
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# Clean up
clean:
	del $(TARGET)
