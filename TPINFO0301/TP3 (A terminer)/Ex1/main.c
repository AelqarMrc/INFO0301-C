#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somme1(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else
    {
        return 1 + (somme1(a, b-1));
    }
}
int somme2(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else
    {
        return (somme1(a+1, b-1));
    }
}





int main(void)
{
    int a = 155,b = 240;
    clock_t debut,fin;
    debut = clock();
    for (int i = 0; i < 1<<20; i++)
    {
        somme1(a,b);
    }
    fin = clock();
    double temps = (fin - debut +0.0)/CLOCKS_PER_SEC;
    printf("%lf\n", temps);
    
    return EXIT_SUCCESS;
}