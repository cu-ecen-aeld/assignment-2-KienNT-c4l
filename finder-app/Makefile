# Compiler (add CROSS_COMPILE before gcc if set)
CC := $(CROSS_COMPILE)gcc

# Compiler flags
CFLAGS := -Wall -Werror

# Output executable
TARGET := writer

# Source files
SRC := writer.c

# Object files
OBJ := $(SRC:.c=.o)

.PHONY: all clean

# Default target
all: $(TARGET)

# Build writer from object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) $(OBJ)
