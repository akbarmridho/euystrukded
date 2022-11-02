#ifndef ADT_PARSERMACHINE_H
#define ADT_PARSERMACHINE_H

#include "boolean.h"
#include "wordmachine.h"
#include <stdio.h>

#define NEWLINE_MARK '\n'
#define FILE_MARK EOF

extern char parser_current_char;
extern boolean parser_EOP;
extern boolean end_line;
extern word_t current_line;

/*
 * Mulai mesin karakter versi file parser
 */
void start_parse(char *path);

/*
 * Maju mesin karakter satu langkah
 */
void advance_parse();

/*
 * Mulai mesin baris versi file parser
 */
void start_line(char *path);

/*
 * Maju mesin kata sebanyak satu baris
 */
void advance_line();

/*
 * Skip newline
 */
void ignore_newline();

/*
 * Pindahkan karakter yang dibaca menjadi baris
 */
void copy_line();

/*
 * Force close file jika belum habis
 */
void force_close();

#endif
