EXE = a.out
CFLAGS=-Wall -Werror

# point d'entrée
all : $(EXE)

# module objet
Element.o : Element.c Element.h
	gcc $(CFLAGS) $< -c

Cellule.o : Cellule.c Cellule.h
	gcc $(CFLAGS) $< -c

File_Ch.o : File_Ch.c File_Ch.h Element.h Cellule.h File_.h
	gcc $(CFLAGS) $< -c

File_Test.o : File_Test.c Element.h File_.h File_Ch.h

# règle principal
$(EXE) : Element.o Cellule.o File_Ch.o File_Test.o
	gcc $^ -o $@

# nettoyage

clean : 
	rm *.o

mrproper : clean
	rm $(EXE)