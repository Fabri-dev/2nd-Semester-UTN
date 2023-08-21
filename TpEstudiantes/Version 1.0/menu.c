#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "menu.h"
#include "verificaciones.h"

void menu(char archivo[])
{
    int opSw=0;
    char op;
    do
    {
        opSw= opciones();
        limpiarPantalla();
        switch(opSw)
        {
        case 1:
            cargarEstudianteAlArchivo(archivo);
            break;
        case 2:
            menuEditarEstudiante(archivo);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            puts("Por favor ingrese una opcion valida");
            break;
        }
        limpiarPantalla();
        printf("Desea seguir en el menu principal? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

    }while(op=='s' || op=='S');


}

int opciones()
{
    int opsw=0;
    puts("1. Cargar estudiante");
    puts("2. Editar estudiante"); //podemos agregar notas,cambiarle el nombre,etc
    puts("3. Buscar estudiante"); // por apellido,nombre o id
    puts("4. Mostrar estudiante"); // todos,nota mas baja o mas alta y aprobados(regimen de aprobar es: 6) o desaprobados
    puts("5. Calcular promedio"); // por estudiante o del curso completo
    puts("------------------------------");
    printf("Que desea hacer?: ");
    fflush(stdin);
    scanf("%i",&opsw);
    return opsw;
}

void menuEditarEstudiante(char archivo[])
{
    int legajo=0, opSw=0;
    stEstudiante aux;
    do
    {
    mostrarTodosLosEstudiantes(archivo);
    puts("-------------------------------------------------------------");
    printf("Ingrese el legajo del estudiante que quiere modificar o agregar notas: ");
    scanf("%i",&legajo);
    }while(validarLegajo(archivo,legajo));

    limpiarPantalla();

    aux=retornarEstudianteXlegajo(archivo,legajo);
    puts("Usted eligio este estudiante:");
    mostrarEstudiante(aux);
    puts("-------------------------------------------------------------");
    opSw= mostrarOpcionesParaModificar();
    modificarEstudiante(opSw,archivo);


}


int mostrarOpcionesParaModificar()
{
    int dato=0;
    puts("1. Nombre");
    puts("2. Apellido");
    puts("3. Agregar Notas");
    puts("4. Comision");
    puts("5. Estado");
    puts("6. Volver al menu principal");
    puts("-------------------------------------------------------------");
    printf("Que desea hacer?:");
    scanf("%i",&dato);
    return dato;
}
