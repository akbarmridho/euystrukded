#include "writer.h"

int native_strlen(char *string) {
    int i = 0;

    while (string[i] != '\0') {
        i++;
    }

    return i;
}

char source_to_char(enum food_source source) {
    if (source == Mix) {
        return 'M';
    } else if (source == Fry) {
        return 'F';
    } else if (source == Chop) {
        return 'C';
    } else if (source == Boil) {
        return 'B';
    } else {
        printf("Source Buy was not allowed here\n");
        return 'T';
    }
}

char *source_to_command(enum food_source source) {
    if (source == Mix) {
        return "MIX";
    } else if (source == Fry) {
        return "FRY";
    } else if (source == Chop) {
        return "CHOP";
    } else if (source == Boil) {
        return "BOIL";
    } else {
        printf("Source Buy was not allowed here\n");
        return "BUY";
    }
}

void setup_writer(char *path) {
    cwriter = fopen(path, "w");
}

void c_write(char *command) {
    fwrite(command, sizeof(char), native_strlen(command), cwriter);
}

void close_writer() {
    fclose(cwriter);
    cwriter = NULL;
}