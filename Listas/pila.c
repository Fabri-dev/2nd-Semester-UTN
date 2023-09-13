#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

void inicPila(Pila*pilita)
{
     pilita->lista=inicLista();
}

int pilaVacia(Pila* pilita)
{
    return pilita->lista?1:0;
}

void apilar(Pila* pilita, stPersona dato)
{
    pilita->lista=agregarNuevoNodoAlPpio(pilita->lista,crearNodo(dato));
}

stPersona tope(Pila*pilita)
{
    return ((nodo*)(pilita->lista))->dato;
}

stPersona desapilar (Pila* p)
{
    stPersona retorno = ((nodo*)(p->lista))->dato;
    borrarNodoPrimero(&(p->lista));
    return retorno;
}

void leer(Pila * p){

p->lista = agregarNuevoNodoAlPpio(p->lista,crearNodo(crearPersona()));

}

void mostrarPila(Pila p){


puts("-----------------------------------------------------------");

while(p.lista != NULL)
{
    mostrarPersona(((nodo*)p.lista)->dato);
}

puts("-----------------------------------------------------------");
}

