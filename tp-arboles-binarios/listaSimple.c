#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"


nodoS*inicLista()
{
    return NULL;
}

nodoS*crearNuevoNodo(stPersona aux)
{
    nodoS*nuevoNodo=(nodoS*)malloc(sizeof(nodoS));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

void agregarAlFinal(nodoS**listaS,nodoS*nuevoNodo)
{
    if((*listaS) != NULL)
    {
        nodoS*seg=*listaS;
        while(seg->siguiente != NULL)
        {
            seg=seg->siguiente;
        }
        seg->siguiente=nuevoNodo;
    }
    else
    {
        *listaS=nuevoNodo;
    }


}


nodoS*arbolToListaSimple(nodoArbol*raiz,nodoS*listaS)
{
    if(raiz != NULL)
    {

    }



    return listaS;
}
