#include <stdio.h>
#include "refrigerator.h"

ListFoodRecipe food_recipe;
simulator_t simulator;
Matrix_R refrigerator;

void store_item_refrigerator(string name){
    food_t val;
    if(is_in_inventory(name)){
        if(is_refrigerator_full()){
            printf("Refrigerator has reach its maximum capacity!");
        }else{
            int is_item_fit;
            int x, y;
            is_fit_index_place(name, &x, &y, &is_item_fit);
            size food_size= get_food_size(inventory(simulator), name);
            if(is_item_fit){
                dequeue_food(&inventory(simulator), get_food_id_from_name(name, inventory(simulator)), &val);
                for(int i= x; i< x+ LENGTH(food_size); i++){
                    for(int j= y; j< y+ WIDTH(food_size); j++){
                        ELMT_R(refrigerator, i, j)= val;
                    }
                }
            }else{
                printf("Your item is bigger than the empty space.");
            }
        }
    }else{
        printf("There is no such item in your inventory.");
    }
}

boolean is_refrigerator_full(){
    boolean full= true;
    for(int i= 0; i< 20 && full; i++){
        for(int j= 0; j<10 && full; j++){
            if(FOOD_ID(ELMT_R(refrigerator, i, j)) == 0){
                full= false;
            }
        }
    }
    return full;
}

void get_item_refrigerator(){

}

void display_refrigerator(){
    
}

int count_zero_area(int x, int y, size food_size){
    int count= 0;
    int temp_row= x+ LENGTH(food_size);
    int temp_col= y+ WIDTH(food_size);
    if(temp_row < 20 && temp_col < 10){
        for(int k= x; k< temp_row; k++){
            for(int l= y; l<temp_col; l++){
                if(FOOD_ID(ELMT_R(refrigerator, k, l)) == 0){
                    count++;
                }
            }
        }
    }
    return count;
}

void is_fit_index_place(string name, int * x, int * y, boolean * fit_in_place){
    size food_size= get_food_size(inventory(simulator), name);
    *fit_in_place= 0;
    int area= LENGTH(food_size) * WIDTH(food_size);
    for(int i= 0; i<20 && !(*fit_in_place); i++){
        for(int j= 0; j<10 && !(*fit_in_place); j++){
            if(FOOD_ID(ELMT_R(refrigerator, i, j)) == 0){
                int count= count_zero_area(i, j, food_size);
                if(count == area){
                    *x= i;
                    *y= j;
                    *fit_in_place= 1;
                }
            }
        }
    }
}