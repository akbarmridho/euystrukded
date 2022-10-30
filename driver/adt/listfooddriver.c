#include "../../src/adt/list_food.h"

// gcc list_food_driver.c "../../src/adt/list_food.c" "../../src/adt/food.c" "../../src/adt/time.c" "../../src/adt/string.c" -o list_food
int main() {
    int capacity = 100;
    ListFood l;
    create_list_food(&l, capacity);
    printf("%c\n", list_food_is_empty(l));

    food_t f1, f2, f3, f4;
    create_food(&f1, 12, char_to_string("Sate ayam"), minute_to_time(120), minute_to_time(10), Mix);
    create_food(&f2, 45, char_to_string("Ayam geprek"), minute_to_time(200), minute_to_time(15), Buy);
    create_food(&f3, 26, char_to_string("Nasi goreng"), minute_to_time(150), minute_to_time(9), Fry);
    create_food(&f4, 5, char_to_string("Jus Alpukat"), minute_to_time(100), minute_to_time(11), Mix);

    enqueue_food(&l, f1);
    enqueue_food(&l, f2);
    enqueue_food(&l, f3);
    enqueue_food(&l, f4);
    display_list_food(l);
    printf("%d,%d,%d\n", list_food_get_idx_head(l), list_food_get_idx_tail(l), list_food_length(l));

    printf("\n\n\n\n");

    food_t dump;
    dequeue_food(&l, 45, &dump);
    display_food(dump);
    display_list_food(l);
    printf("\n\n\n\n");

    ListFood copy_of_l;
    list_food_copy(l, &copy_of_l);
    display_list_food(copy_of_l);
    printf("\n\n\n\n");

    list_food_delete(&copy_of_l, 1);
    display_list_food(copy_of_l);
    printf("\n\n\n\n");

    printf("%d\n", dequeue_food(&copy_of_l, 5, &dump));
    display_list_food(copy_of_l);
    printf("\n\n\n\n");

    expand_list_food(&copy_of_l, 100);
    for (int i = 0; i < 110; i++) {
        ELMT(copy_of_l, i) = f1;
    }
    display_food(ELMT(copy_of_l, 109));
    NEFF(copy_of_l) = 110;

    printf("Capacity after expand: %d\n", CAPACITY(copy_of_l));

    compress_list_food(&copy_of_l);

    printf("Capacity after compress: %d\n", CAPACITY(copy_of_l));

    deallocate_list_food(&copy_of_l);

    display_list_food(copy_of_l);

    return 0;
}