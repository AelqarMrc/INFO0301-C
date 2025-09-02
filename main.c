#include <stdio.h>

void rectangle(int a, int b)     //Dessine sur la console un rectangle d'etoiles
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


void triangle(int x, int y)        //Dessine un triangle d'etoiles
{
    for(int i=1; i<=x; i++)     //nombre de lignes d'etoiles
    {    
        do
        {
            printf("*");
            y++;
        }while(y<i);            //nombre d'etoiles sur la ligne
        y=0;
        printf("\n");
    }
}

int main(void)
{

    int a,b;
    printf("Donnez la hauteur du rectangle : ");
    scanf("%d", &a);                                        // Pour dessiner un rectangle //
    printf("Donnez la largeur du rectangle : ");
    scanf("%d", &b);
    
   /* printf("\n");
    fflush(stdout); */             //Le bout de code qui pose probleme
    
    rectangle(a,b); 

    
/*     int x, y=0;
    printf("Donne moi un nombre : ");       // Pour dessiner un triangle //
    scanf("%d", &x);

    triangle(x,y); */
    
    
    return 0;
}