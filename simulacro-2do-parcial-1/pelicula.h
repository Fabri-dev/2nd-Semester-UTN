#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#define ARCHI_PELI "peliculas.bin"
#include "arbol.h"

typedef struct
{
    char nombreDirector[MAX_DIM];
    nodoArbol* raiz;
}celdaDirector;

stPelicula crearPelicula();
void mostrarUnaPelicula(stPelicula dato);
void inicCeldas(celdaDirector arr[]);
int validarSiExisteDirector(celdaDirector arregloDirectores[],int validos,char nuevoDir[]);
int agregarNuevoDirector(celdaDirector arregloDirectores[],int validos, char nuevoDirector[]);
void mostrarUnaCelda(celdaDirector dato);
void mostrarTodasLasCeldas(celdaDirector arr[], int validos);
int retornarPosCeldaXDirector(celdaDirector arr[],char dirBuscar[],int validos, int i);
int archivoToCeldas(celdaDirector arr[],int validos);
int darAltaNuevaPelicula(stPelicula nuevaPeli,celdaDirector arr[],int validos);
nodoArbol*buscarPeliculaXDirecYNom(celdaDirector arr[],int validos, char nomBuscar[], char direcBuscar[]);
nodoArbol*buscarPeliculaXNombreEnArbol(nodoArbol*raiz,char nombreBuscar[]);


#endif // PELICULA_H_INCLUDED
