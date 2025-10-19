#ifndef PILE_CH_H
#define PILE_CH_H
#include "Cellule.h"

struct xPile_
{
    cellule *haut;
};

void libererPile(Pile_ *);

#endif