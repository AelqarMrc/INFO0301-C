#include <stdio.h>


int max(int a,int b)
{     
    int max;
    if (a<=b)
    {
        max = b;
    }
    else
    {
        max = a;
    }
    
    return max;
}

int min(int a,int b)
{     
    int min;
    if (a<=b)
    {
        min = a;
    }
    else
    {
        min = b;
    }
    
    return min;
}