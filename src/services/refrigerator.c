#include "refrigerator.h"

void store_item_refrigerator(food_t item, point_t loc) {
    food_size size = FOOD_SIZE(item);
    for (int i = 0; i < FOOD_SIZE_LENGTH(size); i++) {
        for (int j = 0; j < FOOD_SIZE_WIDTH(size); j++) {
            ELMT_R(refrigerator, ABSIS(loc) + i, ORDINAT(loc) + j) = item;
        }
    }
    enqueue_food(&refrigerator_food, item);
    dequeue_food(&inventory(simulator), FOOD_ID(item), &item);
}

void retract_item_refrigerator(food_t item) {
    boolean foundstart = false;
    point_t startloc;
    for (int k = 0; k < ROWEFF_R(refrigerator) && !foundstart; k++) {
        for (int l = 0; l < COLEFF_R(refrigerator) && !foundstart; l++) {
            if (is_food_equal(item, ELMT_R(refrigerator, k, l))) {
                foundstart = true;
                create_point(&startloc, k, l);
            }
        }
    }

    if (foundstart) {
        food_t val;
        dequeue_food(&refrigerator_food, FOOD_ID(item), &val);
        enqueue_food(&inventory(simulator), val);

        val = create_empty_slot_elmt();
        for (int i = 0; i < FOOD_SIZE_LENGTH(FOOD_SIZE(item)); i++) {
            for (int j = 0; j < FOOD_SIZE_WIDTH(FOOD_SIZE(item)); j++) {
                ELMT_R(refrigerator, i + ABSIS(startloc), j + ORDINAT(startloc)) = val;
            }
        }
    }
}