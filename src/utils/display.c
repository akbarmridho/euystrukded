#include "display.h"

void clear_display() {
    if (DEBUG) {
        return;
    }
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
}