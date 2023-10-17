#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

typedef struct
{
    char nombreCliente[30];
    int tipoCliente; //1.regular, 2.jubilado, 3.persona gestante, 4.empresario
    int cantidadFacturas;

} stCliente;

typedef struct
{
    stCliente dato;
    struct nodoSimple*siguiente;

} nodoSimple;

typedef struct
{
    stCliente dato;
    struct nodoDoble*anterior;
    struct nodoDoble*siguiente;


} nodoDoble;

typedef struct
{
    nodoDoble * primero; //primer cliente
    nodoDoble * ultimo; //ultimo cliente
    int numeroFila;
    char nombreCajere[50];
} fila;



nodoSimple*inicListaSimple();
stCliente crearClienteAutomatico();
void mostrarCliente(stCliente aux);
nodoSimple*crearNodoSimple(stCliente aux);
nodoSimple*buscarUltimoNodoSimple(nodoSimple*listaS);
nodoSimple*agregarAlFinalSimple(nodoSimple*listaS, nodoSimple*nuevoNodo);
void mostrarListaSimple(nodoSimple*listaS);
void borrarPrimeroSimple(nodoSimple**listaS);


#endif // LISTASIMPLE_H_INCLUDED
