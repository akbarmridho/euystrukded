#include "undo.h"

void undo() {
    if (is_able_to_restore()) {
        restore_state();
        // todo: panggil bagian untuk menampilkan ulang tampilan pengguna
    } else {
        printf("Tidak bisa melakukan undo karena riwayat kosong\n");
    }
}
