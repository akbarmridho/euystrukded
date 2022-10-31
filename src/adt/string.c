#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/* ------------KONSTRUKTOR------------ */
void new_string(string *str, int cap) {
    chars(*str) = (char *) malloc(cap * sizeof(char));
    neff(*str) = 0;
    capacity(*str) = cap;
}
/* F.S. string sembarang
   I.S. string terdefinisi*/

/* ------------PRIMITIF LAIN------------ */

/* menghitung panjang string */
int str_len(string s) {
    return (neff(s));
}

/* mengambil suatu huruf dalam string di indeks ke-x */
char letter_at(string s, int x) {
    return char(s, x);
}

void deallocate_string(string *str) {
    capacity(*str) = 0;
    neff(*str) = 0;
    free(chars(*str));
}

/* mengubah suatu char menjadi string */
string char_to_string(char c[]) {
    string sHasil;
    int i = 0;

    while (c[i] != '\0') {
        i++;
    }

    new_string(&sHasil, i);

    for (int j = 0; j < i; j++) {
        insert_char_last(c[j], &sHasil);
    }
    // while (c[i] != '\0') {
    //     insert_char_last(c[i], &sHasil);
    //     i += 1;
    // }

    return sHasil;
}

/* memotong suatu string mulai dari start indeks sampai ke end indeks */
string cut_str(string s, int idxStart, int idxEnd) {
    string sHasil;
    int i;

    new_string(&sHasil, idxEnd - idxStart + 1);
    for (i = 0; i < idxEnd - idxStart + 1; i++) {
        char(sHasil, i) = char(s, i + idxStart);
        neff(sHasil)++;
    }

    return sHasil;
}

/* mengcopy string */
void copy_string(string s, string *sCopy) {
    int i;

    new_string(sCopy, capacity(s));
    for (i = 0; i < str_len(s) + 1; i++) {
        char(*sCopy, i) = char(s, i);
    }

    neff(*sCopy) = neff(s);
}


/* membandingkan 2 string */
boolean comparestr(string s1, string s2) {
    int i = 0;
    boolean same = true;

    if (str_len(s1) != str_len(s2)) {
        same = false;
    } else {
        while (i < str_len(s1) && same == true) {
            if (char(s1, i) == char(s2, i)) {
                i += 1;
            } else {
                same = false;
            }
        }
    }

    return same;
}

boolean startwith(string full, string start) {
    int i = 0;
    boolean same = true;

    if (str_len(full) < str_len(start)) {

        same = false;
    } else {
        while (i < str_len(start) && same) {
            if (char(full, i) == char(start, i)) {
                i++;
            } else {
                same = false;
            }
        }
    }

    return same;
}

/* menggabungkan 2 string */
string concat(string s1, string s2) {
    string sHasil;

    new_string(&sHasil, capacity(s1) + capacity(s2));

    for (int i = 0; i < str_len(s1); i++) {
        insert_char_last(letter_at(s1, i), &sHasil);
    }

    for (int i = 0; i < str_len(s2); i++) {
        insert_char_last(letter_at(s2, i), &sHasil);
    }

    return sHasil;
}

/* mengubah word (dari word machine) menjadi string */
string word_to_string(word_t word) {
    string sHasil;
    int i;
    new_string(&sHasil, capacity(sHasil));

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
        putchar(char(s, i));
    }
}

/* I.S. string terdefinisi, string mungkin kosong 
   F.S. memasukkan suatu char dari word ke dalam string di posisi paling belakang */
void insert_char_last(char c, string *s) {
    char(*s, str_len(*s)) = c;
    neff(*s) += 1;
}