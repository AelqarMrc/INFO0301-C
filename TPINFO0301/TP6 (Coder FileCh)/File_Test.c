// choisissez : 0 pour implem Tab ; 1 pour implem Ch
#define VERSION 1

#include "Element.h"
#include "File_.h"

#if VERSION == 0
	#include "File_tab.h"
#else
	#include "File_Ch.h"
#endif

#include <stdio.h>
#include <stdlib.h>

// fonctions calculables
// A. leurs declarations (definitions a la fin)
void viderF(File_ *);
void transfererff(File_ *, File_ *);
void inverserF(File_ *);

// pour ces deux la on ne change pas les valeurs de la File, et leur ordre global est OK
// mais si l'implem est en chainage les cellules ne sont pas necessairement au meme endroit
//  => passer un File_ *
int  tailleF(File_ *);
void afficherF(File_ *);

// B. le programme de test 
// definitions des fonctions calculables a la fin
int main(void){ 
	File_ f;
	Element e;
	
	creerFile(&f);
	for(int i=0 ; i<3 ; i++){
	 	saisie(&e);
		enfiler(&f, e);
	}
	printf("contenu apres remplissage : "); 
		afficherF(&f);	// le contenu de la structure change : on passe le ptr 

	printf("\n\t => taille (2 fois) : %d %d\n", tailleF(&f), tailleF(&f));
	printf("contenu avant inversion : "); 	afficherF(&f);
	inverserF(&f);
	printf("\ncontenu apres inversion : "); 	afficherF(&f);
	
	viderF(&f);
	printf("\ncontenu apres vidage : "); 		afficherF(&f);
	printf("\n\t => taille : %d\n", tailleF(&f));


	// libererFile(&f);
	return EXIT_SUCCESS;
}

// fonctions calculables
// C. leurs definitions (declarations a la fin)

void viderF(File_* ff){	
    while ( ! fileVide(*ff) )
		defiler(ff);
}

// routine : transfert d'une File dans une autre 
// (utile pour certaines fonctions calculables mais pas utilisee dans le main)
void transfererFF(File_* ff1, File_* ff2)
{
	
}

int tailleF(File_ *ff)
{
 	return 0;
}

void afficherF(File_* ff)
{
    File_ f2;
	creerFile(&f2);

	while (!fileVide(*ff))
	{
		enfiler(&f2, ff->deb->val);	
		defiler(ff);
	}
	while (!fileVide(f2))
	{
		enfiler(ff, f2.deb->val);
		affichage(ff->fin->val);	
		defiler(&f2);
	}
}

void inverserF(File_* ff)
{
 	
}
