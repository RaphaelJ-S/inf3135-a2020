OPT_GCC=gcc -std=c11 -Wall -Werror=vla -pedantic
OPT_CUNIT=-I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu
WEB_TCV=https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/

default: tp3 

all: tp3 test_tp3 

tp3: lib tp3.c malib.c malib.h 
	@$(OPT_GCC) -o tp3 tp3.c malib.c outil3.c tcv.o -lm

test_tp3: tp3.c lib malib.c malib.h
	@$(OPT_GCC) -D_ERR_ -o test_tp3 tp3.c malib.c outil3.c tcv.o -lm

run: tp3 tests/data.txt 
	@cat tests/data.txt | ./tp3 -d -i -s 

clean: 
	@rm -rf ./data/ tp3 test_tp3 tcv.[oh]

lib: 
ifeq ($(wildcard ./tcv.h),) 
	@wget -qN --directory-prefix=./data/ $(WEB_TCV)tp1.zip $(WEB_TCV)tp2.zip $(WEB_TCV)tp3.zip ; unzip -uoq "./data/tp[123].zip"
else ifeq ($(wildcard ./tcv.o),)
	@wget -qN --directory-prefix=./data/ $(WEB_TCV)tp1.zip $(WEB_TCV)tp2.zip $(WEB_TCV)tp3.zip ; unzip -uoq "./data/tp[123].zip"
endif

.PHONY:clean lib all default

