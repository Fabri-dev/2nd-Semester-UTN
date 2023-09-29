#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
void menu()
{
    nodoS*lista1=iniciarLista();
    nodoS*lista2=iniciarLista();
    nodoS*lista3=iniciarLista();
    nodoD*listaDoble=iniciarLista();
    stExamen*arr=NULL;
    int validos=0;
    int opsw=0;
    char letra;

    puts("Ejercicio 1");
    puts("Ejercicio 2");
    puts("Ejercicio 3");
    puts("Ejercicio 4");
    puts("Ejercicio 5");
    puts("---------------------------");
    printf("Que ejercicio desea hacer?: ");
    scanf("%i",&opsw);

    switch(opsw)
    {
    case 1:
        lista1=cargarListaOrdenada(lista1);
        mostrarLista(lista1);
        puts("\n");
        lista1=eliminarRepetidos(lista1);
        mostrarLista(lista1);
        break;
    case 2:
        lista1=cargarListaOrdenada(lista1);
        lista2=cargarListaOrdenada(lista2);
        lista3=interseccion(lista1,lista2);

        if(lista3 != NULL)
        {

            puts("\nLISTA 3 (interseccion):");
            mostrarLista(lista3);
        }

        break;
    case 3:
        printf("Que inciso quiere?: ");
        fflush(stdin);
        scanf("%c",&letra);
        inciso(letra);
        break;
    case 4:
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        validos=contarAlumnosAsignaturaRecursivo(listaDoble,"progra");
        arr=crearArregloDinamicoExamen(validos);

        cargarArregloAsignaturaEspecifica(listaDoble,arr,validos,"progra");


        mostrarArreglo(arr,validos);
        break;
    case 5:
        break;
    default:
        puts("Ingrese un ejercicio valido");
        break;
    }


}

void inciso(char letra)
{
    nodoD*listaDoble=iniciarLista();
    float prom=0;
    int flag=0,cont=0;
    switch(letra)
    {
    case 'b':
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        mostrarListaDoble(listaDoble);
        break;
    case 'c':
        listaDoble=agregarAlPpioDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarAlPpioDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarAlPpioDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarAlPpioDoble(listaDoble,crearNodoDoble(crearExamen()));
        puts("\n");
        mostrarListaDoble(listaDoble);
        puts("\n");
        listaDoble=eliminarDniEspecificoDoble(listaDoble,"3");
        mostrarListaDoble(listaDoble);

        break;
    case 'd':

        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));

        prom=calcularPromedioxDniYAsignaturaDoble(listaDoble,"5","progra");
        if(prom != 0)
        {

            printf("El promedio es: %.2f",prom);
        }
        else
        {
            puts("No se encontro alumno");
        }
        break;
    case 'e':
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        verificarSiExisteDniEnAsignaturaRecursivo(listaDoble,"progra","5",0)?puts("Se encontro el dato buscado"):puts("Error dato no encontrado");
        break;
    case 'f':
        puts("Asignatura: progra");
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        mostrarExamenAsignaturaRecursivo(listaDoble,"progra");

        break;
    case 'g':
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));
        listaDoble=agregarOrdenadoDoble(listaDoble,crearNodoDoble(crearExamen()));

        mostrarListaDoble(listaDoble);

        cont=contarAlumnosAsignaturaRecursivo(listaDoble,"progra");

        if(cont != 0)
        {
            printf("\nEl nro de alumnos de esa asignatura es: %i \n",cont);
        }
        else
        {
            puts("No hay alumnos de esa asignatura");
        }
        break;
    default:
        puts("Ingrese un inciso correcto");
        break;
    }
}


