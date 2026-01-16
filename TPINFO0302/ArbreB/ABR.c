#include "Key.h"
#include "ABR.h"
#include "stdlib.h"
#include "stdio.h"

/*******************************************/

// init_noeud(...);

Noeud* init_noeud()
{
    Noeud* n = malloc(sizeof(Noeud));
    n -> pere = NULL;
    n -> filsG = NULL;
    n -> filsD = NULL;
    n -> key = 0;

    return n;
}

/*******************************************/

// Fonction de recherche implémentation

Noeud* ABR_rechercher(ABR x, Key k)
{
    if ((x==NULL)||(x->key == k))
        return x;
    else
    { 
        if (x->key < k)
        {
            if (x->filsD == NULL)
                return NULL;
            return ABR_rechercher(x->filsD, k);
        }
        else
        {
            if (x->filsG == NULL)
                return NULL;
            return ABR_rechercher(x->filsG, k);
        }
    }
}

Noeud* ABR_minimum(ABR x)
{
    if ((x == NULL) || (x->filsG == NULL))
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
    if (x==NULL)
        return x;
    else if (x->filsG != NULL)
    {
        Noeud* tmp = x->filsG;
        while (tmp->filsD!=NULL)
            tmp = tmp->filsD;
        return tmp;
    }
    else 
    {
        Noeud* tmp = x->pere;
        while (tmp!=NULL && x == tmp -> filsG)
        {
            x = tmp;
            tmp = tmp->pere;
        }
        return tmp;
    }

    
}

Noeud* ABR_successeur(ABR x)
{
    if ((x==NULL) || ((x->pere == NULL) && (x->filsD == NULL)))
        return x;
    else
    {
        if (x->filsD->filsG == NULL)
            return x->filsD;
        else
        {
            while (x->filsG != NULL)
                x = x->filsG;
            return x;
        }    
    }
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
    {
        printf("un probleme cas 1 !!!!\n");
        return;
    }
    else    
    {
        if ((p->filsG == NULL) && (p->filsD == NULL)) /**** CAS 2 : NOEUD SANS FILS ****/
        {
            if (p->pere == NULL) // SI RACINE 
                {printf("un probleme cas 2 racine !!!!\n"); *px = NULL;}
            else /******  OPERATION 1 : METTRE LE POINTEUR DU PERE VERS LE FILS A NULL ******/
            {
                if (p->pere->filsG == p) // SI LE NOEUD EST LE FILS GAUCHE DU PERE  
                    {printf("un probleme cas si 2 !!!!\n"); p->pere->filsG = NULL;}                                          
                else                                                                
                    {printf("un probleme cas 2 si 2 !!!!\n"); p->pere->filsD = NULL;} // SI LE NOEUD EST LE FILS DROIT DU PERE 
            }
            free(p); /******  OPERATION 2 : APPLIQUER LA SUPPRESSION  ******/
        }       

        else if (p->filsG == NULL || p->filsD == NULL) /**** CAS 3 : NOEUD AVEC UN SEUL FILS DROITE OU GAUCHE ****/
        {
            Noeud* pf = p->filsG;   //
            if (pf == NULL)         /******  OPERATION 0 : ON REPERE LE FILS EXISTANT DU NOEUD A SUPPRIMER  ******/
            {printf("un probleme cas 3 op 0 !!!!\n");pf = p->filsD;}      //

            pf->pere = p->pere; /******  OPERATION 1 : LE PERE DU NOEUD DEVIENT LE PERE DU FILS  ******/
            
            /******  OPERATION 2 : ON RELIE LE FILS DU NOEUD ET SON PERE AVANT DE SUPPRIMER  ******/

            if (p->pere ==  NULL) // SI RACINE
                {printf("un probleme cas 3 op 2 si racine !!!!\n"); *px = pf;}
            else 
            {
                if (p->pere->filsD == p) // SI LE NOEUD EST FILS DROIT DU PERE     
                    {printf("un probleme cas 3 op 2 si fD !!!!\n"); p->pere->filsD = pf;}
                else                     // SI LE NOEUD EST FILS GAUCHE DU PERE
                    {printf("un probleme cas 3 op 2 si fG !!!!\n"); p->pere->filsG = pf;}
            }
            
            /******  OPERATION 3 : ON APPLIQUE LA SUPPRESSION  ******/
            free(p);
        } 
        
        else /**** CAS 4 : NOEUD AVEC 2 FILS ****/
        {
            /******  OPERATION 0 : ON PREND LE PREDECESSEUR (OU LE SUCCESSEUR)  ******/
            printf("un probleme ici !!!!\n");
            Noeud* q = ABR_predecesseur(p);
            printf("%p   %p   %p  %d\n", q->filsG, q->filsD, q->pere, q->key);

            /******  OPERATION 1 : ON ECHANGE LA CLE ENTRE LE PREDECESSEUR ET L'ABR COURANT (NOEUD A SUPPRIMER INITIALEMENT)  ******/
            p->key = q->key;

            /******  OPERATION 3 : ON SUPPRIME LE PREDECESSEUR (APPEL RECURSIF DE LA SUPPRESSION TERMINAL)  ******/
            ABR_supprimer(px,q);
        }
        
          
    }
    
}