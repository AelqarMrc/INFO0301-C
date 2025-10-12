#ifndef TEMPS_H
#define TEMPS_H

typedef struct temps 
{
    int h,m;
    double s;
}temps;

temps creer(int h, int m, double s);

_Bool correct(temps t);

void afficher (struct temps t);

struct temps normaliser(struct temps);

struct temps creer2(void);

void saisir(struct temps *pt);

#endif 
