#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"

int main()
{
    char op;
    int opsw,dato=0;
    nodoArbol*raiz=inicArbol();
    nodoS*listaSimple=inicLista();
    stPersona aux;
    char*auxStr;
    do
    {
        puts("1. Ingresar nodo a un arbol");
        puts("2. Mostrar preorder");
        puts("3. Mostrar inorder (menor a mayor)");
        puts("4. Mostrar postorde");
        puts("5. Arbol to Lista");
        puts("6. Mostrar Lista");
        puts("7. Buscar persona x legajo en Arbol");
        puts("8. Buscar persona x nombre en Arbol");
        puts("9. Calcular niveles de arbol");
        puts("10. ");
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
            listaSimple=arbolToListaSimple(raiz,listaSimple);
            mostrarListaSimple(listaSimple);
            break;
        case 6:
            mostrarListaSimple(listaSimple);
            break;
        case 7:
            aux=buscarUnaPersonaXLegajoVerificado(raiz,preguntarDatoEntero());
            break;
        case 8:
            printf("Ingrese el nombre que quiere buscar(15 caracteres max.): ");
            fflush(stdin);
            scanf("%s",&auxStr);
            aux=buscarUnaPersonaXNombreVerificado(raiz,auxStr);
            break;
        case 9:
            dato=calcularAlturaArbol(raiz,0);
            printf("El numero de niveles que tiene el arbol es: %i \n",dato);
            break;
        case 10:
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
