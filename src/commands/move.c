#include "move.h"

void cmd_move(string direction) {
    string north = char_to_string("NORTH");
    string south = char_to_string("SOUTH");
    string east = char_to_string("EAST");
    string west = char_to_string("WEST");

    point_t delta, pos;
    string nums;
    pos = simulator.position;

    if (startwith(direction, north)) {
        create_point(&delta, 0, -1);
        nums = cut_str(direction, 6, neff(direction) - 1);
    } else if (startwith(direction, south)) {
        create_point(&delta, 0, 1);
        nums = cut_str(direction, 6, neff(direction) - 1);
    } else if (startwith(direction, east)) {
        create_point(&delta, 1, 0);
        nums = cut_str(direction, 5, neff(direction) - 1);
    } else if (startwith(direction, west)) {
        create_point(&delta, -1, 0);
        nums = cut_str(direction, 5, neff(direction) - 1);
    } else {
        printf("Perintah yang anda masukan salah! Pilihan yang tersedia: NORTH, SOUTH, EAST, WEST\n");
        printf("Enter command: ");
        return;
    }

    int n = string_to_natural_int(nums);

    if (n == -1 || n == 0) {
        printf("Format MOVE salah! Gunakan \"MOVE {NORTH|SOUTH|EAST|WEST} [n_times](opsional)\" dengan n_times > 0\n");
        printf("\nEnter command: ");
        return;
    } else if (n == -2 || n > 0) {
        if (n == -2) {
            n = 1;
        }
        backup_state();
        for (int i = 0; i < n; i++) {
            if (is_able_move_to(point_plus_delta(pos, ABSIS(delta), ORDINAT(delta)))) {
                move(point_plus_delta(pos, ABSIS(delta), ORDINAT(delta)));
                pos = simulator.position;
                next_tick();
            } else {
                clear_display();
                display_info();
                if (i == 0) {
                    printf("Anda tidak bisa bergerak ke sana :(\n");
                } else {
                    printf("Anda hanya bisa bergerak sebanyak %d langkah\n", (i));

                }
                printf("Enter command: ");
                return;
            }
        }

    }

    clear_display();
    display_info();
    printf("Enter command: ");
}
