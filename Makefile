tp1: tp1.c
	gcc -std=c11 -Wall -Werror=vla -pedantic -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o tp1 tp1.c tcv.o -lcunit

test: tp1
	./tp1

lib: 
	wget https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	mkdir data && mv tp1.zip ./data
clean: 
	rm -rf ./data
	rm -f tp1

.PHONY: clean lib
