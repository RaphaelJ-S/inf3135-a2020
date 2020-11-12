OPT_GCC=gcc -std=c11 -Wall -Werror=vla -pedantic
OPT_CUNIT=-I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu

default: tp2 

all: tp2 tp1a test_tp2

tp2: lib tp2.c malib.c malib.h 
	@$(OPT_GCC) -o tp2 tp2.c malib.c tcv.o

test_tp2: test_tp2.c test_tp2.h test_tp2_main.c tp2
	$(OPT_GCC) $(OPT_CUNIT) -o test_tp2 test_tp2_main.c test_tp2.c tcv.o malib.c -lcunit

test-tp2: tp2
	cat data.txt | ./tp2

tp1a: tp1a.c simple.c simple.h lib
	@$(OPT_GCC) $(OPT_CUNIT) -o tp1a tp1a.c simple.c tcv.o -lcunit

test-tp1a: tp1a
	./tp1a

test-tp1b: liste.sh tp1a
	./tp1a | ./liste.sh

clean: 
	@rm -rf ./data t*[a2] tcv.[oh]

lib: 
ifeq ($(wildcard ./tcv.h),) 
	@wget -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	@mkdir -p ./data ; mv ./tp1.zip ./data ; unzip -uq ./data/tp1.zip 
else ifeq ($(wildcard ./tcv.o),)
	@wget -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	@mkdir -p ./data ; mv ./tp1.zip ./data ; unzip -uq ./data/tp1.zip 
endif
.PHONY:clean lib all default

