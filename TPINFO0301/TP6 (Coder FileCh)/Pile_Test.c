// choisissez : 0 pour implem Tab ; 1 pour implem Ch
#define VERSION 1

#include "Element.h"
#include "Pile_.h"

#if VERSION == 0
	#include "Pile_tab.h"
#else
	#include "Pile_Ch.h"
#endif

#include <stdio.h>
#include <stdlib.h>

// fonctions calculables
// A. leurs declarations (definitions a la fin)
void viderP(Pile_ *);
void transfererPP(Pile_ *, Pile_ *);
void inverserP(Pile_ *);

// pour ces deux la on ne change pas les valeurs de la pile, et leur ordre global est OK
// mais si l'implem est en chainage les cellules ne sont pas necessairement au meme endroit
//  => passer un Pile_ *
int  tailleP(Pile_ *);
void afficherP(Pile_ *);

// B. le programme de test 
// definitions des fonctions calculables a la fin
int main(void){ 
	Pile_ p;
	Element e;
	
	creerPile(&p);
	for(int i=0 ; i<3 ; i++){
	 	saisie(&e);
		empiler(&p, e);
	}
	printf("contenu apres remplissage : "); 
		afficherP(&p);	// le contenu de la structure change : on passe le ptr 

	printf("\n\t => taille (2 fois) : %d %d\n", tailleP(&p), tailleP(&p));
	printf("contenu avant inversion : "); 	afficherP(&p);
	inverserP(&p);
	printf("\ncontenu apres inversion : "); 	afficherP(&p);
	
	viderP(&p);
	printf("\ncontenu apres vidage : "); 		afficherP(&p);
	printf("\n\t => taille : %d\n", tailleP(&p));


	libererPile(&p);
	return EXIT_SUCCESS;
}

// fonctions calculables
// C. leurs definitions (declarations a la fin)

void viderP(Pile_* pp){	
    while ( ! pileVide(*pp) )
		depiler(pp);
}

// routine : transfert d'une pile dans une autre 
// (utile pour certaines fonctions calculables mais pas utilisee dans le main)
void transfererPP(Pile_* pp1, Pile_* pp2)
{
	Pile_ pTmp;
	creerPile(&pTmp);
	while (!pileVide(*pp1))
	{
		empiler(&pTmp, pp1->haut->val);	
		depiler(pp1);
	}
	while (!pileVide(pTmp))
	{
		empiler(pp2, pTmp.haut->val);
		depiler(&pTmp);
	}
}

int tailleP(Pile_ *pp)
{
 	int nb = 0;
	Pile_ p2;
	creerPile(&p2);

	while (!pileVide(*pp))
	{
		empiler(&p2, pp->haut->val);	
		depiler(pp);
		nb++;
	}
	while (!pileVide(p2))
	{
		empiler(pp, p2.haut->val);	
		depiler(&p2);
	}
	
	
	return nb;
}

void afficherP(Pile_* pp)
{
	Pile_ p2;
	creerPile(&p2);

	while (!pileVide(*pp))
	{
		empiler(&p2, pp->haut->val);	
		depiler(pp);
	}
	while (!pileVide(p2))
	{
		empiler(pp, p2.haut->val);
		affichage(pp->haut->val);	
		depiler(&p2);
	}
}

void inverserP(Pile_* pp)
{
 	Pile_ p2, p3;
	creerPile(&p2);
	creerPile(&p3);

	while (!pileVide(*pp))
	{
		empiler(&p2, pp->haut->val);	
		depiler(pp);
	}
	while (!pileVide(p2))
	{
		empiler(&p3, p2.haut->val);	
		depiler(&p2);
	}
	while (!pileVide(p3))
	{
		empiler(pp, p3.haut->val);	
		depiler(&p3);
	}
}
