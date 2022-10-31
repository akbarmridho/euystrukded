#include "processor.h"

void process_request(enum food_source source) {
    switch (source) {
        case Buy:
            if (!is_able_to_buy()) {
                printf("Anda tidak berada di area telepon!\nEnter command: ");
                return;
            }
            break;
        case Boil:
            if (!is_able_to_boil()) {
                printf("Anda tidak berada di area ketel uap!\nEnter command: ");
                return;
            }
            break;
        case Fry:
            if (!is_able_to_fry()) {
                printf("Anda tidak berada di area penggorengan!\nEnter command: ");
                return;
            }
            break;
        case Mix:
            if (!is_able_to_mix()) {
                printf("Anda tidak berada di area pengaduk!\nEnter command: ");
                return;
            }
            break;
        case Chop:
            if (!is_able_to_chop()) {
                printf("Anda tidak berada di area pemotongan!\nEnter command: ");
                return;
            }
            break;
        default:
            display_info();
            printf("INVALID SOURCE\n");
            return;
    }

    printf("======================\n");
    switch (source) {
        case Buy:
            printf("=        BUY         =\n");
            break;
        case Boil:
            printf("=        BOIL        =\n");
            break;
        case Fry:
            printf("=        FRY         =\n");
            break;
        case Mix:
            printf("=        MIX         =\n");
            break;
        case Chop:
            printf("=        CHOP        =\n");
            break;
        default:
            printf("INVALID SOURCE\n");
    }
    printf("======================\n");

    printf("List Bahan Makanan:\n");

    int counter = 0;

    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        food_recipe_t current = LFR_ELMT(food_recipe, i);

        if (FOOD_SOURCE(FR_FOOD(current)) == source) {
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

    string prompt = char_to_string("Masukkan pilihan: (ketik 0 untuk membatalkan)");
    int choice = validate_int(0, counter, prompt);

    if (choice == 0) {
        clear_display();
        display_info();
        return;
    }

    int lfr_food_index = lfr_search_n_first_by_source(food_recipe, source, choice);
    food_t food = FR_FOOD(LFR_ELMT(food_recipe, lfr_food_index));
    int food_id = FOOD_ID(food);
    string name = FOOD_NAME(food);
    Tree recipe_tree = lt_search_by_id(&list_tree_recipe, food_id);

    boolean lack_ingredient = false;

    switch (source) {
        case Boil:
            if (can_boil_food(recipe_tree)) {
                backup_state();
                boil(recipe_tree);
            } else {
                lack_ingredient = true;
            }
            break;
        case Buy:
            add_to_delivery_list(food);
            break;
        case Fry:
            if (can_fry_food(recipe_tree)) {
                backup_state();
                fry(recipe_tree);
            } else {
                lack_ingredient = true;
            }
            break;
        case Mix:
            if (can_mix_food(recipe_tree)) {
                backup_state();
                mix(recipe_tree);
            } else {
                lack_ingredient = true;
            }
            break;
        case Chop:
            if (can_chop_food(recipe_tree)) {
                backup_state();
                chop(recipe_tree);
            } else {
                lack_ingredient = true;
            }
            break;
        default:
            printf("Unreachable code in processor.c\n");
    }

    if (source == Buy) {
        printf("Berhasil memesan ");
        print_string(name);
        printf(". Pesanan akan diantar dalam ");
        write_fulltime(FOOD_DELIVERY_TIME(food));
        printf("\nEnter command: ");
    } else {
        if (lack_ingredient) {
            printf("Gagal membuat ");
            print_string(name);
            printf(" karena anda tidak memiliki bahan berikut:\n");

            for (int i = 0; i < recipe_tree->children_count; i++) {
                food_t food_ingredient = T_FOOD(T_CHILDREN(recipe_tree, i));

                if (food_count(inventory(simulator), FOOD_ID(food_ingredient)) <= 0) {
                    printf("  %d. ", i + 1);
                    print_string(FOOD_NAME(food_ingredient));
                    putchar('\n');
                }
            }
        } else {
            clear_display();
            display_info();
            print_string(name);
            printf(" selesai dibuat dan sudah masuk ke inventory!\nEnter command: ");
        }
    }

}
