#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int main()
{
    char op;
    int opsw=0,dato=0;

    nodoPersona*listaSimple=inicListaSimple();
    nodoContacto*listaDoble=inicListaDoble();
    do
    {
        puts("1. Agregar al principio Personas (Muchas)");
        puts("2. Agregar al final Personas (Muchas)");
        puts("3. Verificar si existe un DNI buscado");
        puts("4. Mostrar lista Personas de forma recursiva");
        puts("5. Agregar al principio Contacto (Muchos)");
        puts("6. Agregar al final Contacto(Muchos)");
        puts("7. Agregar de manera ordenada x DNI Contacto (Muchos)");
        puts("8. Mostrar contactos de manera Recursiva Inversa");
        puts("9. Mostrar contactos normal");
        puts("10. Contar contactos");
        puts("-------------------------------------------");
        printf("Que ejercicio elige: ");
        scanf("%i",&opsw);


        switch(opsw)
        {
        case 1:
            listaSimple=agregarAlPpioMuchos(listaSimple);
            break;
        case 2:
            listaSimple= cargarMuchosAlFinal(listaSimple);
            break;
        case 3:
            printf("Ingrese el dni que quiere buscar: ");
            scanf("%i",&dato);
            verificarSiExisteDniRecursivo(listaSimple,dato)?puts("Existe el DNI buscado"):puts("El DNI buscado no se encontro");
            break;
        case 4:
            mostrarListaSimpleRecursivo(listaSimple);
            break;
        case 5:
            listaDoble=agregarAlPpioMuchosDoble(listaDoble,listaSimple);
            break;
        case 6:
            listaDoble=cargarMuchosAlFinalDoble(listaDoble,listaSimple);
            break;
        case 7:
            listaDoble=agregarMuchosOrdenados(listaDoble,listaSimple);
            break;
        case 8:
            mostrarListaDobleRecursivoInverso(listaDoble);
            break;
        case 9:
            mostrarListaDoble(listaDoble);
            break;
        case 10:
            //deje que el usuario elija para darle mas funcionalidad al programa
            puts("0. Inactivos");
            puts("1. Activos");
            puts("--------------");
            printf("Que contactos quiere mostrar?: ");
            scanf("%i",&dato);
            switch(dato)
            {
            case 0:
                dato=contarContactos(listaDoble,0);
                printf("La cantidad de contactos inactivos es: %i \n",dato);
                break;
            case 1:
                dato=contarContactos(listaDoble,1);
                printf("La cantidad de contactos activos es: %i \n",dato);
                break;
            default:
                puts("Ingrese una opcion valida");
                break;
            }
            break;

        default:
            break;
        }
        printf("Desea volver al menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

        system("cls");
    }
    while(op=='s' || op=='S');




    return 0;
}
