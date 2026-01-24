#include "../.h/cellule.h"
#include "../.h/liste.h"
#include "stdlib.h"
#include "stdbool.h"
#include "../.h/graphe.h"
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
    (*g)->l_adj = malloc(sizeof(liste[TAILLE]));
    liste *l = (*g)->l_adj;
    
    
    for (size_t i = 0; i < TAILLE; i++)
    {
        cellule c;
        initialiser_cellule(&c, i+1);
        initialiser_liste(&(l[i]));
        printf("zbib\n");
        inserer_liste(&(l[i]), &c);
        afficher_liste((l[i]));
    }
    

    fclose(fichier);
}

void afficher_graphe(graphe *g){
    printf("Graphe initialise : %zu sommets, Oriente: %d, Value: %d\n", g->n_sommets, g->oriente, g->value);
}

