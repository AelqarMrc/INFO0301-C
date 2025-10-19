#ifndef ELEMENT_H
#define ELEMENT_H

typedef struct xElement 
{
    double x;
    int n;
}Element;

void saisie(Element *);
void affichage(Element);
int egaux(Element, Element);

double valeurReelle(Element);
int valeurEntiere(Element);

#endif