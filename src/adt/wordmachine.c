#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "charmachine.h"
#include "wordmachine.h"
#include <string.h>


char current_char;
boolean EOP;
boolean end_word;
word_t current_word;

/*
Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang
F.S. : CC ≠ BLANK atau CC = MARK 
*/
void ignore_blank(){
   while (current_char==BLANK && current_char!=CLI_MARK){
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
void start_word(){
   start();
   ignore_blank();
   if(current_char== CLI_MARK){
      end_word= true;
   }else{
      end_word= false;
      copy_word();
   }
}

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, end_word = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
void advance_word(){
   ignore_blank();
   if(current_char == CLI_MARK){
      end_word= true;
   }else{
      copy_word();
      end_word= false;
   }
}

/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void copy_word(){
   int i= 0;
   while((current_char != CLI_MARK) && (current_char != BLANK) && (i<NMax)){
      current_word.tab_word[i]= current_char;
      advance();
      i++;
   }
   current_word.length= i;
}

// int file_row_length(FILE *source){
//    /*Kamus*/
//    int row_length= 1;
//    char temp;

//    /*Algoritma*/
//    do{
//       temp= fgetc(source);
//       if(temp== '\n'){
//          row_length+=1;
//       }
//    } while(temp!=EOF);
//    return row_length;
// }


// int sum_of_file_character(FILE *source){
//    int word_count= 0;
//    while(!feof(source)){
//       char temp;
//       temp= fgetc(source);
//       word_count++;
//    }
//    return word_count;
   
// }

// typedef struct{
//    char *string;
//    // int length;
// }String;

// void make_empty_string(String * s){
//    (*s).length= 0;
// }

// String get_line_string(FILE *source){
//    char cc;
//    int i= 0;
//    String new_cw;
//    make_empty_string(&new_cw);
//    while (!feof(source)){
//       fgets(new_cw.string[i], 2048, source);
//       i++;
//    }
//    return new_cw;
// }

// void get_line_string(FILE * source, char * str, int * length){
//    fgets(str, 2048, source);
//    int i= 0;
//    *length= 0;
//    while(str[i]!='\n' || str[i]!='\0'){
//       *length+=1;
//    }
// }





