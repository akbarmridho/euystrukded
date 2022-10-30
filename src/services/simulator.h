/*
Kurangi waktu kadaluarsa inventory
bila ada yg kadaluarsa, tambahkan ke notification lalu tambahkan ke food history

tambahkan waktu program juga
*/
void simulator_next_tick();

/*
I.S. sembarang
F.S. Info simulator tampil pada layar
*/
void display_info();

/*
    Mengembalikan true jika object disekitar simulator, 
    mengembalikan false jika tidak
*/
boolean is_near(point_t object);

/*
    Mengembalikan true jika terdapat telepon di simulator,
    mengembalikan false jika tidak
*/
boolean is_able_to_buy();

/*
    Mengembalikan true jika terdapat chopper di simulator,
    mengembalikan false jika tidak
*/
boolean is_able_to_chop();

/*
    Mengembalikan true jika terdapat boiler di simulator,
    mengembalikan false jika tidak
*/
boolean is_able_to_boil();

/*
    Mengembalikan true jika terdapat fryer di simulator,
    mengembalikan false jika tidak
*/
boolean is_able_to_fry();

/*
    Mengembalikan true jika terdapat mixer di simulator,
    mengembalikan false jika tidak
*/
boolean is_able_to_mix();

// is able to buy dll