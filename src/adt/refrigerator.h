#ifndef ADT_REFRIGERATOR_H
#define ADT_REFRIGERATOR_H

#include "../adt/food.h"
#include "../adt/matrix.h"


typedef struct{
    food_t mem[ROW_CAP][COL_CAP];
    int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
    int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix_R;

#define ROWEFF_R(f) (f).rowEff
#define COLEFF_R(f) (f).colEff
#define ELMT_R(f, i, j) (f).mem[i][j]

void create_refrigerator(Matrix_R * refrigerator, int x, int y);

boolean is_refrigerator_empty(Matrix_R fridge);

boolean is_refrigerator_full(Matrix_R refrigerator);

boolean is_item_fit(Matrix_R fridge, food_t food, point_t loc);

food_t create_empty_slot_elmt();

void display_refrigerator(Matrix_R fridge);

#endif