#include "canvas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 50
#define COLS 50
#include <stdlib.h> // for abs()

void draw_line(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        canvas[y1][x1] = '*';
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

char canvas[ROWS][COLS];

void init_canvas() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            canvas[i][j] = ' ';
}

void display_canvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}


// Create a new canvas
Canvas* canvas_create(int width, int height) {
    Canvas* canvas = (Canvas*)malloc(sizeof(Canvas));
    canvas->width = width;
    canvas->height = height;
    canvas->object_count = 0;

    // Initialize grid with spaces
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas->grid[i][j] = ' ';
        }
    }

    return canvas;
}

// Clear the canvas
void canvas_clear(Canvas* canvas) {
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            canvas->grid[i][j] = ' ';
        }
    }
    canvas->object_count = 0;
}

// Draw a pixel on canvas
void canvas_draw_pixel(Canvas* canvas, int x, int y, char ch) {
    if (x >= 0 && x < canvas->width && y >= 0 && y < canvas->height) {
        canvas->grid[y][x] = ch;
    }
}

// Display the canvas
void canvas_display(Canvas* canvas) {
    system("clear"); // Clear screen (use "cls" on Windows)
    
    // Print top border
    printf("+");
    for (int i = 0; i < canvas->width; i++) {
        printf("-");
    }
    printf("+\n");

    // Print grid
    for (int i = 0; i < canvas->height; i++) {
        printf("|");
        for (int j = 0; j < canvas->width; j++) {
            printf("%c", canvas->grid[i][j]);
        }
        printf("|\n");
    }

    // Print bottom border
    printf("+");
    for (int i = 0; i < canvas->width; i++) {
        printf("-");
    }
    printf("+\n");
}

// Add an object to canvas
void canvas_add_object(Canvas* canvas, Object obj) {
    if (canvas->object_count < MAX_OBJECTS) {
        canvas->objects[canvas->object_count] = obj;
        canvas->object_count++;
        printf("\n✓ Object added successfully!\n");
    } else {
        printf("\n✗ Canvas is full! Cannot add more objects.\n");
    }
}

// Delete an object from canvas
void canvas_delete_object(Canvas* canvas, int index) {
    if (index >= 0 && index < canvas->object_count) {
        for (int i = index; i < canvas->object_count - 1; i++) {
            canvas->objects[i] = canvas->objects[i + 1];
        }
        canvas->object_count--;
        printf("\n✓ Object deleted successfully!\n");
        canvas_redraw_all(canvas);
    } else {
        printf("\n✗ Invalid object index!\n");
    }
}

// Modify an object
void canvas_modify_object(Canvas* canvas, int index, Object new_obj) {
    if (index >= 0 && index < canvas->object_count) {
        canvas->objects[index] = new_obj;
        printf("\n✓ Object modified successfully!\n");
        canvas_redraw_all(canvas);
    } else {
        printf("\n✗ Invalid object index!\n");
    }
}

// List all objects
void canvas_list_objects(Canvas* canvas) {
    printf("\n=== Objects on Canvas ===\n");
    if (canvas->object_count == 0) {
        printf("No objects on canvas.\n");
        return;
    }

    for (int i = 0; i < canvas->object_count; i++) {
        printf("\nObject %d:\n", i);
        printf("  Type: ");
        switch (canvas->objects[i].type) {
            case 'L': printf("Line\n"); break;
            case 'C': printf("Circle\n"); break;
            case 'R': printf("Rectangle\n"); break;
            case 'T': printf("Triangle\n"); break;
            default: printf("Unknown\n");
        }
        printf("  Position: (%d, %d)\n", canvas->objects[i].x, canvas->objects[i].y);
    }
}

// Redraw all objects on canvas
void canvas_redraw_all(Canvas* canvas) {
    // Clear grid
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            canvas->grid[i][j] = ' ';
        }
    }

    // Redraw all objects (will be done by main.c)
}

// Free canvas memory
void canvas_free(Canvas* canvas) {
    free(canvas);
}
