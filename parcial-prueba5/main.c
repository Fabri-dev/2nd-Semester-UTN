#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
int main()
{
    int opsw=0,dato=0;
    char op;
    char buscar[20];
    nodoD*listaDoble=inicLista();
    do
    {

        puts("Ejercicio 1");
        puts("Ejercicio 2");
        puts("Ejercicio 3");
        puts("Ejercicio 4");
        puts("Ejercicio 5");
        puts("Ejercicio 6");
        puts("-------------------");
        printf("Ingrese el ejercicio: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            agregarAlPpio(&listaDoble,crearNodo(crearJugador(listaDoble)));
            mostrarLista(listaDoble);
            break;
        case 2:

            listaDoble=agregarOrdenarListaXPosicion(listaDoble,crearNodo(crearJugador(listaDoble)));
            mostrarLista(listaDoble);
            break;
        case 3:
            printf("Ingrese el equipo del que quiere contar puntos: ");
            fflush(stdin);
            gets(buscar);
            dato=contarPuntosXEquipoRecursivo(listaDoble,buscar);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;

        }
        printf("Desea volver al menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");
    }
    while(op == 's' || op=='S');

    return 0;
}
