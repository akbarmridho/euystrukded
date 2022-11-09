#ifndef ADT_SIZE_H
#define ADT_SIZE_H

typedef struct{
    int food_length;
    int food_width;
}size;

#define LENGTH(f) (f).food_length
#define WIDTH(f) (f).food_width

void create_size(size * f, int length, int width);

#endif