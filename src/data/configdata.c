#include <stdio.h>
#include "configdata.h"

ListFoodRecipe food_recipe;
Matrix map;
ListTree list_tree_recipe;

boolean DEBUG = false;
boolean CONFIG_DEBUG = false;
boolean MAP_DEBUG = false;
boolean FOOD_DEBUG = false;
boolean TREE_DEBUG = false;


void load_map(char *path) {
    start_line(path);

    int row, col;
    string cline_str = word_to_string(current_line);
    char *first_line_str = to_native_str(cline_str);
    deallocate_string(&cline_str);

    sscanf(first_line_str, "%d %d", &row, &col);
    free(first_line_str);

    create_matrix(row, col, &map);

    int i = 0;

    while (i < row) {
        advance_line();
        for (int j = 0; j < col; j++) {
            MAT_ELMT(map, i, j) = current_line.tab_word[j];
        }
        i++;
    }

    if (CONFIG_DEBUG && MAP_DEBUG) {
        printf("MAPDEBUG: MAP CONFIG\n");
        printf("Mapsize %d row %d col\n", row, col);
        display_matrix(map);
        printf("ENDMAPDEBUG: ENDMAP\n");
    }
}

void load_temp_list_food(ListFood *lf, char *path) {
    string BUY = char_to_string("Buy");
    string CHOP = char_to_string("Chop");
    string BOIL = char_to_string("Boil");
    string MIX = char_to_string("Mix");
    string FRY = char_to_string("Fry");

    start_line(path);
    string current_line_str = word_to_string(current_line);
    char *food_line_str = to_native_str(current_line_str);
    deallocate_string(&current_line_str);

    int food_count;
    sscanf(food_line_str, "%d", &food_count);
    free(food_line_str);

    if (CONFIG_DEBUG && FOOD_DEBUG) {
        printf("DEBUG: FOOD RECIPE\n");
        printf("from food.txt, count: %d\n", food_count);
    }

    create_list_food(lf, food_count);

    for (int i = 0; i < food_count; i++) {
        advance_line();

        string cline_str = word_to_string(current_line);
        char *fc_line_str = to_native_str(cline_str);
        deallocate_string(&cline_str);

        int food_id;
        sscanf(fc_line_str, "%d", &food_id);
        free(fc_line_str);

        int day, hour, minute;
        day_time_t expire_time, delivery_time;

        advance_line();
        string name = word_to_string(current_line);

        advance_line();
        string expire_string = word_to_string(current_line);
        char *expire_time_native_str = to_native_str(expire_string);
        deallocate_string(&expire_string);
        sscanf(expire_time_native_str, "%d %d %d", &day, &hour, &minute); //NOLINT
        free(expire_time_native_str);
        create_time(&expire_time, day, hour, minute);

        advance_line();
        string delivery_time_str = word_to_string(current_line);
        char *delivery_time_native_str = to_native_str(delivery_time_str);
        sscanf(delivery_time_native_str, "%d %d %d", &day, &hour, &minute); //NOLINT
        deallocate_string(&delivery_time_str);
        free(delivery_time_native_str);

        create_time(&delivery_time, day, hour, minute);

        enum food_source source;
        advance_line();
        string method = word_to_string(current_line);

        if (comparestr(method, MIX)) {
            source = Mix;
        } else if (comparestr(method, CHOP)) {
            source = Chop;
        } else if (comparestr(method, FRY)) {
            source = Fry;
        } else if (comparestr(method, BUY)) {
            source = Buy;
        } else if (comparestr(method, BOIL)) {
            source = Boil;
        } else {
            printf("READ food.txt. INVLAID METHOD. Found ");
            print_string(method);
            return;
        }
        deallocate_string(&method);

        food_t food;
        string namecpy;
        copy_string(name, &namecpy);
        create_food(&food, food_id, namecpy, expire_time, delivery_time, source);

        if (CONFIG_DEBUG && FOOD_DEBUG) {
            printf("Read Food No %d from food.txt\n", i + 1);
            display_food(food);
            putchar('\n');
        }

        ELMT(*lf, i) = food;
        NEFF(*lf)++;
    }

    force_close();
}

