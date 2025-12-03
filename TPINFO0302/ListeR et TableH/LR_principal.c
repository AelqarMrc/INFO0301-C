/* Ch Jaillet
 * Info0302 : listes de recherche
 * fichier : LR_principal.c
 *******************
 */
 
#include "Key.h"
#include "LR.h"
#include <stdlib.h>
#include <stdio.h>

//////////////////////
// pour le débuggage
#define dprint  // commenter si inutile
void debug(char* msg) {	
    static int XXX = 0;
	XXX++;
#ifdef dprint
	printf("================ [%d] %s\n", XXX, msg);	
#endif
}	

//////////////////////
// deux fonctions calculables : affichage et vidage

void afficher(LR x) {
	Element2p * p = x;
	printf("contenu : \t");
	while ( p != NULL ) {
		printf("%d ", p->key);
		p = p->svt;
	}
	printf("\n");
}

void vider(LR* px) {
	while( *px != NULL )
		LR_supprimer(px, *px);
}

//////////////////////
// Et maintenant ? (tatatata !)

int main(void) {
	LR x;
	Element2p* p;
	int i;
	x = NULL; // a la place de LR_creer(&x);
debug("creation");	
	afficher(x);
debug("affichage a vide");	
	LR_inserer(&x, 1);
	afficher(x);
	printf("%p\n", x->svt);
debug("aff apres insertion 1");	
	LR_inserer(&x, 2);
	afficher(x);
debug("aff apres insertion 2");	
	for(i=3; i<=4 ; i++){
        LR_inserer(&x, i);
        afficher(x);
debug("OK (?) apres chacune des 2 nouvelles insertions");	
    }

debug("=====================");	
	p = LR_rechercher(x, 5); printf("%p\n", p);
	p = LR_rechercher(x, 3); printf("%p\n", p);
	LR_supprimer(&x, p);
	afficher(x);
	
debug("vidage :");	
	vider(&x);
	afficher(x);

debug("fini !");
	return EXIT_SUCCESS;
}
