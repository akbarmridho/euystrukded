#ifndef __FOOD_h
#define __FOOD_h

#include "wordmachine.h"
#include "time.h"

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
    word_t name;
    time_t expire_time;
    time_t delivery_time;
    food_source source;
} food_t;

void create_food(food_t *f, word_t name, time_t expire_time, time_t delivery_time, food_source source);

#endif