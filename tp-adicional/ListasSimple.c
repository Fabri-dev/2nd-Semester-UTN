#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListasSimple.h"


nodoCancion*inicLista()
{
    return NULL;
}

stCancion crearCancion(nodoCancion*listaSimple)
{
    stCancion aux;
    aux.idCancion=buscarUltimoID(listaSimple)+1;
    aux.cantidadReproducciones=0;

    printf("Ingrese el titulo: ");
    fflush(stdin);
    gets(aux.titulo);

    printf("Ingrese el artista: ");
    fflush(stdin);
    gets(aux.artista);

    printf("Ingrese el genero: ");
    fflush(stdin);
    gets(aux.genero);

    printf("Ingrese el album: ");
    fflush(stdin);
    gets(aux.album);

    printf("Ingrese la duracion: ");
    scanf("%i",&aux.duracion);


    return aux;
}

int buscarUltimoID(nodoCancion*listaS)
{
    int ultimoid=0;
    if(listaS != NULL)
    {
        ultimoid = listaS->dato.idCancion;
        while(listaS != NULL)
        {
            if(ultimoid < listaS->dato.idCancion)
            {
                ultimoid=listaS->dato.idCancion;

            }
            listaS=listaS->siguiente;
        }
    }

    return ultimoid;
}

nodoCancion*crearNodoCancion(stCancion aux)
{
    nodoCancion*nuevoNodo=(nodoCancion*)malloc(sizeof(nodoCancion));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoCancion*agregarAlPpioSimple(nodoCancion*listaS,nodoCancion*nuevoNodo)
{
    nuevoNodo->siguiente=listaS;
    return nuevoNodo;
}

nodoCancion*agregarOrdenadoPorDuracionSimple(nodoCancion*listaS,nodoCancion*nuevoNodo)
{
    if(listaS == NULL || nuevoNodo->dato.duracion < listaS->dato.duracion)
    {
        listaS=agregarAlPpioSimple(listaS,nuevoNodo);
    }
    else
    {
        nodoCancion*ante=listaS;
        nodoCancion*seg=listaS->siguiente;
        while(seg != NULL && seg->dato.duracion < nuevoNodo->dato.duracion)
        {
            ante=seg;
            seg=seg->siguiente;
        }
        ante->siguiente=nuevoNodo;
        nuevoNodo->siguiente=seg;
    }
    return listaS;
}

nodoCancion*borrarCancionSimple(nodoCancion*listaS,int idBuscar)
{
    int flag=0;
    if(listaS != NULL)
    {
        nodoCancion*aux;
        if(listaS->dato.idCancion == idBuscar)
        {
            aux=listaS;
            listaS=listaS->siguiente;
            flag=1;
        }
        else
        {
            nodoCancion*ante=listaS;
            nodoCancion*seg=listaS->siguiente;

            while(seg->dato.idCancion != idBuscar)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg->dato.idCancion == idBuscar)
            {

                ante->siguiente=seg->siguiente;
                aux=seg;
                flag=1;
            }
        }

        free(aux);

    }
    else
    {
        puts("Lista vacia");
    }

    if(flag)
    {
        puts("Nodo borrado de forma existosa");
    }
    else
    {
        puts("No se encontro el id del nodo buscado");
    }

    return listaS;
}

void mostrarCancion(stCancion aux)
{
    printf("ID de la cancion: %i \n",aux.idCancion);
    printf("Duracion: %i \n",aux.duracion);
    printf("Titulo: %s \n",aux.titulo);
    printf("Artista: %s \n",aux.artista);
    printf("Genero: %s \n",aux.genero);
    printf("Album: %s \n",aux.album);
    printf("Cantidad de reproducciones: %i \n",aux.cantidadReproducciones);
    puts("---------------------------------------");

}

void mostrarListaSimple(nodoCancion*listaS)
{
    if(listaS != NULL)
    {
        while(listaS != NULL)
        {
            mostrarCancion(listaS->dato);
            listaS=listaS->siguiente;
        }

    }

    else
    {
        puts("La lista esta vacia");
    }

}

nodoCancion*aumentarCantidadReproducciones(nodoCancion*listaS,int idBuscar)
{
    int flag=0;
    if(listaS != NULL)
    {
        nodoCancion*aux=listaS;
        while(aux != NULL && flag==0) //lo pongo en la condicion ya que quiero que se corte una vez que aumente la cantidadRepro
        {
            if(aux->dato.idCancion == idBuscar)
            {
                aux->dato.cantidadReproducciones+=1;
                flag=1;
            }
            aux=aux->siguiente;
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return listaS;
}


nodoCancion*buscarCancionesPorTitulo(nodoCancion*listaS,char tituloBuscar[])
{
    nodoCancion*sublista=NULL;
    if(listaS != NULL)
    {

        while(listaS != NULL)
        {
            if(strcmpi(listaS->dato.titulo,tituloBuscar)==0) //aca no lo corto ya que pueden haber mas canciones con el mismo titulo por lo tanto debo recorrer la lista hasta el final
            {
                sublista=agregarOrdenadoPorDuracionSimple(sublista,listaS);
            }
            listaS=listaS->siguiente;
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return sublista;
}

nodoCancion*buscarCancionesPorGenero(nodoCancion*listaS,char generoBuscar[])
{
    nodoCancion*sublista=NULL;
    if(listaS != NULL)
    {

        while(listaS != NULL)
        {
            if(strcmpi(listaS->dato.titulo,generoBuscar)==0)
            {
                sublista=agregarOrdenadoPorDuracionSimple(sublista,listaS);
            }
            listaS=listaS->siguiente;
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return sublista;
}

nodoCancion*buscarCancionesPorAlbum(nodoCancion*listaS,char albumBuscar[])
{
    nodoCancion*sublista=NULL;
    if(listaS != NULL)
    {

        while(listaS != NULL)
        {
            if(strcmpi(listaS->dato.titulo,albumBuscar)==0)
            {
                sublista=agregarOrdenadoPorDuracionSimple(sublista,listaS);
            }
            listaS=listaS->siguiente;
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return sublista;
}

nodoCancion*retornarNodoSimpleXid(nodoCancion*listaS,int idBuscar)
{
    int flag=0;
    if(listaS != NULL)
    {
        while(listaS != NULL && flag==0)
        {
            if(listaS->dato.idCancion == idBuscar)
            {
                flag=1;
            }
            else
            {

                listaS=listaS->siguiente;
            }
        }
        if(listaS == NULL)
        {
            puts("ID buscado no existe");
        }

    }
    else
    {
        puts("Lista vacia");
    }
    return listaS;
}

int contarNodosSimple(nodoCancion*listaS)
{
    int cont=0;

    while(listaS != NULL)
    {
        cont++;
        listaS=listaS->siguiente;
    }

    return cont;
}
