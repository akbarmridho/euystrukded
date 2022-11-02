#include "move.h"

void cmd_move(string direction) {
    string north = char_to_string("NORTH");
    string south = char_to_string("SOUTH");
    string east = char_to_string("EAST");
    string west = char_to_string("WEST");

    point_t delta, pos;
    string nums;
    pos = simulator.position;
    int num_start;

    if (startwith(direction, north)) {      /* cek arah yang dituju dengan mengecek prefiks argumen */
        create_point(&delta, 0, -1);
        num_start = 6;
    } else if (startwith(direction, south)) {
        create_point(&delta, 0, 1);
        num_start = 6;
    } else if (startwith(direction, east)) {
        create_point(&delta, 1, 0);
        num_start = 5;
    } else if (startwith(direction, west)) {
        create_point(&delta, -1, 0);
        num_start = 5;
    } else {                                                    /* argumen arah tujuan tidak sesuai */
        printf("Perintah yang anda masukan salah! Pilihan yang tersedia: NORTH, SOUTH, EAST, WEST\n");
        printf("Enter command: ");
        return;
    }

    int n;
    if (neff(direction) > num_start - 1) {      /* cek apakah argumen tidak hanya mengandung arah, misal "EAST ", "EAST)1" */
        if (letter_at(direction, num_start - 1) == ' ') {        /* argumen berstruktur "<arah> <string>"*/
            nums = cut_str(direction, num_start, neff(direction) - 1);
            n = string_to_natural_int(nums);
        } else {                                                        /* argumen salah, misal "EASTr12"*/
            printf("Perintah yang anda masukan salah! Pilihan yang tersedia: NORTH, SOUTH, EAST, WEST\n");
            printf("Enter command: ");
            return;
        }
    } else {                                    /* argumen hanya mengandung arah tujuan */
        n = 1;
    }

    if (n == -1 || n == 0) {            /* argumen setelah arah bukan string numerik atau bernilai 0 */
        printf("Format MOVE salah! Gunakan \"MOVE {NORTH|SOUTH|EAST|WEST} [n_times]\" dengan n_times opsional dan bernilai positif\n");
        printf("\nEnter command: ");
        return;
    } else if (n == -2 || n > 0) {      /* argumen berstruktur "<arah>" atau "<arah> " atau "<arah> <langkah>"*/
        if (n == -2) {
            n = 1;
        }
        backup_state();                     /* lakukan backup dan move */
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
