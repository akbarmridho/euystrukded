#include "time.h"
#include <stdio.h>

/*
Konstruktor: Membentuk sebuah TIME dari komponen-komponennya
Membentuk sebuah TIME dari komponen-komponennya yang valid
Prekondisi : d,h,m valid untuk membentuk TIME
*/
void create_time(day_time_t *t, int d, int h, int m) {
    DAY(*t) = d;
    HOUR(*t) = h;
    MINUTE(*t) = m;
}

/*
I.S. : T sembarang
F.S. : Nilai T ditulis dg format HH:MM
Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM
tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
Hanya menampilkan jam dan menit, tidak termasuk hari
*/
void write_time(day_time_t t) {
    printf("%d:%d", HOUR(t), MINUTE(t));
}

/*
 * Menuliskan hari
 */
void write_day(day_time_t t) {
    printf("Day %d", DAY(t));
}

/*
 * Menuliskan hari dan waktu
 */
void write_fulltime(day_time_t t) {
    int total = 0;
    if (DAY(t) != 0) {
        printf("%d hari", DAY(t));
        total++;
    }
    if (HOUR(t) != 0) {
        if (total > 0) {
            putchar(' ');
        }
        printf("%d jam", HOUR(t));
        total++;
    }
    if (MINUTE(t) != 0) {
        if (total > 0) {
            putchar(' ');
        }
        printf("%d menit", MINUTE(t));
    }
}

/*
Diberikan sebuah TIME, mengonversi jumlah menit dari hari ke-nol menuju menit terakhir pada hari tertentu
Rumus : menit = 24*60*day + 60*hour + menit
*/
long time_to_minute(day_time_t t) {
    return 24 * 60 * DAY(t) + 60 * HOUR(t) + MINUTE(t);
}

/*
Mengonversi menit ke waktu, dimulai dari day nol, versi pointer
*/
void pminute_to_time(long N, day_time_t *result) {
    int day = N / (24 * 60);
    N -= day * 24 * 60;
    int hour = N / 60;
    N -= hour * 60;

    create_time(result, day, hour, N);
}

/*
Mengonversi menit ke waktu, dimulai dari day nol
*/
day_time_t minute_to_time(long N) {
    day_time_t result;
    pminute_to_time(N, &result);

    return result;
}

/* Mengirimkan true jika T1=T2 (bagian jam dan menit), false jika tidak */
boolean TEQ(day_time_t t1, day_time_t t2) {
    return HOUR(t1) == HOUR(t2) && MINUTE(t1) == MINUTE(t2);
}

/* Mengirimkan true jika T1=T2, false jika tidak */
boolean DTEQ(day_time_t t1, day_time_t t2) {
    return TEQ(t1, t2) && DAY(t1) == DAY(t2);
}

/* Mengirimkan true jika T1<T2 (bagian jam dan menit), false jika tidak */
boolean TLT(day_time_t t1, day_time_t t2) {
    if (HOUR(t1) < HOUR(t2)) {
        return true;
    } else if (HOUR(t1) == HOUR(t2)) {
        return MINUTE(t1) < MINUTE(t2);
    }

    return false;
}

/* Mengirimkan true jika T1<T2, false jika tidak */
boolean DTLT(day_time_t t1, day_time_t t2) {
    if (DAY(t1) < DAY(t2)) {
        return true;
    } else if (DAY(t1) == DAY(t2)) {
        return TLT(t1, t2);
    }

    return false;
}

/* Mengirimkan true jika T1>T2 (bagian jam dan menit), false jika tidak */
boolean TGT(day_time_t t1, day_time_t t2) {
    return !TEQ(t1, t2) && !TLT(t1, t2);
}

/* Mengirimkan true jika T1>T2, false jika tidak */
boolean DTGT(day_time_t t1, day_time_t t2) {
    return !DTEQ(t1, t2) && !DTLT(t1, t2);
}

/* Menambahkan time t sebanyak n menit*/
void pnext_n_minute(day_time_t *t, int n) {
    int minute = time_to_minute(*t) + n;
    pminute_to_time(minute, t);
}

/* Mengurangi time t sebanyak n menit*/
void pprev_n_minute(day_time_t *t, int n) {
    int minute = time_to_minute(*t) - n;
    pminute_to_time(minute, t);
}

/* Mengirim N menit setelah T dalam bentuk TIME */
day_time_t next_n_minute(day_time_t t, int n) {
    int minute = time_to_minute(t) + n;
    return minute_to_time(minute);
}

/* Mengirim N menit sebelum T dalam bentuk TIME */
day_time_t prev_n_minute(day_time_t t, int n) {
    int minute = time_to_minute(t) - n;
    return minute_to_time(minute);
}

/*
Mengirim t_final-t_initial dlm menit, dengan kalkulasi
asumsikan t_final >= t_initial
*/
long time_duration(day_time_t t_initial, day_time_t t_final) {
    return time_to_minute(t_final) - time_to_minute(t_initial);
}