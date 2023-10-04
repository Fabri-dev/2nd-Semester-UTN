#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dato;
    struct nodoS*siguiente;
} nodoS;

nodoS*inicLista();
nodoS*crearNodoNormal(int aux);
nodoS*agregarAlPpioNormal(nodoS*listaS,nodoS*nuevoNodo);
nodoS*agregarAlFinalNormal(nodoS*listaS,nodoS*nuevoNodo);
nodoS*agregarOrdenadoNormal(nodoS*listaS,nodoS*nuevoNodo);
int preguntarDato();
void mostrarListaNormal(nodoS*lista);
void agregarAlPpioRefe(nodoS**listaS,nodoS*nuevoNodo);
void agregarAlFinalRefe(nodoS**listaS,nodoS*nuevoNodo);
nodoS*borrarUnNodoNormal(nodoS*listaS,int datoBorrar);
void borrarUnNodoRefe(nodoS**listaS,int datoBorrar);
void agregarOrdenadoRefe(nodoS**listaS,nodoS*nuevoNodo);
void crearNodoRefe(nodoS**nuevoNodo,int aux);
void mostrarListaRecursivo(nodoS*listaS);
void mostrarListaInvertidoRecursivo(nodoS*listaS);
void mostrarListaReferenciaRecursivo(nodoS**listaS);
int contarNodosIterativo(nodoS*listaS);
int contarNodosRecursivo(nodoS*listaS);
nodoS*retornarUnNodoEspecifico(nodoS*listaS,int datoBuscar);

int main()
{
    int dato=0;
    nodoS*listaSimple=inicLista();

    listaSimple=agregarAlFinalNormal(listaSimple,crearNodoNormal(preguntarDato()));
    listaSimple=agregarAlPpioNormal(listaSimple,crearNodoNormal(preguntarDato()));
    listaSimple=agregarOrdenadoNormal(listaSimple,crearNodoNormal(preguntarDato()));
//    agregarAlPpioRefe(&listaSimple,crearNodoNormal(preguntarDato()));
//    agregarAlPpioRefe(&listaSimple,crearNodoNormal(preguntarDato()));
//    agregarAlPpioRefe(&listaSimple,crearNodoNormal(preguntarDato()));
//    agregarAlFinalRefe(&listaSimple,crearNodoNormal(preguntarDato()));
//    mostrarListaNormal(listaSimple);
//    listaSimple=borrarUnNodoNormal(listaSimple,5);
//    borrarUnNodoRefe(&listaSimple,10);
//    puts("\n\n\n\n");
//    mostrarListaNormal(listaSimple);
//    agregarOrdenadoRefe(&listaSimple,crearNodoNormal(preguntarDato()));
//    agregarOrdenadoRefe(&listaSimple,crearNodoNormal(preguntarDato()));
//    agregarOrdenadoRefe(&listaSimple,crearNodoNormal(preguntarDato()));
//    nodoS*nuevoNodo;
//    crearNodoRefe(&nuevoNodo,65);
//    agregarAlPpioRefe(&listaSimple,nuevoNodo);
    mostrarListaNormal(listaSimple);
//    puts("\n\n\n");
//    mostrarListaInvertidoRecursivo(listaSimple);
//    puts("\n\n\n");
//    mostrarListaRecursivo(listaSimple);
//    puts("\n\n\n");
//    mostrarListaReferenciaRecursivo(&listaSimple);
//    dato=contarNodosIterativo(listaSimple);
//    printf("Tienes: %i nodos",dato);
//    dato=contarNodosRecursivo(listaSimple);
//    printf("Tienes: %i nodos",dato);




    return 0;
}


nodoS*inicLista()
{
    return NULL;
}

