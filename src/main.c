#include <stdio.h>
#include "commands/boil.h"
#include "commands/buy.h"
#include "commands/catalog.h"
#include "commands/chop.h"
#include "commands/cookbook.h"
#include "commands/delivery.h"
#include "commands/exit.h"
#include "commands/fry.h"
#include "commands/inventory.h"
#include "commands/mix.h"
#include "commands/move.h"
#include "commands/redo.h"
#include "commands/start.h"
#include "commands/undo.h"
#include "commands/wait.h"

/*
Urutan program

CLI:
tampilkan CLI
START
EXIT???

load config data
semua data tersebut disimpan sebagai eksternal variabel pada modul di folder data

services bisa mengakses dan mengubah data
sebisa mungkin, aksi yang mengubah source data dilakukan pada folder services, bukan commands

tampilkan map
waiting for command


*/