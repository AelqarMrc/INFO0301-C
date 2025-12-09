#include "Key.h"
#include "ABR.h"
#include "stdlib.h"

/*******************************************/

// init_noeud(...);

Noeud* init_noeud()
{
    Noeud* n = malloc(sizeof(Noeud));
    n -> pere = NULL;
    n -> filsG = NULL;
    n -> filsD = NULL;
    n -> key = NULL;
}

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

Noeud* ABR_predecesseur(ABR x)
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

Noeud* ABR_successeur(ABR x)
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

void ABR_inserer(ABR* px, Key k)
{
    if (*px==NULL) // ABR COURANT VIDE -> cas trivial
    {
        *px = init_noeud(); // CREATION D'UN NOUVEAU NOEUD
        (*px)->key = k;
    }
    
    else if (k == (*px)->key) // SI EXISTE DEJA ON SORT -> cas moins trivial
        return;
    
    else if (k < (*px)->key) // VAL DE LA CLE INFERIEUR A L'ABR COURANT -> cas général
        ABR_inserer(&((*px)->filsG), k); // PASSAGE DE PARAMETRE DE L'ADRESSE DU FILS GAUCHE DONC &(...)
    
    else // VAL DE LA CLE SUPERIEUR A L'ABR COURANT
        ABR_inserer(&((*px)->filsD), k);
}

void ABR_supprimer(ABR* px, Noeud* p)
{
    if (*px == NULL) /**** CAS 1 : ARBRE VIDE ****/
        return;
    else    
    {
        if (p->filsG == NULL && p->filsD == NULL) /**** CAS 2 : NOEUD SANS FILS ****/
        {
            if (p->pere == NULL) // SI RACINE 
                *px = NULL;
            else /******  OPERATION 1 : METTRE LE POINTEUR DU PERE VERS LE FILS A NULL ******/
            {
                if (p->pere->filsG == p) // SI LE NOEUD EST LE FILS GAUCHE DU PERE  
                    p->pere->filsG = NULL;                                          
                else                                                                
                    p->pere->filsD = NULL; // SI LE NOEUD EST LE FILS DROIT DU PERE 
            }
            free(p); /******  OPERATION 2 : APPLIQUER LA SUPPRESSION  ******/
        }       

        else if (p->filsG == NULL || p->filsD == NULL) /**** CAS 3 : NOEUD AVEC UN SEUL FILS DROITE OU GAUCHE ****/
        {
            Noeud* pf = p->filsG;   //
            if (pf == NULL)         /******  OPERATION 0 : ON REPERE LE FILS EXISTANT DU NOEUD A SUPPRIMER  ******/
                pf = p->filsD;      //

            pf->pere = p->pere; /******  OPERATION 1 : LE PERE DU FILS DEVIENT LE PERE DU NOEUD  ******/
            
            /******  OPERATION 2 : ON RELIE LE FILS DU NOEUD ET SON PERE AVANT DE SUPPRIMER  ******/

            if (p->pere ==  NULL) // SI RACINE
                *px = NULL;
            else  
                if (p->pere->filsD == p) // SI LE NOEUD EST FILS DROIT DU PERE     
                    p->pere->filsD = pf;
                else                     // SI LE NOEUD EST FILS GAUCHE DU PERE
                    p->pere->filsG = pf;
            
            /******  OPERATION 3 : ON APPLIQUE LA SUPPRESSION  ******/
            free(p);
        } 
        
        else /**** CAS 3 : NOEUD AVEC 2 FILS ****/
        {
            /******  OPERATION 0 : ON PREND LE PREDECESSEUR (OU LE SUCCESSEUR)  ******/
            Noeud* q = ABR_predecesseur(p);

            /******  OPERATION 1 : ON ECHANGE LA CLE ENTRE LE PREDECESSEUR ET L'ABR COURANT (NOEUD A SUPPRIMER INITIALEMENT)  ******/
            p->key = q->key;

            /******  OPERATION 3 : ON SUPPRIME LE PREDECESSEUR (APPEL RECURSIF DE LA SUPPRESSION TERMINAL)  ******/
            ABR_supprimer(px,q);
        }
        
          
    }
    
}