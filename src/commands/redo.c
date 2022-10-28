#include "redo.h"

void redo() {
    if (is_able_to_restore_backup()) {
        restore_backup_state();
        // todo: panggil bagian untuk menampilkan ulang tampilan pengguna
    } else {
        printf("Tidak bisa melakukan redo karena riwayat kosong\n");
    }
}