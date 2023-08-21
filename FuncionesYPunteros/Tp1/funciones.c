#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXDIM 10



void limpiarPantalla()
{
    system("cls");
}

void inicializarCeldas(int arr[], int validos)
{
    for (int i=0; i < validos; i++)
    {
        arr[i]=-1;
    }
    puts("Todas las celdas del arreglo fueron inicializadas en -1");

}

void mostrarArreglo(int arr[],int validos)
{
    for(int i=0; i< validos; i++)
    {
        printf("arr[%i]= %i \n",i,arr[i]);
    }

}

int cargarArreglo(int arr[])
{
    int i=0;
    char op;
    do
    {
        printf("Ingrese un valor en arr[%i]: ",i);
        scanf("%i",&arr[i]);
        i++;


        printf("Desea continuar? s/n: ");
        fflush(stdin);
        scanf("%c",&op);


    }while(op=='s' && i<MAXDIM);

    return i;
}

int sumarContArr(int arr[],int validos)
{
    int sum=0;

    for (int i=0; i < validos; i++)
    {
        sum+=arr[i];
    }
    return sum;
}


float calcularPromedio(int arr[], int validos)
{
    float prom=0;
    int sum=0;

    sum=sumarContArr(arr,validos);
    prom=(float)sum/validos;
    return prom;
}

void ejercicio1()
{
    int arreglo[MAXDIM];
    int validos=0, suma=0;
    float prom=0;
    //1:
    inicializarCeldas(arreglo,MAXDIM);
    mostrarArreglo(arreglo,MAXDIM);

    //2:
    validos=cargarArreglo(arreglo);
    mostrarArreglo(arreglo,validos);

    //3:
    suma=sumarContArr(arreglo,validos);
    printf("La suma de todos los elementos del arreglo es: %i \n",suma);

    //4:
    printf("La cantidad de elementos del arreglo es: %i \n",validos);

    //5:

    prom= calcularPromedio(arreglo,validos);
    printf("El promedio de los elementos del arreglos es: %.2f \n",prom);
}


void ejercicio2()
{
    int arreglo[MAXDIM];




}
