#include "charmachine.h"
#include "wordmachine.h"


char current_char;
boolean EOP;
//boolean end_word;
//word_t current_word;

/*
Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK 
*/
void ignore_blank() {
    while (current_char == BLANK && current_char != CLI_MARK) {
        advance();
    }
}
/*
source bisa berupa stdin atau file
parameter is_file bisa berupa
I.S. : CC sembarang
F.S. : end_word = true, dan CC = MARK;
          atau end_word = false, CWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
*/
// void start_word(FILE *source, boolean is_file);
void start_word() {
    start();
    ignore_blank();
    if (current_char == CLI_MARK) {
        end_word = true;
    } else {
        end_word = false;
        copy_word();
    }
}

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, end_word = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
void advance_word() {
    ignore_blank();
    if (current_char == CLI_MARK) {
        end_word = true;
    } else {
        copy_word();
        end_word = false;
    }
}

/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void copy_word() {
    int i = 0;
    while ((current_char != CLI_MARK) && (current_char != BLANK) && (i < NMax)) {
        current_word.tab_word[i] = current_char;
        advance();
        i++;
    }
    current_word.length = i;
}
