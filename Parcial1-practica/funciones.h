#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///estructuras


typedef struct {
   char patente[6];
   int valor;
   char marca[10];
} stAuto;

typedef struct {
   stAuto dato;
   struct nodoAuto * siguiente;
} nodoAuto;

///funciones
void menu();
stAuto crearAuto();
nodoAuto*inicLista();
nodoAuto * crearNodo (stAuto aux);
void agregarFinal(nodoAuto**lista, nodoAuto*nuevo);
int insertarCelda(stAuto arr [], int dim, stAuto dato, int validos);
void mostrarAuto(stAuto aux);
void mostrarArregloAuto(stAuto arr[],int validos);
void agregarMuchos(nodoAuto ** lista);
int pasar(nodoAuto * lista, stAuto arr[], int dimension);
void mostrarArregloRecursivo(stAuto arr[], int i, int validos);
int sumaRecursivaPares(nodoAuto*lista);
int cargarArregloAuto(stAuto arr[], int dimension);
void mostrarLista(nodoAuto*lista);
#endif // FUNCIONES_H_INCLUDED
