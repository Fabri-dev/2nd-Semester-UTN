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
int preguntarDato();
void mostrarPersona(stPersona aux);
nodoArbol*crearNodoArbol(stPersona aux);
nodoArbol*ingresarXLegajo(nodoArbol*raiz,nodoArbol*nuevoNodo);
nodoArbol* ingresarMuchosNodosXLegajo(nodoArbol*raiz);
void mostrarPreorder(nodoArbol*raiz);
void mostrarInorder(nodoArbol*raiz);
void mostrarPostorder(nodoArbol*raiz);
stPersona retornarUnaPersonaXLegajo(nodoArbol*raiz,int legajoBuscar);
int verificarSiExistePersonaXLegajo(nodoArbol*raiz,int legajoBuscar);
stPersona buscarUnaPersonaVerificado(nodoArbol*raiz,int legajoBuscar);
#endif // ARBOLES_H_INCLUDED
