#include "Pile_Tab.h"
#include "stdlib.h"

void creerPile (Pile_ *ppile)
{
    ppile -> tab = malloc(MAX * sizeof(Element));
    ppile -> nb = 0;
}

int pileVide(Pile_ pile)
{
    return pile.nb == 0;
}

Element sommet(Pile_ pile)
{   
    return *(pile.tab + (pile.nb-1));
}

void empiler(Pile_ *pp, Element e)
{
    if (pp->nb == MAX)
        return ;
    *(pp->tab+pp->nb) = e;
    pp->nb++;
}

void depiler(Pile_ *ppile)
{
    if (ppile -> nb == 0)
        return ;
    ppile -> nb--;
}