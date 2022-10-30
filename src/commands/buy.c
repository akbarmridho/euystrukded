/**
 * @file buy.c
 * @brief buy command
 * @version 1.0
 * @date 2022-10-30
 */
#include "buy.h"


/* command buy */
void cmd_buy() {
    ListFoodRecipe purchaseable;
    create_lfr(&purchaseable);

    printf("======================\n");
    printf("=        BUY         =\n");
    printf("======================\n");

    printf("List Bahan Makanan:\n");

    /* display and store buyable recipes in purchasable */
    int counter = 1;
    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        food_recipe_t current = LFR_ELMT(food_recipe, i);
        if (FOOD_SOURCE(FR_FOOD(current)) == Fry) {
            lfr_insert_last(&purchaseable, current);
            printf("   %d. ", counter);
            print_string(FOOD_NAME(FR_FOOD(current)));

            printf(" (");
            write_fulltime(FOOD_DELIVERY_TIME(FR_FOOD(current)));
            printf(")\n");
            counter++;
        }
    }
    printf("\nKirim 0 untuk exit.\n");

    /* input user choice */
    int choice = validate_int(0, LFR_NEFF(purchaseable), char_to_string("Enter Command: "));
    while (choice != 0) {
        food_t purchase = FR_FOOD(LFR_ELMT(purchaseable, choice));
        string name = FOOD_NAME(purchase);

        add_to_delivery_list(purchase);

        printf("Berhasil memesan ");
        print_string(name);
        printf(". ");

        print_string(name);
        printf(" akan diantar dalam ");
        write_fulltime(FOOD_DELIVERY_TIME(purchase));
        printf(".\n");

        putchar('\n');
        choice = validate_int(0, LFR_NEFF(purchaseable), char_to_string("Enter Command: "));
    }
}