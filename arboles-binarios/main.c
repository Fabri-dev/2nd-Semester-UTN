#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"


//1. Mostrar sin desarrollar código: (arbol en la imagen)
//a) El contenido de sus nodos según cada recorrido: preorden, inorden y posorden.

/*  preorden: 8 3 1 6 4 7 10 14 13
    inorden: 1 3 4 6 7 8 10 13 14
    postorden: 1 4 7 6 3 13 14 10 8
*/

//b) Indicar niveles y altura.
/*
    Tiene 4 niveles
*/

int main()
{
    int arr[8]={3,10,1,6,14,4,7,13};
    int validos=8;
    char op;
    int opsw=0,dato=0;

    nodoArbol*raiz=inicArbol();

    raiz=insertarNodo(raiz,crearNodoArbol(8));

    for(int i=0; i < validos; i++)
    {
        raiz=insertarNodo(raiz,crearNodoArbol(arr[i]));
    }

    do
    {

    puts("1. Ingresar un elemento al arbol");
    puts("2. Mostrar en preOrder (raiz a la izquierda del todo)");
    puts("3. Mostrar en inOrder (raiz en el medio)");
    puts("4. Mostrar en postOrder (raiz a la derecha del todo)");
    puts("5. Contar cantidad de nodos terminales (hojas)");
    puts("6. Contar nodos grado 1 (osea que solo tengan un solo nodo)");
    puts("7. Buscar un dato");
    puts("8. Buscar un dato pro");
    puts("9. Buscar numero menor");
    puts("----------------------------------------------------");
    printf("Que desea hacer?: ");
    scanf("%i",&opsw);
    switch(opsw)
    {
    case 1:
        raiz=insertarNodo(raiz,crearNodoArbol(preguntarDato()));
        break;
    case 2:
        mostrarPreOrder(raiz);
        break;
    case 3:
        mostrarInOrder(raiz);
        break;
    case 4:
        mostrarPostOrder(raiz);
        break;
    case 5:
        dato=contarHojas(raiz);
        printf("La cantidad de nodos terminales(hojas) son: %i \n",dato);
        break;
    case 6:
        dato=contarNodosGradoUno(raiz);
        printf("La cantidad de nodos de grado uno son: %i \n",dato);
        break;
    case 7:
        buscarDatoEnArbol(raiz,preguntarDato()) ? printf("Dato encontrado ! \n"):printf("El dato que usted busco no existe \n");

        break;
    case 8:
        buscarDatoEnArbolPro(raiz,preguntarDato()) ? printf("Dato encontrado ! \n"):printf("El dato que usted busco no existe \n");
        break;
    case 9:
        dato=buscarMenor(raiz);
        printf("El numero menor es: %i \n",dato);
        break;
    default:
        break;
    }

        printf("Desea volver al menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }while(op=='s' || op=='S');

    return 0;
}
