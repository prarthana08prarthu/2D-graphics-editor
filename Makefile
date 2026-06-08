CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm
TARGET = graphics_editor
SOURCES = main.c graphics.c canvas.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
	@echo "✓ Build successful! Run with: ./$(TARGET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "✓ Cleaned up object files and executable"

rebuild: clean all

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run
