.PHONY: all allbuild alltest cle

allbuild:labo03-1 labo03-2 labo03-3 labo06-1 labo06-3 labo06-4 labo06-5 labo07-1

alltest: lab3-1_test labo3-2_test labo3-3_test

labo07-1: stack.c
	gcc stack.c -lm -o stack

labo06-5: labo06-5.c
	gcc labo06-5.c -o labo06-5

labo06-4: labo06-4.c
	gcc labo06-4.c -lm -o labo06-4

labo06-3: labo06-3.c
	gcc labo06-3.c -lm -o labo06-3

labo6-3T: labo06-3
	./labo06-3

labo06-1: labo06-1.c
	gcc labo06-1.c -o labo06-1

labo6-1Test : labo06-1
	./labo06-1

labo03-3: labo03-3.c
	gcc labo03-3.c -o labo03-3

labo03-2: labo03-2.c
	gcc labo03-2.c -o labo03-2

labo3-2_test: labo03-2
	./labo03-2

lab03-1: labo03-1.c
	gcc labo03-1.c -o labo03-1

lab3-1_test: labo03-1
	./labo03-1

