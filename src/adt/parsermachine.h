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

void start_parse(char *path);

void advance_parse();

void start_line(char *path);

void advance_line();

void ignore_newline();

void copy_line();

void force_close();

#endif
