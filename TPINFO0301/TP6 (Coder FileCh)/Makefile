EXE = a.out
CFLAGS=-Wall -Werror

# point d'entrée
all : $(EXE)

# module objet
Element.o : Element.c Element.h
	gcc $(CFLAGS) $< -c

Cellule.o : Cellule.c Cellule.h
	gcc $(CFLAGS) $< -c

Pile_Ch.o : Pile_Ch.c Pile_Ch.h Element.h Cellule.h Pile_.h
	gcc $(CFLAGS) $< -c

Pile_Test.o : Pile_Test.c Element.h Pile_.h Pile_Ch.h

# règle principal
$(EXE) : Element.o Cellule.o Pile_Ch.o Pile_Test.o
	gcc $^ -o $@

# nettoyage

clean : 
	rm *.o

mrproper : clean
	rm $(EXE)