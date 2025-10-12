#include "Element.h"

#include <stdio.h>

// partie generique //////////////////////////
void saisie(Element* pe) {
    scanf("%lf %d", &pe->x, &pe->n );
}

void affichage(Element e) {
 	printf("%d ", e.n);
//	printf("(x , n) = (%lf , %d)", e.x, e.n);   
}

int egaux(Element e, Element f) {
    return e.x == f.x  &&  e.n == f.n;
}

// partie specifique /////////////////////////
double valeurReelle(Element e) {
 	return e.x;
}
int valeurEntiere(Element e) {
    return e.n;
}
