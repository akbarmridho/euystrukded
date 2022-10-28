#include <stdio.h>
#include "string.h"

/* ------------KONSTRUKTOR------------ */
void new_string (string *str) {
    chars(*str,0) = STRING_MARK;
    
}
/* F.S. string sembarang
   I.S. string terdefinisi*/

/* ------------PRIMITIF LAIN------------ */

/* menghitung panjang string */
int str_len(string s) {
    int counter = 0;
    while (chars(s,counter) != STRING_MARK) {
        counter += 1;
    }

    return counter + 1;
}

/* mengambil suatu huruf dalam string di indeks ke-x */
char letter_at(string s, int x) {
    return chars(s,x);
}

/* mengubah suatu char menjadi string */
string char_to_string(char c[]) {
    string sHasil;
    int i = 0;
    new_string(&sHasil);

    while (c[i] != '\0') {
        chars(sHasil,i) = c[i];
        i += 1;
    }

    return sHasil;
}

/* memotong suatu string mulai dari start indeks sampai ke end indeks */
string cut_str(string s, int idxStart, int idxEnd) {
    string sHasil;
    int i;
    for (i = idxStart; i < idxEnd + 1; i++) {
        chars(sHasil,i) = chars(s,i);
    }
}

/* mengcopy string */
string copy_string(string s) {
    string sCopy;
    int i;

    new_tring(&sCopy);
    for (i = 0; i < str_len(s) + 1; i++) {
        chars(sCopy,i) = chars(s,i);
    }
}


/* membandingkan 2 string */
boolean comparestr(string s1, string s2) {
    int i = 0;
    boolean same = false;

    if (str_len(s1) != str_len(s2)) {
        same = false;
    } else {
        while (i < str_len(s1) && same == true) {
            if (chars(s1,i) == chars(s2,i)) {
                i += 1;
            } else {
                same = false;
            }
        }
    }

    return same;
}


/* menggabungkan 2 string */
string concat(string s1, string s2) {
    int i,j = 0;
    string sHasil;

    newString(&sHasil);
    for (i = 0; i < str_len(s1); i++) {
        chars(sHasil,i) = chars(s1,i);
    }

    i += 1;
    while (chars(s2,j) != STRING_MARK) {
        chars(sHasil,i) = chars(s2,j);
        j++;
        i++;
    }

    return sHasil;
}

/* mengubah word (dari word machine) menjadi string */
string word_to_string(word_t word) {
    string sHasil;
    int i;
    new_string(&sHasil);

    for (i = 0; i < word.length; i++) {
        insert_char_last(word.tab_word[i], &sHasil);
    }

    return sHasil;
}

/* I.S. string terdefinisi dan tidak kosong 
   F.S. mencetak string*/
void print_string(string s) {
    int i = 0;

    for (i = 0; i < str_len(s); i++) {
        printf(chars(s,i));
    }
}

/* I.S. string terdefinisi, string mungkin kosong 
   F.S. memasukkan suatu char dari word ke dalam string di posisi paling belakang */
void insert_char_last(char c, string *s) {
    chars(*s, str_len(*s)) = c;
}