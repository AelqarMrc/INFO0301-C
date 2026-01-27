#include "../.h/cellule.h"
#include "../.h/liste.h"
#include "stdlib.h"
#include "stdbool.h"
#include "../.h/graphe.h"
#include "stdio.h"
#include "string.h"

void initialiser_graphe(graphe **g, const char* nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir %s\n", nomFichier);
        return;
    }

    *g = malloc(sizeof(graphe));
    char label[50]; // Pour lire les étiquettes comme "n_sommets" ou "oriente"
    int val;

    // 1. Lecture des métadonnées
    fscanf(fichier, "%s %zu", label, &((*g)->n_sommets));
    
    fscanf(fichier, "%s %d", label, &val);
    (*g)->oriente = (bool)val; // Correction ici
    
    fscanf(fichier, "%s %d", label, &val);
    (*g)->value = (bool)val;
    
    (*g)->n_aretes = 0;

    // 2. Initialisation de la liste d'adjacence
    size_t n = (*g)->n_sommets;
    (*g)->l_adj = malloc(n * sizeof(liste));
    for (size_t i = 0; i < n; i++) {
        initialiser_liste(&(*g)->l_adj[i]);
    }

    // 3. Lecture des arêtes
    char buffer[50];
    // On avance jusqu'au début des arêtes
    while (fscanf(fichier, "%s", buffer) != EOF && strcmp(buffer, "DEBUT_DEF_ARETES") != 0);

    // Boucle de lecture des arêtes
    while (fscanf(fichier, "%s", buffer) != EOF && strcmp(buffer, "FIN_DEF_ARETES") != 0) {
        int som1 = atoi(buffer);
        int som2;
        
        if (fscanf(fichier, "%d", &som2) == 1) {
            // ALLOCATION DYNAMIQUE INDISPENSABLE
            cellule *nouvelle = malloc(sizeof(cellule));
            if (nouvelle != NULL) {
                initialiser_cellule(nouvelle, som2);
                inserer_liste(&(*g)->l_adj[som1], nouvelle);
                (*g)->n_aretes++;
                
                // Si le graphe n'est pas orienté, on ajoute l'arête inverse
                if (!(*g)->oriente) {
                    cellule *symetrique = malloc(sizeof(cellule));
                    initialiser_cellule(symetrique, som1);
                    inserer_liste(&(*g)->l_adj[som2], symetrique);
                }
            }
        }
    }

    fclose(fichier);
}

void afficher_graphe(graphe *g){
    int TAILLE = g->n_sommets;
    liste *l = g->l_adj;
    printf("Graphe initialise : %zu sommets, Oriente: %d, Value: %d\n", g->n_sommets, g->oriente, g->value);
    for (size_t i = 0; i < TAILLE; i++)
    {
        afficher_liste(l[i]);
        printf("\n");
    }
    
}

