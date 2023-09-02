#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
stPersona crearPersona()
{
    stPersona aux;

    printf("Ingrese el nombre de la persona: ");
    fflush(stdin);
    gets(aux.nombre);
    do
    {
        printf("Ingrese la edad de la persona: ");
        scanf("%i",&aux.edad);

    }
    while(validarEdad(aux.edad));


    return aux;
}

int validarEdad(int dato)
{
    int flag=0;

    if(dato <=0)
    {
        flag=1;
    }

    return flag;
}





void cargarArchivoPersonas(char archivo[])
{
    char op;
    FILE*buffer=fopen(archivo,"ab");

    if(buffer != NULL)
    {

        do
        {

            stPersona aux=crearPersona();
            fwrite(&aux,sizeof(stPersona),1,buffer);

            printf("Desea seguir cargando personas al archivo? s/n: ");
            fflush(stdin);
            scanf("%c",&op);
        }
        while(op == 's' || op=='S');


        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}

void mostrarPersona(stPersona aux)
{
    printf("El nombre es: %s \n",aux.nombre);
    printf("La edad es: %i \n",aux.edad);
    puts("-----------------------------------------\n");
}


nodo*inicLista()
{
    return NULL;
}

nodo*crearNodo(stPersona aux)
{
    nodo*nuevoNodo=(nodo*)malloc(sizeof(nodo)); //creo el espacio del nuevo nodo
    nuevoNodo->dato=aux; //le asigno un valor al campo dato
    nuevoNodo->siguiente=NULL; //el siguiente del nuevo nodo nace "huerfano" osea que se crea apuntando a la nada
    return nuevoNodo;
}

nodo*agregarNuevoNodoAlFinal(nodo*cabeza,nodo*nuevoNodo)
{
    nodo*seg=cabeza;

    if(cabeza != NULL)
    {

        while(seg->siguiente != NULL)
        {
            seg=seg->siguiente;
        }
        seg->siguiente=nuevoNodo;


    }
    else
    {
        cabeza=nuevoNodo;

    }

    return cabeza;
}

nodo*archivoToLista(nodo*cabeza,char archivo[])
{
    stPersona aux;
    FILE*buffer=fopen(archivo,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stPersona),1,buffer)>0)
        {
            cabeza=agregarNuevoNodoAlPpio(cabeza,crearNodo(aux));


        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return cabeza;
}

nodo*agregarNuevoNodoAlPpio(nodo*cabeza,nodo*nuevoNodo)
{
    if(cabeza != NULL)
    {
        nuevoNodo->siguiente=cabeza;
        cabeza=nuevoNodo;

    }
    else
    {
        cabeza=nuevoNodo;
    }
    return cabeza;
}

void mostrarLista(nodo*cabeza)
{
    int i=0;

    while(cabeza != NULL)
    {
        printf("---------------Nodo(%i)-------------------\n",i);
        mostrarPersona(cabeza->dato);
        cabeza=cabeza->siguiente;
        i++;
    }
}

//2. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.

nodo*ArchivoToListaOrdenado(nodo*cabeza,char archivo[])
{
    stPersona aux;
    FILE*buffer=fopen(archivo,"rb");

    if(buffer != NULL)
    {

        while(fread(&aux,sizeof(stPersona),1,buffer)>0)
        {
            //mostrarPersona(aux);
            cabeza=ordenarMenoraMayor(cabeza,crearNodo(aux));

        }

        fclose(buffer);
    }
    else
    {
        puts("error con el archivo");
    }

    return cabeza;
}

nodo*ordenarMenoraMayor(nodo*cabeza,nodo*nuevoNodo)
{
    if(cabeza == NULL)
    {
         cabeza = nuevoNodo;
    }
    else if(nuevoNodo->dato.edad < cabeza->dato.edad)
    {

            cabeza=agregarNuevoNodoAlPpio(cabeza,nuevoNodo);

    }
    else
    {
        nodo*seg=cabeza->siguiente;
        nodo*antes=cabeza;

            while(seg != NULL && nuevoNodo->dato.edad>seg->dato.edad)
            {
                antes=seg;
                seg=seg->siguiente;
            }
            antes->siguiente=nuevoNodo;
            if(seg != NULL)
            {
                nuevoNodo->siguiente=seg;
            }



    }

    return cabeza;
}

//Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada. (considerar caso ordenada y caso desordenada)
int buscarPersonaLista(nodo*cabeza,stPersona busqueda)
{
    int flag=0;

    if(cabeza != NULL)
    {
        nodo*seg=cabeza;
        while(seg != NULL && flag==0)
        {

            if(seg->dato.edad == busqueda.edad && strcmpi(seg->dato.nombre,busqueda.nombre)==0)
            {
                flag=1;
            }
            seg=seg->siguiente;
        }

    }
    else
    {
        flag=0;
    }



    return flag;
}
//Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos.






