#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "charmachine.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void start(){
    pita= stdin;
    advance();
}

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.

   source bisa berupa stdin atau file
   parameter is_file bisa berupa

   I.S. : sembarang
   F.S. : current_char adalah karakter pertama pada pita
          Jika current_char != MARK maka EOP akan padam (false)
          Jika current_char = MARK maka EOP akan menyala (true) */
// void start_main(FILE *source, boolean is_file){
//     if(is_file){
//         source = fopen("config/map.txt", "r");
//         if(source == NULL){
//             printf("Error\n");
//         }else{

//         }
//     }
// }

/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = current_char, current_char != MARK
   F.S. : current_char adalah karakter berikutnya dari current_char yang lama,
          current_char mungkin = MARK
          Jika  current_char = MARK maka EOP akan menyala (true) */
void advance(){
    retval= fscanf(pita, "%c", &current_char);
    EOP= (current_char==CLI_MARK);
    if(EOP){
        fclose(pita);
    }
}
