#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int val;
    struct cellule *svt;
}maillon;

int main(void)
{
    maillon *p = malloc(sizeof(maillon));
    p -> val = 1;
    p-> svt = malloc(sizeof(maillon));
    p -> val = 2;
    p-> svt -> svt = malloc(sizeof(maillon));
    p -> val = 3;
    p-> svt -> svt -> svt = NULL; 
    

    free(p->svt->svt);
    free(p->svt);
    free(p);

    return EXIT_SUCCESS;
}