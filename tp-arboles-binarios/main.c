#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

int main()
{
    char op;
    int opsw;
    nodoArbol*raiz=inicArbol();
    do
    {
        puts("1. Ingresar nodo a un arbol");
        puts("2. Mostrar preorder");
        puts("3. Mostrar inorder (menor a mayor)");
        puts("4. Mostrar postorde");
        puts("5. ");
        puts("6. ");
        puts("7. ");
        puts("-------------------------------------");
        printf("Ingrese el ejercicio que desea: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            raiz=ingresarMuchosNodosXLegajo(raiz);
            break;
        case 2:
            mostrarPreorder(raiz);
            break;
        case 3:
            mostrarInorder(raiz);
            break;
        case 4:
            mostrarPostorder(raiz);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
        }

        printf("Desea volver al menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }
    while(op == 's' || op=='S');




    return 0;
}
