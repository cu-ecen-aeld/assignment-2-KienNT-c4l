# Compiler
CC = $(CROSS_COMPILE)gcc

# Output executable
TARGET = writer

# Source files
SRC = writer.c

# Object files
OBJ = $(SRC:.c=.o)

.PHONY: all clean

# Default target
all: $(TARGET)

# Build writer from object files
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Compile .c -> .o
%.o: %.c
	$(CC) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) $(OBJ)
