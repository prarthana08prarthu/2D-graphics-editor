#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "canvas.h"

// Drawing functions
void draw_line(Canvas* canvas, int x1, int y1, int x2, int y2);
void draw_circle(Canvas* canvas, int cx, int cy, int radius);
void draw_rectangle(Canvas* canvas, int x, int y, int width, int height);
void draw_triangle(Canvas* canvas, int x1, int y1, int x2, int y2, int x3, int y3);

// Helper functions
void bresenham_line(Canvas* canvas, int x1, int y1, int x2, int y2);
void midpoint_circle(Canvas* canvas, int cx, int cy, int radius);

#endif
