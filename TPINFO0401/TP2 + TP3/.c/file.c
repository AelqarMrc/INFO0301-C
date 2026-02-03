#include "../.h/cellule.h"
#include "../.h/liste.h"
#include "stdlib.h"
#include "stdbool.h"
#include "../.h/graphe.h"
#include "../.h/parcours.h"
#include "../.h/COULEUR.h"
#include "stdio.h"
#include "../.h/file.h"

// Fonction d'initialisation et de destruction 

void initialiser_file(file* f, size_t TAILLE){
    f->queue = -1;
    f->tete = -1;
}

void detruire_file(file* f){
    free(f);
}

// Fonction de consultation 

bool file_vide(file f){
    return f.tete == -1;
}

bool file_pleine(file f){
    return f.tete != -1;
}


// Fonction de modification 

void enfiler(file* f, sommet_parc_larg *s){
    if (file_vide(*f))
    {
        return ; 
    }

    if (file_vide(*f))
    {
        f->tete = 0;
    }
    

    f->queue = (f->queue + 1 )%MAX;
    f->tab_s[f->queue] = s;
}

sommet_parc_larg* defiler(file* f){
    sommet_parc_larg* s= f->tab_s[f->tete];
    free(f->tab_s[f->tete]);
    f->tete += 1;

    return s;
}

// Fonction d'affichage 

void afficher_file(file f){
    
    
}