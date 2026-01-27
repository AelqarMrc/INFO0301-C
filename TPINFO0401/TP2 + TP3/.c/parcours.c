#include "../.h/cellule.h"
#include "../.h/liste.h"
#include "stdlib.h"
#include "stdbool.h"
#include "../.h/graphe.h"
#include "../.h/parcours.h"
#include "../.h/COULEUR.h"
#include "stdio.h"
#include "string.h"

void parcours_largeur(graphe* g, int id_som)
{
    // Initialisation d'un tab de sommet et allocation
    sommet_parc_larg **ts = malloc(sizeof(sommet_parc_larg*[g->n_sommets]));
    for (size_t i = 0; i < g->n_sommets; i++)
    {
        sommet_parc_larg *s = malloc(sizeof(sommet_parc_larg));
        s->distance = 0;
        s->pere = NULL;
        s->couleur = BLANC;
        ts[i] = s;
    }
    

}