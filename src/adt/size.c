#include <stdio.h>
#include "size.h"

void create_size(size * f, int length, int width){
    LENGTH(*f) = length;
    WIDTH(*f) = width;
}