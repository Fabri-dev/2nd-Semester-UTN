#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "funciones.h"


stCliente crearClienteExceptoCompra()
{
    stCliente aux;

    printf("Ingrese el nombre del cliente: ");
    fflush(stdin);
    gets(aux.Nombre);

    printf("Ingrese el medio de pago: ");
    scanf("%i",&aux.mediodepago);

    return aux;
}

nodoCliente*crearNodoCliente(stCliente aux)
{
    nodoCliente*nuevoNodo=(nodoCliente*)malloc(sizeof(nodoCliente));
    nuevoNodo->dato=aux;
    nuevoNodo->anterior=NULL;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoCliente*inicListaDoble()
{
    return NULL;
}

void mostrarCliente(stCliente aux)
{
    printf("El nombre del cliente es: %s \n",aux.Nombre);
    printf("El medio de pago es: %i \n",aux.mediodepago);
    printf("El monto es: %.2f \n",aux.totalCompra);
    puts("----------------------------------------");

}

void mostrarListaClientes(nodoCliente*listaD)
{
    while(listaD != NULL)
    {
        mostrarCliente(listaD->dato);
        listaD=listaD->siguiente;
    }
}

nodoCliente*retornarUltimoNodoCliente(nodoCliente*listaD)
{
    nodoCliente*seg=listaD->siguiente;
    while(seg->siguiente != NULL)
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodoCliente*agregarAlFinal(nodoCliente*listaD,nodoCliente*nuevoNodo)
{
    if(listaD != NULL)
    {
        nodoCliente*seg=retornarUltimoNodoCliente(listaD);
        seg->siguiente=nuevoNodo;
        nuevoNodo->anterior=seg;
    }
    else
    {
        listaD= nuevoNodo;
    }
    return listaD;
}
nodoCliente*comprarConsola(nodoCliente*listaDoble,nodoConsola*lista,char nombreCliente[],int medioPago)
{

    int flag;
    char marcaAux[20];
    char modeloAux[20];
    int stockAux;
    stCliente aux;

        mostrarListaConsola(lista);
        puts("----------------------------------------");
        printf("Ingrese la marca que quiere comprar: ");
        fflush(stdin);
        gets(marcaAux);
        printf("Ingrese el modelo que quiere comprar: ");
        fflush(stdin);
        gets(modeloAux);
        printf("Ingrese la cantidad de consolas que quiere comprar: ");
        scanf("%i",&stockAux);
        flag=consultarStockConsola(lista,stockAux,marcaAux,modeloAux);

        if(flag == 1) // hay stock
        {
        aux.mediodepago=medioPago;
        strcpy(aux.Nombre,nombreCliente);
        aux.totalCompra=retornarTotalCompraYRestarStock(lista,stockAux,marcaAux,modeloAux);
        listaDoble= agregarAlFinal(listaDoble,crearNodoCliente(aux));
        }
        else //no hago nada
        {
            puts("Error stock insuficiente no voy a crear un cliente");
        }

    return listaDoble;
}

float calcularTotalVendido(nodoCliente*listaD)
{
    float total=0;

    while(listaD!= NULL)
    {
        total+=listaD->dato.totalCompra;
        listaD=listaD->siguiente;
    }
    return total;
}

nodoCliente*cargarFilaClientes(nodoCliente*fila,nodoConsola*listaSimple)
{
    char op;
    do
    {
        stCliente aux=crearClienteExceptoCompra();
        fila=comprarConsola(fila,listaSimple,aux.Nombre,aux.mediodepago);
        printf("Desea seguir cargando clientes a la fila? s/n");
        fflush(stdin);
        scanf("%c",&op);

    }while(op=='s'||op=='S');

    return fila;
}

nodoCliente* borrarNodoPrimerCliente(nodoCliente*listaD)
{
    nodoCliente*nuevaListaD;
    if(listaD != NULL)
    {
        nodoCliente*aux=listaD;
        if(listaD->siguiente != NULL)
        {
            listaD=listaD->siguiente;
            listaD->anterior=NULL;


            aux->siguiente=NULL;
        }
        free(aux);
    }
    else
    {
        puts("Lista Vacia");
    }
    return nuevaListaD;
}

nodoCliente*atender(nodoCliente*fila)
{
    if(fila != NULL)
    {
        borrarNodoPrimerCliente(fila);
        puts("Se atendio un cliente !!\n");
    }
    else
    {
        puts("Fila vacia !");
    }
    return fila;
}
