#include "graphics.h"
#include <stdlib.h>
#include <math.h>


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
void modify_object(int index) {
    if (index < 0 || index >= object_count) return;

    if (objects[index].type == 'L') {
        int x1, y1, x2, y2;
        printf("Enter new line coordinates (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        objects[index].params[0] = x1;
        objects[index].params[1] = y1;
        objects[index].params[2] = x2;
        objects[index].params[3] = y2;
    }
    else if (objects[index].type == 'C') {
        int cx, cy, r;
        printf("Enter new circle center and radius (cx cy r): ");
        scanf("%d %d %d", &cx, &cy, &r);
        objects[index].params[0] = cx;
        objects[index].params[1] = cy;
        objects[index].params[2] = r;
    }
    else if (objects[index].type == 'R') {
        int x, y, w, h;
        printf("Enter new rectangle (x y width height): ");
        scanf("%d %d %d %d", &x, &y, &w, &h);
        objects[index].params[0] = x;
        objects[index].params[1] = y;
        objects[index].params[2] = w;
        objects[index].params[3] = h;
    }
    else if (objects[index].type == 'T') {
        int x1, y1, x2, y2, x3, y3;
        printf("Enter new triangle coordinates (x1 y1 x2 y2 x3 y3): ");
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        objects[index].params[0] = x1;
        objects[index].params[1] = y1;
        objects[index].params[2] = x2;
        objects[index].params[3] = y2;
        objects[index].params[4] = x3;
        objects[index].params[5] = y3;
    }

    // Clear and redraw everything
    init_canvas();
    for (int i = 0; i < object_count; i++) {
        if (objects[i].type == 'L') {
            draw_line(canvas, objects[i].params[0], objects[i].params[1],
                      objects[i].params[2], objects[i].params[3]);
        }
        else if (objects[i].type == 'C') {
            draw_circle(canvas, objects[i].params[0], objects[i].params[1],
                        objects[i].params[2]);
        }
        else if (objects[i].type == 'R') {
            draw_rectangle(canvas, objects[i].params[0], objects[i].params[1],
                           objects[i].params[2], objects[i].params[3]);
        }
        else if (objects[i].type == 'T') {
            draw_triangle(canvas, objects[i].params[0], objects[i].params[1],
                          objects[i].params[2], objects[i].params[3],
                          objects[i].params[4], objects[i].params[5]);
        }
    }
}





// Bresenham's line algorithm - draws a line between two points
void bresenham_line(Canvas* canvas, int x1, int y1, int x2, int y2) {
    int dx = labs(x2 - x1);
    int dy = labs(y2 - y1);
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
