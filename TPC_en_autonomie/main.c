#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
#include <errno.h>


int main(void)
{
    int tab[5] = {1,10,3,-2,50};
    int taille = 5;
    somme_de_t(tab,taille);
    printf("le maximum du tableau est : %d\n", max_de_t(tab,taille));    
    printf("le minimum du tableau est : %d\n", min_de_t(tab,taille));    

    return EXIT_SUCCESS;
}