#ifndef __CELLULE_H__ 
#define __CELLULE_H__ 

typedef struct cellule_type {
	int id_sommet;
	struct cellule_type *pred;
	struct cellule_type *succ;
} cellule;

void initialiser_cellule(cellule*, int);

#endif 