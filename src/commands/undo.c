#include "undo.h"

void undo() {
    if (is_able_to_restore()) {
        restore_state();
        clear_display();
        display_info();
        printf("Enter command: ");
    } else {
        printf("Tidak bisa melakukan undo karena riwayat kosong\nEnter command: ");
    }
}
