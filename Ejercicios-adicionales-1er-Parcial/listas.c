#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
nodoS*iniciarLista()
{
    return NULL;
}

int preguntarDato()
{
    int aux;
    printf("Ingrese el dato: ");
    fflush(stdin);
    scanf("%i",&aux);
    return aux;
}

nodoS*crearNodo(int num)
{
    nodoS*nuevoNodo=(nodoS*)malloc(sizeof(nodoS)); //creo un espacio de memoria de tipo nodo
    nuevoNodo->dato=num;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoS*agregarAlFinal(nodoS*listaS,nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {
        nodoS*antes=listaS;
        nodoS*seg=listaS->siguiente;
        while(seg != NULL)
        {
            antes=seg;
            seg=seg->siguiente;
        }
        antes->siguiente=nuevoNodo;
        seg=nuevoNodo;
    }
    else
    {
        listaS=nuevoNodo;
    }

    return listaS;
}

void mostrarDato(int num)
{
    printf("El dato es: %i \n",num);

}

void mostrarLista(nodoS*lista)
{
    int i=0;
    while(lista != NULL)
    {
        printf("----------------NODO: %i---------------\n",i);
        mostrarDato(lista->dato);
        lista=lista->siguiente;
        i++;
    }
}

nodoS*agregarAlPpio(nodoS*listaS,nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {
        nuevoNodo->siguiente=listaS;
        listaS=nuevoNodo;
    }
    else
    {
        listaS=nuevoNodo;
    }

    return listaS;

}

nodoS*agregarOrdenado(nodoS*listaS,nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {
        if(nuevoNodo->dato < listaS->dato)
        {
            listaS=agregarAlPpio(listaS,nuevoNodo);
        }
        else
        {
            nodoS*antes=listaS;
            nodoS*seg=listaS->siguiente;
            while(seg != NULL && nuevoNodo->dato > listaS->dato)
            {
                antes=seg;
                seg=seg->siguiente;
            }
            antes->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
        }

    }
    else
    {
        listaS=nuevoNodo;
    }
    return listaS;
}

nodoS*cargarListaOrdenada(nodoS*listaS)
{
    char op;
    do
    {
        listaS=agregarOrdenado(listaS,crearNodo(preguntarDato()));
        printf("Desea seguir cargando nodos de manera ordenada? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    while(op=='s' || op=='S');
    return listaS;
}

nodoS*eliminarRepetidos(nodoS*listaS)
{
    nodoS*fijo=listaS;
    if(fijo->siguiente != NULL)
    {
        nodoS*borrar;

        while(fijo != NULL)
        {
            nodoS*antes=fijo;
            nodoS*revision=fijo->siguiente;
            while(revision != NULL)
            {
                if(revision->dato == fijo->dato)
                {
                    antes->siguiente=revision->siguiente;
                    borrar=revision;
                    free(borrar);
                    revision=antes->siguiente;
                }
                else
                {
                    antes=revision;
                    revision=revision->siguiente;
                }
            }



            fijo=fijo->siguiente;
        }

    }

    return listaS;
}


nodoS*interseccion(nodoS*lista1,nodoS*lista2)
{
    nodoS*lista3=iniciarLista();

    if(lista1 != NULL && lista2 != NULL)
    {
        while(lista1 != NULL && lista2 != NULL)
        {
            if(lista1->dato == lista2->dato)
            {
                lista3=agregarOrdenado(lista3,crearNodo(lista1->dato));
            }
            lista1=lista1->siguiente;
            lista2=lista2->siguiente;
        }
    }
    if(lista3 == NULL)
    {
        puts("No hay interseccion :(");
    }
    return lista3;
}

stExamen crearExamen()
{
    stExamen aux;

    printf("Ingrese su DNI: ");
    fflush(stdin);
    gets(aux.dni);

    printf("Ingrese el nombre de la asignatura: ");
    fflush(stdin);
    gets(aux.asignatura);

    printf("Ingrese el numero de parcial: ");
    scanf("%i",&aux.nroParcial);

    printf("Ingrese la nota del parcial: ");
    scanf("%f",&aux.Nota);

    return aux;

}

nodoD*crearNodoDoble(stExamen aux)
{
    nodoD*nuevoNodo=(nodoD*)malloc(sizeof(nodoD));
    nuevoNodo->anterior=NULL;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->dato= aux;
    return nuevoNodo;
}

nodoD*agregarAlPpioDoble(nodoD*listaD,nodoD*nuevoNodo)
{
    if(listaD != NULL)
    {
        nuevoNodo->siguiente=listaD;
        listaD->anterior=nuevoNodo;
        listaD=nuevoNodo;
    }
    else
    {
        listaD=nuevoNodo;
    }
    return listaD;
}

nodoD*agregarOrdenadoDoble(nodoD*listaD,nodoD*nuevoNodo)
{
    if(listaD == NULL)
    {
        listaD=nuevoNodo;
    }
    else if(nuevoNodo->dato.dni < listaD->dato.dni)
    {
        listaD=agregarAlPpioDoble(listaD,nuevoNodo);
    }
    else
    {
        nodoD*antes=listaD;
        nodoD*seg=listaD->siguiente;
        while(seg != NULL && nuevoNodo->dato.dni > listaD->dato.dni)
        {
            antes=seg;
            seg=seg->siguiente;
        }
        nuevoNodo->siguiente=seg;
        antes->siguiente=nuevoNodo;
        nuevoNodo->anterior=antes;
        if(seg != NULL)
        {
            seg->anterior=nuevoNodo;
        }

    }
    return listaD;
}

void mostrarExamen(stExamen dato)
{
    printf("El dni es: %s \n",dato.dni);
    printf("La asignatura es: %s \n",dato.asignatura);
    printf("La nota del examen es: %.2f \n",dato.Nota);
    printf("El nro de parcial es: %i \n",dato.nroParcial);
    puts("--------------------------------------------------");
}

void mostrarListaDoble(nodoD*listaD)
{
    while(listaD != NULL)
    {
        mostrarExamen(listaD->dato);
        listaD= listaD->siguiente;
    }
}

nodoD*eliminarDniEspecificoDoble(nodoD*listaD,char dniEliminar[])
{
    if(listaD != NULL)
    {
        nodoD*ante=listaD;
        nodoD*seg=listaD;
        nodoD*aux;
        while(seg != NULL)
        {
            if(strcmpi(seg->dato.dni,dniEliminar)==0)
            {
                aux=seg; // guardo el que quiero borrar para mas tarde

                if(ante->anterior == NULL) // el principio
                {
                    seg=seg->siguiente;
                    seg->anterior=ante->anterior;
                    aux->siguiente=NULL;

                    listaD= seg;

                }
                else if(seg->siguiente == NULL) // el final
                {
                    ante->siguiente=seg->siguiente;
                    aux->anterior= NULL;
                }
                else
                {

                    ante->siguiente=seg->siguiente; // conecto al anterior con el siguiente
                    aux->anterior=NULL; // desconecto el anterior del que quiero borrar

                    seg=seg->siguiente; // me muevo hacia adelante
                    seg->anterior=ante; // conecto el siguiente del que quiero borrar con el anterior


                    aux->siguiente=NULL; // desconecto el siguiente del que quiero borrar
                }

                free(aux);

            }



            ante=seg;
            seg=seg->siguiente;
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return listaD;
}

float calcularPromedioxDniYAsignaturaDoble(nodoD*listaD,char dniBuscar[], char asignaturaBuscar[])
{
    float prom=0;
    float sum=0;
    int contador=0;
    while(listaD != NULL)
    {
        if(strcmpi(listaD->dato.asignatura,asignaturaBuscar)==0 && strcmpi(listaD->dato.dni,dniBuscar)==0)
        {
            sum+= listaD->dato.Nota;
            contador++;
        }
        listaD=listaD->siguiente;
    }
    if(contador != 0)
    {

        prom=(float) sum/contador;
    }
    return prom;
}

int verificarSiExisteDniEnAsignaturaRecursivo(nodoD*listaD,char asignaturaBuscar[],char dniBuscar[],int flag)
{
    if(flag==0 && strcmpi(listaD->dato.asignatura,asignaturaBuscar)==0 && strcmpi(listaD->dato.dni,dniBuscar)==0)
    {
        flag=1;
    }
    else
    {
        flag=verificarSiExisteDniEnAsignaturaRecursivo(listaD->siguiente,asignaturaBuscar,dniBuscar,flag);
    }
    return flag;
}

void mostrarExamenAsignaturaRecursivo(nodoD*listaD,char asignaturaBuscar[])
{
    if(listaD != NULL && strcmpi(listaD->dato.asignatura,asignaturaBuscar) == 0)
    {
        printf("DNI: %s \n",listaD->dato.dni);
        printf("Nro. parcial: %i \n",listaD->dato.nroParcial);
        printf("Nota: %.2f \n",listaD->dato.Nota);

        mostrarExamenAsignaturaRecursivo(listaD->siguiente,asignaturaBuscar);
    }
    else
    {
        puts("Final");
    }
}

int contarAlumnosAsignaturaRecursivo(nodoD*listaD,char asignaturaBuscar[])
{
    int rta = 0;
    if(listaD != NULL)
    {
        puts("Entre a distinto de null");
        if(strcmpi(listaD->dato.asignatura,asignaturaBuscar)==0)
        {
            puts("encontre la asignatura");

            rta=1;
            listaD=ultimaOcurrenciaDniRecursivo(listaD,listaD->dato.dni);

        }
        rta+=contarAlumnosAsignaturaRecursivo(listaD->siguiente,asignaturaBuscar);
    }
    else
    {
        puts("lista vacia");
    }


    return rta;
}


nodoD*ultimaOcurrenciaDniRecursivo(nodoD*listaD, char dniBuscar[])
{

    if(listaD != NULL)
    {
        nodoD*proximo = listaD->siguiente;
        if(proximo != NULL)
        {
            if(strcmpi(proximo->dato.dni,listaD->dato.dni) == 0)
            {
                listaD=ultimaOcurrenciaDniRecursivo(proximo,dniBuscar);
            }

        }

    }

    return listaD;
}

stExamen*crearArregloDinamicoExamen(int t)
{
    stExamen*arr=(stExamen*)malloc(sizeof(stExamen)*t);
    return arr;
}


void cargarArregloAsignaturaEspecifica(nodoD*listaD,stExamen arr[],int dim,char asignaturaBuscar[])
{
    int i=0;
    while(i < dim)
    {
        if(strcmpi(listaD->dato.asignatura,asignaturaBuscar)==0)
        {
            arr[i]=listaD->dato;
            i++;
        }
        listaD=ultimaOcurrenciaDniRecursivo(listaD,listaD->dato.dni);
        listaD=listaD->siguiente;
    }
}


void mostrarArreglo(stExamen arr[],int validos)
{
    puts("\nEsto es un arreglo");
    for(int i=0; i <validos; i++)
    {
        mostrarExamen(arr[i]);
    }

}
