#ifndef __LISTEC_H__
#define __LISTEC_H__
#include "Element.h"

typedef struct xListe ListeC;


///
/// Création Libération 
///
void creationListe(ListeC *);
void liberationListe(ListeC *);

///
/// Consultations
///
int ListeCVide(ListeC);
int estDebut(ListeC);
int estFin(ListeC);
Element valeurCourante(ListeC );

///
/// Déplacements
///
void allerDebut(ListeC *);
void allerFin(ListeC *);
void avancer(ListeC *);

///
/// Actions
///
void inserer(ListeC *, Element);
void supprimer(ListeC *);

#endif