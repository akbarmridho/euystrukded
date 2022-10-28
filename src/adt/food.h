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

/* SELEKTOR */
#define ID(f) (f).id
#define NAME(f) (f).name
#define EXPIRE_TIME(f) (f).expire_time
#define DELIVERY_TIME(f) (f).delivery_time
#define SOURCE(f) (f).source

/* KONSTRUKTOR */
void create_food(food_t *f,int id, word_t name, day_time_t expire_time, day_time_t delivery_time, enum food_source source);
// I.S. f sembarang
// F.S  f terdefinisi dengan atribut sesuai argumen


void display_food(food_t food);
// I.S. food terdefinisi
// F.S  menampilkan atribut food pada layar


#endif