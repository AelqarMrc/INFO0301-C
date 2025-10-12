#include <stdio.h>
#include <stdlib.h>
#include "temps.h"

temps creer(int h, int m, double s)
{
    temps t = {h,m,s};
    return t;
}

temps normaliser(temps t)
{
    while ((t.m >= 60) || (t.s) >= 60)
    {
        if (t.s >= 60)
        {
            t.m += 1;
            t.s -= 60;
        }
        else if (t.m >= 60)
        {
            t.h += 1;
            t.m -= 60;
        }
    }
    return t;
}

temps creer2(void)
{
    int h,m;
    double s;
    
    printf("donne moi la valeur de h : ");
    scanf("%d", &h);
    printf("donne moi la valeur de m : ");
    scanf("%d", &m);
    printf("donne moi la valeur de s : ");
    scanf("%lf", &s);
    temps t = {h,m,s};

    return t;
}

void afficher(temps t)
{
    printf("heure : %d:%d:%.lf\n", t.h, t.m, t.s);
}

void saisir(temps *pt)
{
    printf("donne moi la valeur de h : ");
    scanf("%d", &pt->h);
    printf("donne moi la valeur de m : ");
    scanf("%d", &pt->m);
    printf("donne moi la valeur de s : ");
    scanf("%lf", &pt->s);
}