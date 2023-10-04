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

        ulti->sig = nuevoNodo;
        nuevoNodo->ant = ulti;

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
        nodo2*siguienteDeSeg = seg->sig;
        if(strcmpi(lista->dato.nombre,nombre)==0)
        {
            if(lista->sig !=NULL){
            lista=seg;
            lista->ant=NULL;
            free(antes);
        }
        }
        else
        {
            while(seg != NULL && strcmpi(seg->dato.nombre,nombre)!=0)
            {
                antes=seg;
                seg=seg->sig;
                siguienteDeSeg = seg->sig;

            }

            if(seg != NULL)
            {
                antes->sig=seg->sig;
                siguienteDeSeg->ant = antes;
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

///Crear una función recursiva que determine si una lista doblemente vinculada es capicúa.
///(Después de ver recursividad - si no, hacer iterativo, NO usar contador)

int devolverCapicua (nodo2* lista,nodo2* ulti)
{

    int flag = 1;

    if(lista!= ulti && lista->sig != ulti)
    {
        if(lista->dato.edad == ulti->dato.edad )
        {
            flag = devolverCapicua(lista->sig,ulti->ant);
        }
        else
        {
            flag =0;
        }
    }


    return flag;
}

/**Dada una lista doblemente enlazada ordenada de enteros,
eliminar el  nodo que se encuentra en el punto medio de la lista, si la cantidad de nodos es par,
 eliminar el inmediatamente superior.*/


nodo2* eliminarNodoDelMedio(nodo2 * lista)
{

    if(lista !=NULL)
    {
        nodo2* seg = lista;
        nodo2*ulti=buscarUltimoNodo(lista);
        while(seg!= ulti && seg->sig != ulti)
        {
            seg=seg->sig;
            ulti=ulti->ant;
        }
        lista=borrarNodo(lista,ulti->dato.nombre);
    }
    return lista;
}






