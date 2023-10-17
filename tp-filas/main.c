#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filas.h"
#include <time.h>

const char *nombresClientes[40] = {"Juan","Maria","Carlos","Ana","Pedro","Luis","Sofia","Miguel","Laura","Pablo","Elena","Diego","Isabel","Andres","Valentina","Javier",
    "Carmen","Ricardo","Gabriela","Santiago","Natalia","Alejandro","Olivia","Fernando","Teresa","Rodrigo","Raquel","Manuel","Adriana","Gustavo","Beatriz",
    "Daniel","Patricia","Hugo","Monica","Roberto","Lorena","Carlos","Marcela"
};


int main()
{
    srand(time(NULL));

    char op;
    int opsw, dato=0,validos= 5;

    int contF1=0,contF3=0,contF4=0;

    nodoSimple*listaSimple=inicListaSimple();
    nodoDoble*listaDoble1=inicListaDoble();
    nodoDoble*listaDoble2=inicListaDoble();
    nodoDoble*listaDoble3=inicListaDoble();
    nodoDoble*listaDoble4=inicListaDoble();
    nodoDoble*listaDoble5=inicListaDoble();
    fila cajas[5];
    stCliente aux;

    do
    {
        puts("1. Cargar lista SIMPLE ");
        puts("2. Mostrar lista SIMPLE de clientes");
        puts("3. Cargar filas");
        puts("4. Mostrar filas");
        puts("5. Ubicar todos los clientes en sus respectivas filas");
        puts("6. PRUEBA");
        puts("------------------------------");
        printf("Ingrese una opcion: ");
        scanf("%i",&opsw);

        switch(opsw) // switch opcion del usuario
        {
        case 1:

            printf("Ingrese cuantos clientes quiere agregar a la fila simple: ");
            scanf("%i",&dato);


            for(int i=0; i < dato; i++)
            {
                listaSimple=agregarAlFinalSimple(listaSimple,crearNodoSimple(crearClienteAutomatico(&nombresClientes)));
            }
            mostrarListaSimple(listaSimple);
            break;
        case 2:

            mostrarListaSimple(listaSimple);

            break;

        case 3:

            inicMuchasFilas(&cajas,validos);
            puts("\n");
            mostrarMuchasFilas(&cajas,validos);


            break;
        case 4:
            mostrarMuchasFilas(&cajas,validos);
            break;
        case 5:

            break;
        case 6:

            break;
        default:



            puts("Ingrese una opcion correcta");

            break;
        }


        printf("Desea volver al menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }
    while(op=='s'||op=='S');




    return 0;
}
