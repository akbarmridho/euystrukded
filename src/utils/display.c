//
// Created by akbar on 31/10/2022.
//

#include "display.h"

void clear_display() {
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
}