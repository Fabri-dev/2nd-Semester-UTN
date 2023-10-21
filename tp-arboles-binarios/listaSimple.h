#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include "arboles.h"

nodoS*inicLista();
nodoS*crearNuevoNodo(stPersona aux);
void agregarAlFinal(nodoS**listaS,nodoS*nuevoNodo);
nodoS*arbolToListaSimple(nodoArbol*raiz,nodoS*listaS);

#endif // LISTASIMPLE_H_INCLUDED
