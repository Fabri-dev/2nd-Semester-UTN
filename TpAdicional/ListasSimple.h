#ifndef LISTASSIMPLE_H_INCLUDED
#define LISTASSIMPLE_H_INCLUDED

typedef struct
{
    int idCancion;
    char titulo[25];
    char artista[25];
    char genero[25];
    char album[25];
    int duracion;
    int cantidadReproducciones;
} stCancion ;

typedef struct
{
    stCancion dato ;
    struct nodoCancion * siguiente;
} nodoCancion;

typedef struct
{
    int idCancion;
    struct nodoListaReproduccion* siguiente;
    struct nodoListaReproduccion* anterior;
}nodoListaReproduccion;

typedef struct
{
    struct nodoListaReproduccion* primero;
    struct nodoListaReproduccion* ultimo;

}fila;



nodoCancion*inicLista();
stCancion crearCancion(nodoCancion*listaSimple);
int buscarUltimoID(nodoCancion*listaS);
nodoCancion*crearNodoCancion(stCancion aux);
nodoCancion*agregarAlPpioSimple(nodoCancion*listaS,nodoCancion*nuevoNodo);
nodoCancion*agregarOrdenadoPorDuracionSimple(nodoCancion*listaS,nodoCancion*nuevoNodo);
nodoCancion*borrarCancionSimple(nodoCancion*listaS,int idBuscar);
void mostrarCancion(stCancion aux);
void mostrarListaSimple(nodoCancion*listaS);
nodoCancion*aumentarCantidadReproducciones(nodoCancion*listaS,int idBuscar);
nodoCancion*buscarCancionesPorTitulo(nodoCancion*listaS,char tituloBuscar[]);
nodoCancion*buscarCancionesPorGenero(nodoCancion*listaS,char generoBuscar[]);
nodoCancion*buscarCancionesPorAlbum(nodoCancion*listaS,char albumBuscar[]);

nodoCancion*retornarNodoSimpleXid(nodoCancion*listaS,int idBuscar);
int contarNodosSimple(nodoCancion*listaS);





#endif // LISTASSIMPLE_H_INCLUDED
