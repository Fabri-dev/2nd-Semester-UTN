#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDoble.h"


nodoDoble*inicListaDoble()
{
    return NULL;
}

nodoDoble*crearNodoDoble(stCliente aux)
{
    nodoDoble*nuevoNodo=(nodoDoble*)malloc(sizeof(nodoDoble));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    return nuevoNodo;
}

nodoDoble*buscarUltimoNodoDoble(nodoDoble*listaD)
{
    if(listaD != NULL)
    {
        while(listaD->siguiente != NULL)
        {
            listaD=listaD->siguiente;
        }
    }
    return listaD;
}

nodoDoble*agregarAlPpioDoble(nodoDoble*listaD,nodoDoble*nuevoNodo)
{
    nuevoNodo->siguiente=listaD;
    if(listaD!= NULL)
    {
        listaD->anterior=nuevoNodo;
    }
    return nuevoNodo;
}

nodoDoble*agregarAlFinalDoble(nodoDoble*listaD,nodoDoble*nuevoNodo)
{

    if(listaD != NULL)
    {
        nodoDoble*aux=buscarUltimoNodoDoble(listaD);
        aux->siguiente=nuevoNodo;
    }
    else
    {
        listaD=nuevoNodo;
    }


    return listaD;
}

nodoDoble*agregarOrdenadoDobleXCantidadFacturasMenorAMayor(nodoDoble*listaD,nodoDoble*nuevoNodo)
{
    if(listaD != NULL)
    {
        if(listaD->dato.cantidadFacturas > nuevoNodo->dato.cantidadFacturas)
        {

            listaD=agregarAlPpioDoble(listaD,nuevoNodo);
        }
        else
        {
            nodoDoble*ante=listaD;
            nodoDoble*seg=listaD->siguiente;

            while(seg != NULL && seg->dato.cantidadFacturas < nuevoNodo->dato.cantidadFacturas)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->anterior=ante;
            nuevoNodo->siguiente=seg;
            if(seg != NULL)
            {
                seg->anterior=nuevoNodo;
            }
        }
    }
    else
    {
        listaD=nuevoNodo;
    }

    return listaD;
}

void mostrarListaDoble(nodoDoble*listaD)
{
    if(listaD == NULL)
    {
        puts("Lista vacia");
    }

    while(listaD != NULL)
    {
        mostrarCliente(listaD->dato);
        listaD=listaD->siguiente;
    }
}

int contarListaDoble(nodoDoble*listaD)
{
    int cont=0;

    while(listaD != NULL)
    {
        cont++;
        listaD=listaD->siguiente;
    }

    return cont;
}


