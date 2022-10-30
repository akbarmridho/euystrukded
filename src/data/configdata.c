#include <stdio.h>
#include "configdata.h"
#include "../adt/matrix.h"
#include "../adt/list_food.h"

Matrix map;
ListFoodRecipe food_recipe;

int convert(char cc){
    return(cc-48);
}

void load_map(char * path){
    FILE *fp;
    fp= fopen(path, "r");//buka file
    if (fp == NULL) {
        printf("Null file\n");
    }

    int count= 0;//menentukan baris berapa yang diproses
    typedef struct{
        int row;
        int col;
    }Matrix_size;

    Matrix_size size;
    size.row= 0;
    size.col= 0;
    boolean found_row= false;
    boolean found_col= false;
    // char temp= fgetc(fp);
    while(!feof(fp)){ // mendapatkan row pertama dari file (row_size, col_size)
        // printf("%c", temp);
        char temp= fgetc(fp);
        if(count == 0  && temp != '\n'){
            if(temp!= ' ' && !found_row){
                int convertion= (int) temp - 48;
                // printf("%d", convertion);
                size.row= size.row* 10 + convertion;
                // found_row= true;
            }else{
                found_row= true;
            }
            if(temp!= ' ' && !found_col){
                int convertion= (int)temp - 48;
                // printf("\n%d\n", convertion);
                size.col= size.col* 10 + convertion;
                // found_col= true;
            }else{
                found_col= true;
            }
        }else if(temp != '\n'){
            //tidak ada apa2, cuman gak tau mau gimana
        }else{
            count++;
        }
        // printf("%c", temp);
    }
    // printf("%d %d\n", size.row, size.col);
    fclose(fp);
    // Matrix map;
    create_matrix(size.row, size.col, &map);
    fp= fopen(path, "r");
    count= 0;
    int i= 0, j=0;
    while(!feof(fp)){
        char mat_val= fgetc(fp);
        if(count != 0){
            if(mat_val != '\n'){
                MAT_ELMT(map, i, j)= mat_val;
                j++;
            }else{
                j=0;
                i++;
            }
        }
        if(mat_val == '\n'){
            count++;
        }
    }
    fclose(fp);
}

void load_food_recipe(char * path_food, char * path_recipe){
    ListFood food;
    create_list_food(&food, 100);
    FILE *fp_food, *fp_recipe;
    fp_food= fopen(path_food, "r");
    int count= 0;
    int total_food= 0;
    while(!feof(fp_food)){
        char val= fgetc(fp_food);
        if(count == 0 && val != '\n'){
            int conversion= (int)val- 48;
            total_food= total_food* 10 + conversion;
        }
    }
    NEFF(food) = total_food;
    // printf("%d", NEFF(food));
    fclose(fp_food);
    fp_recipe= fopen(path_recipe, "r");
    fclose(fp_recipe);
}