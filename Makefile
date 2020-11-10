
tp1a: tp1a.c simple.c simple.h tcv.h tcv.o
	gcc -std=c11 -Wall -Werror=vla -pedantic -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o tp1a tp1a.c simple.c tcv.o -lcunit

test: tp1a tcv.h tcv.o simple.c simple.h
	./tp1a

liste : liste.sh tp1a
	./tp1 | ./liste.sh

lib: 
	wget https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	mkdir ./data ; mv ./tp1.zip ./data ; unzip -uq ./data/tp1.zip 

clean: 
	rm -rf ./data ./tp1 ./tcv.[oh]

.PHONY: clean lib
