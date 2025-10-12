#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <time.h>
#include "point.h"
#include "tab_point.h"


int main(void)
{
    srand(time(NULL));
    Point a, b;
    remplir(&a);
    remplir(&b);
   

    afficher(a);
    afficher(b);
}
