#include <stdio.h>
#include "refrigerator.h"

ListFoodRecipe food_recipe;
simulator_t simulator;
Matrix refrigerator;

void store_item_refrigerator(string name){
    if(is_in_inventory(name)){
        if(is_refrigerator_full()){
            printf("Refrigerator has reach its maximum capacity!");
        }else{
            if(is_item_fit(name)){

            }else{
                printf("Your item is bigger than the empty space.");
            }
        }
    }else{
        printf("There is no such item in your inventory.");
    }
}

boolean is_refrigerator_full(){
    int i= 0, j= 0;
    boolean full= true;
    for(int i= 0; i< 20 && full; i++){
        for(int j= 0; j<10 && full; j++){
            if(MAT_ELMT(refrigerator, i, j) == 0){
                full= false;
            }
        }
    }
    return full;
}

void get_item_refrigerator();

void display_refrigerator();

boolean is_item_fit(string name){
    size food_size= get_food_size(inventory(simulator), name);
    boolean is_fit= true;
    int i= 0;
    int j= 0;
    while(is_fit && i<20){
        if(j==9 && WIDTH(food_size) > 1 && MAT_ELMT(refrigerator, i, j) == 0){
            i++;
        }else if(i == 19 && LENGTH(food_size)>1){
            is_fit= false;
        }
    }
}
