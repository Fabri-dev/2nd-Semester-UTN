#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "clientes.h"

void menu()
{
    int opsw;
    char op;
    int flag;
    float total=0;
    stCliente aux;
    nodoConsola*listaConsola=inicLista();
    nodoCliente*listaCliente=inicListaDoble();

    do
    {
        puts("Ejercicio 1");
        puts("Ejercicio 2");
        puts("Ejercicio 3");
        puts("Ejercicio 4");
        puts("Ejercicio 5");
        puts("Ejercicio 6");
        puts("Ejercicio 7");
        puts("Ejercicio 8");
        puts("--------------------");
        printf("Que ejercicio quiere elegir?: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            listaConsola=crearNodoConsola(crearConsola());
            mostrarListaConsola(listaConsola);
            break;
        case 2:

            listaConsola=crearNodoConsola(crearConsola());
            listaConsola= agregarOrdenadoXStock(listaConsola,crearNodoConsola(crearConsola()));
            listaConsola= agregarOrdenadoXStock(listaConsola,crearNodoConsola(crearConsola()));
            mostrarListaConsola(listaConsola);
            break;
        case 3:
            mostrarConsolasXprecioRecursivo(listaConsola,1.2);
            break;
        case 4:
            listaConsola=crearNodoConsola(crearConsola());
            flag= consultarStockConsola(listaConsola,5,"Playstation","slim");
            printf("FLAG= %i",flag);
            mostrarListaConsola(listaConsola);
            break;
        case 5:
            listaConsola=crearNodoConsola(crearConsola());
            aux=crearClienteExceptoCompra();
            listaCliente= comprarConsola(listaCliente,listaConsola,aux.Nombre,aux.mediodepago);
            mostrarListaConsola(listaConsola);
            puts("--------------------------------");
            mostrarListaClientes(listaCliente);
            break;
        case 6:
            total=calcularTotalVendido(listaCliente);
            printf("El total vendido es de: %.2f");

            break;
        case 7:
            break;
        case 8:
            break;
        default:
            break;
        }

        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }
    while(op=='s' || op=='S');

}

stConsola crearConsola()
{
    stConsola aux;

    printf("Ingrese el codigo del producto: ");
    scanf("%i",&aux.codigoProducto);

    printf("Ingrese la marca de la consola: ");
    fflush(stdin);
    gets(aux.marca);

    printf("Ingrese el precio en miles (ej: 1.2): ");
    scanf("%f",&aux.precioEnMiles);

    printf("Ingrese cuanto stock tiene: ");
    scanf("%i",&aux.stock);

    printf("Ingrese el modelo de la consola: ");
    fflush(stdin);
    gets(aux.modelo);


    return aux;
}

nodoConsola* inicLista()
{
    return NULL;
}

void mostrarConsola(stConsola aux)
{
    printf("El codigo del producto: %i \n",aux.codigoProducto);
    printf("La marca de la consola es: %s \n",aux.marca);
    printf("El modelo es: %s \n",aux.modelo);
    printf("El precio en miles es: %.2f \n",aux.precioEnMiles);
    printf("El stock es: %i \n",aux.stock);
    puts("----------------------------");
}

void mostrarListaConsola(nodoConsola*lista)
{
    while(lista != NULL)
    {
        mostrarConsola(lista->dato);
        lista=lista->siguiente;
    }

}

nodoConsola* crearNodoConsola(stConsola aux)
{
    nodoConsola*nuevoNodo=(nodoConsola*)malloc(sizeof(nodoConsola));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;

    return nuevoNodo;
}

nodoConsola* agregarAlPpio(nodoConsola*lista,nodoConsola*nuevoNodo)
{
    if(lista != NULL)
    {
        nuevoNodo->siguiente=lista;
    }
        lista=nuevoNodo;

    return lista;
}

nodoConsola* agregarOrdenadoXStock(nodoConsola*lista, nodoConsola*nuevoNodo)
{
    if(lista != NULL)
    {
        if(lista->dato.stock > nuevoNodo->dato.stock)
        {
            lista=agregarAlPpio(lista,nuevoNodo);

        }
        else
        {
            nodoConsola*seg=lista->siguiente;
            nodoConsola*ante=lista;
            while(seg != NULL && seg->dato.stock < nuevoNodo->dato.stock)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
        }
    }
    else
    {
        lista=nuevoNodo;
    }

    return lista;
}

void mostrarConsolasXprecioRecursivo(nodoConsola*lista,float precio)
{
    if(lista != NULL)
    {
        if(lista->dato.precioEnMiles == precio)
        {
            mostrarConsola(lista->dato);
        }
        mostrarConsolasXprecioRecursivo(lista->siguiente,precio);
    }
}

int consultarStockConsola(nodoConsola*lista,int consultaStock, char marcaD[], char modeloD[])
{
    int flag=0;
    if(lista != NULL)
    {
        while(lista != NULL && (strcmpi(lista->dato.marca,marcaD) != 0 || strcmpi(lista->dato.marca,marcaD) != 0 || lista->dato.stock < consultaStock))
        {
            lista=lista->siguiente;
        }
        if(lista != NULL)
        {
            flag=1;
        }
    }

    return flag;
}

float retornarTotalCompraYRestarStock(nodoConsola*lista,int consultaStock, char marcaD[], char modeloD[])
{
    float compra=0;
    if(lista != NULL)
    {
        while(lista != NULL && (strcmpi(lista->dato.marca,marcaD) != 0 || strcmpi(lista->dato.marca,marcaD) != 0 || lista->dato.stock < consultaStock))
        {
            lista=lista->siguiente;
        }
        if(lista != NULL)
        {
            compra=consultaStock*(lista->dato.precioEnMiles);
            lista->dato.stock-=consultaStock;
        }
    }

    return compra;
}



