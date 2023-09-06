#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas2.h"

stPersona crearPersona()
{
    stPersona aux;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s",&aux.nombre);

    printf("Ingrese la edad: ");
    scanf("%i",&aux.edad);

    return aux;
}

void mostrarPersona(stPersona aux)
{
    printf("Nombre: %s \n",aux.nombre);
    printf("Edad: %i \n",aux.edad);

}
nodo2* inicLista()
{
    return NULL;
}

nodo2* crearNodoDoble(stPersona aux)
{

    nodo2*nuevoNodo=(nodo2*)malloc(sizeof(nodo2));

    nuevoNodo->dato=aux;

    nuevoNodo->sig=NULL;
    nuevoNodo->ant=NULL;

    return nuevoNodo;
}

nodo2* agregarAlPpio(nodo2* lista,nodo2* nuevoNodo)
{

    nuevoNodo->sig = lista;
    if(lista != NULL)
        lista->ant = nuevoNodo;

    return nuevoNodo;
}

nodo2*agregarAlFinal(nodo2 *lista,nodo2*nuevoNodo)
{

    if(lista == NULL)
        lista=nuevoNodo;
    else
    {
        nodo2 * ulti = buscarUltimoNodo(lista);
        printf("\nUltimo buscado\n");
        ulti->sig = nuevoNodo;
        nuevoNodo->ant = ulti;
        printf("Enlazado");
    }

    return lista;
}

nodo2* buscarUltimoNodo(nodo2* lista)
{
        while(lista!=NULL&&lista->sig !=NULL)
            lista = lista->sig;

    return lista;
}

nodo2* agregarEnOrdenXedad(nodo2* lista,nodo2* nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else if(nuevoNodo->dato.edad<lista->dato.edad)
    {
        lista = agregarAlPpio(lista,nuevoNodo);
    }
    else
    {
        nodo2* seg = lista->sig;
        nodo2* ante = seg;

        while(seg != NULL && seg->dato.edad < nuevoNodo->dato.edad)
        {
            ante=seg;
            seg=seg->sig;
        }
        ante->sig=nuevoNodo;
        nuevoNodo->ant=ante;
        nuevoNodo->sig = seg;
        if(seg !=NULL)
        {
            nuevoNodo->sig = seg->ant;
        }
    }

    return lista;
}

void mostrarLista(nodo2*lista)
{
    int i=0;
    if(lista != NULL)
    {
        while(lista != NULL)
        {
            printf("-----------(NODO: %i)---------------\n",i);
            mostrarPersona(lista->dato);
            lista=lista->sig;
            i++;
        }
    }
    else
    {
        puts("La lista esta vacia");
    }
}

nodo2* cargarListaDoble(nodo2*lista)
{
    char op;
    stPersona aux;
    nodo2* nuevoNodo=NULL;
    do
    {

        lista=agregarAlFinal(lista,crearNodoDoble(crearPersona()));

        printf("Desea seguir cargando la lista? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    while(op=='s' || op=='S');

    return lista;
}


int verificarSiExisteNombre(nodo2*lista,char nombre[])
{
    int flag=0;
    while(lista != NULL && flag==0)
    {
        lista=lista->sig;
        if(strcmpi(lista->dato.nombre,nombre)==0)
        {
            flag=1;
        }
    }

    if(flag == 0 )
    {
        puts("El nombre buscado no existe en la lista");
    }

    return flag;
}

nodo2* borrarNodo(nodo2*lista, char nombre[])
{
    if(lista == NULL)
    {
        puts("La lista esta vacia");
    }
    else
    {
        nodo2*antes=lista;
        nodo2*seg=lista->sig;
        if(strcmpi(lista->dato.nombre,nombre)==0)
        {
            lista=seg;
            if(lista!= NULL)
            {
                lista->ant=NULL;
            }
            free(antes);

        }
        else
        {
            while(seg != NULL && strcmpi(lista->dato.nombre,nombre)!=0)
            {
                antes=seg;
                seg=seg->sig;
            }

            if(seg != NULL)
            {
                antes->sig=seg->sig;
                seg->ant=antes;
                free(seg);
            }
            else
            {
                puts("No se encontro el nombre");
            }


        }
    }

    return lista;
}


