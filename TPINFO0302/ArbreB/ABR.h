#ifndef __ABR_H__ 
#define __ABR_H__ 


typedef struct Element3p
{
    Key key;
    struct Element3p* pere;
    struct Element3p* filsG;
    struct Element3p* filsD;
}Noeud;

typedef Noeud* ABR;

/**********************************/

// Fonction de recherche 

Noeud* ABR_rechercher(ABR, Key);
Noeud* ABR_minimum(ABR);
Noeud* ABR_maximum(ABR);
Noeud* ABR_predecesseur(ABR, Key);
Noeud* ABR_successeur(ABR, Key);

/**********************************/

// Fonction de modification

void ABR_inserer(ABR*, Key);
void ABR_supprimer(ABR*, Noeud*);

#endif