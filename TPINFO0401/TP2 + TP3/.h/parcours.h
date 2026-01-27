#ifndef __PARCOURS_H__
#define __PARCOURS_H__
#include "COULEUR.h"

typedef struct xsommet sommet_parc_larg;

struct xsommet
{
    sommet_parc_larg* pere;
    int distance;
    COULEUR couleur;
};


void parcours_largeur(graphe*, int);

#endif