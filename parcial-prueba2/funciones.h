#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
	int codigoProducto;
	char marca[50]; // Nintendo Switch, Xbox, Playstation
	float precioEnMiles;
    int stock;
	char modelo[50];// Común, Pro, Slim
}stConsola ;

typedef struct nodoConsola{
	stConsola dato ;
	struct nodoConsola * siguiente;
}nodoConsola;

typedef struct {

   char Nombre[50];
  int mediodepago; //1 efectivo, 2 patacones, 3 dolar     ahorro
    float totalCompra;
}stCliente ;

typedef struct nodoCliente{
	stCliente dato;
	struct nodoCliente* siguiente;
	struct nodoCliente* anterior;
}nodoCliente;



void menu();
stConsola crearConsola();
nodoConsola* inicLista();
nodoConsola* crearNodoConsola(stConsola aux);
void mostrarConsola(stConsola aux);
void mostrarListaConsola(nodoConsola*lista);
nodoConsola* agregarAlPpio(nodoConsola*lista,nodoConsola*nuevoNodo);
nodoConsola* agregarOrdenadoXStock(nodoConsola*lista, nodoConsola*nuevoNodo);
void mostrarConsolasXprecioRecursivo(nodoConsola*lista,float precio);
int consultarStockConsola(nodoConsola*lista,int consultaStock, char marcaD[], char modeloD[]);
float retornarTotalCompraYRestarStock(nodoConsola*lista,int consultaStock, char marcaD[], char modeloD[]);



#endif // FUNCIONES_H_INCLUDED
