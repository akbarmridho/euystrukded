#include "parsermachine.h"

static FILE *fp;
static int retval_parse;
char parser_current_char;
boolean parser_EOP;
boolean end_line;
word_t current_line;

void start_parse(char *path) {
    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("FILE LOAD ERROR map.txt. GOT NULL FILE FROM PATH %s\n", path);
    }

    advance_parse();
}

void advance_parse() {
//    retval_parse = fscanf(fp, "%c", &parser_current_char);
    parser_current_char = fgetc(fp);
    parser_EOP = (parser_current_char == FILE_MARK);

    if (parser_EOP) {
        fclose(fp);
        fp = NULL;
    }
}

void start_line(char *path) {
    start_parse(path);
    end_line = false;
    advance_line();
}

void advance_line() {
    if (parser_current_char == FILE_MARK) {
        end_line = true;
    } else {
        ignore_newline();
        copy_line();
        end_line = false;
    }
}

void ignore_newline() {
    while (parser_current_char == NEWLINE_MARK) {
        advance_parse();
    }
}

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

void force_close() {
    if (fp != NULL) {
        fclose(fp);
    }
}