#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct{

    int edad;
    char nombre[20];

}stPersona;


typedef struct{

    stPersona dato;
    struct nodo*siguiente;

}nodo;

//funciones archivo

stPersona crearPersona();
void cargarArchivoPersonas(char archivo[]);
void mostrarPersona(stPersona aux);
int validarEdad(int dato);


//funciones listas
nodo*inicLista();
nodo*crearNodo(stPersona aux);
nodo*agregarNuevoNodoAlFinal(nodo*cabeza,nodo*nuevoNodo);
nodo*archivoToLista(nodo*cabeza,char archivo[]);
nodo*agregarNuevoNodoAlPpio(nodo*cabeza,nodo*nuevoNodo);
void mostrarLista(nodo*cabeza);
nodo*ArchivoToListaOrdenado(nodo*cabeza,char archivo[]);
nodo*ordenarMenoraMayor(nodo*cabeza,nodo*nuevoNodo);
int buscarPersonaLista(nodo*cabeza,stPersona busqueda);
nodo*intercalarListasXedad(nodo*lista1,nodo*lista2);
nodo*cargarLista(nodo*cabeza);
nodo*invertirElementosLista(nodo*cabeza);
nodo*borrarNodoXNombre(nodo*cabeza,char nombre[]);

#endif // LISTAS_H_INCLUDED
