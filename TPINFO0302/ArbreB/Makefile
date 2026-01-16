EXE = a.out
CFLAGS = -Wall -Werror

all : $(EXE)
ABR.o : ABR.c ABR.h Key.h
	gcc $(CFLAGS) $< -c

ABR_principal.o : ABR_principal.c Key.h ABR.h
	gcc $(CFLAGS) $< -c

$(EXE) : ABR.o ABR_principal.o
	gcc $^ -o $@

clean : 
	rm *.o

mrproper : clean
	rm $(EXE)