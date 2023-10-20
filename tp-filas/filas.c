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
        inicFila(&cajas[i],i);
    }
}

void mostrarMuchasFilas(fila cajas[], int validos)
{
    for(int i=0; i < validos; i++)
    {
        mostrarUnaFila(cajas[i]);
    }
}

void ordenarClientesDeListaSimple(nodoSimple**listaS,fila*cajas[])
{
    if((*listaS) != NULL)
    {
        int contF1=0,contF3=0,contF4=0;

        while((*listaS) != NULL)
        {
            contF1=contarListaDoble(cajas[0]->primero);
            contF3=contarListaDoble(cajas[2]->primero);
            contF4=contarListaDoble(cajas[3]->primero);
            switch((*listaS)->dato.tipoCliente)
            {
            case 1:

                if(contF4 < contF3 && contF4 < contF1) // evaluo si es la f4
                {
                    cajas[3]->primero=agregarOrdenadoDobleXCantidadFacturasMenorAMayor(cajas[3]->primero,crearNodoDoble((*listaS)->dato));
                }
                else if(contF3 < contF1 && contF3 < contF4) // evaluo si es la f3
                {
                    cajas[2]->ultimo->siguiente=(*listaS);
                }
                else // la f1 recibe si llegan a ser todos iguales o si la f1 es la menor
                {
                    cajas[0]->ultimo->siguiente=(*listaS);
                }

                break;
            case 2:
                cajas[1]->ultimo->siguiente=(*listaS);
                break;
            case 3:
                cajas[2]->primero=agregarAlPpioDoble(cajas[2]->primero,crearNodoDoble((*listaS)->dato));
                break;
            case 4:
                cajas[4]->ultimo->siguiente=(*listaS);
                break;
            default:
                break;
            }
            borrarPrimeroSimple(listaS);
        }
    }
    else
    {
        puts("Fila general vacia");
    }
}

