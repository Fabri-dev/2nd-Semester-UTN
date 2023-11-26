#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"

stPelicula crearPelicula()
{
    stPelicula aux;
    printf("Ingrese el ID de la pelicula: "); //se puede hacer autoincremental hay q buscar en todo el arreglo de arboles
    scanf("%i",&aux.id);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(aux.nombre);

    printf("Ingrese la duracion: ");
    scanf("%i",&aux.duracion);

    printf("Ingrese la direccion: ");
    fflush(stdin);
    gets(aux.direccion);

    printf("Ingrese el genero: ");
    fflush(stdin);
    gets(aux.genero);

    printf("Ingrese el anio: ");
    scanf("%i",&aux.anio);

    return aux;
}

void mostrarUnaPelicula(stPelicula dato)
{
    printf("ID pelicula.........: %i \n",dato.id);
    printf("Nombre..............: %s \n",dato.nombre);
    printf("Duracion............: %i \n",dato.duracion);
    printf("Direccion...........: %s \n",dato.direccion);
    printf("Genero..............: %s \n",dato.genero);
    printf("Anio................: %i \n",dato.anio);
    puts(" ");

}

void inicCeldas(celdaDirector arr[])
{
    for(int i=0; i < MAX_DIM; i++)
    {
        arr[i].raiz=inicArbol();
    }
}

int validarSiExisteDirector(celdaDirector arregloDirectores[],int validos,char nuevoDir[])
{
    int flag=0;
    for(int i=0; i < validos; i++)
    {
        if(strcmpi(arregloDirectores[i].nombreDirector,nuevoDir)==0)
        {
            puts("Ya existe ese director");
            flag=1;
        }
    }

    return flag;

}

int agregarNuevoDirector(celdaDirector arregloDirectores[],int validos, char nuevoDirector[])
{
    if(validarSiExisteDirector(arregloDirectores,validos,nuevoDirector)==0 && validos < MAX_DIM)
    {
        strcpy(arregloDirectores[validos].nombreDirector,nuevoDirector);
        validos++;
    }

    return validos;
}

void mostrarUnaCelda(celdaDirector dato)
{
    puts("======================================");
    printf("DIRECTOR: %s \n",dato.nombreDirector);
    puts("--------------------------------------");
    mostrarPreorden(dato.raiz);
    puts("======================================");

}

void mostrarTodasLasCeldas(celdaDirector arr[], int validos)
{
    for(int i=0; i < validos; i++)
    {
        mostrarUnaCelda(arr[i]);
    }
    if(validos==0)
    {
        puts("Arreglo vacio");
    }
}


int retornarPosCeldaXDirector(celdaDirector arr[],char dirBuscar[],int validos, int i)
{

    if(i < validos)
    {
        if(strcmpi(arr[i].nombreDirector,dirBuscar)!=0)
        {
            i= retornarPosCeldaXDirector(arr,dirBuscar,validos,i+1);
        }
    }
    else
    {
        i= -1;
    }

    return i;
}

int darAltaNuevaPelicula(stPelicula nuevaPeli,celdaDirector arr[],int validos)
{
    nodoArbol*nuevoNodo=crearNodoArbol(nuevaPeli);
    int pos=retornarPosCeldaXDirector(arr,nuevaPeli.direccion,validos,0);
    if(pos == -1)
    {
        agregarNuevoDirector(arr,validos,nuevaPeli.direccion);
        validos++;
        pos= validos-1;
    }
    arr[pos].raiz=ingresarPelicula(arr[pos].raiz,nuevoNodo);
    return validos;
}

int archivoToCeldas(celdaDirector arr[],int validos)
{
    FILE*buffer=fopen(ARCHI_PELI,"rb");
    stPelicula auxPeli;
    if(buffer != NULL)
    {
        while(fread(&auxPeli,sizeof(stPelicula),1,buffer)>0)
        {
            validos= darAltaNuevaPelicula(auxPeli,arr,validos);
        }

        fclose(buffer);
    }

    return validos;
}


//void celdasToArchivo(celdaDirector arr[],int validos)
//{
//
//
//
//
//
//
//
//
//}


nodoArbol*buscarPeliculaXDirecYNom(celdaDirector arr[],int validos, char nomBuscar[], char direcBuscar[])
{
    int i=0;
    nodoArbol*aux=inicArbol();
    while(strcmpi(arr[i].nombreDirector,direcBuscar)!=0 && i < validos)
    {
        //mientras que no encuentro la direccion que busco e i es < a validos me muevo
        i++;
    }



    if(strcmpi(arr[i].nombreDirector,direcBuscar)==0) //pongo esta condicion por si no lo encontre
    {
        aux=buscarPeliculaXNombreEnArbol(arr[i].raiz,nomBuscar);
    }
    else
    {
        puts("No existe esa direccion");
    }

    return aux;
}

nodoArbol*buscarPeliculaXNombreEnArbol(nodoArbol*raiz,char nombreBuscar[])
{
    nodoArbol*aux=NULL;
    if(raiz != NULL)
    {
        if(strcmpi(raiz->dato.nombre,nombreBuscar)==0)
        {
            aux=raiz;
        }
        else
        {
            if(strcmpi(raiz->dato.nombre,nombreBuscar) < 0)
            {
                aux=buscarPeliculaXNombreEnArbol(raiz->izq,nombreBuscar);
            }
            else
            {
                aux=buscarPeliculaXNombreEnArbol(raiz->der,nombreBuscar);
            }
        }
    }
    else
    {
        puts("Dato no encontrado");
    }

    return aux;
}

nodoArbol*buscarPeliculaXDirecYAnio(nodoArbol*raiz, char direcBuscar[],int anioBuscar)
{
    nodoArbol*aux=NULL;
    if(raiz != NULL)
    {
        if(raiz->dato.anio==anioBuscar && strcmpi(raiz->dato.direccion,direcBuscar)==0)
        {
            aux=raiz;
        }
        else
        {
            aux=buscarPeliculaXDirecYAnio(raiz->izq,direcBuscar,anioBuscar);
            aux=buscarPeliculaXDirecYAnio(raiz->der,direcBuscar,anioBuscar);
        }
    }
    return aux;
}

