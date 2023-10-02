#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

typedef struct{

    int dato;
    struct nodoS*siguiente;

}nodoS;

typedef struct{

    int dato;
    struct nodoD*siguiente;
    struct nodoD*anterior;
}nodoD;

nodoS*inicLista();
int preguntarDato();
nodoS*crearNodoSimple(int datoN);
nodoS*agregarAlPpio(nodoS*lista,nodoS*nuevoNodo);
nodoS*agregarAlFinal(nodoS*listaS, nodoS*nuevoNodo);
void mostrarDato(int aux);
void mostrarLista(nodoS*listaS);
void mostrarListaRecursivo(nodoS*listaS);
int contarNodos(nodoS*lista);
nodoS*eliminarNodoXposicion(nodoS*listaS, int posicion);
nodoS*eliminarNodosMayores(nodoS*listaS,int valor);
nodoD*agregarOrdenadoDoble(nodoD*listaD,nodoD*nuevoNodo);
nodoD*simpleToDoble(nodoD*listaD,nodoS**listaS);
void mostrarListaDoble(nodoD*listaD);

















#endif // LISTASIMPLE_H_INCLUDED
