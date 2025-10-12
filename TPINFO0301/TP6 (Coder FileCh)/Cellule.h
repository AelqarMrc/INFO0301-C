#ifndef __CELLULE_H__
#define __CELLULE_H__
#include "Element.h"

typedef struct xcell {
    Element val;
    struct xcell* svt;
} cellule;

cellule* nouvelleCellule(Element, cellule*);

#endif
