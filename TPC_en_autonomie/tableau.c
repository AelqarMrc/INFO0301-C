#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

void somme_de_t (int tab[], int taille)
{
    int res = 0;
    for (unsigned i = 0; i < taille; i++)
    {
        res += tab[i];
    }
    
    printf("le resultat de la somme des elements du tableau est : %d\n", res);
}

int max_de_t(int tab[], int taille)
{
    int max = tab[0];

    for (unsigned i = 0; i < taille; i++)
    {
        if (max < tab[i])
            max = tab[i];
    }
    return max;
}

int min_de_t(int tab[], int taille)
{
    int min = tab[0];

    for (unsigned i = 0; i < taille; i++)
    {
        if (min > tab[i])
            min = tab[i];
    }
    return min;
}