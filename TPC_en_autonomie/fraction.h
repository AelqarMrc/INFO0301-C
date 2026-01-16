#ifndef FRACTION_H
#define FRACTION_H

typedef struct
{
    int numerateur;
    int denominateur;
}fraction_t;

extern void afficher(fraction_t);
fraction_t multiplier(fraction_t f1, fraction_t f2);

#endif 