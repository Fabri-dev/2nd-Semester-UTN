#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXDIM 10

int main()
{
    int *punta, *puntb;
int x=7;
int y=5;
punta=&x;
*punta=3;
puntb=&y;
*puntb=x;
x=9;
puntb=punta;
printf("%d, %d",*puntb, y);

    return 0;
}
