EXE = a.out
CFLAGS=-Wall -Werror

all : $(EXE)
LR.o : LR.c LR.h
	gcc $(CFLAGS) $< -c

LR_principal.o : LR_principal.c Key.h LR.h
	gcc $(CFLAGS) $< -c

$(EXE) : LR.o LR_principal.o
	gcc $^ -o $@

clean : 
	rm *.o

mrproper : clean 
	rm $(EXE)