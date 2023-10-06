#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char posicion[20]; //buscador,cazador,golpeador,guardian
    int curso;
    int puntosGanados;
    char equipo[20]; //Raverclaw,Hufflepuuf,Gryffindor,Slytherin

}stJugador;

typedef struct
{
    stJugador dato;
    struct nodoD*siguiente;
    struct nodoD*anterior;
}nodoD;

//funciones

stJugador crearJugador(nodoD*listaD);
int buscarUltimoIdListas(nodoD*listaD);
void elegirEquipo(char*equipo[]);
void elegirPosicion(char*posicion[]);
void mostrarJugador(stJugador aux);

nodoD*inicLista();
nodoD*crearNodo(stJugador aux);
void agregarAlPpio(nodoD**listaD,nodoD*nuevoNodo);
void mostrarLista(nodoD*listaD);

nodoD*agregarOrdenarListaXPosicion(nodoD*listaD,nodoD*nuevoNodo);
int contarPuntosXEquipoRecursivo(nodoD*listaD,char equipoBuscar[]);
nodoD*encontrarPosicionJugadorXCursoyNombre(nodoD*listaD,int cursoBuscar,char nombreBuscar[]);







#endif // FUNCIONES_H_INCLUDED
