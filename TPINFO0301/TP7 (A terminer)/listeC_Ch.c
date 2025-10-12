#include "Cellule.h"
#include "ListeC.h"
#include "ListeC_Ch.h"
#include "stdlib.h"

void creationListe(ListeC *L)
{
    L = malloc(sizeof(Cellule));
    L -> deb = NULL;
    L -> crt = NULL;
    L -> fin = NULL;
}

void liberationListe(ListeC *L)
{
       
}