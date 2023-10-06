#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dato;
    struct nodoD*anterior;
    struct nodoD*siguiente;
} nodoD;

nodoD*inicListaDoble();
int preguntarDato();
nodoD*crearNodo(int aux);
nodoD*agregarAlPpioDoble(nodoD*listaD,nodoD*nuevoNodo);
nodoD*agregarAlFinalDoble(nodoD*listaD,nodoD*nuevoNodo);
nodoD*borrarNodoDoble(nodoD*listaD,int datoBorrar);
void mostrarListaDoble(nodoD*listaD);
nodoD*agregarOrdenadoDoble(nodoD*listaD,nodoD*nuevoNodo); //menor a mayor
nodoD*borrarNodoDoble(nodoD*listaD,int datoBorrar);
void mostrarListaDobleInvRecursivo(nodoD*listaD);
void mostrarListaDobleRecursivo(nodoD*listaD);












int main()
{
    nodoD*listaDoble=inicListaDoble();
//    listaDoble=agregarAlFinalDoble(listaDoble,crearNodo(preguntarDato()));
//    listaDoble=agregarAlPpioDoble(listaDoble,crearNodo(preguntarDato()));
//    listaDoble=agregarAlFinalDoble(listaDoble,crearNodo(preguntarDato()));
//    listaDoble=agregarAlPpioDoble(listaDoble,crearNodo(preguntarDato()));
    listaDoble=agregarOrdenadoDoble(listaDoble,crearNodo(preguntarDato()));
    listaDoble=agregarOrdenadoDoble(listaDoble,crearNodo(preguntarDato()));
    listaDoble=agregarOrdenadoDoble(listaDoble,crearNodo(preguntarDato()));
    listaDoble=agregarOrdenadoDoble(listaDoble,crearNodo(preguntarDato()));

//    mostrarListaDoble(listaDoble);
//    listaDoble=borrarNodoDoble(listaDoble,6);
//    puts("\n\n");
//    mostrarListaDoble(listaDoble);

    mostrarListaDobleInvRecursivo(listaDoble);
    puts("\n\n");
    mostrarListaDobleRecursivo(listaDoble);
    return 0;
}

nodoD*inicListaDoble()
{
    return NULL;
}

int preguntarDato()
{
    int dato;
    printf("Ingrese un dato: ");
    scanf("%i",&dato);
    return dato;
}

nodoD*crearNodo(int aux)
{
    nodoD*nuevoNodo=(nodoD*)malloc(sizeof(nodoD));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    return nuevoNodo;
}

nodoD*agregarAlPpioDoble(nodoD*listaD,nodoD*nuevoNodo)
{
    nuevoNodo->siguiente=listaD;
    if(listaD != NULL)
    {
        listaD->anterior=nuevoNodo;
    }
    return nuevoNodo;
}

nodoD*agregarAlFinalDoble(nodoD*listaD,nodoD*nuevoNodo)
{
    if(listaD != NULL)
    {
        nodoD*seg=listaD;
        while(seg->siguiente != NULL)
        {
            seg=seg->siguiente;
        }
        seg->siguiente=nuevoNodo;
        nuevoNodo->anterior=seg;
    }
    else
    {
        listaD=nuevoNodo;
    }
    return listaD;
}

void mostrarListaDoble(nodoD*listaD)
{
    while(listaD != NULL)
    {
        printf("Dato: %i \n",listaD->dato);
        puts("---------------------------");
        listaD=listaD->siguiente;
    }
}


nodoD*agregarOrdenadoDoble(nodoD*listaD,nodoD*nuevoNodo) //menor a mayor
{

    if(listaD != NULL)
    {
        if(nuevoNodo->dato < listaD->dato)
        {
            listaD=agregarAlPpioDoble(listaD,nuevoNodo);
        }
        else
        {
            nodoD*ante=listaD;
            nodoD*seg=listaD->siguiente;

            while(seg != NULL && seg->dato < nuevoNodo->dato)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            ante->siguiente=nuevoNodo;
            nuevoNodo->anterior=ante;
            nuevoNodo->siguiente=seg;
            if(seg != NULL)
            {
                seg->anterior=nuevoNodo;
            }
        }

    }
    else
    {
        listaD= nuevoNodo;
    }

    return listaD;
}


nodoD*borrarNodoDoble(nodoD*listaD,int datoBorrar)
{
    nodoD*aux;
    nodoD*seg=listaD->siguiente;
    if(listaD != NULL)
    {
        if(listaD->dato == datoBorrar)
        {
            aux=listaD;
            listaD=listaD->siguiente;
        }
        else
        {
            while(seg != NULL && seg->dato != datoBorrar)
            {
                seg=seg->siguiente;
            }
            if(seg != NULL)
            {
                ((nodoD*)seg->anterior)->siguiente=seg->siguiente;
                if(seg->siguiente != NULL)
                {
                ((nodoD*)seg->siguiente)->anterior=seg->anterior;

                }

                aux=seg;
            }
            else
            {
                puts("Dato no encontrado en la lista");
            }
        }


        free(aux);
    }
    else
    {
        puts("Lista vacia");
    }
    return listaD;
}

void mostrarListaDobleInvRecursivo(nodoD*listaD)
{
    if(listaD != NULL)
    {
        mostrarListaDobleInvRecursivo(listaD->siguiente);
        printf("Dato: %i \n",listaD->dato);
        puts("---------------------------");
    }
}

void mostrarListaDobleRecursivo(nodoD*listaD)
{
        if(listaD != NULL)
    {
        printf("Dato: %i \n",listaD->dato);
        puts("---------------------------");
        mostrarListaDobleRecursivo(listaD->siguiente);
    }
}







