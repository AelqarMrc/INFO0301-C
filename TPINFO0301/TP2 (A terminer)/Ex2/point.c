#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "math.h"

void remplir(Point *p)
{
    p -> x = (-3.1) + (5-(3.1) * rand() / RAND_MAX);
    p -> y = (-3.1) + (5-(3.1) * rand() / RAND_MAX);
}

void afficher(Point p)
{
    printf("le Point de coordonnees : (%lf,%lf)\n", p.x, p.y);
}

// double distance(Point a, Point b)
// {
//     double distA = sqrt(a.x*a.x + a.y*a.y);
//     double distB = sqrt(b.x*b.x + b.y*b.y);
//     return distA - distB; 
// }