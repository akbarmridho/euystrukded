/*
sumber data file history.h pada folder data
terdapat dua:
action stack, restore stack

ketika melakukan command, panggil backup state
backup state akan disimpan ke stack

ketika melakukan command undo, stack sekarang disimpan ke restore stack dan
state sekarang diubah menjadi stack yang dipop dari backup stack

jika undo terus, stack restore bertambah
ketika melakukan aksi setelah command undo tanpa melakukan redo, stack restore akan direset
*/

void backup_state();

void restore_state();