#include "help.h"

void cmd_main_help() {
    printf(
            "COMMANDs:\n"
            "  EXIT          Keluar dari program.\n"
            "  HELP          Menampilkan daftar perintah (COMMANDs).\n"
            "  CLEAR         Membersihkan tampilan antarmuka.\n"
            "  MOVE {NORTH|SOUTH|EAST|WEST} [n_times]\n"
            "                Menggerakkan posisi pengguna pada peta sebanyak n>0 langkah.\n"
            "                Argumen n_times bersifat opsional.\n"

            "  WAIT [hour] <minute>\n"
            "                Memajukan waktu pada simulasi.\n"
            "                Argumen hour bersifat opsional.\n"

            "  CATALOG       Menampilkan daftar makanan yang dapat dipesan.\n"
            "  COOKBOOK      Menampilkan resep-resep yang tersedia pada buku resep.\n"
            "  DELIVERY      Menampilkan daftar pesanan yang sedang diantar.\n"
            "  INVENTORY     Menampilkan daftar makanan yang dimiliki pengguna.\n"
            "  BUY           Membeli makanan pada lokasi T.\n"
            "  BOIL          Merebus bahan makanan pada lokasi B.\n"
            "  FRY           Menggoreng bahan-bahan makanan pada lokasi F.\n"
            "  MIX           Mencampur bahan-bahan makanan pada lokasi M.\n"
            "  CHOP          Memotong bahan makanan pada lokasi C.\n"
            "  UNDO          Membatalkan perubahan terakhir terhadap data pengguna.\n"
            "  REDO          Membatalkan efek pemanggilan \"UNDO\" terakhir.\n"
            "  AUTOMOVE D    Otomatis pergi ke lokasi D pada map\n"
    );
    printf("\nEnter command: ");
}
