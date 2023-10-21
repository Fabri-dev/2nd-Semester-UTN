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

typedef struct
{
    stPersona dato;
    struct nodoS*siguiente;

}nodoS;

nodoArbol*inicArbol();
stPersona crearUnaPersona();
void mostrarPersona(stPersona aux);
nodoArbol*crearNodoArbol(stPersona aux);
nodoArbol*ingresarXLegajo(nodoArbol*raiz,nodoArbol*nuevoNodo);
nodoArbol* ingresarMuchosNodosXLegajo(nodoArbol*raiz);
void mostrarPreorder(nodoArbol*raiz);
void mostrarInorder(nodoArbol*raiz);
void mostrarPostorder(nodoArbol*raiz);

#endif // ARBOLES_H_INCLUDED
