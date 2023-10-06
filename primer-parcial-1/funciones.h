#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///estructuras

typedef struct {
char nombre[50];
char telefono[50];
int DNI; // valores del 1 al 100
}stPersona;

typedef struct{
	stPersona dato;
	struct nodoPersona* siguiente;
}nodoPersona;

typedef struct {
 int DNI;
 int tipoContacto; //1-familia 2-trabajo 3-amigos
int activo; //1-true 0-false
}stContacto;

typedef struct{
	stContacto dato;
	struct nodoContacto* siguiente;
	struct nodoContacto* anterior;
}nodoContacto;


///funciones Listas Simples

int verificarSiExisteDniRecursivo(nodoPersona*listaS,int dniBuscar);
stPersona crearPersona(nodoPersona*listaS);
int validarDNI(int dato,nodoPersona*listaS);
nodoPersona*inicListaSimple();
nodoPersona*crearNodoPersona(stPersona aux);
nodoPersona*agregarAlPpio(nodoPersona*listaS,nodoPersona*nuevoNodo);
void mostrarPersona(stPersona aux);
void mostrarListaSimpleRecursivo(nodoPersona*listaS);
nodoPersona*cargarMuchosAlFinal(nodoPersona*listaS);
nodoPersona*agregarAlPpioMuchos(nodoPersona*listaS);
nodoPersona*agregarAlFinal(nodoPersona*listaS,nodoPersona*nuevoNodo);

///Funciones Listas Dobles

stContacto crearContacto(nodoPersona*listaS);
int validarActivo(int dato);
int validarTipoContacto(int dato);
nodoContacto*inicListaDoble();
nodoContacto*crearNodoContacto(stContacto aux);
nodoContacto*agregarAlPpioDoble(nodoContacto*listaD,nodoContacto*nuevoNodo);
nodoContacto*agregarAlFinalDoble(nodoContacto*listaD,nodoContacto*nuevoNodo);
nodoContacto*agregarOrdenado(nodoContacto*listaD,nodoContacto*nuevoNodo);
nodoContacto*agregarAlPpioMuchosDoble(nodoPersona*listaD,nodoPersona*listaS);
nodoContacto*agregarMuchosOrdenados(nodoContacto*listaD,nodoPersona*listaS);
void mostrarDNIDisponibles(nodoPersona*listaS);
nodoContacto*cargarMuchosAlFinalDoble(nodoContacto*listaD,nodoPersona*listaS);
void mostrarContacto(stContacto aux);
void mostrarListaDobleRecursivoInverso(nodoContacto*listaD);
int contarContactos(nodoContacto*listaD,int pedido);
void mostrarListaDoble(nodoContacto*listaD);

#endif // FUNCIONES_H_INCLUDED