void load_recipe(char *path, ListFood *lf) {
    start_line(path);
    string recipe_count_str = word_to_string(current_line);
    char *recipe_line = to_native_str(recipe_count_str);
    deallocate_string(&recipe_count_str);

    int count;

    sscanf(recipe_line, "%d", &count);
    free(recipe_line);

    if (DEBUG && FOOD_DEBUG) {
        printf("DEBUG: RECIPE DEBUG\n");
        printf("Found %d recipe\n", count);
    }

    for (int i = 0; i < list_food_length(*lf); i++) {
        food_t food = ELMT(*lf, i);

        if (FOOD_SOURCE(food) == Buy) {
            recipe_t recipe;
            create_recipe(&recipe, FOOD_ID(food), 0, NULL);
            food_recipe_t fr;
            create_food_recipe(&fr, food, recipe);
            lfr_insert_last(&food_recipe, fr);
        }
    }

    for (int i = 0; i < count; i++) {
        int food_id;
        int ingredient_count;

        advance_line();
        string each_recipe_line = word_to_string(current_line);
        char *current_line_str = to_native_str(each_recipe_line);
        deallocate_string(&each_recipe_line);
        int endidx;

        sscanf(current_line_str, "%d %d%n", &food_id, &ingredient_count, &endidx);

        if (DEBUG && FOOD_DEBUG) {
            printf("Readingf recipe with id %d and ingredient %d\n", food_id, ingredient_count);
        }

        recipe_t recipe;

        if (ingredient_count == 0) {
            create_recipe(&recipe, food_id, ingredient_count, NULL);
            printf("Found recipe with 0 ingredient with id %d. Did you add food with source Buy to recipe?\n", food_id);
        } else {
            int children[ingredient_count];

            int val;
            int offset;

            for (int k = 0; k < ingredient_count; k++) {
                sscanf(&current_line_str[endidx], "%d%n", &val, &offset);
                children[k] = val;
            }

            create_recipe(&recipe, food_id, ingredient_count, children);
        }

        boolean found = false;
        int j = 0;

        while (!found && j < list_food_length(*lf)) {
            if (FOOD_ID(ELMT(*lf, j)) == food_id) {
                found = true;
            } else {
                j++;
            }
        }

        if (!found) {
            printf("Recipe cannot find food from list food with id %d\n", food_id);
            return;
        }

        food_t food = ELMT(*lf, j);
        food_recipe_t fr;
        create_food_recipe(&fr, food, recipe);
        lfr_insert_last(&food_recipe, fr);
    }

    force_close();
}

void load_food_recipe(char *path_food, char *path_recipe) {
    // LOAD FOOD
    ListFood food;
    create_lfr(&food_recipe);
    load_temp_list_food(&food, path_food);
    load_recipe(path_recipe, &food);
}

void build_tree_recipe() {

    for (int i = 0; i < lfr_length(food_recipe); i++) {
        food_recipe_t fr = LFR_ELMT(food_recipe, i);
        recipe_t recipe = fr.recipe;
        Tree new;

        if (recipe.ingredients_count != 0) {
            Address children[recipe.ingredients_count];

            for (int j = 0; j < recipe.ingredients_count; j++) {
                Tree child = lt_search_by_id(&list_tree_recipe, recipe.ingredients[j]);

                if (child == NULL) {
                    printf("No child found!\n");
                } else {
                    children[j] = child;
                }
            }

            new_tree(fr.food, recipe.ingredients_count, children, &new);
        } else {
            new_tree(fr.food, recipe.ingredients_count, NULL, &new);
        }

        lt_insert_last(&list_tree_recipe, new);
    }

    if (CONFIG_DEBUG && TREE_DEBUG) {
        printf("DEBUG: TREE DEBUG START\n\n");
        for (int i = 0; i < list_tree_recipe.length; i++) {
            display_tree(list_tree_recipe.content[i]);
            putchar('\n');
        }
        printf("DEBUG: TREE DEBUG END\n\n");
    }


}