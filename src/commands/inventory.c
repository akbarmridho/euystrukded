/**
 * @file inventory.c
 * @brief command INVENTORY
 * @version 1.0
 * @date 2022-10-30
 */

#include "inventory.h"

void cmd_inventory() {
    ListFood inv_list = inventory(simulator);
    printf("List Makanan di Inventor\n");
    printf("(nama - waktu sisa kedaluwarsa)\n");
    for (int i = 0; i < NEFF(inv_list); i++) {
        food_t food = ELMT(inv_list, i);
        printf("   %d. ", (i + 1));
        print_string(FOOD_NAME(food));
        printf(" - ");
        write_fulltime(FOOD_EXPIRE_TIME(food));
        
        putchar('\n');
    }
}
