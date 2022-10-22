#ifndef __SIMULATOR_H
#define __SIMULATOR_H

#include "string.h"
#include "point.h"
#include "list_food.h"
#include "notification.h"

typedef struct
{
    string name;
    point_t position;
    time_t time;
    ListFood inventory;
    ListNotification notification;
} simulator_t;

/*
fungsi yang diperlukan????
create simumlator, dll
*/

#endif