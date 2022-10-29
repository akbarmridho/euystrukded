#include <stdio.h>
#include "../../src/adt/point.h"

int main(){
    point_t p1, p2, p3;
    char eq;

    /* create_point */
    create_point(&p1, 1, 1);
    create_point(&p2, 4, 1);
    create_point(&p3, 1, 1);

    /* display point */
    printf("p1 = ");    /* (1,1) */
    write_point(p1);
    putchar('\n');

    printf("p2 = ");    /* (4,1) */
    write_point(p2);
    putchar('\n');

    printf("p3 = ");    /* (1,1) */
    write_point(p3);
    putchar('\n');

    /* is_point_equal */
    printf("True = 1, False = 0\n");
    eq = (is_point_equal(p1, p2))? 'y' : 'n';
    printf("p1==p2? %c\n", eq);     /* expected n */
    eq = (is_point_equal(p1, p3))? 'y' : 'n';
    printf("p1==p3? %c\n", eq);     /* expected y */
    eq = (is_point_equal(p2, p3))? 'y' : 'n';
    printf("p2==p3? %c\n", eq);     /* expected n */

    /* move point */
    point_move(&p1, 10, 15);
    printf("(1, 1) + (10, 15) = ");     /* expected (11, 16)*/
    write_point(p1);
    putchar('\n');

    return 0;
}