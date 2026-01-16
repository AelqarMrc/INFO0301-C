#include "cellule.h"
#include "stdlib.h"

void initialiser_cellule(cellule* c, int id) {
    c -> pred = NULL;
    c -> succ = NULL;
    c -> id_sommet = id;
}