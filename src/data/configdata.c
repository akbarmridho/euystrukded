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
//    printf("%d %d\n", size.row, size.col);
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
//    display_matrix(map);
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
    int counter_dummy_day = 0;
    int counter_dummy_min = 0;
    new_string(&name, 100);
    new_string(&action, 100);
    while (!feof(fp_food)) {
        char val = fgetc(fp_food);
        // printf("1\n");
        if (count != 0) {
            // printf("1\n");
            if (counter == 0) {
                if (val != '\n') {
                    int convertion = (int) val - 48;
                    id = id * 10 + convertion;
                } else {
                    count++;
                    counter++;
                    ELMT(food, index).id = id;
                    // printf("%d\n", ELMT(food, index).id);
                    id = 0;
                }
            } else if (counter == 1) {
                if (val != '\n') {
                    // printf("%c\n", val);
                    insert_char_last(val, &name);
                    // print_string(name);
                    // printf("\n");
                    // neff(name)++;
                } else {
                    // count++;
                    counter++;
                    ELMT(food, index).name = name;
                    // printf("%s\n", ELMT(food, index).name);
                    // print_string(ELMT(food, index).name);
                    // printf("\n");
                    deallocate_string(&name);
                    new_string(&name, 100);
                }
            } else if (counter == 2) {
                if (val != '\n') {
                    // day= 0;
                    // printf("1\n");
                    // printf("%c",val);
                    // if (val == ' '){
                    //     printf("blank");
                    // }
                    if (val != ' ' && !found_day) {
                        // printf("%c ", val);
                        // printf("1 ");
                        if (val >= '0' && val <= '9') {
                            // day= 0;
                            // printf("%d ", day);
                            int convertion = val - '0';
                            day = day * 10;
                            // printf("%d ", day);
                            day += convertion;
                            // printf("%d ", convertion);
                            // convertion= 0;
                            // printf("%d ", day);

                        }

                        // printf("%d\n", found_day);
                    } else {
                        // int day= 0;
                        // printf("1 ");
                        found_day = true;
                        // break;
                    }
                    // printf("%d ", found_day);
                    if (found_day) {
                        // printf("1 ");
                        if (val == ' ' && counter_dummy_day == 0 && !found_hour) {
                            // printf("1 ");
                            counter_dummy_day++;
                            // counter_dummy_day= 0;
                            // printf("%d ", counter_dummy_day);
                        } else if (!found_hour && val != ' ') {
                            // printf("1 ");
                            if (val >= '0' && val <= '9') {
                                // hour= 0;
                                int convertion = (int) val - 48;
                                hour = hour * 10 + convertion;
                                // printf("%d ", hour);
                                // printf("%d ", counter_dummy_day);
                            }
                        } else {
                            // printf("1 ");
                            found_hour = true;
                            // printf("%d ", counter_dummy_day);
                        }
                    }
                    if (found_day && found_hour) {
                        // printf("1 ");
                        if (val == ' ' && counter_dummy_min == 0 && !found_minute) {
                            counter_dummy_min++;
                            // printf("%d ", counter_dummy_min);
                        } else if (val != ' ' && !found_minute) {
                            // min= 0;
                            if (val >= '0' && val <= '9') {
                                int convertion = (int) val - 48;
                                min = min * 10 + convertion;
                                // printf("%d ", counter_dummy_min);
                                // printf("%d ", min);
                            }
                        } else {
                            found_minute = true;
                        }
                    }
                } else {
                    // count++;
                    counter++;

                    ELMT(food, index).expire_time.dd = day;
                    // printf("%d ", ELMT(food, index).expire_time.dd);
                    ELMT(food, index).expire_time.hh = hour;
                    // printf("%d ", ELMT(food, index).expire_time.hh);
                    ELMT(food, index).expire_time.mm = min;
                    // printf("%d ", ELMT(food, index).expire_time.mm);
                    day = 0;
                    // printf("%d ", day);
                    hour = 0;
                    min = 0;
                    counter_dummy_day = 0;
                    counter_dummy_min = 0;
                    found_day = false;
                    found_hour = false;
                    found_minute = false;
                    // printf("-\n");
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
                        if (val == ' ' && counter_dummy_day == 0 && !found_hour) {
                            counter_dummy_day++;
                        } else if (val != ' ' && !found_hour) {
                            if (val >= '0' && val <= '9') {
                                int convertion = (int) val - 48;
                                hour = hour * 10 + convertion;
                            }
                        } else {
                            found_hour = true;
                        }
                    }
                    if (found_day && found_hour) {
                        if (val == ' ' && counter_dummy_min == 0 && !found_minute) {
                            counter_dummy_min++;
                        } else if (val != ' ' && !found_minute) {
                            if (val >= '0' && val <= '9') {
                                int convertion = (int) val - 48;
                                min = min * 10 + convertion;
                            }
                        } else {
                            found_minute = true;
                        }
                    }
                } else {
                    // count++;
                    counter++;
                    ELMT(food, index).delivery_time.dd = day;
                    // printf("%d ", ELMT(food, index).delivery_time.dd);
                    ELMT(food, index).delivery_time.hh = hour;
                    // printf("%d ", ELMT(food, index).delivery_time.hh);
                    ELMT(food, index).delivery_time.mm = min;
                    // printf("%d ", ELMT(food, index).delivery_time.mm);
                    day = 0;
                    hour = 0;
                    min = 0;
                    counter_dummy_day = 0;
                    counter_dummy_min = 0;
                    found_day = false;
                    found_hour = false;
                    found_minute = false;
                    // printf("-\n");
                }
            } else if (counter == 4) {
                if (val != '\n' && !feof(fp_food)) {
                    insert_char_last(val, &action);
                    // print_string(action);
                    // printf("\n");
                    // neff(action)++;
                } else {
                    // count++;

                    // print_string(action);
                    // printf("\n");
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
                        // print_string(buy_s);
                        // printf("\n");
                    } else if (comparestr(action, mix_s)) {
                        ELMT(food, index).source = Mix;
                        // print_string(mix_s);
                        // printf("\n");
                    } else if (comparestr(action, fry_s)) {
                        ELMT(food, index).source = Fry;
                        // print_string(fry_s);
                        // printf("\n");
                    } else if (comparestr(action, chop_s)) {
                        ELMT(food, index).source = Chop;
                        // print_string(chop_s);
                        // printf("\n");
                    }
                    // printf("\n%d\n ", comparestr(action, fry_s));
                    deallocate_string(&action);
                    new_string(&name, 100);
                    counter = 0;
                    index++;
                }
            }
        }
        if (val == '\n') {
            count++;
        }
    }
    // printf("listfood done");
    fclose(fp_food);
    // printf("%d\n", food.buffer[0].delivery_time.dd);
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
    int counter_dummy_total = 0;
    int counter_dummy_child = 0;
    boolean found_id_recipe = false;
    boolean found_total_recipe = false;
    boolean found_id_child = false;
    recipe_t recipe;
    int i = 0;
    int idx_lfr = 0;
    while (!feof(fp_recipe)) {
        int val = fgetc(fp_recipe);
        if (count != 0) {
            if (val != '\n' && !feof(fp_recipe)) {
                // printf("1 ");
                if (val != ' ' && !found_id_recipe) {
                    // printf("1 ");
                    if (val >= '0' && val <= '9') {
                        int convertion = (int) val - 48;
                        id_recipe = id_recipe * 10 + convertion;
                    }
                } else {
                    found_id_recipe = true;
                }
                if (found_id_recipe) {
                    if (val == ' ' && counter_dummy_total == 0 && !found_total_recipe) {
                        counter_dummy_total++;
                    } else if (val != ' ' && !found_total_recipe) {
                        if (val >= '0' && val <= '9') {
                            int convertion = (int) val - 48;
                            total_recipe = total_recipe * 10 + convertion;
                        }
                    } else {
                        found_total_recipe = true;
                    }
                }
                if (found_id_recipe && found_total_recipe) {
                    if (val == ' ' && counter_dummy_child == 0 && !found_id_child) {
                        counter_dummy_child++;
                    } else if (val != ' ' && !found_id_child) {
                        if (val >= '0' && val <= '9') {
                            int convertion = (int) val - 48;
                            id_child = id_child * 10 + convertion;
                            // printf("%d ", id_child);
                        }
                    } else {
                        found_id_child = true;
                    }
                }
                if (found_id_child) {
                    list_ingredient[index_ing] = id_child;
                    // printf("%d ", id_child);
                    id_child = 0;
                    index_ing++;
                    found_id_child = false;
                    counter_dummy_child = 0;
                }
            } else {
                list_ingredient[index_ing] = id_child;
                create_recipe(&recipe, id_recipe, total_recipe, list_ingredient);
                // printf("%d ", recipe.ingredients_count);
                // for(int i= 0; i<recipe.ingredients_count; i++){
                //     printf("%d ", recipe.ingredients[i]);
                // }
                id_child = 0;
                // printf("-\n");
                id_recipe = 0;
                total_recipe = 0;
                index_ing = 0;
                counter_dummy_total = 0;
                counter_dummy_child = 0;
                found_id_recipe = false;
                found_id_child = false;
                found_total_recipe = false;
                boolean found = false;
                // printf("%d ", food.buffer[1].id == recipe.food_id);
                while (!found) {
                    // printf("1 ");
                    // found= true;
                    if (food.buffer[i].id == recipe.food_id) {
                        // printf("1 ");
                        // printf("%d ", food.buffer[i].id);
                        found = true;
                        food_recipe_t food_recipe_temp;
                        food_recipe_temp.food = food.buffer[i];
                        food_recipe_temp.recipe = recipe;
                        food_recipe.contents[idx_lfr] = food_recipe_temp;
                        idx_lfr++;
                    }
                    i++;
                }
            }
        }
        if (val == '\n') {
            count++;
        }
    }
    // printf("%d ", idx_lfr);
    /*Untuk buy*/
    food_recipe_t food_recipe_temp;
    for (int j = 0; j < index; j++) {
        if (food.buffer[j].source == Buy) {
            int temp[] = {0};
            // printf("%d ", food.buffer[j].id);
            create_recipe(&recipe, food.buffer[j].id, 0, temp);
            food_recipe_temp.food = food.buffer[j];
            food_recipe_temp.recipe = recipe;
            food_recipe.contents[idx_lfr] = food_recipe_temp;
            idx_lfr++;
        }
    }
    /*neff lfr*/
    food_recipe.neff = idx_lfr - 1;
    fclose(fp_recipe);
    // printf("%d ", food_recipe.neff);
    // printf("%d ", food_recipe.contents[3].recipe.ingredients_count);
}

void build_tree_recipe() {
    for (int i = lfr_get_first_idx(food_recipe); i <= lfr_get_last_idx(food_recipe); i++) {
        add_from_food_recipe(&list_tree_recipe, food_recipe, LFR_ELMT(food_recipe, i));
    }
}