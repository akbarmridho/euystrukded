#include "food.h"

void create_food(food_t *f, int id, string name, time_t expire_time, time_t delivery_time,enum food_source source){
    NAME(*f) = name;
    ID(*f) = id;
    EXPIRE_TIME(*f) = expire_time;
    DELIVERY_TIME(*f) = delivery_time;
    SOURCE(*f) = source;
}

void display_food(food_t food){
    printf("%d\n",ID(food));
    // display name
    // display expire time
    // display delivery time
    printf("\n");
}