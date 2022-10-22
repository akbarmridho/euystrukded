# Detail Struktur dan Alur Program

## Folder Structure

- adt
- commands
- config
- data
- services
- utils
- main.c

Folder adt digunakan untuk menyimpan semua header dan implementasi ADT yang digunakan dalam program ini.

Folder commands berisi implementasi setiap perintah pada program. Setiap implementasi command tidak boleh secara langsung memanipulasi source data, tetapi harus melalui modul services. Setiap implementasi command biasanya menggunakan beberapa services sekaligus.

Folder config berisi konfigurasi program, yang meliputi resep, makanan, dan peta.

Folder data berisi modul yang tugasnya menyimpan data secara global. Semua data yang berkaitan dengan runtime program akan disimpan di sini.

Folder services berisi modul layanan yang berhak memanipulasi data. Setiap service memiliki layanan yang berbeda-beda dan bisa berdiri sendiri.

Folder utils berisi modul tambahan untuk mendukung main program atau modul lainnya.

main.c adalah main entry program yang bertugas menghubungkan seluruh modul sehingga menjadi program utuh.

## Alur program

Berikut alur umum program

1. main.c dipanggil, lalu melakukan load data dari config, melakukan scraping data lain-lain, lalu disimpan pada variabel global yang dideklarasikan di modul config.
2. Program menunggu perintah
3. Ada perintah masuk, program melakukan parsing command, lalu memanggil command yang terkait.
4. Fungsi command dipanggil, lalu menjalankan algoritma yang harus dilakukan untuk menjalankan perintah tersebut. Contoh langkahnya adalah dengan memanggil beberapa service sekaligus.
5. Perintah selesai, program kembali ke langkah 2.

## Konsep Ticker

Modul clock adalah modul yang berkaitan dengan waktu. Ini bisa diibaratkan dengan clock cycle processor, refresh rate monitor, atau yang lainnya. Terdapat beberapa fitur yang bergantung pada ticker ini, yaitu delivery, inventory, dan jam.

Bila kita melewati satu siklus tick, maka program akan menjalankan beberapa alur berikut.

1. Menambahkan waktu sekarang sebanyak satu menit.
2. Mengurangi semua waktu kadaluarsa inventori sebanyak satu menit. Bila ada yang kadaluarsa, keluarkan barang dari inventori dan kirim notifikasi.
3. Mengurangi semua waktu delivery pada delivery list sebanyak satu menit. Bila ada yang waktu deliverynya nol, keluarkan makanan tersebut dari delivery list, masukkan makanan ke inventory, dan kirim notifikasi.

Pendekatan ini agak tidak efisien karena banyak melakukan komputasi dan pemanggilan fungsi berulang, tetapi bisa menghasilkan program yang lebih sederhana.

## Undo Redo

Untuk memudahkan implementasi, kami melakukan backup history setelah pemanggilan setiap command yang memiliki side effect pada data utama.

Keunggulan pendekatan ini:

1. Program hanya perlu memanggil backup state program sebelum melakukan command yang memilki side effect.
2. Tidak perlu repot melakukan tracking semua barang yang masuk dan kelaur dari inventori dan delivery.
3. Tidak perlu repot melakukan sinkronisasi waktu yang berlalu dan memastikan waktu kadaluarsa dan delivery setiap makanan tetap sesuai ketika melakukan undo atau redo.
4. Pendekatan ini juga memungkinkan penerapan fitur undo redo pada command bonus terakhir menjadi lebih mudah.

Kekurangan dari pendekatan ini adalah tidak efisien secara memori.