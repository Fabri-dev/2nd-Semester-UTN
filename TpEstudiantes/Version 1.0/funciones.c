#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "menu.h"
#include "verificaciones.h"

stEstudiante crearUnEstdiante(char archivoEstudiante[])
{
    stEstudiante aux;
    int i = 0;
    char op;

    aux.legajo=buscarUltimoID(archivoEstudiante); // legajo autoincremental
    aux.estado=1; // 1= activo , 0= inactivo
    do
    {
        printf("Ingrese el nombre del estudiante: ");
        fflush(stdin);
        gets(aux.nombre);
    }
    while(validarNumEnString(aux.nombre));

    do
    {
        printf("Ingrese el apellido del estudiante: ");
        fflush(stdin);
        gets(aux.apellido);
    }
    while(validarNumEnString(aux.apellido));

    do
    {
        printf("Ingrese la comision del estudiante: ");
        scanf("%i",&aux.comision);
    }
    while(validarComision(aux.comision)); ///agregar validacion de que no haya caracteres en numeros


    do
    {
        do
        {
            printf("Ingrese las notas correspondiente del alumno (max 6): ");
            fflush(stdin);
            scanf("%i",&aux.notas[i]);
        }
        while(validarNota(aux.notas[i]));

        i++;

        if(i < DIM_NOTAS)
        {
        puts("Desea ingresar mas notas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        }

    }
    while((op=='s'||op == 'S') && i<DIM_NOTAS);

    aux.cantidadNotas=i;

    return aux;
}

void limpiarPantalla()
{
    system("cls");
}

void cargarEstudianteAlArchivo(char archivo[])
{
    stEstudiante aux;
    FILE*buffer=fopen(archivo,"ab");
    if(buffer != NULL)
    {
        aux=crearUnEstdiante(archivo);
        fwrite(&aux,sizeof(stEstudiante),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}

void mostrarEstudiante(stEstudiante aux)
{
    puts("---------------------------------");
    printf("Legajo: %i \n",aux.legajo);
    printf("Nombre: %s \n",aux.nombre);
    printf("Apellido: %s \n",aux.apellido);
    printf("Comision: %i \n",aux.comision);
    printf("Notas: ");
    mostrarNotas(aux);
    printf("Estado: %i \n",aux.estado);
}
void mostrarNotas(stEstudiante aux)
{
    for (int i=0; i < aux.cantidadNotas; i++)
    {
        printf("(%i)",aux.notas[i]);
    }
    printf("\n");
}

void mostrarTodosLosEstudiantes(char archivo[])
{
    FILE*buffer=fopen(archivo,"rb");
    stEstudiante aux;
    if(buffer !=NULL)
    {
        while(fread(&aux,sizeof(stEstudiante),1,buffer)>0)
        {
            mostrarEstudiante(aux);
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}

stEstudiante retornarEstudianteXlegajo(char archivo[], int legajo)
{
    stEstudiante aux;
    int flag=1;
    FILE*buffer=fopen(archivo,"rb");
    if(buffer!= NULL)
    {
        while(fread(&aux,sizeof(stEstudiante),1,buffer) >0 && flag==0)
        {
            if(aux.legajo == legajo)
            {
                flag=0;
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("error con el archivo");
    }

    if(flag == 1)
    {
        puts("No se encontro un estudiante con ese legajo");
    }

    return aux;

}

void modificarEstudiante(int opsw, char archivo[])
{
    switch(opsw)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
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





}
