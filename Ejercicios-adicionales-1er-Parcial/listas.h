#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct
{
    int dato;
    struct nodoS *siguiente;

}nodoS;

typedef struct {
int nroParcial;
char dni[9];
char asignatura[20];
float Nota;
}stExamen;

typedef struct
{
    stExamen dato;
    struct nodoD*siguiente;
    struct nodoD*anterior;

}nodoD;

nodoS*iniciarLista();
int preguntarDato();
nodoS*crearNodo(int num);
nodoS*agregarAlFinal(nodoS*listaS,nodoS*nuevoNodo);
void mostrarDato(int num);
void mostrarLista(nodoS*lista);
nodoS*agregarAlPpio(nodoS*listaS,nodoS*nuevoNodo);
nodoS*agregarOrdenado(nodoS*listaS,nodoS*nuevoNodo);
nodoS*cargarListaOrdenada(nodoS*listaS);
nodoS*eliminarRepetidos(nodoS*listaS);
nodoS*interseccion(nodoS*lista1,nodoS*lista2);
stExamen crearExamen();
nodoD*crearNodoDoble(stExamen aux);
nodoD*agregarAlPpioDoble(nodoD*listaD,nodoD*nuevoNodo);
nodoD*agregarOrdenadoDoble(nodoD*listaD,nodoD*nuevoNodo);
void mostrarExamen(stExamen dato);
void mostrarListaDoble(nodoD*listaD);
nodoD*eliminarDniEspecificoDoble(nodoD*listaD,char dniEliminar[]);
float calcularPromedioxDniYAsignaturaDoble(nodoD*listaD,char dniBuscar[], char asignaturaBuscar[]);
int verificarSiExisteDniEnAsignaturaRecursivo(nodoD*listaD,char asignaturaBuscar[],char dniBuscar[],int flag);
void mostrarExamenAsignaturaRecursivo(nodoD*listaD,char asignaturaBuscar[]);
int contarAlumnosAsignaturaRecursivo(nodoD*listaD,char asignaturaBuscar[]);
nodoD*ultimaOcurrenciaDniRecursivo(nodoD*listaD, char dniBuscar[]);

stExamen*crearArregloDinamicoExamen(int t);
void cargarArregloAsignaturaEspecifica(nodoD*listaD,stExamen arr[],int dim,char asignaturaBuscar[]);



void mostrarArreglo(stExamen arr[],int validos);






#endif // LISTAS_H_INCLUDED
