#include "map.h"
#include <stdio.h>

/*
 * Menampilkan peta dan juga posisi player saat ini
 */
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

/*
 * Periksa jika pemain bisa bergerak ke suatu titik
 */
boolean is_able_move_to(point_t destination) {
    return mat_is_idx_valid(map, destination.x, destination.y) &&
           (MAT_ELMT(map, ORDINAT(destination), ABSIS(destination)) == '#');
}

/*
 * Menampilkan posisi karakter pada map
 */
point_t get_char_pos(char c) {
    boolean found = false;
    int i = 0;

    point_t destination;

    while (i < MAT_ROW_EFF(map) && !found) {
        int j = 0;

        while (j < MAT_COL_EFF(map) && !found) {
            if (MAT_ELMT(map, i, j) == c) {
                found = true;
                create_point(&destination, j, i);
            } else {
                j++;
            };
        }

        i++;
    }

    return destination;
}

// mendapatkan posisi boiler
point_t get_boiler_position() {
    return get_char_pos('B');
}

// mendapatkan posisi chopper
point_t get_fryer_position() {
    return get_char_pos('F');
}

// mendapatkan posisi mixer
point_t get_mixer_position() {
    return get_char_pos('M');
}

// mendapatkan posisi telepon
point_t get_delivery_position() {
    return get_char_pos('T');
}

// mendapatkan posisi chopper
point_t get_chopper_position() {
    return get_char_pos('C');
}

point_t get_refrigerator_position(){
    return get_char_pos('R');
}