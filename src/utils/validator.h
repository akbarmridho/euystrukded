#ifndef UTILS_VALIDATOR_h
#define UTILS_VALIDATOR_h

#include "../adt/string.h"

/* inputs an integer x and returns x if min<=x<=max, else input x until x satisfies range */
int validate_int(int min, int max, string prompt);

#endif