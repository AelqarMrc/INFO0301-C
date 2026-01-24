#include "cellule.h"
#include "liste.h"
#include "stdlib.h"
#include "stdio.h"

void initialiser_liste(liste* l){
    l->tete = NULL;
}

void inserer_liste(liste*l, cellule* x){
    x->succ = l->tete;
    if (l->tete != NULL)
        l->tete->pred = x;
    l->tete = x;
    x->pred = NULL;
}

void afficher_liste(liste l){
    cellule* x = l.tete;
    printf("tete --> ");

    while (x!=NULL)
    {
        printf("%d ", x->id_sommet);
        x = x->succ;
    }      
}

cellule* rechercher_liste(liste l, int id){
        cellule *courant = l.tete;
    while (courant != NULL) {
        if (courant->id_sommet == id) {
            return courant;
        }
        courant = courant->succ;
    }
    return NULL;
} 

void detruire_liste(liste *l){
    cellule *courant = l->tete;
    cellule *suivant;
    while (courant != NULL) {
        suivant = courant->succ;
        free(courant);
        courant = suivant;
    }
    l->tete = NULL;
}
