#include "automove.h"

void move_auto_to(point_t destination) {
    point_t *path;
    int steps;

    find_path(simulator.position, destination, &path, &steps);

    if (steps == 0) {
        printf("Already reached destination\n");
        return;
    } else if (steps < 0) {
        printf("Steps shouldn't be negative\n");
    }

    int i = steps;
    while (i >= 0) {
        move(path[i--]);
//        clear_display();
//        display_info();
    }

    clear_display();
    display_info();
    printf("Total steps taken %d\n", steps - 1);

    free(path);
}