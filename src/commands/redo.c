#include "redo.h"

void redo() {
    if (is_able_to_restore_backup()) {
        restore_backup_state();
        clear_display();
        display_info();
        printf("Enter command: ");
    } else {
        printf("Tidak bisa melakukan redo karena riwayat kosong\nEnter command: ");
    }
}