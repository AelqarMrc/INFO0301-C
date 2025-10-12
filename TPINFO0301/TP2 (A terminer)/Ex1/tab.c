#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

void remplirTab(double t[MAX], int *pTaille)
{
    
    do
    {
        printf("Donnez la taille de tableau entre 0 et %d\n", MAX);
        scanf("%d", pTaille);     
    } while (*pTaille > MAX || *pTaille < 0);

    for (int i = 0; i < *pTaille; i++)
    {
        t[i]=1;
    }
    
}

void affichage(double t[MAX], int taille)
{
    printf("tab [ | ");
    for (int i = 0; i < taille; i++)
    {
        printf("%.2lf | ", t[i]);
    }
    printf("]\n");
    
}
