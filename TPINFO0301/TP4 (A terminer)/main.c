#include <stdio.h>
#include <stdlib.h>
#include "PileTSEnt.h"

int main(void)
{
    Pile maPile; 

    creerPile(&maPile);
    pileVide(&maPile);

    if (pileVide(&maPile))
        printf("Ma pile est vide au départ\n");

    empiler(&maPile, 3);
    empiler(&maPile, 7);
    empiler(&maPile, 4);

    printf("Le sommet de la pile est %d\n", sommet(&maPile));

    pileVide(&maPile);
    if (!pileVide(&maPile))
    {
        depiler(&maPile);
        printf("Le sommet de la pile est %d\n", sommet(&maPile));
    }

    
    
}