#ifndef POINT_H
#define POINT_H
#define MAX 100

typedef struct
{
    double x, y;
}Point;

void remplir();
void afficher(Point a);
double distance(Point a, Point b);
double extremites(Point a);
double tri(Point a);

#endif 