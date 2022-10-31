#ifndef UTILS_PARSER_H
#define UTILS_PARSER_H

#include "../adt/string.h"

char *to_native_str(string str);

void pto_native_str(char *output, string input);

int read_next_int(FILE *file);

void read_next_line(FILE *file, string *result);

#endif