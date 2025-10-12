#include "stdio.h"
#include "stdlib.h"
#include "Element.h"

void saisie(Element *pe)
{
    printf("Entrez la valeur Reelle : ");
    scanf("%lf", &(pe->x));
    printf("Entrez la valeur Entiere : ");
    scanf("%d", &(pe->n));
}

void affichage(Element elem)
{
    printf("(x , n) = (%.2lf , %d)\n", elem.x, elem.n); 
}

int egaux(Element elem1, Element elem2)
{
    return elem1.x == elem2.x && elem1.n == elem2.n;
}

double valeurReelle(Element elem)
{
    return elem.x;
}

int valeurEntiere(Element elem)
{
    return elem.n;
}