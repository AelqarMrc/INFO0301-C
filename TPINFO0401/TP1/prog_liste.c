#include "cellule.h"
#include "liste.h"
#include "stdio.h"
#include "stdlib.h"

void afficher_cellule(cellule c){
    printf("id_sommet : %d - pred : %p - succ : %p\n", c.id_sommet, c.pred, c.succ);
}

int main(void)
{
    liste l;

    printf("*** Creation d'une liste vide ***\n");
    initialiser_liste(&l);
    printf("tete /\n");

    printf("*** Ajout de 4 sommets ***\n");
    printf("\n");
    
    for (int i = 0; i < 4; i++)
    {
        printf("Entrez l'indice du sommet : ");
        cellule* c1 = malloc(sizeof(cellule));
        initialiser_cellule(c1, 0);
        scanf("%d", &(c1->id_sommet));
        printf("\n");
        inserer_liste(&l,c1);    
        printf("%p\n", l.tete);
    }


    printf("*** Affichage de la liste obtenue ***\n");
    printf("\n");
    afficher_liste(l);

}