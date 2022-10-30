#include "../../src/adt/time.h"
#include <stdio.h>

int main()
{
    day_time_t t1;
    pminute_to_time(1234, &t1);

    write_day(t1);
    printf("\n");
    write_time(t1);
    printf("\n");
    write_fulltime(t1);
    printf("\n");

    day_time_t t2;
    pminute_to_time(12340, &t2);

    write_day(t2);
    printf("\n");
    write_time(t2);
    printf("\n");
    write_fulltime(t2);
    printf("\n");

    printf("DTGT %d\n", DTEQ(t1, t2));

    pnext_n_minute(&t2, 80);
    write_day(t2);
    printf("\n");
    write_time(t2);
    printf("\n");

    printf("diff %ld\n", time_duration(t2, next_n_minute(t2, 60)));
    return 0;
}