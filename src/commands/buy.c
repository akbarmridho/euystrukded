/**
 * @file buy.c
 * @brief buy command
 * @version 1.0
 * @date 2022-10-30
 */
#include "buy.h"


/* command buy */
void cmd_buy() {
    if (!is_able_to_buy()) {
        printf("Anda tidak berada di area telepon!\nEnter command: ");
        return;
    }

    printf("======================\n=        BUY         =\n======================\n");

    printf("List Bahan Makanan:\n");

    int counter = 0;

    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        food_recipe_t current = LFR_ELMT(food_recipe, i);
        if (FOOD_SOURCE(FR_FOOD(current)) == Buy) {
            counter++;
            printf("  %d. ", counter);
            print_string(FOOD_NAME(FR_FOOD(current)));

            printf(" (");
            write_fulltime(FOOD_DELIVERY_TIME(FR_FOOD(current)));
            printf(")\n");
        }
    }

    if (counter == 0) {
        printf("Tidak ada resep yang tersedia\nEnter command: ");
        return;
    }

    printf("\nKirim 0 untuk exit.\n\n");
    string prompt = char_to_string("Enter command: ");
    int choice = validate_int(0, counter, prompt);

    if (choice != 0) {
        backup_state();
        next_tick();
    }

    while (choice != 0) {
        int lfr_food_index = lfr_search_n_first_by_source(food_recipe, Buy, choice);
        food_t food = FR_FOOD(LFR_ELMT(food_recipe, lfr_food_index));
        int food_id = FOOD_ID(food);
        string name = FOOD_NAME(food);

        add_to_delivery_list(food);

        printf("Berhasil memesan ");
        print_string(name);
        printf(". Pesanan akan diantar dalam ");
        write_fulltime(FOOD_DELIVERY_TIME(food));
        putchar('\n');

        choice = validate_int(0, counter, prompt);
    }

    clear_display();
    display_info();
    printf("\nEnter command: ");
}