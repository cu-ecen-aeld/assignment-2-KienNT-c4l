# Compiler (native hoặc cross-compile)
CC ?= $(CROSS_COMPILE)gcc

# Output executable
TARGET = writer

# Source files
SRC = writer.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET)

# Link object -> executable
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

# Compile .c -> .o
%.o: %.c
	$(CC) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) $(OBJ)
