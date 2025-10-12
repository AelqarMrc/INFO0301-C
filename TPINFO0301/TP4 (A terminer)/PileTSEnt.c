#include "PileTSEnt.h"

void creerPile(Pile *pPile){pPile -> nb = 0;}
_Bool pileVide(Pile *pPile){return pPile -> nb == 0;}
int sommet(Pile *pPile){return pPile -> tab[pPile -> nb-1];}
void empiler(Pile *pPile, int val){pPile -> tab[pPile -> nb++] = val;}
void depiler(Pile *pPile){if (pPile -> nb >0) pPile -> nb--;}