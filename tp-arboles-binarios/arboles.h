#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED


typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
}stPersona;

typedef struct
{
    stPersona dato;
    struct nodoArbol*izquierda;
    struct nodoArbol*derecha;
}nodoArbol;


nodoArbol*inicLista();
stPersona crearUnaPersona();
nodoArbol*crearNodoArbol(stPersona aux);


#endif // ARBOLES_H_INCLUDED
