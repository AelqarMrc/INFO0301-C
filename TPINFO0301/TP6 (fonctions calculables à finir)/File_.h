#ifndef FILE_H
#define FILE_H
#include "Element.h"

    typedef struct xFile_ File_;

    void creerFile(File_*);
    int fileVide(File_);
    Element tete(File_);
    void enfiler(File_*, Element);
    void defiler(File_*);


#endif 