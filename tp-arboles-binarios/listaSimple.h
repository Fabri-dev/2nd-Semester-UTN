#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include "arboles.h"

nodoS*inicLista();
nodoS*crearNodoLista(stPersona aux);
nodoS*agregarAlFinalLista(nodoS*listaS,nodoS*nuevoNodo);
nodoS*arbolToListaSimple(nodoArbol*raiz,nodoS*listaS);
void mostrarListaSimple(nodoS*listaS);


#endif // LISTASIMPLE_H_INCLUDED
