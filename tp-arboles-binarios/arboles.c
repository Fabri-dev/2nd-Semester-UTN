#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"


nodoArbol*inicArbol()
{
    return NULL;
}

stPersona crearUnaPersona()
{
    stPersona aux;
    printf("Ingrese el nro. de legajo: ");
    scanf("%i",&aux.legajo);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s",&aux.nombre);

    printf("Ingrese la edad: ");
    scanf("%i",&aux.edad);

    return aux;
}

nodoArbol*crearNodoArbol(stPersona aux)
{
    nodoArbol*nuevoNodo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevoNodo->dato=aux;
    nuevoNodo->derecha=NULL;
    nuevoNodo->izquierda=NULL;
    return nuevoNodo;
}

nodoArbol*ingresarXLegajo(nodoArbol*raiz,nodoArbol*nuevoNodo)
{
    if(raiz != NULL)
    {
        if(nuevoNodo->dato.legajo < raiz->dato.legajo)
        {
            raiz->izquierda=ingresarXLegajo(raiz->izquierda,nuevoNodo);
        }
        else
        {
            raiz->derecha=ingresarXLegajo(raiz->derecha,nuevoNodo);
        }
    }
    else
    {
        raiz=nuevoNodo;
    }

    return raiz;
}

nodoArbol* ingresarMuchosNodosXLegajo(nodoArbol*raiz)
{
    char op;
    do
    {

        raiz=ingresarXLegajo(raiz,crearNodoArbol(crearUnaPersona()));

        printf("Desea seguir cargando nodos? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }while(op=='s' || op=='S');
    return raiz;
}


void mostrarPersona(stPersona aux)
{
    printf("El legajo es: %i \n",aux.legajo);
    printf("El nombre es: %s \n",aux.nombre);
    printf("La edad es: %i \n",aux.edad);
    puts("---------------------------------");
}

void mostrarInorder(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        mostrarInorder(raiz->izquierda);
        mostrarPersona(raiz->dato);
        mostrarInorder(raiz->derecha);
    }
}

void mostrarPreorder(nodoArbol*raiz)
{
        if(raiz != NULL)
    {
        mostrarPersona(raiz->dato);
        mostrarInorder(raiz->izquierda);
        mostrarInorder(raiz->derecha);
    }
}

void mostrarPostorder(nodoArbol*raiz)
{
        if(raiz != NULL)
    {
        mostrarInorder(raiz->izquierda);
        mostrarInorder(raiz->derecha);
        mostrarPersona(raiz->dato);
    }
}
