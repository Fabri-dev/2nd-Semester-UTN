#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListasSimple.h"

int preguntarID()
{
    int dato=0;
    printf("Ingrese el ID: "); // tengo que verificar si existe el id
    scanf("%i",&dato);
    return dato;
}

nodoListaReproduccion*crearNodoListaRepro(int datoId)
{
    nodoListaReproduccion*nuevoNodoDoble=(nodoListaReproduccion*)malloc(sizeof(nodoListaReproduccion));
    nuevoNodoDoble->anterior=NULL;
    nuevoNodoDoble->siguiente=NULL;
    nuevoNodoDoble->idCancion=datoId;
    return nuevoNodoDoble;
}

nodoListaReproduccion*agregarAlPpioDoble(nodoListaReproduccion*listaD, nodoListaReproduccion*nuevoNodo)
{
    nuevoNodo->siguiente=listaD;
    if(listaD != NULL)
    {
        listaD->anterior=nuevoNodo;
    }
    return nuevoNodo;
}

void mostrarListaDoble(nodoListaReproduccion*listaD)
{
    puts("Ultimo");
    while(listaD != NULL)
    {
        printf("id cancion: %i ",listaD->idCancion);
        printf("\n------------------------------\n");
        listaD=listaD->siguiente;

    }
    puts("Primero");
}

nodoListaReproduccion*borrarNodoDoble(nodoListaReproduccion*listaD,int idBuscar)
{
    if(listaD == NULL)
    {
        puts("Lista vacia");
    }
    else
    {
        int flag=0;
        nodoListaReproduccion*aux;
        if(listaD->idCancion == idBuscar)
        {
            flag=1;
            aux=listaD;
            listaD=listaD->siguiente;
        }
        else
        {
            nodoListaReproduccion*ante=listaD;
            nodoListaReproduccion*seg=listaD->siguiente;
            while(seg != NULL && seg->idCancion != idBuscar)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            if(seg != NULL)
            {
                flag=1;
                aux=seg; // guardo el que quiero borrar
                ante->siguiente=seg->siguiente; // conecto el siguiente de ante con el siguiente de seg
                seg=seg->siguiente; // me muevo uno para adelante para conectar el anterior del siguiente del seg
                if(seg != NULL) // si no estoy en el final entonces:
                {

                seg->anterior=ante; // conecto el anterior de seg con ante
                }
            }

        }
        if(flag)
        {
            free(aux);
        }
    }

    return listaD;
}



int contarDuracionTotalPlaylistRecursivo(nodoCancion*listaS,nodoListaReproduccion*listaD)
{
    int sum=0;
    if(listaD != NULL)
    {
        sum=contarDuracionTotalPlaylistRecursivo(listaS,listaD->siguiente);
        nodoCancion*aux=retornarNodoSimpleXid(listaS,listaD->idCancion);
        sum+=aux->dato.duracion;
    }

    return sum;
}

int contarCantidadDeCancionesEnPlaylistXGenero(nodoCancion*listaS,nodoListaReproduccion*listaD,char generoBuscar[])
{
    int cont=0;
    while(listaD != NULL)
    {
        nodoCancion*aux=retornarNodoSimpleXid(listaS,listaD->idCancion);
        if(strcmpi(aux->dato.genero,generoBuscar)==0)
        {
            cont++;
        }
        listaD=listaD->siguiente;
    }
    return cont;
}

int contarCantidadDeCancionesEnPlaylistXAlbum(nodoCancion*listaS,nodoListaReproduccion*listaD,char albumBuscar[])
{
    int cont=0;
    while(listaD != NULL)
    {
        nodoCancion*aux=retornarNodoSimpleXid(listaS,listaD->idCancion);
        if(strcmpi(aux->dato.album,albumBuscar)==0)
        {
            cont++;
        }
        listaD=listaD->siguiente;
    }
    return cont;
}

int contarCantidadDeCancionesEnPlaylistXArtista(nodoCancion*listaS,nodoListaReproduccion*listaD,char artistaBuscar[])
{
    int cont=0;
    while(listaD != NULL)
    {
        nodoCancion*aux=retornarNodoSimpleXid(listaS,listaD->idCancion);
        if(strcmpi(aux->dato.titulo,artistaBuscar)==0)
        {
            cont++;
        }
        listaD=listaD->siguiente;
    }
    return cont;
}

nodoListaReproduccion*buscarUltimoNodoDoble(nodoListaReproduccion*listaD)
{

    if(listaD != NULL)
    {
        while(listaD->siguiente != NULL)
        {
            listaD=listaD->siguiente;
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return listaD;
}

nodoListaReproduccion*reproducirUnaCancion(fila**cola,nodoCancion**listaS,nodoListaReproduccion*listaD)
{

    if(listaD == NULL)
    {
        puts("Lista de reproduccion vacia");

    }
    else if(listaD->siguiente == NULL)
    {
        (*cola)->primero= NULL;
        (*cola)->ultimo= NULL;


        *listaS=aumentarCantidadReproducciones(*listaS,listaD->idCancion);
        listaD=borrarNodoDoble(listaD,listaD->idCancion);
    }
    else
    {
        nodoListaReproduccion*aux;

        aux=buscarUltimoNodoDoble(listaD);
        (*cola)->primero=aux->anterior;
        *listaS=aumentarCantidadReproducciones(*listaS,aux->idCancion);
        listaD=borrarNodoDoble(listaD,aux->idCancion);
    }

    return listaD;
}
