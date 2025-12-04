#ifndef __TH_CH_H__
#define __TH_CH_H__
#define MAX 10
#include "LR.h"

typedef LR* TH[MAX];

void h(Key);

// Fonction de création et de libération (Procédure en Algo)

void TH_initialiser(TH*);
void TH_liberer(TH*);

// Fonction de consultation 

Element2p TH_rechercher(TH, Key);


// Fonction de modification

void TH_inserer(TH*, Key);
void TH_supprimer(TH*, Element2p*);

#endif 