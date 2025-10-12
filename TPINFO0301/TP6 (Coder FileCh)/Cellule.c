#include "Cellule.h"
#include "stdlib.h"

cellule* nouvelleCellule(Element e, cellule *x)
{
    x -> val = e;
    x -> svt = NULL;
    return x;
}
