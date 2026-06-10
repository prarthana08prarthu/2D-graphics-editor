#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "graphics.h"

void display_menu() {
    printf("\n2D Graphics Editor\n");
    printf("Canvas size: 80 x 24\n");
    printf("1. Add object\n");
    printf("2. Delete object\n");
    printf("3. Modify object\n");
    printf("4. Display picture\n");
    printf("5. List objects\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
}

int main() {
    Canvas* canvas = canvas_create(80, 24);
    int choice;
    int shape_type, x1, y1, x2, y2, x3, y3, radius;
    int obj_index;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add object
                printf("\nChoose shape type:\n");
                printf("1. Line\n");
                printf("2. Rectangle\n");
                printf("3. Circle\n");
                printf("4. Triangle\n");
                printf("Enter shape type: ");
                scanf("%d", &shape_type);

                switch (shape_type) {
                    case 1: // Line
                        printf("Enter x1 y1 x2 y2: ");
                        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                        draw_line(canvas, x1, y1, x2, y2);
                        
                        Object line_obj;
                        line_obj.type = 'L';
                        line_obj.x = x1;
                        line_obj.y = y1;
                        line_obj.x2 = x2;
                        line_obj.y2 = y2;
                        canvas_add_object(canvas, line_obj);
                        break;

                    case 2: // Rectangle
                        printf("Enter top-left x y and bottom-right x y: ");
                        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                        draw_rectangle(canvas, x1, y1, x2 - x1, y2 - y1);
                        
                        Object rect_obj;
                        rect_obj.type = 'R';
                        rect_obj.x = x1;
                        rect_obj.y = y1;
                        rect_obj.x2 = x2;
                        rect_obj.y2 = y2;
                        canvas_add_object(canvas, rect_obj);
                        break;

                    case 3: // Circle
                        printf("Enter center x y and radius: ");
                        scanf("%d %d %d", &x1, &y1, &radius);
                        draw_circle(canvas, x1, y1, radius);
                        
                        Object circle_obj;
                        circle_obj.type = 'C';
                        circle_obj.x = x1;
                        circle_obj.y = y1;
                        circle_obj.size = radius;
                        canvas_add_object(canvas, circle_obj);
                        break;

                    case 4: // Triangle
                        printf("Enter x1 y1 x2 y2 x3 y3: ");
                        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
                        draw_triangle(canvas, x1, y1, x2, y2, x3, y3);
                        
                        Object tri_obj;
                        tri_obj.type = 'T';
                        tri_obj.x = x1;
                        tri_obj.y = y1;
                        tri_obj.x2 = x2;
                        tri_obj.y2 = y2;
                        canvas_add_object(canvas, tri_obj);
                        break;

                    default:
                        printf("Invalid shape type!\n");
                }
                break;

            case 2: // Delete object
                printf("\nEnter object index to delete: ");
                scanf("%d", &obj_index);
                canvas_delete_object(canvas, obj_index);
                break;

            case 3: // Modify object
                printf("\nEnter object index to modify: ");
                scanf("%d", &obj_index);
                // Modify functionality can be added here
                break;

            case 4: // Display picture
                printf("\n");
                canvas_display(canvas);
                break;

            case 5: // List objects
                printf("\nObjects on canvas:\n");
                canvas_list_objects(canvas);
                break;

            case 0: // Exit
                printf("Goodbye.\n");
                canvas_free(canvas);
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
