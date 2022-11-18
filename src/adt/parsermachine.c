#include "parsermachine.h"

static FILE *fp;
char parser_current_char;
boolean parser_EOP;
boolean end_line;
word_t current_line;

/*
 * Mulai mesin karakter versi file parser
 */
int start_parse(char *path) {
    fp = fopen(path, "rt");

    if (fp == NULL) {
        printf("FILE LOAD ERROR. GOT NULL FILE FROM PATH %s\n", path);
        return 1; // retcode file not found
    }

    advance_parse();
    return 0; // retcode success
}

/*
 * Maju mesin karakter satu langkah
 */
void advance_parse() {
    parser_current_char = fgetc(fp);
//    fscanf(fp, "%c", &parser_current_char);
    parser_EOP = (parser_current_char == FILE_MARK);

    if (parser_EOP) {
        fclose(fp);
        fp = NULL;
    }
}

/*
 * Mulai mesin baris versi file parser
 */
int start_line(char *path) {
    int retcode = start_parse(path);

    if (retcode == 0) {
        end_line = false;
        advance_line();
    }
    return retcode;
}

/*
 * Maju mesin kata sebanyak satu baris
 */
void advance_line() {
    if (parser_current_char == FILE_MARK) {
        end_line = true;
    } else {
        ignore_newline();
        copy_line();
        end_line = false;
    }
}

/*
 * Skip newline
 */
void ignore_newline() {
    while (parser_current_char == NEWLINE_MARK) {
        advance_parse();
    }
}

/*
 * Pindahkan karakter yang dibaca menjadi baris
 */
void copy_line() {
    int i = 0;

    while (parser_current_char != NEWLINE_MARK && parser_current_char != FILE_MARK && i < NMax) {
        if (parser_current_char != '\r') {
            current_line.tab_word[i] = parser_current_char;
            i++;
        }
        advance_parse();
    }

    current_line.length = i;
}

/*
 * Force close file jika belum habis
 */
void force_close() {
    if (fp != NULL) {
        fclose(fp);
    }
}