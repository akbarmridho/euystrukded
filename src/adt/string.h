#ifndef ADT__STRING_H
#define ADT__STRING_H

#include "wordmachine.h"

#define MAX 100
#define UNDEF -1

typedef struct 
{
    char *chars;
    int neff;
    int capacity
} string ;

#define STRING_MARK '\0'
#define chars(s) (s).chars
#define char(s,i) (s).chars[i]
#define neff(s) (s).neff
#define capacity(s) (s).capacity

/* ------------KONSTRUKTOR------------ */

/* F.S. string sembarang
   I.S. string terdefinisi*/
void new_string (string *str, int cap);

/* ------------PRIMITIF LAIN------------ */

/* menghitung panjang string */
int str_len(string s);

/* mengambil suatu huruf dalam string di indeks ke-x */
char letter_at(string s, int x);

/* mengubah suatu char menjadi string */
string char_to_string(char c[]);

/* memotong suatu string mulai dari start indeks sampai ke end indeks */
string cut_str(string s, int idxStart, int idxEnd);

/* mengcopy string */
string copy_string(string s, string *sCopy);

/* membandingkan 2 string */
boolean comparestr(string s1, string s2);

/* menggabungkan 2 string */
string concat(string s1, string s2);

/* mengubah word (dari word machine) menjadi string */
string word_to_string(word_t kata);

/* I.S. string terdefinisi dan tidak kosong 
   F.S. mencetak string*/
void print_string(string s);

/* I.S. string terdefinisi, string mungkin kosong 
   F.S. memasukkan suatu char dari word ke dalam string di posisi paling belakang */
void insert_char_last(char c, string *s);

#endif