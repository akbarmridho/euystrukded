#include "food.h"

/*
 * food size
 */
void create_size(food_size * f, int length, int width) {
    FOOD_SIZE_LENGTH(*f) = length;
    FOOD_SIZE_WIDTH(*f) = width;
}
/*
 * Buat makanan dari parameter
 */
void
create_food(food_t *f, int id, string name, day_time_t expire_time, day_time_t delivery_time, enum food_source source, food_size size) {
    FOOD_NAME(*f) = name;
    FOOD_ID(*f) = id;
    FOOD_EXPIRE_TIME(*f) = expire_time;
    FOOD_DELIVERY_TIME(*f) = delivery_time;
    FOOD_SOURCE(*f) = source;
    FOOD_SIZE(*f) = size;
}

/*
 * Menampilkan makanan ke terminal
 */
void display_food(food_t food) {
    printf("%d\n", FOOD_ID(food));

    print_string(FOOD_NAME(food));
    printf("\n");

    printf("%d ", DAY(FOOD_EXPIRE_TIME(food)));
    printf("%d ", HOUR(FOOD_EXPIRE_TIME(food)));
    printf("%d\n", MINUTE(FOOD_EXPIRE_TIME(food)));

    printf("%d ", DAY(FOOD_DELIVERY_TIME(food)));
    printf("%d ", HOUR(FOOD_DELIVERY_TIME(food)));
    printf("%d\n", MINUTE(FOOD_DELIVERY_TIME(food)));

    switch (FOOD_SOURCE(food)) {
        case (Buy):
            printf("Buy\n");
            break;

        case (Boil):
            printf("Boil\n");
            break;

        case (Chop):
            printf("Chop\n");
            break;

        case (Mix):
            printf("Mix\n");
            break;

        case (Fry):
            printf("Fry\n");
            break;

    }
}

/* PEMBANDING */
boolean is_food_equal(food_t food_a, food_t food_b) {
    boolean equal = (
        comparestr(FOOD_NAME(food_a), FOOD_NAME(food_b))
        && FOOD_ID(food_a) == FOOD_ID(food_b)
        && time_to_minute(FOOD_EXPIRE_TIME(food_a)) == time_to_minute(FOOD_EXPIRE_TIME(food_b))
        && time_to_minute(FOOD_DELIVERY_TIME(food_a)) == time_to_minute(FOOD_DELIVERY_TIME(food_b))
        && FOOD_SOURCE(food_a) == FOOD_SOURCE(food_b)
        && is_point_equal(FOOD_SIZE(food_a), FOOD_SIZE(food_b))
    );
    return equal;
}