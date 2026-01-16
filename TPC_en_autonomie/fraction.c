#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"


void afficher(fraction_t f)
{
    printf("%d/%d\n", f.numerateur, f.denominateur);
}

fraction_t multiplier(fraction_t f1,fraction_t f2)
{
    fraction_t res;

    res.numerateur = f1.numerateur*f2.numerateur;
    res.denominateur = f1.denominateur*f2.denominateur;

    return res;
}