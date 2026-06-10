#include "canvas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new canvas
Canvas* canvas_create(int width, int height) {
    Canvas* canvas = (Canvas*)malloc(sizeof(Canvas));
    canvas->width = width;
    canvas->height = height;
    canvas->object_count = 0;

    // Initialize grid with underscores
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas->grid[i][j] = '_';
        }
    }

    return canvas;
}

// Clear the canvas
void canvas_clear(Canvas* canvas) {
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            canvas->grid[i][j] = '_';
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
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            printf("%c", canvas->grid[i][j]);
        }
        printf("\n");
    }
}

// Add an object to canvas
void canvas_add_object(Canvas* canvas, Object obj) {
    if (canvas->object_count < MAX_OBJECTS) {
        canvas->objects[canvas->object_count] = obj;
        printf("Object added with index %d.\n", canvas->object_count);
        canvas->object_count++;
    } else {
        printf("Canvas is full! Cannot add more objects.\n");
    }
}

// Delete an object from canvas
void canvas_delete_object(Canvas* canvas, int index) {
    if (index >= 0 && index < canvas->object_count) {
        for (int i = index; i < canvas->object_count - 1; i++) {
            canvas->objects[i] = canvas->objects[i + 1];
        }
        canvas->object_count--;
        printf("Object deleted.\n");
        canvas_redraw_all(canvas);
    } else {
        printf("Invalid object index!\n");
    }
}

// Modify an object
void canvas_modify_object(Canvas* canvas, int index, Object new_obj) {
    if (index >= 0 && index < canvas->object_count) {
        canvas->objects[index] = new_obj;
        printf("Object modified.\n");
        canvas_redraw_all(canvas);
    } else {
        printf("Invalid object index!\n");
    }
}

// List all objects
void canvas_list_objects(Canvas* canvas) {
    if (canvas->object_count == 0) {
        printf("No objects on canvas.\n");
        return;
    }

    for (int i = 0; i < canvas->object_count; i++) {
        printf("Object %d: Type %c at (%d, %d)\n", i, canvas->objects[i].type, canvas->objects[i].x, canvas->objects[i].y);
    }
}

// Redraw all objects on canvas
void canvas_redraw_all(Canvas* canvas) {
    // Clear grid
    for (int i = 0; i < canvas->height; i++) {
        for (int j = 0; j < canvas->width; j++) {
            canvas->grid[i][j] = '_';
        }
    }
    // Redraw all objects (will be done by main.c)
}

// Free canvas memory
void canvas_free(Canvas* canvas) {
    free(canvas);
}
