OPT_GCC=gcc -std=c11 -Wall -Werror=vla -pedantic
OPT_CUNIT=-I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu
WEB_TCV=https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/

default: tp2 

all: tp2 tp1 

tp2: lib tp2.c malib.c malib.h 
	@$(OPT_GCC) -o tp2 tp2.c malib.c tcv.o -lm

test-tp2: tp2
	@./tp2

tp1: tp1.c simple.c simple.h lib
	@$(OPT_GCC) $(OPT_CUNIT) -o tp1 tp1.c simple.c tcv.o -lcunit

test-tp1a: tp1
	@./tp1

test-tp1b: liste.sh tp1
	@./tp1 | ./liste.sh

clean: 
	@rm -rf ./data/ t*[21] tcv.[oh]

lib: 
ifeq ($(wildcard ./tcv.h),) 
	@wget -q $(WEB_TCV)tp1.zip $(WEB_TCV)tp2.zip $(WEB_TCV)tp3.zip ; mkdir -p ./data ; mv ./tp[123].zip ./data ; unzip -uq ./data/tp[123].zip 
else ifeq ($(wildcard ./tcv.o),)
	@wget -q $(WEB_TCV)tp1.zip $(WEB_TCV)tp2.zip $(WEB_TCV)tp3.zip ; mkdir -p ./data ; mv ./tp[123].zip ./data/ ; unzip -uq ./data/tp[123].zip 
endif

.PHONY:clean lib all default

