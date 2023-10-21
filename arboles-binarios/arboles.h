#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

typedef struct
{
    int dato;
    struct nodoArbol*izquierda;
    struct nodoArbol*derecha;

}nodoArbol;

int preguntarDato();
nodoArbol*inicArbol();
nodoArbol*crearNodoArbol(int aux);
nodoArbol*insertarNodo(nodoArbol*raiz,nodoArbol*nuevoNodo);
void mostrarPreOrder(nodoArbol*raiz);
void mostrarInOrder(nodoArbol*raiz);
void mostrarPostOrder(nodoArbol*raiz);
int contarHojas(nodoArbol*raiz);
int contarNodosGradoUno(nodoArbol*raiz);
int buscarDatoEnArbol(nodoArbol*raiz,int datoBuscar);
int buscarDatoEnArbolPro(nodoArbol*raiz,int datoBuscar);
int buscarMenor(nodoArbol*raiz);









#endif // ARBOLES_H_INCLUDED
