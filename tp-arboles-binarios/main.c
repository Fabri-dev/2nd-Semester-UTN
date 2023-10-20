#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

int main()
{
    char op;
    int opsw;

    do
    {
        puts("1. ");
        puts("2. ");
        puts("3. ");
        puts("4. ");
        puts("-------------------------------------");
        printf("Ingrese el ejercicio que desea: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }

        printf("Desea volver al menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }while(op == 's' || op=='S');




    return 0;
}
