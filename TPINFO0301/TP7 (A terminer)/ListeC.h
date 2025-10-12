#ifndef __LISTEC_H__
#define __LISTEC_H__

typedef struct xListe ListeC;


///
/// Création Libération 
///
void creationListe(ListeC *);
void liberationListe(ListeC *);

///
/// Déplacements
///
void allerDebut(ListeC *);
void allerFin(ListeC *);
void avancer(ListeC *);


///
/// Consultations
///
void ListeCVide(ListeC *);
int estDebut(ListeC *);
int estFin(ListeC *);
void valeurCourante(ListeC *);


#endif