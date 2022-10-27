#ifndef __STRING_H
#define __STRING_H

#include "wordmachine.h"

#define MAX 1000
#define UNDEF -1

typedef char *String;

typedef struct 
{
    char kata[MAX];
} string ;

#define STRING_MARK '\0'
#define kata(s,i) (s).kata[i]

/* ------------KONSTRUKTOR------------ */
void new_string (string *str);
/* F.S. string sembarang
   I.S. string terdefinisi*/

/* ------------PRIMITIF LAIN------------ */
int strlen(string s);
/* menghitung panjang string */

char letter_at(string s, int x);
/* mengambil suatu huruf dalam string di indeks ke-x */

string char_to_string(char c);
/* mengubah suatu char menjadi string */

string cut_str(string s, int idxStart, int idxEnd);
/* memotong suatu string mulai dari start indeks sampai ke end indeks */

string copy_string(string s);
/* mengcopy string */

string comparestr(string s1, string s2);
/* membandingkan 2 string */

string concat(string s1, string s2);
/* menggabungkan 2 string */

string word_to_string(word_t kata);
/* mengubah word (dari word machine) menjadi string */

#endif