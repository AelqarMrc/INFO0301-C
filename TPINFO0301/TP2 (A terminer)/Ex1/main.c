#include <stdio.h>
#include <stdlib.h>
#include "tab.h"

int main(void)
{
    double t[MAX];
    int taille;

    remplirTab(t, &taille);
    affichage(t, taille);
    
    
}