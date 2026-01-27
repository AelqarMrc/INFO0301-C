#include "../.h/cellule.h"
#include "../.h/liste.h"
#include "stdlib.h"
#include "stdbool.h"
#include "../.h/graphe.h"
#include "stdio.h"


int main()
{
    graphe *G;
    initialiser_graphe(&G, "graphe_12_no_nv_1.txt");
    afficher_graphe(G);

    return EXIT_SUCCESS;
}
