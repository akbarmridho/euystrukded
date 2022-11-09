#include <stdio.h>
#include "refrigerator.h"

Matrix_R refrigerator;

void initialize_refrigerator(){
    create_refrigerator(&refrigerator, 20, 10);
    day_time_t temp_time;
    create_time(&temp_time, 0, 0, 0);
    food_t dummy;
    size food_size;
    create_size(&food_size, 1, 1);
    create_food(&dummy, 0, char_to_string("none"), temp_time, temp_time, Buy,  food_size);
    for(int i= 0; i<20; i++){
        for(int j= 0; j<10; j++){
            ELMT_R(refrigerator, i, j)= dummy;
        }
    }
}