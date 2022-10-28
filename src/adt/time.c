#include "time.h"
#include <stdio.h>

boolean is_time_valid(int d, int h, int m)
{
    return d >= 0 && h >= 0 && h <= 23 && m >= 0 && m <= 59;
}

void create_time(day_time_t *t, int d, int h, int m)
{
    DAY(*t) = d;
    HOUR(*t) = h;
    MINUTE(*t) = m;
}

void write_time(day_time_t t)
{
    printf("%d:%d", HOUR(t), MINUTE(t));
}

void write_day(day_time_t t)
{
    printf("Day %d", DAY(t));
}

long time_to_minute(day_time_t t)
{
    return 24*60*DAY(t) + 60*HOUR(t) + MINUTE(t);
}

void pminute_to_time(long N, day_time_t* result)
{
    int day = N / (24*60);
    N -= day*24*60;
    int hour = N / 60;
    N -= hour*60;

    create_time(result, day, hour, N);
}

day_time_t minute_to_time(long N)
{
    day_time_t result;
    pminute_to_time(N, &result);

    return result;
}

boolean TEQ(day_time_t t1, day_time_t t2)
{
    return HOUR(t1) == HOUR(t2) && MINUTE(t1) == MINUTE(t2);
}

boolean DTEQ(day_time_t t1, day_time_t t2)
{
    return TEQ(t1, t2) && DAY(t1) == DAY(t2);
}

boolean TLT(day_time_t t1, day_time_t t2)
{
    if (HOUR(t1) < HOUR(t2)) {
        return true;
    } else if (HOUR(t1) == HOUR(t2)) {
        return MINUTE(t1) < MINUTE(t2);
    }

    return false;
}

boolean DTLT(day_time_t t1, day_time_t t2)
{
    if (DAY(t1) < DAY(t2)) {
        return true;
    } else if (DAY(t1) == DAY(t2)) {
        return TLT(t1, t2);
    }

    return false;
}

boolean TGT(day_time_t t1, day_time_t t2)
{
    return !TEQ(t1, t2) && !TLT(t1, t2);
}

boolean DTGT(day_time_t t1, day_time_t t2)
{
    return !DTEQ(t1, t2) && !DTLT(t1, t2);
}

void pnext_n_minute(day_time_t *t, int n)
{
    int minute = time_to_minute(*t) + n;
    pminute_to_time(minute, t);
}

void pprev_n_minute(day_time_t *t, int n)
{
    int minute = time_to_minute(*t) - n;
    pminute_to_time(minute, t);
}

day_time_t next_n_minute(day_time_t t, int n)
{
    int minute = time_to_minute(t) + n;
    return minute_to_time(minute);
}

day_time_t prev_n_minute(day_time_t t, int n)
{
    int minute = time_to_minute(t) - n;
    return minute_to_time(minute);
}

long time_duration(day_time_t t_initial, day_time_t t_final)
{
    return time_to_minute(t_final) - time_to_minute(t_initial);
}