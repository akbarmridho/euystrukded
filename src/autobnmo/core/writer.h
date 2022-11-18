#ifndef AUTOBNMO_CORE_WRITER_H
#define AUTOBNMO_CORE_WRITER_H

#include <stdio.h>
#include "../../adt/food.h"

static FILE *cwriter;

int native_strlen(char *string);

char source_to_char(enum food_source source);

char *source_to_command(enum food_source source);

void setup_writer(char *path);

void c_write(char *command);

void close_writer();

#endif
