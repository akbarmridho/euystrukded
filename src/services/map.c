#include "map.h"
#include <stdio.h>
#include "../data/configdata.h"

Matrix map;

void display_map(){
    for(int i= 0; i< MAT_ROW_EFF(map)+2; i++){
        for(int j= 0; j< MAT_COL_EFF(map)+2; j++){
            if(j==0 || j == MAT_COL_EFF(map)+1 || i == 0 || i == MAT_ROW_EFF(map)+1){
                printf("* ");
            }else{
                if(MAT_ELMT(map, i, j) == '#'){
                    printf("  ");
                }else{
                    printf("%c ", MAT_ELMT(map, i, j));
                }
            }
        }
        printf("\n");
    }
}

boolean is_able_move_to(point_t destination){
    return (MAT_ELMT(map, ABSIS(destination), ORDINAT(destination))=='#');
}

point_t get_boiler_position(){
    // boolean found = false;
    point_t destination;
    for(int i= 0; i< MAT_ROW_EFF(map); i++){
        for(int j= 0; j< MAT_COL_EFF(map); j++){
            if(MAT_ELMT(map, i, j) == 'B'){
                ABSIS(destination) = i;
                ORDINAT(destination)= j;
                break;
            }
        }
    }
    return destination;
}

point_t get_fryer_position(){
    point_t destination;
    for(int i= 0; i< MAT_ROW_EFF(map); i++){
        for(int j= 0; j< MAT_COL_EFF(map); j++){
            if(MAT_ELMT(map, i, j) == 'F'){
                ABSIS(destination) = i;
                ORDINAT(destination)= j;
                break;
            }
        }
    }
    return destination;
}

point_t get_mixer_position(){
    point_t destination;
    for(int i= 0; i< MAT_ROW_EFF(map); i++){
        for(int j= 0; j< MAT_COL_EFF(map); j++){
            if(MAT_ELMT(map, i, j) == 'M'){
                ABSIS(destination) = i;
                ORDINAT(destination)= j;
                break;
            }
        }
    }
    return destination;
}

point_t get_delivery_position(){
    point_t destination;
    for(int i= 0; i< MAT_ROW_EFF(map); i++){
        for(int j= 0; j< MAT_COL_EFF(map); j++){
            if(MAT_ELMT(map, i, j) == 'T'){
                ABSIS(destination) = i;
                ORDINAT(destination)= j;
                break;
            }
        }
    }
    return destination;
}

point_t get_chopper_position(){
    point_t destination;
    for(int i= 0; i< MAT_ROW_EFF(map); i++){
        for(int j= 0; j< MAT_COL_EFF(map); j++){
            if(MAT_ELMT(map, i, j) == 'C'){
                ABSIS(destination) = i;
                ORDINAT(destination)= j;
                break;
            }
        }
    }
    return destination;
}