#include "../.h/parcours.h"
#include "../.h/file.h"
#include "stdlib.h"

void initialiser_file(file* f, size_t TAILLE){
    f->queue = -1;
    f->tete = -1;
}

void detruire_file(file* f){
    free(f);
}

void enfiler(file* f, sommet_parc_larg *s){
    if ((f->queue + 1) % MAX == f->tete)
    {
        return ; 
    }

    if (f->tete == -1)
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