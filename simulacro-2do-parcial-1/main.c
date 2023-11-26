#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#define ARCHI_PELI "peliculas.bin"


void limpiarPantalla()
{
    system("cls");
}

int main()
{
    int opsw=0;
    char op='s';

    int auxEntero=0;
    char auxString1[MAX_DIM];
    char auxString2[MAX_DIM];
    stPelicula auxPelicula;
    nodoArbol* auxArbol=inicArbol();

    celdaDirector arregloArboles[MAX_DIM];
    inicCeldas(arregloArboles);
    //int validos=archivoToCeldas(arregloArboles,validos);
    int validos=0;
    printf("validos: %i",validos);
    //el criterio de ordenacion del arbol es por nombre

    //4. archivo to arreglo de arboles

    do
    {


        puts("1. Agregar un nuevo director al arreglo");
        puts("2. Retornar pos del director buscado");
        puts("3. Insertar una nueva pelicula al arbol");
        puts("4. Mostrar todo");
        puts("5. Mostrar peliculas por direccion y nombre");
        puts("7. Buscar una pelicula por director");
        puts("8. Buscar pelicula por anio");
        puts("9. Salir");
        puts("-------------------------------------------------");
        printf("Ingrese una opcion: ");
        scanf("%i",&opsw);
        limpiarPantalla();
        switch(opsw)
        {
        case 1:
            printf("Ingrese un nuevo director: ");
            fflush(stdin);
            gets(auxString1);
            validos=agregarNuevoDirector(arregloArboles,validos,auxString1);
            printf("Validos: %i \n",validos);
            break;
        case 2:
            printf("Ingrese un nuevo director: ");
            fflush(stdin);
            gets(auxString1);
            auxEntero=retornarPosCeldaXDirector(arregloArboles,auxString1,validos,0);
            printf("POS: %i \n",auxEntero);
            break;
        case 3:
            auxPelicula=crearPelicula();
            validos=darAltaNuevaPelicula(auxPelicula,arregloArboles,validos);
            break;
        case 4:
            mostrarTodasLasCeldas(arregloArboles,validos);
            break;
        case 5:
            printf("Ingrese la direccion de la pelicula que quiere buscar: ");
            fflush(stdin);
            gets(auxString1);
            printf("Ingrese el nombre de la pelicula que quiere buscar: ");
            fflush(stdin);
            gets(auxString2);
            auxArbol=buscarPeliculaXDirecYNom(arregloArboles,validos,auxString2,auxString1);
            mostrarUnaPelicula(auxArbol->dato);
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            op='n';
            break;
        default:
            puts("Ingrese una opcion valida");
            break;
        }
    }
    while(op=='s');

    return 0;
}
