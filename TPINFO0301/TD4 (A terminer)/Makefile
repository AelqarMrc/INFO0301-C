EXE = a.out
CFLAGS=-Wall -Werror

# point d'entrée
all : $(EXE)

# module objet
Element.o : Element.c Element.h
	gcc $(CFLAGS) $< -c

Pile_Tab.o : Pile_Tab.c Pile_Tab.h Element.h Pile_.h
	gcc $(CFLAGS) $< -c

Pile_Test.o : Pile_Test.c Element.h Pile_.h Pile_Tab.h

# règle principal
$(EXE) : Element.o Pile_Tab.o Pile_Test.o
	gcc $^ -o $@

# nettoyage

clean : 
	rm *.o

mrproper : clean
	rm $(EXE)