#include <stdio.h>
#include "refrigerator.h"

Matrix refrigerator;

void initialize_refrigerator(){
    create_matrix(20, 10, &refrigerator);
    for(int i= 0; i<20; i++){
        for(int j= 0; j<10; j++){
            MAT_ELMT(refrigerator, i, j)= 0;
        }
    }
}