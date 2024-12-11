# Define the compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99 -O2 -Wno-unused-parameter -lm

# Include directories
INCLUDES = -I.

# Source files
SRCS = main.c sha2.c memzero.c starknet_fncs.c mini-gmp.c mini-gmp-helpers.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Executable file
EXEC = main

# Make sure to keep going after errors
MAKEFLAGS += -k

# Default target
all: $(EXEC)

# Rule to link the object files and create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up the build files
clean:
	del /f $(OBJS) $(EXEC).exe

# Phony targets
.PHONY: all clean