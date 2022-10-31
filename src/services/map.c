#include "map.h"
#include <stdio.h>
//
//simulator_t simulator;
//Matrix map;

void display_map() {
    int k = 0, l = 0;
    for (int i = 0; i < MAT_ROW_EFF(map) + 2; i++) {
        for (int j = 0; j < MAT_COL_EFF(map) + 2; j++) {
            if (j == 0 || j == MAT_COL_EFF(map) + 1 || i == 0 || i == MAT_ROW_EFF(map) + 1) {
                printf("* ");
            } else {
                if (simulator.position.x == l && simulator.position.y == k) {
                    printf("S ");
                } else if (MAT_ELMT(map, k, l) == '#') {
                    printf("  ");
                } else {
                    printf("%c ", MAT_ELMT(map, k, l));
                }
                l++;
            }
        }
        l = 0;
        if (i != 0) {
            k++;
        }
        printf("\n");
    }
    printf("\n");
}


boolean is_able_move_to(point_t destination) {
    return mat_is_idx_valid(map, destination.x, destination.y) &&
           (MAT_ELMT(map, ORDINAT(destination), ABSIS(destination)) == '#');
}

point_t get_char_pos(char c) {
    boolean found = false;
    int i = 0;

    point_t destination;

    while (i < MAT_ROW_EFF(map) && !found) {
        int j = 0;

        while (j < MAT_COL_EFF(map) && !found) {
            if (MAT_ELMT(map, i, j) == c) {
                found = true;
                create_point(&destination, i, j);
            }
        }
    }

    return destination;
}

point_t get_boiler_position() {
    return get_char_pos('B');
}

point_t get_fryer_position() {
    return get_char_pos('F');
}

point_t get_mixer_position() {
    return get_char_pos('M');
}

point_t get_delivery_position() {
    return get_char_pos('T');
}

point_t get_chopper_position() {
    return get_char_pos('C');
}