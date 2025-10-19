#include "Pile_.h"
#include "Pile_Ch.h"
#include "stdlib.h"

void creerPile(Pile_ *pp)
{
    pp -> haut = NULL;
}

void libererPile(Pile_ *pp)
{
    free(pp->haut);
}

int pileVide(Pile_ p)
{
    return p.haut == NULL;
}

Element sommet(Pile_ p)
{
    return p.haut -> val;
}

void empiler(Pile_ *pp, Element e)
{
    cellule *tmp = malloc(sizeof(cellule));
    tmp -> val = e;
    tmp -> svt = pp -> haut;
    pp -> haut = tmp;
}


void depiler(Pile_ *pp)
{
    if (pileVide(*pp))
        return ;
    cellule *tmp = pp->haut;
    pp -> haut = tmp -> svt;
    free(tmp); 
}
