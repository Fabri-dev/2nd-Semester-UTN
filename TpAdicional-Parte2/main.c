#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"

void menu();


int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void menu()
{
    int opsw=0;
    char op, inciso;
    int dato=0,aux=0;
    nodoS*listaSimple=inicLista();
    nodoD*listaDoble=inicLista();
    do
    {


        puts("Ejercicio 1");
        puts("Ejercicio 2");
        puts("Ejercicio 3");
        puts("Ejercicio 4");
        puts("Ejercicio 5");

        puts("Ejercicio 7");
        puts("---------------------------------");
        printf("Que ejercicio quiere: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:

            printf("Cuantos nodos quiere agregar a la lista?: ");
            scanf("%i",&dato);
            for(int i= 0; i < dato; i++)
            {
                aux=rand()%100;
                listaSimple=agregarAlFinal(listaSimple,crearNodoSimple(aux));
            }
            mostrarLista(listaSimple);
            break;
        case 2:
            printf("a o b?: ");
            fflush(stdin);
            scanf("%c",&inciso);
            if(inciso == 'a')
            {
                mostrarLista(listaSimple);
            }
            else if(inciso == 'b')
            {
                mostrarListaRecursivo(listaSimple);
            }
            break;
        case 3:
            dato=contarNodos(listaSimple);
            printf("La cantidad de nodos que hay es: %i\n",dato);
            break;
        case 4:
            mostrarLista(listaSimple);
            printf("Ingrese la posicion que quiere eliminar: ");
            scanf("%i",&dato);
            listaSimple=eliminarNodoXposicion(listaSimple,dato);
            mostrarLista(listaSimple);
            break;
        case 5:
            printf("Ingrese a partir de que valor quiere eliminar: ");
            scanf("%i",&dato);
            listaSimple=eliminarNodosMayores(listaSimple,dato);
            mostrarLista(listaSimple);
            break;
        case 7:
            puts("\nLISTA SIMPLE: ");
            mostrarLista(listaSimple);
            puts("\nLISTA DOBLE: ");
            mostrarListaDoble(listaDoble);
            listaDoble=simpleToDoble(listaDoble,&listaSimple);
            puts("\nLISTA SIMPLE: ");
            mostrarLista(listaSimple);
            puts("\nLISTA DOBLE: ");
            mostrarListaDoble(listaDoble);
            break;
        default:
            break;
        }

        printf("Desea volver al menu? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }
    while(op=='s' || op=='S');


}
