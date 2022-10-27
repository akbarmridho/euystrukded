#include <stdio.h>
#include "string.h"

/* ------------KONSTRUKTOR------------ */
void new_string (string *str) {
    kata(*str,0) = STRING_MARK;
    
}
/* F.S. string sembarang
   I.S. string terdefinisi*/

/* ------------PRIMITIF LAIN------------ */
int strlen(string s) {
    int counter = 0;
    while (kata(s,counter) != STRING_MARK) {
        counter += 1;
    }

    return counter + 1;
}
/* menghitung panjang string */

// string charToString(char c) {
//     int i = 0;
//     string str;

//     newString(&str);
//     for (i = 0; i < MAX; i++){
//         kata(str,i) = c[i];
//     }
// }
/* mengubah suatu char menjadi string */

char letter_at(string s, int x) {
    return kata(s,x);
}
/* mengambil suatu huruf dalam string di indeks ke-x */

string cut_str(string s, int idxStart, int idxEnd) {
    string sHasil;
    int i;
    for (i = idxStart; i < idxEnd + 1; i++) {
        kata(sHasil,i) = kata(s,i);
    }
}
/* memotong suatu string mulai dari start indeks sampai ke end indeks */

string copy_string(string s) {
    string sCopy;
    int i;

    new_tring(&sCopy);
    for (i = 0; i < strlen(s) + 1; i++) {
        kata(sCopy,i) = kata(s,i);
    }
}
/* mengcopy string */

boolean comparestr(string s1, string s2) {
    int i = 0;
    boolean same = false;

    if (strlen(s1) != strlen(s2)) {
        same = false;
    } else {
        while (i < strlen(s1) && same == true) {
            if (kata(s1,i) == kata(s2,i)) {
                i += 1;
            } else {
                same = false;
            }
        }
    }

    return same;
}
/* membandingkan 2 string */

string concat(string s1, string s2) {
    int i,j = 0;
    string sHasil;

    newString(&sHasil);
    for (i = 0; i < strlen(s1); i++) {
        kata(sHasil,i) = kata(s1,i);
    }

    i += 1;
    while (kata(s2,j) != STRING_MARK) {
        kata(sHasil,i) = kata(s2,j);
        j++;
        i++;
    }

    return sHasil;
}
/* menggabungkan 2 string */

string word_to_string(word_t word) {
    string sHasil;
    int i;

    for (i = 0; i < word.length; i++) {
        kata(sHasil,i) = word.tab_word[i];
    }

    return sHasil;
}
/* mengubah word (dari word machine) menjadi string */