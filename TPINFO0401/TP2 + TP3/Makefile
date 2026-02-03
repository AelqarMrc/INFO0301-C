Comp = gcc
CFLAGS = -Wall -Werror
C_DIR = ./.c
H_DIR = ./.h


CFLAGS += -I $(H_DIR)

OBJ = cellule.o liste.o graphe.o parcours.o file.o main.o
EXE = a.out 
all: $(EXE)



cellule.o : ../TP1/cellule.c $(H_DIR)/cellule.h
	gcc $(CFLAGS) $< -c

liste.o : ../TP1/liste.c $(H_DIR)/cellule.h $(H_DIR)/liste.h
	gcc $(CFLAGS) $< -c

graphe.o : $(C_DIR)/graphe.c $(H_DIR)/cellule.h $(H_DIR)/liste.h $(H_DIR)/graphe.h
	gcc $(CFLAGS) $< -c

parcours.o : $(C_DIR)/parcours.c $(H_DIR)/cellule.h $(H_DIR)/liste.h $(H_DIR)/graphe.h $(H_DIR)/COULEUR.h $(H_DIR)/parcours.h
	gcc $(CFLAGS) $< -c

file.o : $(C_DIR)/file.c $(H_DIR)/cellule.h $(H_DIR)/liste.h $(H_DIR)/graphe.h $(H_DIR)/COULEUR.h $(H_DIR)/parcours.h $(H_DIR)/file.h
	gcc $(CFLAGS) $< -c

main.o : $(C_DIR)/main.c $(C_DIR)/file.c $(H_DIR)/cellule.h $(H_DIR)/liste.h $(H_DIR)/graphe.h $(H_DIR)/COULEUR.h $(H_DIR)/parcours.h $(H_DIR)/file.h
	gcc $(CFLAGS) $< -c 

$(EXE): cellule.o liste.o graphe.o parcours.o file.o main.o
	gcc $^ -o $@

clean :
	rm *.o

mrproper : clean
	rm $(EXE)