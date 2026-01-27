#ifndef FILE_H
#define FILE_H
#define MAX 10
#include "stdlib.h"

typedef struct 
{
    sommet_parc_larg *tab_s[MAX];
    int queue;
    int tete;
}file;

void initialiser_file(file*, size_t);
void detruire_file(file*);
void enfiler(file*, sommet_parc_larg*);
sommet_parc_larg* defiler(file*);

#endif // !FILE_H