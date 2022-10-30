#include "../../src/adt/list_delivery.h"

// gcc list_delivery_driver.c "../../src/adt/list_delivery.c" "../../src/adt/food.c" "../../src/adt/time.c" "../../src/adt/string.c" -o list_delivery
int main() {
    int capacity = 100;
    ListDelivery l;
    create_list_delivery(&l, capacity);
    printf("%c\n", list_delivery_is_empty(l));

    food_t f1, f2, f3, f4, f5;
    create_food(&f1, 12, char_to_string("Sate ayam"), minute_to_time(120), minute_to_time(10), Mix);
    create_food(&f2, 45, char_to_string("Ayam geprek"), minute_to_time(200), minute_to_time(15), Buy);
    create_food(&f3, 26, char_to_string("Nasi goreng"), minute_to_time(150), minute_to_time(9), Fry);
    create_food(&f4, 5, char_to_string("Jus Alpukat"), minute_to_time(100), minute_to_time(11), Mix);
    create_food(&f5, 5, char_to_string("Jus Alpukat siap diantar"), minute_to_time(100), minute_to_time(0), Mix);

    enqueue_delivery(&l, f1);
    enqueue_delivery(&l, f2);
    enqueue_delivery(&l, f3);
    enqueue_delivery(&l, f4);
    enqueue_delivery(&l, f5);
    display_list_delivery(l);
    printf("%d,%d,%d\n", list_delivery_get_idx_head(l), list_delivery_get_idx_tail(l), list_delivery_length(l));

    printf("\n\n\n\n");

    food_t dump;
    dequeue_delivery(&l, &dump);
    display_food(dump);
    printf("\n");
    display_list_delivery(l);
    printf("\n\n\n\n");

    ListDelivery copy_of_l;
    list_delivery_copy(l, &copy_of_l);
    display_list_delivery(copy_of_l);
    printf("\n\n\n\n");

    list_delivery_delete(&copy_of_l, 1);
    display_list_delivery(copy_of_l);
    printf("\n\n\n\n");

    expand_list_delivery(&copy_of_l, 100);
    for (int i = 0; i < 110; i++) {
        ELMT(copy_of_l, i) = f1;
    }
    display_food(ELMT(copy_of_l, 109));
    NEFF(copy_of_l) = 110;

    printf("Capacity after expand: %d\n", CAPACITY(copy_of_l));

    compress_list_delivery(&copy_of_l);

    printf("Capacity after compress: %d\n", CAPACITY(copy_of_l));

    deallocate_list_delivery(&copy_of_l);

    display_list_delivery(copy_of_l);

    return 0;
}