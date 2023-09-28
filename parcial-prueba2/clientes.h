#include "funciones.h"
#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED



stCliente crearClienteExceptoCompra();
nodoCliente*crearNodoCliente(stCliente aux);
nodoCliente*inicListaDoble();
void mostrarCliente(stCliente aux);
void mostrarListaClientes(nodoCliente*listaD);
nodoCliente*comprarConsola(nodoCliente*listaDoble,nodoConsola*lista,char nombreCliente[],int medioPago);
nodoCliente*agregarAlFinal(nodoCliente*listaD,nodoCliente*nuevoNodo);
nodoCliente*retornarUltimoNodoCliente(nodoCliente*listaD);
nodoCliente*cargarFilaClientes(nodoCliente*fila,nodoConsola*listaSimple);
nodoCliente* borrarNodoPrimerCliente(nodoCliente*listaD);
nodoCliente*atender(nodoCliente*fila);










#endif // CLIENTES_H_INCLUDED
