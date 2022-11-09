#include <stdio.h>
#include "refrigerator.h"

void create_refrigerator(Matrix_R * refrigerator, int x, int y){
    ROWEFF_R(*refrigerator)= x;
    COLEFF_R(*refrigerator)= y;
}