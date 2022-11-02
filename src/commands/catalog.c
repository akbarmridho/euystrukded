#include <stdio.h>
#include "catalog.h"

void display_catalog() {
    printf("List Makanan\n");
    printf("(nama - durasi kadaluarsa - aksi yang diperlukan - delivery time)\n");

    int counter = 1;
    for (int i = 0; i < neff(food_recipe); i++) {
        if (food_recipe.contents[i].food.source == Buy) {
            printf("%d. ", counter++);
            print_string(food_recipe.contents[i].food.name);
            printf(" - ");

            if (food_recipe.contents[i].food.expire_time.dd == 0 && food_recipe.contents[i].food.expire_time.hh == 0 &&
                food_recipe.contents[i].food.expire_time.mm == 0) {
                printf("0");
            } else {
                write_fulltime(food_recipe.contents[i].food.expire_time);
                printf(" - ");
            }
            printf("BUY - ");
            write_fulltime(food_recipe.contents[i].food.delivery_time);
            printf("\n");
        }
    }

    printf("\nEnter command: ");
}