#include "Element.h"
#include "Pile_.h"
#include "Pile_Tab.h"
#include "stdio.h"
#include "stdlib.h"

// Déclaration des Fonction calculabe de Pile_

void viderPile(Pile_ pile);
void copierPile(Pile_ *pile1, Pile_ *pile2);
void inverserPile(Pile_ *pile);


Pile_ pile1, pile2;
Element e;

int main(void)
{
    //
    //
    // Définitions des Piles et Elements à tester 
    creerPile(&pile1);
    creerPile(&pile2);
    // 
    // 
    // Remplissage de la pile :
    // for (int i = 0; i < 1; i++)
    // {
    //     saisie(&e);
    //     creerPile(&pile1);
    // }
    // printf("contenu après remplissage\n");
    // affichage(sommet(&pile1));

    // printf("double de e : %lf\n", valeurReelle(sommet(&pile1)));
    // printf("int de e : %d\n", valeurEntiere(e));

    e.x = 4;
    e.n = 6;
    Pile_ *pp = &pile1;

    for (int i = 0; i < 3; i++)
    {
        saisie(&e);
        empiler(pp, e);
    }
    
    affichage(sommet(*pp));

    

    return EXIT_SUCCESS;
}

////////////////        Définition des Fonctions calculables de Pile_

void viderPile(Pile_ pile)
{
    while (!pileVide(pile))
    {
        depiler(&pile);
    }
}

//
//
//

void copierPile(Pile_ *pile1, Pile_ *pile2)
{
    Pile_ pileTmp;
    creerPile(&pileTmp);        // Créer une pile temp pour changer l'ordre des valeurs pour la copie et éviter d'inverser les valeurs     

    while (!(pileVide(*pile1)))
    {
        empiler(&pileTmp, sommet(*pile1));
        depiler(pile1);
    }
    while (!(pileVide(pileTmp)))
    {
        empiler(pile2, sommet(pileTmp));
        empiler(pile1, sommet(pileTmp));
        depiler(&pileTmp);
    }
    
}

//
//
//

void inverserPile(Pile_ *pile)
{
    Pile_ pileTmp;
    creerPile(&pileTmp);

    while (!pileVide(*pile))
    {
        empiler(&pileTmp, sommet(*pile));
        depiler(pile);
    }
    while (!pileVide(pileTmp))
    {
        empiler(pile, sommet(pileTmp));
        depiler(&pileTmp);
    }
}