Notes du tp 2 : 

graphe d'inclusions => on a pas le droit d'inclure un .c dans un quoique ce soit; ni d'inclure un .h dans un point .h.
(cf cahier de brouillon afev)

Compilation séparé : 
gcc point.c -c
gcc tab-point.c -c
gcc princ.c -c
gcc point-o tab-point.o \
    princ.o
