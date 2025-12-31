CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = hello_cpp
all: $(TARGET)

$(TARGET): hello.o
	$(CXX) hello.o -o $(TARGET)

hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -c hello.cpp

clean:
	rm -f hello.o hello_cpp

