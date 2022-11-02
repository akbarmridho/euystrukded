#ifndef SERVICE_NOTIFIER_H
#define SERVICE_NOTIFIER_H

#include "../adt/string.h"
#include "../adt/notification.h"
#include "../data/simulator.h"
#include "../data/history.h"

void notify(string notification);

void notify_redo(string notification);

void notify_undo(string notification);

void clear_notification();

void display_notification();

#endif