#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "canvas.h"
typedef struct {
    char type; // 'C' circle, 'R' rectangle, 'L' line, 'T' triangle
    int params[6]; // store coordinates or radius depending on type
} Shape;

Shape objects[100];
int object_count;


// Drawing functions
void draw_line(Canvas* canvas, int x1, int y1, int x2, int y2);
void draw_circle(Canvas* canvas, int cx, int cy, int radius);
void draw_rectangle(Canvas* canvas, int x, int y, int width, int height);
void draw_triangle(Canvas* canvas, int x1, int y1, int x2, int y2, int x3, int y3);

// Helper functions
void bresenham_line(Canvas* canvas, int x1, int y1, int x2, int y2);
void midpoint_circle(Canvas* canvas, int cx, int cy, int radius);
objects[object_count].type = 'L';
objects[object_count].params[0] = x1;
objects[object_count].params[1] = y1;
objects[object_count].params[2] = x2;
objects[object_count].params[3] = y2;
object_count++;


#endif
