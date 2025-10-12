#ifndef PILETSENT_H
#define PILETSENT_H
#define MAX 100

typedef struct
{
    int nb;
    int tab[MAX];
}Pile;


void creerPile(Pile *pPile);
_Bool pileVide(Pile *pPile);
int sommet(Pile *pPile);
void empiler(Pile *pPile, int val);
void depiler(Pile *pPile);


#endif 