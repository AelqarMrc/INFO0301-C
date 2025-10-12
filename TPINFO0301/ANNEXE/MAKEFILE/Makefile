# Info0301 2025-2026
# TP 4 : tours de Hanoi
# Ch Jaillet
# 25/9/2025
#*****************
# fic : makefile2

EXE=a.out

# compilation séparée avec vérification
# sans règle d'inférence / variables

# point d'entrée
all: $(EXE)

# modules objets
PileTSEnt.o : PileTSEnt.c PileTSEnt.h
	gcc $< -c

plateauHanoi.o : plateauHanoi.c plateauHanoi.h PileTSEnt.h
	gcc $< -c

principal.o : principal.c plateauHanoi.h
	gcc $< -c

# règle principale
$(EXE) : PileTSEnt.o plateauHanoi.o principal.o
	gcc $^ -o $@

###################
# et aussi : nettoyage

clean :
	rm *.o

mrproper : clean
	rm $EXE
