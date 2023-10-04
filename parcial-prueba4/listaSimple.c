#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "listaSimple.h"

//1. Crear una lista enlazada de números enteros positivos al azar, la
//inserción se realiza por el último nodo.

nodoS*inicLista()
{
    return NULL;
}

int preguntarDato()
{
    int dato=0;
    printf("Ingrese el dato: ");
    scanf("%i",&dato);
    return dato;
}

nodoS* crearNodoSimple(int datoN)
{
    nodoS*nuevoNodo=(nodoS*)malloc(sizeof(nodoS));
    nuevoNodo->dato=datoN;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoS*agregarAlPpio(nodoS*lista,nodoS*nuevoNodo)
{
    nuevoNodo->siguiente=lista;
    return nuevoNodo;
}

nodoS*agregarAlFinal(nodoS*listaS, nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {
        nodoS*ante=listaS;
        nodoS*seg=listaS->siguiente;
        while(seg != NULL)
        {
            ante=seg;
            seg=seg->siguiente;
        }
        ante->siguiente=nuevoNodo;

    }
    else
    {
        listaS=nuevoNodo;
    }


    return listaS;
}

void mostrarDato(int aux)
{
    printf("Dato: %i\n",aux);
    puts("---------------------------------");
}

void mostrarLista(nodoS*listaS)
{
    while(listaS != NULL)
    {
        mostrarDato(listaS->dato);
        listaS=listaS->siguiente;
    }
}

void mostrarListaRecursivo(nodoS*listaS)
{
    if(listaS != NULL)
    {
        mostrarListaRecursivo(listaS->siguiente);
        mostrarDato(listaS->dato);
    }
}

int contarNodos(nodoS*lista)
{
    int cont=0;
    while(lista != NULL)
    {
        cont++;
        lista=lista->siguiente;
    }
    return cont;
}

nodoS*eliminarNodoXposicion(nodoS*listaS, int posicion)
{
    int max=contarNodos(listaS);
    if(posicion <= max)
    {
        nodoS*ante=listaS;
        nodoS*seg=listaS;

        if(posicion == 1)
        {
            seg=seg->siguiente;
            listaS=seg;
            free(ante);
        }
        else
        {
            while(posicion > 1)
            {
                ante=seg;
                seg=seg->siguiente;
                posicion--;
            }
            ante->siguiente=seg->siguiente;
            free(seg);
        }

    }
    else
    {
        puts("Pos invalida");
    }
    return listaS;
}





nodoS*eliminarNodosMayores(nodoS*listaS,int valor)
{
    if(listaS != NULL)
    {
        nodoS*ante=listaS;
        nodoS*seg=listaS;
        nodoS*aux=listaS;
        while(seg != NULL)
        {
            if(listaS->dato > valor)
            {

                listaS=listaS->siguiente;
                free(aux);
            }
            else if(seg->dato > valor)
            {
                ante->siguiente=seg->siguiente;
                aux=seg;
                seg=seg->siguiente;
                free(aux);
            }
            else
            {
                ante=seg;
                seg=seg->siguiente;
            }
        }
    }
    else
    {
        puts("Lista vacia");
    }


    return listaS;
}

nodoD*crearNodoDoble(int aux)
{
    nodoD*nuevoNodo=(nodoD*)malloc(sizeof(nodoD));
    nuevoNodo->dato=aux;
    nuevoNodo->anterior=NULL;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoD*agregarAlPpioDoble(nodoD*listaD,nodoD*nuevoNodo)
{
    nuevoNodo->siguiente=listaD;
    if(listaD != NULL)
    {
        listaD->anterior= nuevoNodo;
    }
    return nuevoNodo;
}

nodoD*agregarOrdenadoDoble(nodoD*listaD,nodoD*nuevoNodo)
{
    if(listaD != NULL)
    {
        if(nuevoNodo->dato < listaD->dato)
        {
            listaD=agregarAlPpio(listaD,nuevoNodo);
        }
        else
        {
            nodoD*ante=listaD;
            nodoD*seg=listaD->siguiente;
            while(seg!= NULL && seg->dato > nuevoNodo->dato)
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

nodoD*simpleToDoble(nodoD*listaD,nodoS**listaS)
{
    while(*listaS != NULL)
    {
        nodoS*aux=*listaS;
        listaD=agregarOrdenadoDoble(listaD,crearNodoDoble((*listaS)->dato));

        *listaS=(*listaS)->siguiente;
        free(aux);
    }
    return listaD;
}

void mostrarListaDoble(nodoD*listaD)
{
    while(listaD != NULL)
    {
        mostrarDato(listaD->dato);
        listaD=listaD->siguiente;
    }
}
