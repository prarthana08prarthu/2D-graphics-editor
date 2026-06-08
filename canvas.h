#ifndef CANVAS_H
#define CANVAS_H

#define MAX_WIDTH 50
#define MAX_HEIGHT 20
#define MAX_OBJECTS 100

typedef struct {
    int x;
    int y;
    int size;
    char type; // 'C' for circle, 'R' for rectangle, 'L' for line, 'T' for triangle
    int width;
    int height;
    int x2;
    int y2;
} Object;

typedef struct {
    char grid[MAX_HEIGHT][MAX_WIDTH];
    Object objects[MAX_OBJECTS];
    int object_count;
    int width;
    int height;
} Canvas;

// Canvas operations
Canvas* canvas_create(int width, int height);
void canvas_clear(Canvas* canvas);
void canvas_display(Canvas* canvas);
void canvas_free(Canvas* canvas);

// Object operations
void canvas_add_object(Canvas* canvas, Object obj);
void canvas_delete_object(Canvas* canvas, int index);
void canvas_modify_object(Canvas* canvas, int index, Object new_obj);
void canvas_list_objects(Canvas* canvas);

// Drawing on canvas
void canvas_draw_pixel(Canvas* canvas, int x, int y, char ch);
void canvas_redraw_all(Canvas* canvas);

#endif
