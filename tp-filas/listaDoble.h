#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include "listaSimple.h"

nodoDoble*inicListaDoble();
nodoDoble*crearNodoDoble(stCliente aux);
nodoDoble*agregarAlPpioDoble(nodoDoble*listaD,nodoDoble*nuevoNodo);
nodoDoble*buscarUltimoNodoDoble(nodoDoble*listaD);
nodoDoble*agregarAlFinalDoble(nodoDoble*listaD,nodoDoble*nuevoNodo);
nodoDoble*agregarOrdenadoDobleXCantidadFacturasMenorAMayor(nodoDoble*listaD,nodoDoble*nuevoNodo);
void mostrarListaDoble(nodoDoble*listaD);
int contarListaDoble(nodoDoble*listaD);
















#endif // LISTADOBLE_H_INCLUDED
