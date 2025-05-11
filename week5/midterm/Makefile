# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable name
TARGET = simpleBankingSystem.exe

# Source files
SRCS = main.cpp account.cpp userInterface.cpp validation.cpp menu.cpp
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