#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "temps.h"


int main(void)
{
    temps t,t2;
    int h = 12, m = 50;
    double s = 33;    
    
    t = creer(h,m,s);
    t2 = creer2();
    afficher(t);
    afficher(t2);

    saisir(&t);

    t = normaliser(t);
    afficher(t);


}