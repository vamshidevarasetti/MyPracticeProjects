# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Target executable (final artifact)
TARGET = hello

# Default target
all: $(TARGET)

# Link step
$(TARGET): hello.o
	$(CC) hello.o -o $(TARGET)

# Compile step
hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

# Clean build artifacts
clean:
	rm -f hello.o hello
