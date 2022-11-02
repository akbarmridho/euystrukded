#ifndef SERVICE_NOTIFIER_H
#define SERVICE_NOTIFIER_H

#include "../adt/string.h"
#include "../adt/notification.h"
#include "../data/simulator.h"
#include "../data/history.h"

/*
 * Mengirim notifikasi
 */
void notify(string notification);

/**
 * Mengirim motifikasi ke state undo
 * @param notification
 */
void notify_undo(string notification);

/*
 * Menghapus isi notifikasi
 */
void clear_notification();

/*
 * Menampilkan notifikasi
 */
void display_notification();

#endif