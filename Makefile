option=gcc -std=c11 -Wall -Werror=vla -pedantic

default: tp2 


tp2: tp2.c malib.c tcv.o
	$(option) -o tp2 tp2.c malib.c tcv.o

tp1: tp1.c
	gcc -std=c11 -Wall -Werror=vla -pedantic -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o tp1 tp1.c tcv.o -lcunit

test_tp2: test_tp2.c
	$(option) -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o test_tp2 test_tp2.c tcv.o malib.c -lcunit

test-tp1a: tp1
	./tp1

test-tp1b: tp1 liste.sh
	./tp1 | ./liste.sh

test-tp2: tp2
	./tp2

lib: 
	wget https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	mkdir data && mv tp1.zip ./data

clean: 
	rm -rf ./data ; rm "tp1" ; rm *.o

.PHONY: clean lib default
