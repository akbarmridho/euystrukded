#include "refrigerator.h"

void cmd_refrigerator() {
    display_refrigerator(refrigerator);
    if (NEFF(refrigerator_food) == 0) {
        printf("Kulkas Anda kosong\n");
    } else {
        printf("Isi Kulkas:\n");
        printf("(nama - waktu sisa kedaluwarsa - ID)\n");
        for (int i = 0; i < NEFF(refrigerator_food); i++) {
            food_t food = ELMT(refrigerator_food, i);
            printf("   %d. ", (i + 1));
            print_string(FOOD_NAME(food));
            printf(" - ");
            write_fulltime(FOOD_EXPIRE_TIME(food));
            printf(" - ");
            printf("<ID-%d>", FOOD_ID(food));
            putchar('\n');
        }
    }

    printf("\nEnter command: ");
}

/* memasukkan makanan ke kulkas */
void cmd_freeze(int food_idx) {
    if (!is_next_to_refrigerator()) {
        printf("Anda tidak berada di area kulkas!\nEnter command: ");
        return;
    }
    if (food_idx < 0 || food_idx >= NEFF(inventory(simulator))) {
        printf("Indeks tidak ditemukan pada inventory.\n");
        printf("\nEnter command: ");
        return;
    }
    
    food_t item = ELMT(inventory(simulator), food_idx);
    point_t startpoint;
    for (int i = 0; i <= ROWEFF_R(refrigerator) - FOOD_SIZE_LENGTH(FOOD_SIZE(item)); i++) {
        for (int j = 0; j <= ROWEFF_R(refrigerator) - FOOD_SIZE_WIDTH(FOOD_SIZE(item)); j++) {
            create_point(&startpoint, i, j);
            if (is_item_fit(refrigerator, item, startpoint)) {
                backup_state();
                store_item_refrigerator(item, startpoint);
                
                string name = FOOD_NAME(item);
                notify(concat(name, char_to_string(" berhasil dimasukkan ke dalam kulkas.")));
                notify_undo(concat(name, char_to_string(" tidak jadi dimasukkan ke dalam kulkas.")));
                clear_display();
                display_info();
                printf("\nEnter command: ");
                return;
            }
        }
    }
    printf("Makanan tidak dapat dimasukkan ke dalam kulkas.\n");
    printf("\nEnter command: ");
    return;
}

/* mengeluarkan makanan dari kulkas, food_idx adalah idx dari list refrigerator_food */
void cmd_defrost(int food_idx) {
    if (!is_next_to_refrigerator()) {
        printf("Anda tidak berada di area kulkas!\nEnter command: ");
        return;
    }
    if (food_idx < 0 || food_idx >= NEFF(refrigerator_food)) {
        printf("Indeks makanan tidak ditemukan pada kulkas.\n");
        printf("\nEnter command: ");
        return;
    }

    backup_state();
    food_t item = ELMT(refrigerator_food, food_idx);
    retract_item_refrigerator(item);

    string name = FOOD_NAME(item);
    notify(concat(name, char_to_string(" sudah dikembalikan ke inventory.")));
    notify_undo(concat(name, char_to_string(" tidak jadi dikeluarkan dari kulkas.")));
    clear_display();
    display_info();
    printf("\nEnter command: ");
    return;
}