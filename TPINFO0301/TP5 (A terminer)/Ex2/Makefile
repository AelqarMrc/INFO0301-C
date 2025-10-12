all : a.out gcc -Wall -Wextra -Werror
maillon.o : maillon.c maillon.h
	gcc maillon.c -c
principal.o : principal.c maillon.h
	gcc principal.c
a.out : maillon.o principal.o
	gcc maillon.o principal.o
clear :
	rm *.o
mrproper : clear
	rm a.out
