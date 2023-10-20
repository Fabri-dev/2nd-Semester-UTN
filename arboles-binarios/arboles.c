#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

int preguntarDato()
{
    int dato=0;
    printf("Ingrese un dato: ");
    scanf("%i",&dato);
    return dato;
}

nodoArbol*inicArbol()
{
    return NULL;
}

nodoArbol*crearNodoArbol(int aux)
{
    nodoArbol*nuevoNodo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevoNodo->dato=aux;
    nuevoNodo->derecha=NULL;
    nuevoNodo->izquierda=NULL;
    return nuevoNodo;
}

nodoArbol*insertarNodo(nodoArbol*raiz,nodoArbol*nuevoNodo)
{
    if(raiz != NULL)
    {
        if(nuevoNodo->dato < raiz->dato)
        {
            raiz->izquierda=insertarNodo(raiz->izquierda,nuevoNodo);
        }
        else
        {
            raiz->derecha=insertarNodo(raiz->derecha,nuevoNodo);
        }
    }
    else
    {
        raiz=nuevoNodo;
    }
    return raiz;
}

void mostrarPreOrder(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        printf("%i ",raiz->dato);
        mostrarPreOrder(raiz->izquierda);
        mostrarPreOrder(raiz->derecha);
    }
}

void mostrarInOrder(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        mostrarInOrder(raiz->izquierda);
        printf("%i ",raiz->dato);
        mostrarInOrder(raiz->derecha);
    }
}

void mostrarPostOrder(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        mostrarPostOrder(raiz->izquierda);
        mostrarPostOrder(raiz->derecha);
        printf("%i ",raiz->dato);
    }
}


int contarHojas(nodoArbol*raiz)
{
    int cont=0;
    if(raiz != NULL)
    {

        if(raiz->izquierda == NULL && raiz->derecha == NULL)
        {
            printf("no hay nada \n");
            cont=1;
        }
        else
        {
            if(raiz->izquierda != NULL)
            {
                printf("Me movi a la izquierda \n");
                cont+=contarHojas(raiz->izquierda);
            }
            if(raiz->derecha != NULL)
            {
                printf("Me movi a la derecha \n");
                cont+=contarHojas(raiz->derecha);
            }

        }
    }
    return cont;
}

int contarNodosGradoUno(nodoArbol*raiz) // es mejorable pero es lo que me salio
{
    int cont=0;
    if (raiz != NULL)
    {
        if((raiz->izquierda == NULL && raiz->derecha != NULL) || (raiz->izquierda != NULL && raiz->derecha == NULL))
        {
            cont=1;
        }


        if(raiz->izquierda != NULL)
        {
            cont+=contarNodosGradoUno(raiz->izquierda);
        }
        if(raiz->derecha != NULL)
        {
            cont+=contarNodosGradoUno(raiz->derecha);
        }
    }

    return cont;
}

int buscarDatoEnArbol(nodoArbol*raiz,int datoBuscar)
{
    int flag=0;
    if(raiz != NULL)
    {
        if(datoBuscar == raiz->dato)
        {
            flag=1;
        }
        else
        {
            if(datoBuscar < raiz->dato)
            {
                flag=buscarDatoEnArbol(raiz->izquierda,datoBuscar);
            }
            else
            {
                flag=buscarDatoEnArbol(raiz->derecha,datoBuscar);
            }
        }
    }



    return flag;
}

int buscarDatoEnArbolPro(nodoArbol*raiz,int datoBuscar)
{
    return raiz ? ( (raiz->dato == datoBuscar)? 1 : (datoBuscar < raiz->dato) ? buscarDatoEnArbolPro(raiz->izquierda,datoBuscar): buscarDatoEnArbolPro(raiz->derecha,datoBuscar) ): 0;
}
