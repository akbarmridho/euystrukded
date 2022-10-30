#include "undo.h"

void undo() {
    if (is_able_to_restore()) {
        restore_state();
        display_info();
    } else {
        printf("Tidak bisa melakukan undo karena riwayat kosong\n");
    }
}
