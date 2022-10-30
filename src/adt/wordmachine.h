/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef ADT_WORD_MACHINE_H
#define ADT_WORD_MACHINE_H

#include "charmachine.h"

#define NMax 50
#define BLANK ' '

typedef struct {
    char tab_word[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int length;
} word_t;

/* State Mesin Word */
extern boolean end_word;
extern word_t current_word;

/*
Implementasikan ignore blank agar juga bisa menanggap \n sebagai blank
Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK */
void ignore_blank();

/*
source bisa berupa stdin atau file
parameter is_file bisa berupa
I.S. : CC sembarang
F.S. : end_word = true, dan CC = MARK;
          atau end_word = false, CWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata
*/
// void start_word(FILE *source, boolean is_file);
void start_word();

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, end_word = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
void advance_word();

/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void copy_word();

#endif