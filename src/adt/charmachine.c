#include <stdio.h>
#include "charmachine.h"

static FILE *pita;
static int retval;

void start() {
    pita = stdin;
    advance();
}

/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = current_char, current_char != MARK
   F.S. : current_char adalah karakter berikutnya dari current_char yang lama,
          current_char mungkin = MARK
          Jika  current_char = MARK maka EOP akan menyala (true) */
void advance() {
    retval = fscanf(pita, "%c", &current_char);

    EOP = (current_char == CLI_MARK);
    if (EOP) {
        fclose(pita);
    }
}