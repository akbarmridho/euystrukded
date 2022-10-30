#include <stdio.h>
#include "catalog.h"

void display_catalog() {
    printf("List Makanan\n");
    printf("nama - durasi kadaluarsa - aksi yang diperlukan - delivery time\n");
    for (int i = 0; i < neff(food_recipe); i++) {
        printf("%d. ", i + 1);
        print_string(food_recipe.contents[i].food.name);
        printf(" - ");
        if (food_recipe.contents[i].food.expire_time.dd == 0 && food_recipe.contents[i].food.expire_time.hh == 0 &&
            food_recipe.contents[i].food.expire_time.mm == 0) {
            printf("0");
        } else {
            write_fulltime(food_recipe.contents[i].food.expire_time);
            printf(" - ");
        }
        if (food_recipe.contents[i].food.source == Buy) {
            printf("BUY - ");
        }
        if (food_recipe.contents[i].food.source == Mix) {
            printf("MIX - ");
        }
        if (food_recipe.contents[i].food.source == Chop) {
            printf("CHOP - ");
        }
        if (food_recipe.contents[i].food.source == Fry) {
            printf("FRY - ");
        }
        if (food_recipe.contents[i].food.delivery_time.dd == 0 && food_recipe.contents[i].food.delivery_time.hh == 0 &&
            food_recipe.contents[i].food.delivery_time.mm == 0) {
            printf("0");
        } else {
            write_fulltime(food_recipe.contents[i].food.delivery_time);
        }
        printf("\n");
    }
}