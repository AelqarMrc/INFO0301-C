#ifndef TAP_POINT_H
#define TAP_POINT_H

typedef struct 
{
    int ind1;
    int ind2;
} Indices;


    Indices distMinMax(int * tab, int taille);
    void triDist(int *tab, int taille);


#endif 