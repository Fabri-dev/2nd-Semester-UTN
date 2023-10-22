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
int preguntarDatoEntero();
void mostrarPersona(stPersona aux);
nodoArbol*crearNodoArbol(stPersona aux);
nodoArbol*ingresarXLegajo(nodoArbol*raiz,nodoArbol*nuevoNodo);
nodoArbol* ingresarMuchosNodosXLegajo(nodoArbol*raiz);
void mostrarPreorder(nodoArbol*raiz);
void mostrarInorder(nodoArbol*raiz);
void mostrarPostorder(nodoArbol*raiz);
stPersona retornarUnaPersonaXLegajo(nodoArbol*raiz,int legajoBuscar);
int verificarSiExistePersonaXLegajo(nodoArbol*raiz,int legajoBuscar);
stPersona buscarUnaPersonaXLegajoVerificado(nodoArbol*raiz,int legajoBuscar);
int verificarSiExistePersonaXNombre(nodoArbol* raiz,char nombreBuscar[]);
stPersona retornarUnaPersonaXNombre(nodoArbol*raiz,char nombreBuscar[]);
stPersona buscarUnaPersonaXNombreVerificado(nodoArbol*raiz, char nombreBuscar[]);
int calcularAlturaArbol(nodoArbol*raiz);
int contarNodos(nodoArbol*raiz);
int contarHojas(nodoArbol*raiz);



#endif // ARBOLES_H_INCLUDED
