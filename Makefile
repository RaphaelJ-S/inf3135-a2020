OPT_GCC=gcc -std=c11 -Wall -Werror=vla -pedantic
OPT_CUNIT=-I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu
TCV_H=`test -f ./tcv.h`
TCV_O=`test -f ./tcv.o`

default: tp2 

all: tp2 tp1a test_tp2

tp2: lib tp2.c malib.c malib.h 
	@$(OPT_GCC) -o tp2 tp2.c malib.c tcv.o

test_tp2: test_tp2.c tp2
	@$(OPT_GCC) $(OPT_CUNIT) -o test_tp2 test_tp2.c tcv.o malib.c -lcunit

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
ifneq (($(TCV_H),1) || $(TCV_O),1)
	@rm -rf ./data
	@wget -q https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp1.zip
	@mkdir ./data ; mv ./tp1.zip ./data ; unzip -uq ./data/tp1.zip 
endif

.PHONY: clean lib all default

