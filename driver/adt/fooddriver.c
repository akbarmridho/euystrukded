#include "../../src/adt/food.h"


int main() {
    food_t food;
    char food_name[] = "Roti";
    day_time_t del_time;
    create_time(&del_time, 4, 2, 0);
    day_time_t exp_time;
    create_time(&del_time, 4, 2, 0);

    create_food(&food, 1, char_to_string(food_name), exp_time, del_time, Chop);
    display_food(food);
    return 0;
}