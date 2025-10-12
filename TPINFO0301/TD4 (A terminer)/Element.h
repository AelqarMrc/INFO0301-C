#ifndef __ELEMENT_H__
#define __ELEMENT_H__

typedef struct xElement Element;

void saisie(Element *);
void affichage(Element );
int egaux(Element, Element);

struct xElement
{
    double x;
    int n;
};

double valeurReelle(Element);
int valeurEntiere(Element);


#endif 