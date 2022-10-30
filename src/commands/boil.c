#include <stdio.h>
#include "boil.h"
#include "boiler.h"
#include "../utils/validator.h"

/* Melakukan command boil pada makanan */
void do_boil() {
    ListFoodRecipe boilable;

    printf("======================\n");
    printf("=        BOIL        =\n");
    printf("======================\n");

    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    /* display and store fryable recipes in fryables */
    int counter = 1;
    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        food_recipe_t current = LFR_ELMT(food_recipe, i);
        if (FOOD_SOURCE(FR_FOOD(current)) == Boil) {
            lfr_insert_last(&boilable, current);
            printf("   %d. ", counter);
            print_string(FOOD_NAME(FR_FOOD(current)));
            putchar('\n');
            counter++;
        }
    }
    printf("\nKirim 0 untuk exit.\n");

    /* input user choice */
    int choice = validate_int(0, LFR_NEFF(boilable), char_to_string("Enter Command: "));
    while (choice != 0) {
        int result_id = FOOD_ID(FR_FOOD(LFR_ELMT(boilable, choice)));
        string name = FOOD_NAME(FR_FOOD(LFR_ELMT(boilable, choice)));
        Tree recipe_tree = lt_search_by_id(&list_tree_recipe, result_id);

        if (can_boil_food(recipe_tree)) {
            boil(recipe_tree);
            print_string(name);
            printf(" selesai dibuat dan sudah masuk ke inventory!\n");
        } else {
            printf("Gagal membuat ");
            print_string(name);
            printf(" karena kamu tidak memiliki bahan berikut:\n");

            int counter = 1;
            for (int i = 0; i < recipe_tree->children_count; i++) {
                food_t raw = T_FOOD(T_CHILDREN(recipe_tree, i));
                if (food_count(inventory(simulator), FOOD_ID(raw)) <= 0) {
                    printf("   %d. ", counter);
                    print_string(FOOD_NAME(raw));
                    putchar('\n');
                    counter++;
                }
            }
        }

        putchar('\n');
        choice = validate_int(0, LFR_NEFF(boilable), char_to_string("Enter Command: "));
    }
}