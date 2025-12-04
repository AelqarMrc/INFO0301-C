#include "Key.h"
#include "TH_ch.h"
#include "stdlib.h"

// Fonction de hashage
void h(Key *k)
{
    *k = 1 + (*k-1)%MAX;
}

// Fonction de création et de liberation

void TH_initialiser(TH* T)
{
    T = malloc(MAX * sizeof(LR));
    for (int i = 0; i < MAX; i++)
    {
        *(T + i) = NULL; 
    }
}

void TH_liberer(TH* T)
{
    free(T);
}

// Fonction de consultation 

Element2p* TH_rechercher(TH T, Key k)
{
    h(k);
    LR_rechercher(T+k, k);
}

// Fonction de modification 

void TH_inserer(TH *T, Key k)
{
    h(k);
    LR_inserer(T+k, k);
}

void TH_supprimer(TH *T, Key k)
{
    h(k);
    LR_supprimer(T+k, k);
}