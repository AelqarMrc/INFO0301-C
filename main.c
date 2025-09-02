#include <stdio.h>

int main(void)
{

    int a,b;
    printf("Donnez la hauteur du rectangle : ");
    scanf("%d", &a);
    printf("Donnez la largeur du rectangle : ");
    scanf("%d", &b);
    
   /* printf("\n");
    fflush(stdout); */             //Le bout de code qui pose probleme
 

    void rectangle(a,b)     //Dessine sur la console un rectangle d'etoiles
    {
        for(int i; i<a; i++)        //nombre de lignes d'etoiles (hauteur)
        {
            for(int j = 0; j<b; j++)       //nombre d'etoiles sur la ligne (largeur)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    rectangle(a,b);

    return 0;
}