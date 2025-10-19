#include "Cellule.h"
#include "ListeC.h"
#include "ListeC_Ch.h"
#include "stdlib.h"


/// 
/// Creation et Liberation 
///
void creationListe(ListeC *l)
{
    l = malloc(sizeof(cellule));
    l -> deb = NULL;
    l -> crt = NULL;
    l -> fin = NULL;
}

void liberationListe(ListeC *l)
{
    if (ListeCVide(*l))
    return ;
    else
    {
        allerFin(l);
        supprimer(l);
        liberationListe(l);
    }      
}

/// 
/// Consultations
/// 
int estDebut(ListeC l)
{
   return (l.crt == NULL);
}

int estFin(ListeC l)
{
    return (l.crt == l.crt);
}

int ListeCVide(ListeC l)
{
    return (l.deb==l.fin)&&(l.crt==NULL);  
}

Element valeurCourante(ListeC l)
{
    return l.crt->svt->val;
}

/// 
/// Deplacements
///
void allerDebut(ListeC *l)
{
    l->crt = NULL;   
}

void allerFin(ListeC *l)
{
    if(ListeCVide(*l) || estFin(*l))
        return ;
    else
    {
        avancer(l);
        allerFin(l);
    }
}

void avancer(ListeC *l)
{
    if(l->crt == NULL)
        l->crt = l->deb;
    else if(estFin(*l))
        allerDebut(l);
    else 
        l->crt = l->crt->svt;
}

/// 
/// Actions
///
void inserer(ListeC *l, Element e)
{
    cellule *tmp = malloc(sizeof(cellule));
    nouvelleCellule(e, tmp);
    if (l->crt == l->fin)
    {
        l->fin->svt = tmp;
        l->fin = tmp;
        l->crt = tmp;   //maj de la position de la fin et de la cellule courante
    }
    else
    {
        tmp -> svt = l->crt->svt;
        l->crt->svt = tmp;
        l->crt = tmp;  // mise à jour de la position du curseur
    }
}

void supprimer(ListeC *l)
{
    if (ListeCVide(*l))
        return ;
    cellule *tmp;
    tmp = l->crt->svt;
    l->crt->svt = l->crt->svt->svt;
    free(tmp);
}