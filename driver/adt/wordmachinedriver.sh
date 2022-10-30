gcc -o wordmachinedriver wordmachinedriver.c ../../src/adt/charmachine.c ../../src/adt/wordmachine.c ../../src/adt/string.c
echo "halo satu dua tiga\ntiga dua satu\n." > /tmp/wmach
./wordmachinedriver < /tmp/wmach
rm wordmachinedriver