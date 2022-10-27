#ifndef ADT_FOOD_h
#define ADT_FOOD_h

#include "wordmachine.h"
#include "time.h"
#include "string.h"

enum food_source
{
    Buy,
    Chop,
    Mix,
    Fry
};

typedef struct
{
    int id;
    string name;
    day_time_t expire_time;
    day_time_t delivery_time;
    enum food_source source;
} food_t;

void create_food(food_t *f, word_t name, day_time_t expire_time, day_time_t delivery_time, enum food_source source);

#endif