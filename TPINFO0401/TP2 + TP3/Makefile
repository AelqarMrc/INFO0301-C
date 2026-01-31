EXE = a.out 
CFLAGS = -Wall -Werror


all: $(EXE)
cellule.o : ../TP1/cellule.c ./.h/cellule.h
	gcc $(CFLAGS) $< -c

liste.o : ../TP1/liste.c ./.h/cellule.h ./.h/liste.h
	gcc $(CFLAGS) $< -c

graphe.o : ./.c/graphe.c ./.h/cellule.h ./.h/liste.h ./.h/graphe.h
	gcc $(CFLAGS) $< -c

parcours.o : ./.c/parcours.c ./.h/cellule.h ./.h/liste.h ./.h/graphe.h ./.h/COULEUR.h ./.h/parcours.h
	gcc $(CFLAGS) $< -c

file.o : ./.c/file.c ./.h/cellule.h ./.h/liste.h ./.h/graphe.h ./.h/COULEUR.h ./.h/parcours.h ./.h/file.h
	gcc $(CFLAGS) $< -c

main.o : ./.c/main.c ./.c/file.c ./.h/cellule.h ./.h/liste.h ./.h/graphe.h ./.h/COULEUR.h ./.h/parcours.h ./.h/file.h
	gcc $(CFLAGS) $< -c 

$(EXE): cellule.o liste.o graphe.o parcours.o file.o main.o
	gcc $^ -o $@

clean :
	rm *.o

mrproper : clean
	rm $(EXE)