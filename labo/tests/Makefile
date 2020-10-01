all : 
	make max.o
	make max_test

max.o : max.c
	gcc -Wall -Werror=vla -c max.c

max_test : max.o max_test.c
	gcc -Wall -Werror=vla -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o max_test max_test.c max.o -lcunit

exec : exec.c
	gcc -o exec exec.c
clean: 
	rm -f max_test
	rm -f *.o
	
.PHONY : clean all
