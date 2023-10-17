#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"

nodoSimple*inicListaSimple()
{
    return NULL;
}

stCliente crearClienteAutomatico(char*nombresClientes[])
{
    stCliente aux;
    strcpy(aux.nombreCliente,nombresClientes[rand()%40]);
    aux.cantidadFacturas= 1 + rand()%50;
    aux.tipoCliente= 1 + rand()%4;
    return aux;
}

void mostrarCliente(stCliente aux)
{
    printf("Nombre del cliente: %s \n",aux.nombreCliente);
    printf("Tipo de cliente: %i \n",aux.tipoCliente);
    printf("Cantidad de facturas: %i \n",aux.cantidadFacturas);
    puts("-------------------------------");
}



nodoSimple*crearNodoSimple(stCliente aux)
{
    nodoSimple*nuevoNodo=(nodoSimple*)malloc(sizeof(nodoSimple));

    nuevoNodo->siguiente=NULL;
    nuevoNodo->dato=aux;

    return nuevoNodo;
}

nodoSimple*buscarUltimoNodoSimple(nodoSimple*listaS)
{
    if(listaS != NULL)
    {

        while(listaS->siguiente != NULL)
        {
            listaS=listaS->siguiente;
        }
    }

    return listaS;
}

nodoSimple*agregarAlFinalSimple(nodoSimple*listaS, nodoSimple*nuevoNodo)
{
    if(listaS != NULL)
    {
        nodoSimple*seg=buscarUltimoNodoSimple(listaS);
        seg->siguiente=nuevoNodo;
    }
    else
    {
        listaS=nuevoNodo;
    }
    return listaS;
}

void mostrarListaSimple(nodoSimple*listaS)
{
    if(listaS == NULL)
    {
        puts("Lista vacia");
    }

    while(listaS != NULL)
    {
        mostrarCliente(listaS->dato);
        listaS=listaS->siguiente;
    }
}


void borrarPrimeroSimple(nodoSimple**listaS)
{
    if((*listaS) != NULL)
    {
        nodoSimple*aux=(*listaS);
        (*listaS)=(*listaS)->siguiente;
        free(aux);
    }
}








