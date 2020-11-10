CHEMIN=`realpath *inf3135*`

tp1: tp1.c
	gcc -std=c11 -Wall -Werror=vla -pedantic -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o tp1 tp1.c tcv.o -lcunit

test: tp1
	${CHEMIN}/tp1

liste : liste.sh tp1
	${CHEMIN}/tp1 | ${CHEMIN}/liste.sh

lib: 
	wget https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	mkdir ${CHEMIN}/data && mv ${CHEMIN}/tp1.zip ${CHEMIN}/data && unzip ${CHEMIN}/data/tp1.zip 

clean: 
	ls ${CHEMIN}/data ; ls ${CHEMIN}/tp1 ; ls ${CHEMIN}/*.o ; ls ${CHEMIN}/*.h

.PHONY: clean lib
