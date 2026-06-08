#include "graphics.h"
#include <math.h>
#include<stdlib.h>

// Draw a line using Bresenham's algorithm
void draw_line(Canvas* canvas, int x1, int y1, int x2, int y2) {
    bresenham_line(canvas, x1, y1, x2, y2);
}
void delete_object(int index) {
    if (index < 0 || index >= object_count) return;
    for (int i = index; i < object_count - 1; i++) {
        objects[i] = objects[i + 1];
    }
    object_count--;

    init_canvas();
    for (int i = 0; i < object_count; i++) {
        // call draw function depending on objects[i].type
    }
}


// Bresenham's line algorithm - draws a line between two points
void bresenham_line(Canvas* canvas, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
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
