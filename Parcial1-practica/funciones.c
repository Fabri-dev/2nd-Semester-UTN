#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define DIM 10
void menu()
{
    nodoAuto*lista=inicLista();
    stAuto arr[DIM];
    int validos=0;
    int suma;
    int opsw;
    char op;
    do
    {

        puts("Ejercicio 1");
        puts("Ejercicio 2");
        puts("Ejercicio 3");
        puts("Ejercicio 4");
        puts("Ejercicio 5");
        puts("Ejercicio 6");
        puts("Ejercicio 7");
        puts("----------------------------");
        printf("Ingrese que ejercicio quiere hacer: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            lista=crearNodo(crearAuto());
            break;
        case 2:

            lista=crearNodo(crearAuto());
            agregarFinal(&lista,crearNodo(crearAuto()));
            break;
        case 3:
            arr[0]=crearAuto();
            arr[1]=crearAuto();
            validos=2;
            mostrarArregloAuto(arr,validos);
            validos=insertarCelda(arr,DIM,crearAuto(),validos);
            mostrarArregloAuto(arr,validos);
            break;
        case 4:
            agregarMuchos(&lista);
            mostrarLista(lista);
            break;
        case 5:

            agregarMuchos(&lista);
            validos=pasar(lista,arr,DIM);
            puts("LISTA: ");
            mostrarLista(lista);
            puts("ARREGLO: ");
            mostrarArregloAuto(arr,validos);
            break;
        case 6:
            validos=cargarArregloAuto(arr,DIM);
            mostrarArregloRecursivo(arr,0,validos);
            break;
        case 7:
            agregarMuchos(&lista);
            suma= sumaRecursivaPares(lista);
            printf("La suma de los valores de las patentes pares de los automoviles es: %i",suma);
            break;
        default:

            puts("Ingrese un ejercicio correcto");
            break;
        }

        printf("Desea seguir eligiendo ejercicios? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    while(op=='s' || op=='S');


}

stAuto crearAuto()
{
    stAuto aux;
    printf("Ingrese la marca del automovil: ");
    fflush(stdin);
    scanf("%s",&aux.marca);

    printf("Ingrese la patente: ");
    fflush(stdin);
    scanf("%s",&aux.patente);

    printf("Ingrese el valor: ");
    scanf("%i",&aux.valor);

    return aux;
}

nodoAuto*inicLista()
{
    return NULL;
}

nodoAuto * crearNodo (stAuto aux)
{
    nodoAuto* nuevoNodo=(nodoAuto*)malloc(sizeof(nodoAuto));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente= NULL;
    return nuevoNodo;
}

void agregarFinal(nodoAuto**lista, nodoAuto*nuevo)
{
    if(*lista != NULL)
    {
        nodoAuto*seg=*lista;
        while(seg->siguiente != NULL)
        {
            seg=seg->siguiente;
        }
        seg->siguiente=nuevo;
    }
    else
    {
        *lista=nuevo;
    }
}

int insertarCelda(stAuto arr [], int dim, stAuto dato, int validos)
{
    if(validos < dim)
    {
        int i=validos-1;
        while(dato.valor < arr[i].valor && i >= 0)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=dato;
        validos++;
    }
    else
    {
        puts("Arreglo lleno");
    }
    return validos;
}

void mostrarAuto(stAuto aux)
{
    printf("La marca del auto es: %s \n",aux.marca);
    printf("La patente del auto es: %s \n",aux.patente);
    printf("El valor del auto es: %i \n",aux.valor);
    puts("----------------------------------------");
}
void mostrarArregloAuto(stAuto arr[],int validos)
{
    for(int i=0; i<validos; i++)
    {
        mostrarAuto(arr[i]);
    }
}

 void agregarMuchos(nodoAuto ** lista)
 {
     char op;
     do
     {
         nodoAuto*nuevoNodo=crearNodo(crearAuto());
         agregarFinal(lista,nuevoNodo);

        printf("Desea seguir cargando nodos? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
     }while(op=='s' || op=='S');
 }

int pasar(nodoAuto * lista, stAuto arr[], int dimension)
{
    int validos=0;
    for(int i=0; i < dimension; i++)
    {
        insertarCelda(arr,dimension,lista->dato,validos);
        validos++;
    }
    return validos;
}

void mostrarArregloRecursivo(stAuto arr[], int i, int validos)
{
    if(i<validos)
    {
        mostrarAuto(arr[i]);
        mostrarArregloRecursivo(arr,i+1,validos);
    }
    else
    {
        puts("FIN");
    }
}

int sumaRecursivaPares(nodoAuto*lista)
{
    int suma=0;
    if(lista != NULL)
    {
        if(lista->dato.patente[5] % 2==0)
            suma=lista->dato.valor;
        suma+=sumaRecursivaPares(lista->siguiente);
    }
    return suma;
}

void mostrarLista(nodoAuto*lista)
{
    while(lista != NULL)
    {
        mostrarAuto(lista->dato);
        lista=lista->siguiente;
    }
}

int cargarArregloAuto(stAuto arr[], int dimension)
{
    char op;
    int validos=0;
    do
    {
        if(validos < dimension)
        {
            arr[validos]=crearAuto();
            validos++;

        }

        printf("Desea seguir cargando el arreglo? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }while(op=='s'||op=='S');
    return validos;
}
