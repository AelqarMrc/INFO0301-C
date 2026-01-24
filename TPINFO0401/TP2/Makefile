EXE = a.out 
CFLAGS = -Wall -Werror

all: $(EXE)
cellule.o : ../TP1/cellule.c cellule.h
	gcc $(CFLAGS) $< -c

liste.o : ../TP1/liste.c cellule.h liste.h
	gcc $(CFLAGS) $< -c

graphe.o : graphe.c cellule.h liste.h graphe.h
	gcc $(CFLAGS) $< -c

main.o : main.c cellule.h liste.h graphe.h
	gcc $(CFLAGS) $< -c 

$(EXE): cellule.o liste.o graphe.o main.o
	gcc $^ -o $@

clean :
	rm *.o

mrproper : clean
	rm $(EXE)