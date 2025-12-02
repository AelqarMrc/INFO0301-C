#include "LR.h"
#include "stdlib.h"
#include "Key.h"


void LR_inserer(LR* plr, Key k)
{
    Element2p* tmp = malloc(sizeof(Element2p));
    tmp -> key = k;
    tmp -> prec = NULL;
    tmp -> svt = NULL;

    if (*plr!=NULL)
    {
        tmp -> svt = *plr;
        (*plr)-> prec = tmp;
    }
    *plr = tmp;
}

Element2p* LR_rechercher(LR lr, Key k)
{
    Element2p* p = lr;

    if ((p == NULL))
        return p;
    else if (p -> key == k)
        return p;
    else
    {
        p = p -> svt;
        LR_rechercher(p, k);
    }
    return p;
}

void LR_supprimer(LR* plr, Element2p* pe)
{
    if (*plr != NULL)  // Si vide 
        return;
    else if (pe -> prec == NULL)  // Si au début 
    {
        pe -> svt -> prec = NULL;
        *plr = pe -> svt;
    }
    else if (pe -> svt == NULL)  // Si à la fin
    {
        pe -> prec -> svt = NULL;
    }
    else  // Cas général
    {
        pe -> svt -> prec = pe -> prec;
        pe -> prec -> svt = pe -> svt;   
    }
    free(pe);  //Liberation 
}