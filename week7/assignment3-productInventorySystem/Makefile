# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable name
TARGET = productInventorySystem.exe

# Source files
SRCS = assingment3-main.cpp Inventory.cpp Product.cpp
OBJS = $(SRCS:.cpp=.o)

# Main build rule
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Link and compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm $(OBJS) $(TARGET)