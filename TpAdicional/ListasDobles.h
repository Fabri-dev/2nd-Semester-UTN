#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED
#include "ListasSimple.h"

int preguntarID();
nodoListaReproduccion*crearNodoListaRepro(int datoId);
nodoListaReproduccion*agregarAlPpioDoble(nodoListaReproduccion*listaD, nodoListaReproduccion*nuevoNodo);
void mostrarListaDoble(nodoListaReproduccion*listaD);
nodoListaReproduccion*borrarNodoDoble(nodoListaReproduccion*listaD,int idBuscar);
int contarDuracionTotalPlaylistRecursivo(nodoCancion*listaS,nodoListaReproduccion*listaD);
int contarCantidadDeCancionesEnPlaylistXGenero(nodoCancion*listaS,nodoListaReproduccion*listaD,char generoBuscar[]);
int contarCantidadDeCancionesEnPlaylistXAlbum(nodoCancion*listaS,nodoListaReproduccion*listaD,char albumBuscar[]);
int contarCantidadDeCancionesEnPlaylistXArtista(nodoCancion*listaS,nodoListaReproduccion*listaD,char artistaBuscar[]);
nodoListaReproduccion*buscarUltimoNodoDoble(nodoListaReproduccion*listaD);
nodoListaReproduccion*reproducirUnaCancion(fila**cola,nodoCancion**listaS,nodoListaReproduccion*listaD);


























#endif // LISTASDOBLES_H_INCLUDED
