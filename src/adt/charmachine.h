/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef ADT_CHAR_MACHINE_H
#define ADT_CHAR_MACHINE_H

#include "boolean.h"
#include "stdio.h"

#define FILE_MARK EOF
//#define CLI_MARK '.'
#define CLI_MARK '.'
/* State Mesin */
extern char current_char;
extern boolean EOP;

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   source bisa berupa stdin atau file
   parameter is_file bisa berupa
   I.S. : sembarang
   F.S. : current_char adalah karakter pertama pada pita
          Jika current_char != MARK maka EOP akan padam (false)
          Jika current_char = MARK maka EOP akan menyala (true) */
// void start(FILE *source, boolean is_file);

void start();

/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = current_char, current_char != MARK
   F.S. : current_char adalah karakter berikutnya dari current_char yang lama,
          current_char mungkin = MARK
          Jika  current_char = MARK maka EOP akan menyala (true) */
void advance();

#endif