#ifndef LISTAS2_H_INCLUDED
#define LISTAS2_H_INCLUDED

typedef struct{

char nombre[20];
int edad;

}stPersona;

typedef struct{

stPersona dato;

struct nodo2* ant;
struct nodo2* sig;
}nodo2;




stPersona crearPersona();
void mostrarPersona(stPersona aux);

nodo2* inicLista();
nodo2* crearNodoDoble(stPersona aux);
nodo2* agregarAlPpio(nodo2* lista,nodo2* nuevoNodo);
int verificarSiExisteNombre(nodo2*lista,char nombre[]);
nodo2*agregarAlFinal(nodo2 *lista,nodo2*nuevoNodo);
nodo2* buscarUltimoNodo(nodo2* lista);
nodo2* agregarEnOrdenXedad(nodo2* lista,nodo2* nuevoNodo);
void mostrarLista(nodo2*lista);
nodo2* cargarListaDoble(nodo2*lista);

int devolverCapicua (nodo2* lista,nodo2* ulti);
 nodo2* eliminarNodoDelMedio(nodo2 * lista);
#endif // LISTAS2_H_INCLUDED
