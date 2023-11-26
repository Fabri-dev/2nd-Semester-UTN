#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#define MAX_DIM 30

typedef struct
{
    int id;
    char nombre[20];
    int duracion;
    char direccion[30];
    char genero[20];
    int anio;
} stPelicula;


typedef struct{
     stPelicula dato;
     struct nodoArbol * izq;
     struct nodoArbol * der;
} nodoArbol;



nodoArbol*inicArbol();
nodoArbol*crearNodoArbol(stPelicula auxDato);
nodoArbol*ingresarPelicula(nodoArbol* raiz, nodoArbol*nuevoNodo);
void mostrarPreorden(nodoArbol*raiz);




#endif // ARBOL_H_INCLUDED
