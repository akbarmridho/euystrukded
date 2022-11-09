#include <stdio.h>
#include "size.h"

void create_size(size * f, int length, int width){
    LENGTH(*f) = length;
    WIDTH(*f) = width;
}

size get_food_size(ListFood f, string name){
    int index= find_food(name, f);
    return(FOOD_SIZE(ELMT(f, index)));
}