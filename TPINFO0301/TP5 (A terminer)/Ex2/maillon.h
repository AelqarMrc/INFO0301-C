#ifndef MAILLON_H
#define MAILLON_H

typedef struct cellule
{
    int val;
    maillon *svt;
}maillon;


maillon *creerChainage(maillon * *pdeb);
maillon *rechercherVal(maillon * *pdeb);


#endif