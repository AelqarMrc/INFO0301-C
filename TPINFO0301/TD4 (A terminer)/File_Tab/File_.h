#ifndef __FILE_H__
#define __FILE_H__


typedef struct xFile_ File_;


void creerFile(File_ *);
int fileVide(File_);
File_ *sommet(File_);
void emfiler(File_ *, Element);
void defiler(File_*);



#endif