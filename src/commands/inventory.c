/**
 * @file inventory.c
 * @brief command INVENTORY
 * @version 1.0
 * @date 2022-10-30
 */

#include "inventory.h"

void cmd_inventory() {
    printf("List Makanan di Inventor\n");
    printf("(nama - waktu sisa kedaluwarsa)\n");

    if (NEFF(inventory(simulator)) == 0) {
        printf("Anda tidak memiliki makanan\n");
    } else {
        for (int i = 0; i < NEFF(inventory(simulator)); i++) {
            food_t food = ELMT(inventory(simulator), i);
            printf("   %d. ", (i + 1));
            print_string(FOOD_NAME(food));
            printf(" - ");
            write_fulltime(FOOD_EXPIRE_TIME(food));

            putchar('\n');
        }
    }

    printf("\nEnter command: ");
}
