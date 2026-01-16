EXE = a.out
CFLAGS=-Wall -Werror

all : $(EXE)
cellule.o : cellule.c cellule.h
	gcc $(CFLAGS) $< -c

liste.o : liste.c cellule.h liste.h
	gcc $(CFLAGS) $< -c

prog_liste.o : prog_liste.c cellule.h liste.h
	gcc $(CFLAGS) $< -c

$(EXE) : cellule.o liste.o prog_liste.o
	gcc $^ -o $@

clean : 
	rm *.o

mrproper : clean 
	rm $(EXE)