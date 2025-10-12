#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibo(n-1) + fibo(n-2); 
    }
}

int main(void)
{
    clock_t debut,fin;
    debut = clock();
    
    int n = 1;
        printf("%d\n",(fibo(n)));
    fin = clock();
    double temps = (fin - debut +0.0)/CLOCKS_PER_SEC;
    printf("%lf\n", temps);
    return EXIT_SUCCESS;
}