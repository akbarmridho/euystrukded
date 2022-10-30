#include "food.h"

void create_food(food_t *f, int id, string name, day_time_t expire_time, day_time_t delivery_time,enum food_source source){
    FOOD_NAME(*f) = name;
    FOOD_ID(*f) = id;
    FOOD_EXPIRE_TIME(*f) = expire_time;
    FOOD_DELIVERY_TIME(*f) = delivery_time;
    FOOD_SOURCE(*f) = source;
}

void display_food(food_t food){
    printf("%d\n",FOOD_ID(food));

    print_string(FOOD_NAME(food));
    printf("\n");

    printf("%d ",DAY(FOOD_EXPIRE_TIME(food)));
    printf("%d ",HOUR(FOOD_EXPIRE_TIME(food)));
    printf("%d\n",MINUTE(FOOD_EXPIRE_TIME(food)));

    printf("%d ",DAY(FOOD_DELIVERY_TIME(food)));
    printf("%d ",HOUR(FOOD_DELIVERY_TIME(food)));
    printf("%d\n",MINUTE(FOOD_DELIVERY_TIME(food)));
    
    switch (FOOD_SOURCE(food))
    {
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