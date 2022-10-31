#include <stdio.h>
#include "configdata.h"

ListFoodRecipe food_recipe;
Matrix map;
ListTree list_tree_recipe;

boolean DEBUG = true;
boolean MAP_DEBUG = false;
boolean FOOD_DEBUG = false;
boolean TREE_DEBUG = false;

int convert(char cc) {
    return (cc - 48);
}

void load_map(char *path) {
    FILE *fp;
    fp = fopen(path, "r");//buka file

    if (fp == NULL) {
        printf("Null file\n");
    }

    int count = 0;//menentukan baris berapa yang diproses
    typedef struct {
        int row;
        int col;
    } Matrix_size;

    Matrix_size size;
    size.row = 0;
    size.col = 0;
    boolean found_row = false;
    boolean found_col = false;
    // char temp= fgetc(fp);
    while (!feof(fp)) { // mendapatkan row pertama dari file (row_size, col_size)
        // printf("%c", temp);
        char temp = fgetc(fp);
        if (count == 0 && temp != '\n') {
            if (temp != ' ' && !found_row) {
                int convertion = (int) temp - 48;
                // printf("%d\n", convertion);
                size.row = size.row * 10 + convertion;
                // found_row= true;
            } else {
                found_row = true;
            }
            // printf("%d\n", found_row);
            if (found_row) {
                // printf("1\n");
                if (temp == ' ') {
                    //blablabla
                } else {
                    if (!found_col) {
                        if (temp >= '0' && temp <= '9') {
                            int convertion = (int) temp - 48;
                            // printf("\n%d\n", convertion);
                            size.col = size.col * 10 + convertion;
                            // found_col= true;
                        } else {
                            found_col = true;
                            // printf("1\n");
                        }
                    }
                }
            }
        } else if (temp != '\n') {
            //tidak ada apa2, cuman gak tau mau gimana
        } else {
            count++;
        }
        // printf("%c", temp);
    }
    fclose(fp);
    // Matrix map;
    create_matrix(size.row, size.col, &map);
    fp = fopen(path, "r");
    count = 0;
    int i = 0, j = 0;
    while (!feof(fp)) {
        char mat_val = fgetc(fp);
        if (count != 0) {
            if (mat_val != '\n') {
                MAT_ELMT(map, i, j) = mat_val;
                j++;
            } else {
                j = 0;
                i++;
            }
        }
        if (mat_val == '\n') {
            count++;
        }
    }
    fclose(fp);

    if (DEBUG && MAP_DEBUG) {
        printf("MAPDEBUG: MAP CONFIG\n");
        printf("Mapsize %d row %d col\n", size.row, size.col);
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

    FILE *fp;

    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("FILE LOAD ERROR map.txt. GOT NULL FILE FROM PATH %s\n", path);
        return;
    }

    int food_count = read_next_int(fp);

    if (DEBUG && FOOD_DEBUG) {
        printf("DEBUG: FOOD RECIPE\n");
        printf("from food.txt, count: %d\n", food_count);
    }

    create_list_food(lf, food_count);

    for (int i = 0; i < food_count; i++) {
        int food_id = read_next_int(fp);
        int day, hour, minute;
        day_time_t expire_time, delivery_time;
        string name;

        read_next_line(fp, &name);

        string expire_time_str;
        read_next_line(fp, &expire_time_str);
        char *expire_time_native_str = to_native_str(expire_time_str);

        sscanf(expire_time_native_str, "%d %d %d", &day, &hour, &minute); //NOLINT
        deallocate_string(&expire_time_str);
        free(expire_time_native_str);
        create_time(&expire_time, day, hour, minute);

        string delivery_time_str;
        read_next_line(fp, &delivery_time_str);
        char *delivery_time_native_str = to_native_str(delivery_time_str);

        sscanf(delivery_time_native_str, "%d %d %d", &day, &hour, &minute); //NOLINT
        deallocate_string(&delivery_time_str);
        free(delivery_time_native_str);
        create_time(&delivery_time, day, hour, minute);

        string method;
        enum food_source source;
        read_next_line(fp, &method);

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

        if (DEBUG && FOOD_DEBUG) {
            printf("Read Food No %d from food.txt\n", i + 1);
            display_food(food);
            putchar('\n');
        }

        ELMT(*lf, i) = food;
        NEFF(*lf)++;
    }

    fclose(fp);
}

void load_recipe(char *path, ListFood *lf) {
    FILE *fp = fopen(path, "r");

    int count = read_next_int(fp);

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
        int food_id = read_next_int(fp);
        int ingredient_count = read_next_int(fp);

        recipe_t recipe;

        if (ingredient_count == 0) {
            create_recipe(&recipe, food_id, ingredient_count, NULL);
            printf("Found recipe with 0 ingredient with id %d. Did you add food with source Buy to recipe?\n", food_id);
        } else {
            int children[ingredient_count];

            for (int j = 0; j < ingredient_count; j++) {
                children[j] = read_next_int(fp);
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

    fclose(fp);
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

    if (DEBUG && TREE_DEBUG) {
        printf("DEBUG: TREE DEBUG START\n\n");
        for (int i = 0; i < list_tree_recipe.length; i++) {
            display_tree(list_tree_recipe.content[i]);
            putchar('\n');
        }
        printf("DEBUG: TREE DEBUG END\n\n");
    }


}