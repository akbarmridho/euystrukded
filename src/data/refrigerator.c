#include <stdio.h>
#include "refrigerator.h"

Matrix refrigerator;

void initialize_refrigerator(){
    create_matrix(20, 10, &refrigerator);
}