#ifndef __PILE_H__
#define __PILE_H__
#include "Element.h"

typedef struct xPile_ Pile_;


void creerPile(Pile_ *);
int pileVide(Pile_);
Element sommet(Pile_);
void empiler(Pile_ *, Element);
void depiler(Pile_*);



#endif