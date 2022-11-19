#include "refrigerator.h"

Matrix_R refrigerator;
ListFood refrigerator_food;

void initialize_refrigerator() {
    create_refrigerator(&refrigerator, 20, 10);
    day_time_t temp_time;
    create_time(&temp_time, 0, 0, 0);
    food_t dummy = create_empty_slot_elmt();

    for (int i = 0; i < ROWEFF_R(refrigerator); i++) {
        for (int j = 0; j < COLEFF_R(refrigerator); j++) {
            ELMT_R(refrigerator, i, j) = dummy;
        }
    }
    create_list_food(&refrigerator_food, 50);
}