#ifndef ADT_FOOD_H
#define ADT_FOOD_H

#include "time.h"
#include "string.h"
#include "point.h"
// #include "size.h"
#include <stdio.h>

enum food_source {
    Buy,
    Boil,
    Chop,
    Mix,
    Fry
};

/* FOOD SIZE */
typedef point_t food_size;
#define FOOD_SIZE_LENGTH(f_size) (f_size).x
#define FOOD_SIZE_WIDTH(f_size) (f_size).y

void create_size(food_size * f, int length, int width);


/* FOOD */
typedef struct {
    int id;
    string name;
    day_time_t expire_time;
    day_time_t delivery_time;
    enum food_source source;
    food_size size;
} food_t;

/* SELEKTOR */
#define FOOD_ID(f) (f).id
#define FOOD_NAME(f) (f).name
#define FOOD_EXPIRE_TIME(f) (f).expire_time
#define FOOD_DELIVERY_TIME(f) (f).delivery_time
#define FOOD_SOURCE(f) (f).source
#define FOOD_SIZE(f) (f).size

/* KONSTRUKTOR */
// I.S. f sembarang
// F.S  f terdefinisi dengan atribut sesuai argumen
void
create_food(food_t *f, int id, string name, day_time_t expire_time, day_time_t delivery_time, enum food_source source, food_size size);

// I.S. food terdefinisi
// F.S  menampilkan atribut food pada layar
void display_food(food_t food);

/* PEMBANDING */
boolean is_food_equal(food_t food_a, food_t food_b);

#endif