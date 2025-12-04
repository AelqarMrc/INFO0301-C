/* Ch Jaillet
 * Info0302 : tables de hachage, par chainage
 * fichier : TH_principal.c
 *******************
 */
 
#include "Key.h"
#include "TH_ch.h"
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
// deux fonctions bien pratiques ("calculables ?")
// vous pouvez les mettre dans TH_ch.h+c

void afficher(TH x) {	
	printf("contenu : \t");
	// pour verifier que "ca compile", mettez cette ligne en commentaire
	printf("\n");
}

void vider(TH* px) {
	// pour verifier que "ca compile", mettez cette ligne en commentaire
}

//////////////////////
// Et maintenant ? (tatatata !)

int main(void) {
	TH x;
	Element2p* p;
	int i;
	TH_initialiser(&x);  // chaque LR vide
debug("creation OK");	
	afficher(x);
debug("affichage a vide OK");	
	TH_inserer(&x, 5141);
	afficher(x);
debug("aff apres insertion 5141 (OK ?)");	
	TH_inserer(&x, 8520);
	afficher(x);
debug("aff apres insertion 8520 (OK ?)");	
	for(i=3; i<=4 ; i++){
        TH_inserer(&x, 340*i);
        afficher(x);
debug("OK (?) apres chacune des 2 nouvelles insertions");	
    }

debug("=====================");	
debug("recherche de 0");	
	p = TH_rechercher(x, 0); printf("%p\n", p);
debug("recherche de 1020");	
	p = TH_rechercher(x, 1020); printf("%p\n", p);
debug("suppression de 1020");	
	TH_supprimer(&x, p);
debug("affichage apres suppression de 1020");	
	afficher(x);

debug("ajout de 11 et 41 : ");	
	TH_inserer(&x, 11);
	TH_inserer(&x, 41);
	afficher(x);
	
debug("on vide :");	
	vider(&x);
	afficher(x);

	TH_liberer(&x);

	return EXIT_SUCCESS;
}