int preguntarDato()
{
    int dato=0;
    printf("Ingrese un dato: ");
    scanf("%i",&dato);
    return dato;
}
nodoS*crearNodoNormal(int aux)
{
    nodoS*nuevoNodo=(nodoS*)malloc(sizeof(nodoS));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoS*agregarAlPpioNormal(nodoS*listaS,nodoS*nuevoNodo)
{
    nuevoNodo->siguiente=listaS;
    return nuevoNodo;
}

nodoS*agregarAlFinalNormal(nodoS*listaS,nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {
        nodoS*aux=listaS;
        while(aux->siguiente != NULL)
        {
            aux= aux->siguiente;
        }
        aux->siguiente=nuevoNodo;
    }
    else
    {
        listaS=nuevoNodo;
    }
    return listaS;
}

nodoS*agregarOrdenadoNormal(nodoS*listaS,nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {

        if(listaS->dato > nuevoNodo->dato)
        {
            nuevoNodo->siguiente=listaS;
            listaS=nuevoNodo;
        }
        else
        {
            nodoS*ante=listaS;
            nodoS*seg=listaS->siguiente;
            while(seg != NULL && seg->dato > nuevoNodo->dato)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
        }

    }
    else
    {
        listaS=nuevoNodo;
    }
    return listaS;


}

void mostrarListaNormal(nodoS*lista)
{
    while(lista != NULL)
    {
        printf("Dato: %i \n",lista->dato);
        printf("Puntero del nodo: %p\n",lista);
        puts("-----------------------------");
        lista=lista->siguiente;
    }
}

void agregarAlPpioRefe(nodoS**listaS,nodoS*nuevoNodo)
{
    nuevoNodo->siguiente=(*listaS);
    (*listaS)=nuevoNodo;
}

void agregarAlFinalRefe(nodoS**listaS,nodoS*nuevoNodo)
{
    if((*listaS) != NULL)
    {
        nodoS*aux=(*listaS);
        while(aux->siguiente != NULL)
        {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevoNodo;
    }
    else
    {
        (*listaS)=nuevoNodo;
    }
}

nodoS*borrarUnNodoNormal(nodoS*listaS,int datoBorrar)
{
    if(listaS != NULL)
    {
        nodoS*aux=listaS;
        if(listaS->dato == datoBorrar)
        {
            listaS=listaS->siguiente;
            free(aux);
        }
        else
        {
            nodoS*ante=listaS;
            nodoS*seg=listaS->siguiente;
            while(seg != NULL && seg->dato != datoBorrar)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            if(seg != NULL)
            {
                ante->siguiente=seg->siguiente;
                free(seg);
            }
            else
            {
                puts("El dato que se busco no ha sido encontrado");
            }
        }

    }
    else
    {
        puts("Lista vacia");
    }
    return listaS;
}

void borrarUnNodoRefe(nodoS**listaS,int datoBorrar)
{
    if((*listaS) != NULL)
    {
        nodoS*aux=(*listaS);
        if(aux->dato == datoBorrar)
        {
            (*listaS)=(*listaS)->siguiente;
            free(aux);
        }
        else
        {
            nodoS*seg=(*listaS)->siguiente;
            while(seg != NULL && seg->dato != datoBorrar)
            {
                aux=seg;
                seg=seg->siguiente;
            }
            if(seg != NULL)
            {
                aux->siguiente=seg->siguiente;
                free(seg);
            }
            else
            {
                puts("Dato no encontrado");
            }
        }
    }
    else
    {
        puts("Lista vacia");
    }


}

void agregarOrdenadoRefe(nodoS**listaS,nodoS*nuevoNodo)
{
    if((*listaS) != NULL)
    {
        if((*listaS)->dato > nuevoNodo->dato)
        {
            nuevoNodo->siguiente=(*listaS);
            (*listaS)=nuevoNodo;
        }
        else
        {
            nodoS*ante=(*listaS);
            nodoS*seg=(*listaS)->siguiente;
            while(seg != NULL && seg->dato < nuevoNodo->dato)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
        }
    }
    else
    {
        (*listaS)=nuevoNodo;
    }
}

void crearNodoRefe(nodoS**nuevoNodo,int aux)
{
    (*nuevoNodo)=(nodoS*)malloc(sizeof(nodoS));
    (*nuevoNodo)->siguiente=NULL;
    (*nuevoNodo)->dato=aux;
}

void mostrarListaRecursivo(nodoS*listaS)
{
    if(listaS != NULL)
    {
        printf("Dato: %i \n",listaS->dato);
        puts("-----------------------------");
        mostrarListaRecursivo(listaS->siguiente);
    }
}
void mostrarListaInvertidoRecursivo(nodoS*listaS)
{
    if(listaS != NULL)
    {
        mostrarListaInvertidoRecursivo(listaS->siguiente);
        printf("Dato: %i \n",listaS->dato);
        puts("-----------------------------");
    }
}

void mostrarListaReferenciaRecursivo(nodoS**listaS)
{
    if((*listaS) != NULL)
    {
        printf("Dato: %i \n",(*listaS)->dato);
        puts("-----------------------------");
        mostrarListaReferenciaRecursivo(&(*listaS)->siguiente);
    }
}

int contarNodosIterativo(nodoS*listaS)
{
    int cont=0;
    while(listaS != NULL)
    {
        cont++;
        listaS=listaS->siguiente;
    }

    return cont;
}

int contarNodosRecursivo(nodoS*listaS)
{
    int cont=0;
    if(listaS != NULL)
    {
        cont=1+contarNodosRecursivo(listaS->siguiente);

    }

    return cont;
}

nodoS*retornarUnNodoEspecifico(nodoS*listaS,int datoBuscar)
{
    nodoS*aux;
    int flag=0;
    if(listaS != NULL)
    {
        while(listaS != NULL &&flag==0)
        {
            if(listaS->dato == datoBuscar)
            {
                flag=1;
                aux=listaS;
            }
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return aux;
}









