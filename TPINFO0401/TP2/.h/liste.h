#ifndef __LISTE_H__
#define __LISTE_H__

typedef struct {
    cellule *tete;
} liste;

void initialiser_liste(liste*);
void inserer_liste(liste*, cellule*);
void afficher_liste(liste);
cellule* rechercher_liste(liste, int);
void detruire_liste(liste*);


#endif 