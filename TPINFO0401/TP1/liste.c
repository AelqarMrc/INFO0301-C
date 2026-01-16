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

        printf("%d ", x->id_sommet);
        x = x->succ;    
        printf("%d ", x->succ->id_sommet);
        x = x->succ;    
}