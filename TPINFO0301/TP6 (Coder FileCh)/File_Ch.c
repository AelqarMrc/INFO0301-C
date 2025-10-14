#include "File_.h"
#include "File_Ch.h"
#include "stdlib.h"

void creerFile(File_ *pf)
{
    pf->deb = NULL;
    pf->fin = NULL;
}

int fileVide(File_ f)
{
    return (f.deb == NULL)&&(f.fin==NULL);
}

Element tete(File_ f)
{
    return f.deb->val;
}

void enfiler(File_ *pf, Element e)
{
    cellule *tmp = malloc(sizeof(cellule));
    tmp->val = e;
    
    if (fileVide(*pf))
    {
        pf->fin = tmp;
        pf->deb = pf->fin;
    }
    else
    {
        pf->fin->svt = tmp;
        pf->fin = tmp;
    }
}

void defiler(File_ *pf)
{
    if (fileVide(*pf))
        return ;
    cellule *tmp;

    if (pf->deb == pf->fin)
    {
        tmp = pf->deb;
        pf->deb = NULL;
        pf->fin = NULL;
    }
    else
    {
        tmp = pf->deb;
        pf->deb = tmp->svt;
    }

    free(tmp);
}