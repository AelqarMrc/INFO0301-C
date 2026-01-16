#ifndef __LR_H__ 
#define __LR_H__

typedef struct xElement2p Element2p;

struct xElement2p
{
    Element2p *prec;
    Element2p *svt;
    Key key;
    //Element val;
};


typedef Element2p* LR;

void LR_inserer(LR*, Key);
Element2p* LR_rechercher(LR, Key);
void LR_supprimer(LR*, Element2p*);

#endif 