#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "graphics.h"

// Draw a line using Bresenham's algorithm
void draw_line(Canvas* canvas, int x1, int y1, int x2, int y2) {
    bresenham_line(canvas, x1, y1, x2, y2);
}

// Bresenham's line algorithm - draws a line between two points
static inline int abs_int(int v) {
    return (v < 0) ? -v : v;
}

void bresenham_line(Canvas* canvas, int x1, int y1, int x2, int y2) {
    int dx = (x2 > x1 ? x2 - x1 : x1 - x2);
    int dy = (y2 > y1 ? y2 - y1 : y1 - y2);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    int x = x1, y = y1;

    while (1) {
        canvas_draw_pixel(canvas, x, y, '*');

        if (x == x2 && y == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

// Draw a circle using Midpoint Circle algorithm
void draw_circle(Canvas* canvas, int cx, int cy, int radius) {
    midpoint_circle(canvas, cx, cy, radius);
}

// Midpoint circle algorithm
void midpoint_circle(Canvas* canvas, int cx, int cy, int radius) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        // Draw 8 symmetrical points
        canvas_draw_pixel(canvas, cx + x, cy + y, '*');
        canvas_draw_pixel(canvas, cx + y, cy + x, '*');
        canvas_draw_pixel(canvas, cx - y, cy + x, '*');
        canvas_draw_pixel(canvas, cx - x, cy + y, '*');
        canvas_draw_pixel(canvas, cx - x, cy - y, '*');
        canvas_draw_pixel(canvas, cx - y, cy - x, '*');
        canvas_draw_pixel(canvas, cx + y, cy - x, '*');
        canvas_draw_pixel(canvas, cx + x, cy - y, '*');

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        } else {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

// Draw a rectangle
void draw_rectangle(Canvas* canvas, int x, int y, int width, int height) {
    int x2 = x + width - 1;
    int y2 = y + height - 1;

    // Top and bottom lines
    for (int i = x; i <= x2; i++) {
        canvas_draw_pixel(canvas, i, y, '*');
        canvas_draw_pixel(canvas, i, y2, '*');
    }

    // Left and right lines
    for (int i = y; i <= y2; i++) {
        canvas_draw_pixel(canvas, x, i, '*');
        canvas_draw_pixel(canvas, x2, i, '*');
    }
}

// Draw a triangle
void draw_triangle(Canvas* canvas, int x1, int y1, int x2, int y2, int x3, int y3) {
    // Draw three lines connecting the vertices
    draw_line(canvas, x1, y1, x2, y2);
    draw_line(canvas, x2, y2, x3, y3);
    draw_line(canvas, x3, y3, x1, y1);
}
