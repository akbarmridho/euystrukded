#include <stdio.h>
#include "configdata.h"

ListFoodRecipe food_recipe;
Matrix map;
ListTree list_tree_recipe;

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
                if(temp == ' '){
                    //blablabla
                }else{
                    if (!found_col) {
                        int convertion = (int) temp - 48;
                        // printf("\n%d\n", convertion);
                        size.col = size.col * 10 + convertion;
                        // found_col= true;
                    } else {
                        found_col = true;
                        printf("1\n");
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
    printf("%d %d\n", size.row, size.col);
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
}

void load_food_recipe(char *path_food, char *path_recipe) {
    ListFood food;
    create_list_food(&food, 100);
    FILE *fp_food, *fp_recipe;
    fp_food = fopen(path_food, "r");
    int count = 0;
    int total_food = 0;
    while (!feof(fp_food)) {//cari banyak makanan
        char val = fgetc(fp_food);
        if (count == 0 && val != '\n') {
            int conversion = (int) val - 48;
            total_food = total_food * 10 + conversion;
        } else if (val != '\n') {

        } else {
            count++;
        }
    }
    NEFF(food) = total_food;
    // printf("%d", NEFF(food));
    fclose(fp_food);
    fp_food = fopen(path_food, "r");
    count = 0;
    int counter = 0;
    int index = 0;
    string name, action;
    int id = 0;
    int day = 0;
    int hour = 0;
    int min = 0;
    boolean found_day = false;
    boolean found_hour = false;
    boolean found_minute = false;
    new_string(&name, 100);
    new_string(&action, 100);
    while (!feof(fp_food)) {
        char val = fgetc(fp_food);
        if (count != 0) {
            if (counter == 0) {
                if (val != '\n') {
                    int convertion = (int) val - 48;
                    id = id * 10 + convertion;
                } else {
                    count++;
                    counter++;
                    ELMT(food, index).id = id;
                    id = 0;
                }
            } else if (counter == 1) {
                if (val != '\n') {
                    insert_char_last(val, &name);
                    neff(name)++;
                } else {
                    count++;
                    counter++;
                    ELMT(food, index).name = name;
                    deallocate_string(&name);
                    new_string(&name, 100);
                }
            } else if (counter == 2) {
                if (val != '\n') {
                    if (val != ' ' && !found_day) {
                        int convertion = (int) val - 48;
                        day = day * 10 + convertion;
                    } else {
                        found_day = true;
                    }
                    if (found_day) {
                        if (val != ' ' && !found_hour) {
                            int convertion = (int) val - 48;
                            hour = hour * 10 + convertion;
                        } else {
                            found_hour = true;
                        }
                    }
                    if (found_day && found_hour) {
                        if (val != ' ' && !found_minute) {
                            int convertion = (int) val - 48;
                            min = min * 10 + convertion;
                        } else {
                            found_minute = true;
                        }
                    }
                } else {
                    count++;
                    counter++;
                    ELMT(food, index).expire_time.dd = day;
                    ELMT(food, index).expire_time.hh = hour;
                    ELMT(food, index).expire_time.mm = min;
                    int day = 0;
                    int hour = 0;
                    int min = 0;
                    found_day = false;
                    found_hour = false;
                    found_minute = false;
                }
            } else if (counter == 3) {
                if (val != '\n') {
                    if (val != ' ' && !found_day) {
                        int convertion = (int) val - 48;
                        day = day * 10 + convertion;
                    } else {
                        found_day = true;
                    }
                    if (found_day) {
                        if (val != ' ' && !found_hour) {
                            int convertion = (int) val - 48;
                            hour = hour * 10 + convertion;
                        } else {
                            found_hour = true;
                        }
                    }
                    if (found_day && found_hour) {
                        if (val != ' ' && !found_minute) {
                            int convertion = (int) val - 48;
                            min = min * 10 + convertion;
                        } else {
                            found_minute = true;
                        }
                    }
                } else {
                    count++;
                    counter++;
                    ELMT(food, index).delivery_time.dd = day;
                    ELMT(food, index).delivery_time.hh = hour;
                    ELMT(food, index).delivery_time.mm = min;
                    int day = 0;
                    int hour = 0;
                    int min = 0;
                    found_day = false;
                    found_hour = false;
                    found_minute = false;
                }
            } else if (counter == 4) {
                if (val != '\n') {
                    insert_char_last(val, &action);
                    neff(action)++;
                } else {
                    count++;
                    counter = 0;
                    char buy[] = "Buy";
                    char mix[] = "Mix";
                    char chop[] = "Chop";
                    char fry[] = "Fry";
                    string buy_s;
                    string mix_s;
                    string fry_s;
                    string chop_s;
                    new_string(&buy_s, 100);
                    new_string(&mix_s, 100);
                    new_string(&fry_s, 100);
                    new_string(&chop_s, 100);
                    buy_s = char_to_string(buy);
                    mix_s = char_to_string(mix);
                    fry_s = char_to_string(fry);
                    chop_s = char_to_string(chop);
                    if (comparestr(action, buy_s)) {
                        ELMT(food, index).source = Buy;
                    } else if (comparestr(action, mix_s)) {
                        ELMT(food, index).source = Mix;
                    } else if (comparestr(action, fry_s)) {
                        ELMT(food, index).source = Fry;
                    } else if (comparestr(action, chop_s)) {
                        ELMT(food, index).source = Chop;
                    }
                    index++;
                }
            }
        }
    }
    fclose(fp_food);
    // for(int i= 0; i< index + 1; i++){
    //     food_recipe.contents[i].food = food.buffer[i];
    // }
    fp_recipe = fopen(path_recipe, "r");
    create_lfr(&food_recipe);
    count = 0;
    int id_recipe = 0;
    int total_recipe = 0;
    int id_child = 0;
    int list_ingredient[MAX_RECIPE];
    int index_ing = 0;
    boolean found_id_recipe = false;
    boolean found_total_recipe = false;
    boolean found_id_child = false;
    recipe_t recipe;
    int i = 0;
    while (!feof(fp_recipe)) {
        int val = fgetc(fp_recipe);
        if (count != 0) {
            if (val != '\n') {
                if (val != ' ' && !found_id_recipe) {
                    int convertion = (int) val - 48;
                    id_recipe = id_recipe * 10 + convertion;
                } else {
                    found_id_recipe = true;
                }
                if (found_id_recipe) {
                    if (val != ' ' && !found_total_recipe) {
                        int convertion = (int) val - 48;
                        total_recipe = total_recipe * 10 + convertion;
                    } else {
                        found_total_recipe = true;
                    }
                }
                if (found_id_recipe && found_total_recipe) {
                    if (val != ' ' && !found_id_child) {
                        int convertion = (int) val - 48;
                        id_child = id_child * 10 + convertion;
                    } else {
                        found_id_child = true;
                    }
                }
                if (found_id_child) {
                    list_ingredient[index_ing] = id_child;
                    id_child = 0;
                    index_ing++;
                    found_id_child = false;
                }
            } else {
                create_recipe(&recipe, id_recipe, total_recipe, list_ingredient);
                id_recipe = 0;
                total_recipe = 0;
                index_ing = 0;
                found_id_recipe = false;
                found_id_child = false;
                found_total_recipe = false;
                boolean found = false;
                while (!found) {
                    if (food.buffer[i].id == recipe.food_id) {
                        found = true;
                        food_recipe_t food_recipe_temp;
                        food_recipe_temp.food = food.buffer[i];
                        food_recipe_temp.recipe = recipe;
                        food_recipe.contents[i] = food_recipe_temp;
                        i++;
                    }
                }
            }
        }
    }
    /*Untuk buy*/
    food_recipe_t food_recipe_temp;
    for (int j = 0; j < index + 1; j++) {
        if (food.buffer[j].source == Buy) {
            int temp[] = {0};
            create_recipe(&recipe, food.buffer[j].id, 0, temp);
            food_recipe_temp.food = food.buffer[j];
            food_recipe_temp.recipe = recipe;
            food_recipe.contents[i] = food_recipe_temp;
            i++;
        }
    }
    /*neff lfr*/
    food_recipe.neff = i - 1;
    fclose(fp_recipe);
}

void build_tree_recipe() {
    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        add_from_food_recipe(&list_tree_recipe, food_recipe, LFR_ELMT(food_recipe, i));
    }
}