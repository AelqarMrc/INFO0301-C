#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int val;
    struct cellule *svt;
}maillon;

void creation (maillon * *p, int fin)
{
    int valeur;
    maillon *courant;
    *p = NULL;
    for (int i = 0; i < fin; i++)
    {
        printf("Donne la valeur de la chaine n°%d : ", i);
        scanf("%d", &valeur);

        courant = (maillon *) malloc (sizeof(maillon));
        courant -> val = valeur;
        
        printf("Maillon n°%d : val = %d\n",i+1, courant->val);
        
        if (i+1 == fin)
            courant -> svt = NULL;
        else
            courant -> svt = *p;
        
        *p = courant;

    }
    printf("%p\n", courant -> svt);

}

int main(void)
{
    maillon *debut;
    creation(&debut, 3);

    return EXIT_SUCCESS;
}