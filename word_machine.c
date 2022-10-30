#include <stdio.h>
#include "src/adt/wordmachine.c"
#include "src/adt/charmachine.c"
#include "src/adt/string.h"
#include "src/adt/string.c"
#include "src/adt/matrix.h"
#include "src/adt/matrix.c"
#include "src/data/configdata.h"
#include "src/services/map.h"
#include "src/services/map.c"
#include "src/data/configdata.h"
#include "src/data/configdata.c"
// #include "src/adt/list_food_recipe.c"
// #include "src/adt/list_food_recipe.h"

Matrix map;
ListFoodRecipe list;

int main(){
    // FILE *fp;
    // // fp= fopen("src/config/food.txt", "r");
    // // char *str[file_row_length(fp)];
    // // fclose(fp);
    // int length;
    // char temp_value;
    // // get_line_string(fp, str, &length);
    // // printf("%d\n", length);
    // // char *str1;
    // fp= fopen("src/config/food.txt", "r");
    // int i= 0;
    // string str;
    // new_string(&str);
    // do{
    //     temp_value= fgetc(fp);
    //     // printf("1");
    //     // printf("%c", temp_value);
    //     if (temp_value == '\n'){
    //         print_string(str);
    //         i++;
    //         // printf("-");
    //     }else{
    //         // strncat(str[i], &temp_value, 1);
    //         // printf("%c ", temp_value);
    //         insert_char_last(temp_value, &str);
    //     }
    // }while(!feof(fp));
    // fclose(fp);
    // char str[10]= "Hi, ";
    // char str1[10]= "you";
    // strncat(str, str1, strlen(str1));
    // printf("%s", str);
    // char str[100];
    // str[0]= '\0';
    // char str1= 'a';
    // // new_string(&str);
    // strcat(str, &str1);
    // printf("%s", str);
    // print_string(str);
    // Matrix m;
    // create_matrix(10, 10, &m);
    // for(int i= 0; i< 10; i++){
    //     for(int j= 0; j< 10; j++){
            
    //     }
    // }
    // Matrix map;
    load_map("src/config/map.txt");
    // printf("%c", MAT_ELMT(map, 0, 1));

    // for(int i= 0; i< MAT_ROW_EFF(map); i++){
    //     for(int j= 0; j<MAT_COL_EFF(map); j++){
    //         printf("%c", MAT_ELMT(map, i, j));
    //     }
    //     printf("\n");
    // }
    // load_food_recipe("src/config/food.txt", "src/config/recipe.txt");
    display_map();
    // printf("%c", MAT_ELMT(map, 1, 1));
    // FILE *fp;
    // fp= fopen("src/config/map.txt", "r");
    // if(fp==NULL){
    //     printf("NULL");
    // }
    // fclose(fp);
}