#ifndef PLATEAUHANOI_H
#define PLATEAUHANOI_H
#include "PileTSEnt.h"

typedef struct 
{
    int nbD;
    Pile pile[3];

}plateauHanoi;

void creerPlH(plateauHanoi*);
int finiPlH(plateauHanoi);
void deplacerPlH(plateauHanoi*, int i, int j);
void afficherPlH(plateauHanoi);


#endif