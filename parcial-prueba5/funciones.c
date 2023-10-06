#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

stJugador crearJugador(nodoD*listaD)
{
    stJugador aux;

    aux.id= buscarUltimoIdListas(listaD) +1;

    printf("Ingrese el nombre del jugador: ");
    fflush(stdin);
    gets(aux.nombre);

    elegirEquipo(&aux.equipo);

    elegirPosicion(&aux.posicion);

    printf("Ingrese el curso del jugador: ");
    scanf("%i",&aux.curso);

    printf("Ingrese los puntos ganados del jugador: ");
    scanf("%i",&aux.puntosGanados);


    return aux;
}

int buscarUltimoIdListas(nodoD*listaD)
{
    int idAux=0;
    if(listaD != NULL)
    {
        while(listaD != NULL)
        {
            if(listaD->dato.id > idAux)
            {
                idAux=listaD->dato.id;
            }
            listaD=listaD->siguiente;
        }
    }

    return idAux;
}

void elegirEquipo(char*equipo[])
{
    int flag=0,dato=0;

    do
    {
        puts("1. Ravenclaw");
        puts("2. Hufflepuf");
        puts("3. Gryffindor");
        puts("4. Slytherin");
        puts("----------------------------");
        printf("Que equipo es el jugador?: ");
        scanf("%i",&dato);
        switch(dato)
        {
        case 1:
            strcpy(equipo,"Ravenclaw");
            flag=0;
            break;
        case 2:
            strcpy(equipo,"Hufflepuf");
            flag=0;
            break;
        case 3:
            strcpy(equipo,"Gryffindor");
            flag=0;
            break;
        case 4:
            strcpy(equipo,"Slytherin");
            flag=0;
            break;
        default:
            puts("Ingrese una opcion correcta\n");
            flag=1;
            break;
        }

    }
    while(flag);
}

void elegirPosicion(char*posicion[])
{
        int flag=0,dato=0;

    do
    {
        puts("1. Buscador");
        puts("2. Cazador");
        puts("3. Golpeador");
        puts("4. Guardian");
        puts("----------------------------");
        printf("Que posicion es el jugador?: ");
        scanf("%i",&dato);
        switch(dato)
        {
        case 1:
            strcpy(posicion,"Buscador");
            flag=0;
            break;
        case 2:
            strcpy(posicion,"Cazador");
            flag=0;
            break;
        case 3:
            strcpy(posicion,"Golpeador");
            flag=0;
            break;
        case 4:
            strcpy(posicion,"Guardian");
            flag=0;
            break;
        default:
            puts("Ingrese una opcion correcta\n");
            flag=1;
            break;
        }

    }
    while(flag);
}



void mostrarJugador(stJugador aux)
{

    printf("ID: %i \n",aux.id);
    printf("Nombre: %s \n",aux.nombre);
    printf("Posicion: %s \n",aux.posicion);
    printf("Equipo: %s \n",aux.equipo);
    printf("Curso: %i \n",aux.curso);
    printf("Puntos Ganados: %i \n",aux.puntosGanados);
    puts("------------------------\n");
}

nodoD*inicLista()
{
    return NULL;
}

nodoD*crearNodo(stJugador aux)
{
    nodoD*nuevoNodo=(nodoD*)malloc(sizeof(nodoD));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    return nuevoNodo;
}

void agregarAlPpio(nodoD**listaD,nodoD*nuevoNodo)
{
    nuevoNodo->siguiente=(*listaD);
    if((*listaD) != NULL)
    {
        (*listaD)->anterior=nuevoNodo;
    }
    (*listaD)=nuevoNodo;
}

void mostrarLista(nodoD*listaD)
{
    while(listaD != NULL)
    {
        mostrarJugador(listaD->dato);
        listaD=listaD->siguiente;
    }
}

nodoD*agregarOrdenarListaXPosicion(nodoD*listaD,nodoD*nuevoNodo)
{
    if(listaD != NULL)
    {
        if(strcmp(listaD->dato.posicion,nuevoNodo->dato.posicion)>0)//es el primero
        {
            agregarAlPpio(&listaD,nuevoNodo);
        }
        else // esta en la mitad o ultimo
        {
            nodoD*ante=listaD;
            nodoD*seg=listaD->siguiente;
            while(seg != NULL && strcmp(listaD->dato.posicion,nuevoNodo->dato.posicion)<0)
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

int contarPuntosXEquipoRecursivo(nodoD*listaD,char equipoBuscar[])
{
    int sum=0;
    if(listaD != NULL)
    {
        if(strcmp(listaD->dato.equipo,equipoBuscar)==0)
        {
            sum=listaD->dato.puntosGanados;
        }
        sum+=contarPuntosXEquipoRecursivo(listaD->siguiente,equipoBuscar);
    }
    return sum;
}

nodoD*encontrarPosicionJugadorXCursoyNombre(nodoD*listaD,int cursoBuscar,char nombreBuscar[])
{
    nodoD*aux;
    if(listaD != NULL)
    {
        if((strcmp(nombreBuscar,listaD->dato.nombre)==0) && listaD->dato.curso == cursoBuscar)
        {
            aux=listaD;
        }
        else
        {
            encontrarPosicionJugadorXCursoyNombre(listaD->siguiente,cursoBuscar,nombreBuscar);
        }
    }
    return aux;
}


nodoD*borrarNodo(nodoD*listaD,int cursoBorrar)
{

}
