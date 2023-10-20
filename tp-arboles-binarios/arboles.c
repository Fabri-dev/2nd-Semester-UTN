#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"


nodoArbol*inicLista()
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
