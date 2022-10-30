/**
 * @file inventory.c
 * @brief command INVENTORY
 * @version 1.0
 * @date 2022-10-30
 */

#include "inventory.h"

simulator_t simulator;

void cmd_inventory(){
    ListFood inv_list = inventory(simulator);
    printf("List Makanan di Inventor\n");   
    printf("(nama - waktu sisa kedaluwarsa)\n");
    for (int i = 0; i < NEFF(inv_list); i++){
        food_t food = ELMT(inv_list, i);
        printf("   %d. ", (i + 1));
        print_string(FOOD_NAME(food));
        printf(" -");

        if (DAY(FOOD_EXPIRE_TIME(food)) != 0){
            printf(" %d hari", DAY(FOOD_EXPIRE_TIME(food)));
        }
        if (HOUR(FOOD_EXPIRE_TIME(food)) != 0){
            printf(" %d jam", HOUR(FOOD_EXPIRE_TIME(food)));
        }
        if (MINUTE(FOOD_EXPIRE_TIME(food)) != 0){
            printf(" %d menit", MINUTE(FOOD_EXPIRE_TIME(food)));
        }
        putchar('\n');
    }
}
