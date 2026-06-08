#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "graphics.h"

void display_menu() {
    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║     2D GRAPHICS EDITOR - MAIN MENU     ║\n");
    printf("╚════════════════════════════════════════╝\n");
    printf("1. Draw Line\n");
    printf("2. Draw Circle\n");
    printf("3. Draw Rectangle\n");
    printf("4. Draw Triangle\n");
    printf("5. Display Canvas\n");
    printf("6. List Objects\n");
    printf("7. Delete Object\n");
    printf("8. Clear Canvas\n");
    printf("9. Exit\n");
    printf("─────────────────────────────────────────\n");
    printf("Enter your choice (1-9): ");
}

int main() {
    Canvas* canvas = canvas_create(50, 20);
    int choice;
    int x1, y1, x2, y2, x3, y3, radius, width, height;
    int obj_index;

    printf("\n");
    printf("╔════════════════════════════════════════╗\n");
    printf("║   Welcome to 2D Graphics Editor!       ║\n");
    printf("║   Canvas Size: 50 x 20                 ║\n");
    printf("╚════════════════════════════════════════╝\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Draw Line
                printf("\n--- Draw Line ---\n");
                printf("Enter first point (x1 y1): ");
                scanf("%d %d", &x1, &y1);
                printf("Enter second point (x2 y2): ");
                scanf("%d %d", &x2, &y2);

                draw_line(canvas, x1, y1, x2, y2);

                Object line_obj;
                line_obj.type = 'L';
                line_obj.x = x1;
                line_obj.y = y1;
                line_obj.x2 = x2;
                line_obj.y2 = y2;
                canvas_add_object(canvas, line_obj);

                printf("\n✓ Line drawn from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
                break;

            case 2: // Draw Circle
                printf("\n--- Draw Circle ---\n");
                printf("Enter center point (x y): ");
                scanf("%d %d", &x1, &y1);
                printf("Enter radius: ");
                scanf("%d", &radius);

                draw_circle(canvas, x1, y1, radius);

                Object circle_obj;
                circle_obj.type = 'C';
                circle_obj.x = x1;
                circle_obj.y = y1;
                circle_obj.size = radius;
                canvas_add_object(canvas, circle_obj);

                printf("\n✓ Circle drawn at (%d, %d) with radius %d\n", x1, y1, radius);
                break;

            case 3: // Draw Rectangle
                printf("\n--- Draw Rectangle ---\n");
                printf("Enter top-left corner (x y): ");
                scanf("%d %d", &x1, &y1);
                printf("Enter width: ");
                scanf("%d", &width);
                printf("Enter height: ");
                scanf("%d", &height);

                draw_rectangle(canvas, x1, y1, width, height);

                Object rect_obj;
                rect_obj.type = 'R';
                rect_obj.x = x1;
                rect_obj.y = y1;
                rect_obj.width = width;
                rect_obj.height = height;
                canvas_add_object(canvas, rect_obj);

                printf("\n✓ Rectangle drawn at (%d, %d) with size %d x %d\n", x1, y1, width, height);
                break;

            case 4: // Draw Triangle
                printf("\n--- Draw Triangle ---\n");
                printf("Enter first vertex (x1 y1): ");
                scanf("%d %d", &x1, &y1);
                printf("Enter second vertex (x2 y2): ");
                scanf("%d %d", &x2, &y2);
                printf("Enter third vertex (x3 y3): ");
                scanf("%d %d", &x3, &y3);

                draw_triangle(canvas, x1, y1, x2, y2, x3, y3);

                Object tri_obj;
                tri_obj.type = 'T';
                tri_obj.x = x1;
                tri_obj.y = y1;
                tri_obj.x2 = x2;
                tri_obj.y2 = y2;
                canvas_add_object(canvas, tri_obj);

                printf("\n✓ Triangle drawn with vertices (%d, %d), (%d, %d), (%d, %d)\n", 
                       x1, y1, x2, y2, x3, y3);
                break;

            case 5: {
                int index;
                printf("Enter object number to delete (0 to %d): ", object_count - 1);
                scanf("%d", &index);
                delete_object(index);
                break;
            }
            void modify_object(int index) {
    if (index < 0 || index >= object_count) return;

    // Ask user for new parameters depending on type
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
        int x, y, r;
        printf("Enter new circle center (x y) and radius: ");
        scanf("%d %d %d", &x, &y, &r);
        objects[index].params[0] = x;
        objects[index].params[1] = y;
        objects[index].params[2] = r;
    }
    // Add similar blocks for Rectangle and Triangle

    // After modification, clear and redraw
    init_canvas();
    for (int i = 0; i < object_count; i++) {
        if (objects[i].type == 'L') {
            draw_line(objects[i].params[0], objects[i].params[1],
                      objects[i].params[2], objects[i].params[3]);
        }
        else if (objects[i].type == 'C') {
            draw_circle(objects[i].params[0], objects[i].params[1],
                        objects[i].params[2]);
        }
        // Add rectangle/triangle redraws here
    }
}
       case 6: {
           int index;
           printf("Enter object number to modify (0 to %d): ", object_count - 1);
           scanf("%d", &index);
           modify_object(index);
           break;
       }





           

            case 7: // Delete Object
                printf("\n--- Delete Object ---\n");
                canvas_list_objects(canvas);
                printf("\nEnter object index to delete (0-%d): ", canvas->object_count - 1);
                scanf("%d", &obj_index);
                canvas_delete_object(canvas, obj_index);
                break;

            case 8: // Clear Canvas
                printf("\nClearing canvas...\n");
                canvas_clear(canvas);
                printf("✓ Canvas cleared!\n");
                break;

            case 9: // Exit
                printf("\nThank you for using 2D Graphics Editor!\n");
                printf("Goodbye! 👋\n\n");
                canvas_free(canvas);
                exit(0);
        
            case 10: {
                int index;
                printf("Enter object number to modify (0 to %d): ", object_count - 1);
                scanf("%d", &index);
                modify_object(index);
                break;
            }


            default:
                printf("\n✗ Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
