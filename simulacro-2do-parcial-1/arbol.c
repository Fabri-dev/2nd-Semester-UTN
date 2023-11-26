#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

nodoArbol*inicArbol()
{
    return NULL;
}

nodoArbol*crearNodoArbol(stPelicula auxDato)
{
    nodoArbol*nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato=auxDato;

    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

nodoArbol*ingresarPelicula(nodoArbol* raiz, nodoArbol*nuevoNodo)
{
    if(raiz != NULL)
    {
        if(strcmpi(raiz->dato.nombre,nuevoNodo->dato.nombre) < 0)
        {
            raiz->izq=ingresarPelicula(raiz->izq,nuevoNodo);
        }
        else
        {
            raiz->der=ingresarPelicula(raiz->der,nuevoNodo);
        }
    }
    else
    {
        raiz=nuevoNodo;
    }
    return raiz;
}

void mostrarPreorden(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        mostrarUnaPelicula(raiz->dato);
        mostrarPreorden(raiz->izq);
        mostrarPreorden(raiz->der);
    }
}
