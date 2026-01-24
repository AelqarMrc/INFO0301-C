#include "cellule.h"
#include "liste.h"
#include "stdlib.h"
#include "stdbool.h"
#include "graphe.h"
#include "stdio.h"
#define TAILLE 10

void initialiser_graphe(graphe **g, const char* nomFichier){

    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir %s\n", nomFichier);
        return ;
    }
    *g = malloc(sizeof(graphe));
    if (*g == NULL)
    {
        fclose(fichier);
        return ;
    }
    
    char zbib[21];
    int bool_zbib;
 
    // initialisation du graphes jusqu'a nb_aretes

    fscanf(fichier, "%s %zu", zbib, &(*g)->n_sommets);
    fscanf(fichier, "%s %d", zbib, &bool_zbib);
    (*g)->n_aretes = (bool)bool_zbib;
    fscanf(fichier, "%s %d", zbib, &bool_zbib);
    (*g)->value = (bool)bool_zbib;
    (*g)->n_aretes = 0;
    

    // initlalisation liste d'adjacence
    liste *l[TAILLE];
    (*g)->l_adj = *l;
    
    
    for (size_t i = 0; i < TAILLE; i++)
    {
        cellule c;
        initialiser_cellule(&c, i+1);
        initialiser_liste((l[i]));
        inserer_liste((l[i]), &c);
        afficher_liste(*(l[i]));
    }
    

    fclose(fichier);
}

void afficher_graphe(graphe *g){
    printf("Graphe initialise : %zu sommets, Oriente: %d, Value: %d\n", g->n_sommets, g->oriente, g->value);
}

