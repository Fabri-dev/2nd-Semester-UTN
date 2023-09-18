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

typedef struct{
    struct nodo*lista;
}Pila;



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
void borrarNodoPrimero (nodo** lista);

//recursividad
///1. Recorrer una lista y mostrarla en forma invertida.
void mostrarListaInvertidaRecursiva(nodo*aux);
///2. Sumar los elementos de una lista.
int sumarElementosListaRecursivo(nodo*aux);
///3. Mostrar los elementos de una lista ubicados en una posición par.
void mostrarPares(nodo * lista);
///4. Borrar un nodo de una lista simple (buscado por un dato específico).
nodo * borrarNodoRecursivo(nodo* lista,char nombreAux[]);
///5. Insertar un nodo o dato en una lista simplemente enlazada en forma recursiva (manteniendo el orden de forma creciente).
nodo * insertarNodoRecursivo(nodo*lista,nodo*nuevoNodo);
///  6. Invertir una lista simple cambiando los vínculos.
nodo *invertirListaRecursivo(nodo*lista);
#endif // LISTAS_H_INCLUDED
