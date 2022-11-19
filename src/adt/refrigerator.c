#include <stdio.h>
#include "refrigerator.h"

void create_refrigerator(Matrix_R * refrigerator, int x, int y){
    ROWEFF_R(*refrigerator)= x;
    COLEFF_R(*refrigerator)= y;
}

boolean is_refrigerator_empty(Matrix_R fridge) {
    boolean empty= true;
    for(int i = 0; i < ROWEFF_R(fridge) && empty; i++){
        for(int j = 0; j < COLEFF_R(fridge) && empty; j++){
            if(FOOD_ID(ELMT_R(fridge, i, j)) != 0){
                empty= false;
            }
        }
    }
    return empty;
}

boolean is_refrigerator_full(Matrix_R fridge) {
    boolean full= true;
    for(int i = 0; i < ROWEFF_R(fridge) && full; i++){
        for(int j = 0; j < COLEFF_R(fridge) && full; j++){
            if(FOOD_ID(ELMT_R(fridge, i, j)) == 0){
                full= false;
            }
        }
    }
    return full;
}

boolean is_item_fit(Matrix_R fridge, food_t food, point_t loc) {
    food_size size = FOOD_SIZE(food);
    if (ABSIS(loc) + FOOD_SIZE_LENGTH(size) >= ROWEFF_R(fridge) || ORDINAT(loc) + FOOD_SIZE_WIDTH(size) >= COLEFF_R(fridge)) {
        return false;
    } else {
        boolean fit = true;
        int x = ABSIS(loc);
        int y = ORDINAT(loc);
        for (int k = 0; fit && k < FOOD_SIZE_LENGTH(size); k++) {
            for (int l = 0; fit && l < FOOD_SIZE_WIDTH(size); l++) {
                fit = fit && (FOOD_ID(ELMT_R(fridge, ABSIS(loc) + k, ORDINAT(loc) + l)) == 0);
            }
        }
        return fit;
    }

}

food_t create_empty_slot_elmt() {
    food_t dummy;
    food_size dummy_size;
    day_time_t dummy_time = minute_to_time(0);
    create_size(&dummy_size, 1, 1);
    create_food(&dummy, 0, char_to_string("none"), dummy_time, dummy_time, Buy,  dummy_size);
    return dummy;
}

void display_refrigerator(Matrix_R fridge) {
    for (int i = 0; i < ROWEFF_R(fridge); i++) {
        for (int j = 0; j < COLEFF_R(fridge); j++) {
            printf("%03d ", FOOD_ID(ELMT_R(fridge, i, j)));
        }
        putchar('\n');
    }
}
