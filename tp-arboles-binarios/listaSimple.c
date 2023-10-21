#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"


nodoS*inicLista()
{
    return NULL;
}

nodoS*crearNodoLista(stPersona aux)
{
    nodoS*nuevoNodo=(nodoS*)malloc(sizeof(nodoS));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoS*agregarAlFinalLista(nodoS*listaS,nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {
        nodoS*seg=listaS;
        while(seg->siguiente != NULL)
        {
            seg=seg->siguiente;
        }
        seg->siguiente=nuevoNodo;
    }
    else
    {
        listaS=nuevoNodo;
    }
    return listaS;

}


nodoS*arbolToListaSimple(nodoArbol*raiz,nodoS*listaS)
{
    if(raiz != NULL)
    {

        listaS=agregarAlFinalLista(listaS,crearNodoLista(raiz->dato));
        listaS=arbolToListaSimple(raiz->derecha,listaS);
        listaS=arbolToListaSimple(raiz->izquierda,listaS);
    }



    return listaS;
}


void mostrarListaSimple(nodoS*listaS)
{
    while(listaS != NULL)
    {
        mostrarPersona(listaS->dato);
        listaS=listaS->siguiente;
    }
}
