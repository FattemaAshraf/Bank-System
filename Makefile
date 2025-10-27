# Makefile for Bank System Project
# Simple commands to build and run your project!

# Compiler settings
CXX = clang++
CXXFLAGS = -std=c++11 -Wall
TARGET = BankSystem
SRC_DIR = Bank\ System

# Source files
SOURCES = $(SRC_DIR)/Bank\ System.cpp $(SRC_DIR)/Validation.cpp

# Default target - build and run
all: build run

# Build the project
build:
	@echo "🔨 Building Bank System..."
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
	@echo "✅ Build complete!"

# Run the program
run:
	@echo "🚀 Running Bank System..."
	@echo ""
	./$(TARGET)

# Build and run in one command
start: build run

# Clean up compiled files
clean:
	@echo "🧹 Cleaning up..."
	rm -f $(TARGET)
	@echo "✅ Clean complete!"

# Rebuild (clean + build)
rebuild: clean build

# Just compile without running
compile: build

.PHONY: all build run start clean rebuild compile
