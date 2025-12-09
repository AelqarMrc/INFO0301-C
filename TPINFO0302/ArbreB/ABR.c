#include "Key.h"
#include "ABR.h"
#include "stdlib.h"

/*******************************************/

// Fonction de recherche implémentation

Noeud* ABR_rechercher(ABR x, Key k)
{
    if ((x==NULL)||(x->key))
        return x;
    else if (x->key > k)
        return ABR_rechercher(x->filsD, k);
    else
        return ABR_rechercher(x->filsG, k);
}

Noeud* ABR_minimum(ABR x)
{
    if ((x==NULL) || (x->filsG == NULL))
        return x;
    else 
        return ABR_minimum(x->filsG);
}

Noeud* ABR_maximum(ABR x)
{
    if ((x==NULL) || (x->filsD == NULL))
        return x;
    else 
        return ABR_maximum(x->filsD);
}

Noeud* ABR_predecesseur(ABR x, Key k)
{
    if ((x==NULL) || ((x->pere == NULL) && (x->filsG == NULL)))
        return x;
    else if (x->filsG != NULL)
        if (x->filsG->filsD == NULL)
            return x->filsG;
        else    
            while (x->filsD != NULL)
                x = x->filsD;
            return x;
}

Noeud* ABR_successeur(ABR x, Key k)
{
    if ((x==NULL) || ((x->pere == NULL) && (x->filsD == NULL)))
        return x;
    else if (x->filsD != NULL)
        if (x->filsD->filsG == NULL)
            return x->filsD;
        else    
            while (x->filsG != NULL)
                x = x->filsG;
            return x;
}

/*******************************************/

// Fonction de modification implémentation

void ABR_inserer(ABR x, Key k)
{
    
}