gcc -o parsermachinedriver parsermachinedriver.c ../../src/adt/charmachine.c ../../src/adt/wordmachine.c ../../src/adt/string.c ../../src/adt/parsermachine.c
./parsermachinedriver
rm parsermachinedriver