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

void borrarNodoPrimero (nodo** lista)
{
    if (*lista)
    {
        nodo* aux=*lista;
        *lista=(*lista)->siguiente;
        free(aux);
    }
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


nodo*cargarLista(nodo*cabeza)
{
    char op;
    do
    {
        cabeza=agregarNuevoNodoAlFinal(cabeza,crearNodo(crearPersona()));

        printf("Desea seguir cargando nodos a la lista? s/n: ");
        fflush(stdin);
        scanf("%c",&op);


    }
    while(op=='s'||op=='S');


    return cabeza;
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

        while(seg != NULL && nuevoNodo->dato.edad > seg->dato.edad)
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

//Hacer una funci�n que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada. (considerar caso ordenada y caso desordenada)
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




    return flag;
}
//Hacer una funci�n que intercale en orden los elementos de dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros, no se deben crear nuevos nodos.

nodo*intercalarListasXedad(nodo*lista1,nodo*lista2)
{
    nodo*listaIntercalada=inicLista();
    nodo*aux;
    nodo*ante=listaIntercalada;

    while(lista1 != NULL && lista2 != NULL)
    {
        if(lista1->dato.edad < lista2->dato.edad)
        {
            aux=lista1;
            lista1=lista1->siguiente;
        }
        else
        {
            aux=lista2;
            lista2=lista2->siguiente;
        }

        aux->siguiente=NULL;


        listaIntercalada=agregarNuevoNodoAlFinal(listaIntercalada,aux);

    }


    listaIntercalada=agregarNuevoNodoAlFinal(listaIntercalada,(lista1? lista1:lista2));

    return listaIntercalada;
}

//Invertir los elementos de una lista redireccionando solamente los punteros. (No se deben crear nuevos nodos)
nodo*invertirElementosLista(nodo*cabeza)
{
    nodo*invertido=inicLista();
    nodo*aux;
    if(cabeza != NULL)
    {

        while(cabeza != NULL)
        {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;
            invertido= agregarNuevoNodoAlPpio(invertido,aux);
        }
    }
    else
    {
        puts("La lista esta vacia");
    }


    return invertido;
}


nodo*borrarNodoXNombre(nodo*cabeza,char nombre[])
{
    if(cabeza != NULL)
    {
        nodo*aux=cabeza; //creo la anterior desde el principio (que la llamo aux)
        if(strcmpi(cabeza->dato.nombre,nombre)==0)// si esta al principio cambio la cabeza nada mas
        {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;
            free(aux);
        }
        else // si esta en el medio o final
        {
            nodo*seg=cabeza->siguiente; //creo la seguidora
            while(seg->siguiente != NULL && strcmpi(cabeza->dato.nombre,nombre)!=0)//me muevo hasta que encuentre el nombre
            {
                aux=seg;
                seg=seg->siguiente;
            }

            //ahora tengo que ver los casos del por que se corto el while

            if(strcmpi(cabeza->dato.nombre,nombre)==0) // si se corto porque encontre el nombre
            {

                aux->siguiente=seg->siguiente;
                free(seg);
            }
            else //o porque no lo encontre (basicamente seg->siguiente es NULL)
            {
                puts("No se encontro el nombre");
            }

        }
    }
    else
    {
        puts("La lista esta vacia");
    }


    return cabeza;

}

stPersona retornarUltimaPersonaLista(nodo*lista)
{
    while(lista->siguiente != NULL)
    {
        lista=lista->siguiente;
    }

    return lista->dato;
}

void mostrarListaInvertidaRecursiva(nodo*aux)
{
    if(aux != NULL)
    {
        mostrarListaInvertidaRecursiva(aux->siguiente);
        mostrarPersona(aux->dato);
    }

}

int sumarElementosListaRecursivo(nodo*aux)
{
    return (aux)?aux->dato.edad+=sumarElementosListaRecursivo(aux->siguiente):0;


}

void mostrarPares(nodo * lista){

if(lista != NULL){

    mostrarPersona(lista->dato);
   lista = lista->siguiente;
   if(lista !=NULL){
    mostrarPares(lista->siguiente);
   }

}

}

nodo * borrarNodoRecursivo(nodo* lista,char nombreAux[]){



    if(lista != NULL && strcmpi(lista->dato.nombre,nombreAux)!= 0){

        lista->siguiente = borrarNodoRecursivo(lista->siguiente,nombreAux);

    }
    else
    {
        if(lista != NULL)
        {
            nodo * aux = lista;
            lista=lista->siguiente;
            free(aux);
        }
    }


return lista;
}
