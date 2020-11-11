

tp1a: tp1a.c simple.c simple.h lib
	@gcc -std=c11 -Wall -Werror=vla -pedantic -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o tp1a tp1a.c simple.c tcv.o -lcunit

test: tp1a lib simple.c simple.h
	@./tp1a

liste : liste.sh tp1a
	@./tp1a | ./liste.sh

lib: 
ifeq ($(wildcard ./tcv.o),)
	@wget -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	@mkdir ./data ; mv ./tp1.zip ./data ; unzip -uq ./data/tp1.zip 
endif
ifeq (,$(wildcard ./tcv.h),)
	@wget -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	@mkdir ./data ; mv ./tp1.zip ./data ; unzip -uq ./data/tp1.zip 

endif
clean: 
	@rm -rf ./data tp1 tcv.[oh] tp1a tp2

.PHONY: clean lib
