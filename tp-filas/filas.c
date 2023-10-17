#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filas.h"

void inicFila(fila*caja, int nroFila)
{
    printf("Ingrese el nombre del cajero: ");
    fflush(stdin);
    scanf("%s",caja->nombreCajere);

    caja->numeroFila=nroFila;
    caja->primero=inicListaDoble();
    caja->ultimo=inicListaDoble();

}

void mostrarUnaFila(fila caja)
{
    printf("El numero de fila es: %i \n",caja.numeroFila+1);
    printf("El nombre del cajero es: %s \n",caja.nombreCajere);

    if(caja.primero != NULL)
    {
        printf("El primer clientes es: %s \n",caja.primero->dato.nombreCliente);
        printf("El ultimo clientes es: %s \n",caja.ultimo->dato.nombreCliente);
    }
    else
    {
        puts("Fila vacia");
    }
    puts("------------------------------------------");
}

void inicMuchasFilas(fila*cajas[], int validos)
{
    for(int i=0; i < validos; i++)
    {
        printf("Cajero nro: %i \n",i+1);
        inicFila(&caja[i],i);
    }
}

void mostrarMuchasFilas(fila*cajas[], int validos)
{
    for(int i=0; i < validos; i++)
    {
        mostrarUnaFila(caja[i]);
    }
}

void ordenarClientesDeListaSimple(nodoSimple**listaS,fila*cajas[])
{

}

