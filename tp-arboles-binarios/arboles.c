#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"


nodoArbol*inicArbol()
{
    return NULL;
}

int preguntarDatoEntero()
{
    int dato=0;
    printf("Ingrese un dato: ");
    fflush(stdin);
    scanf("%i",&dato);
    return dato;
}

stPersona crearUnaPersona()
{
    stPersona aux;
    printf("Ingrese el nro. de legajo: ");
    scanf("%i",&aux.legajo);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s",&aux.nombre);

    printf("Ingrese la edad: ");
    scanf("%i",&aux.edad);

    return aux;
}

nodoArbol*crearNodoArbol(stPersona aux)
{
    nodoArbol*nuevoNodo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevoNodo->dato=aux;
    nuevoNodo->derecha=NULL;
    nuevoNodo->izquierda=NULL;
    return nuevoNodo;
}

nodoArbol*ingresarXLegajo(nodoArbol*raiz,nodoArbol*nuevoNodo)
{
    if(raiz != NULL)
    {
        if(nuevoNodo->dato.legajo < raiz->dato.legajo)
        {
            raiz->izquierda=ingresarXLegajo(raiz->izquierda,nuevoNodo);
        }
        else
        {
            raiz->derecha=ingresarXLegajo(raiz->derecha,nuevoNodo);
        }
    }
    else
    {
        raiz=nuevoNodo;
    }

    return raiz;
}

nodoArbol* ingresarMuchosNodosXLegajo(nodoArbol*raiz)
{
    char op;
    do
    {

        raiz=ingresarXLegajo(raiz,crearNodoArbol(crearUnaPersona()));

        printf("Desea seguir cargando nodos? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }
    while(op=='s' || op=='S');
    return raiz;
}


void mostrarPersona(stPersona aux)
{
    printf("El legajo es: %i \n",aux.legajo);
    printf("El nombre es: %s \n",aux.nombre);
    printf("La edad es: %i \n",aux.edad);
    puts("---------------------------------");
}

void mostrarInorder(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        mostrarInorder(raiz->izquierda);
        mostrarPersona(raiz->dato);
        mostrarInorder(raiz->derecha);
    }
}

void mostrarPreorder(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        mostrarPersona(raiz->dato);
        mostrarInorder(raiz->izquierda);
        mostrarInorder(raiz->derecha);
    }
}

void mostrarPostorder(nodoArbol*raiz)
{
    if(raiz != NULL)
    {
        mostrarInorder(raiz->izquierda);
        mostrarInorder(raiz->derecha);
        mostrarPersona(raiz->dato);
    }
}


stPersona retornarUnaPersonaXLegajo(nodoArbol*raiz,int legajoBuscar) // primero es necesario verificar antes de buscar ya que sino nos retornaria una persona con datos basura
{
    stPersona aux;
    if(raiz != NULL)
    {
        if(raiz->dato.legajo == legajoBuscar)
        {
            aux=raiz->dato;
        }
        else
        {
            if(legajoBuscar < raiz->dato.legajo)
            {
                aux= retornarUnaPersonaXLegajo(raiz->izquierda,legajoBuscar);
            }
            else
            {
                aux= retornarUnaPersonaXLegajo(raiz->derecha,legajoBuscar);
            }
        }
    }
    else
    {
        puts("Lista vacia");
    }
    return aux;
}

int verificarSiExistePersonaXLegajo(nodoArbol*raiz,int legajoBuscar) //aqui verificamos que exista la persona buscada por legajo, por mas que recorremos el arbol dos veces nos ahorramos de bugs
{
    int flag=0;
    if(raiz != NULL)
    {
        if(raiz->dato.legajo == legajoBuscar)
        {
            flag=1;
        }
        else
        {
            if(legajoBuscar < raiz->dato.legajo)
            {
                flag=verificarSiExistePersonaXLegajo(raiz->izquierda,legajoBuscar);
            }
            else
            {
                flag=verificarSiExistePersonaXLegajo(raiz->derecha,legajoBuscar);
            }
        }
    }

    return flag;
}



stPersona buscarUnaPersonaXLegajoVerificado(nodoArbol*raiz,int legajoBuscar) //aqui juntamos las dos funciones, y si existe la persona buscada por legajo, buscamos de nuevo y la retornamos, sino, no existe la persona
{
    stPersona aux;
    if(verificarSiExistePersonaXLegajo(raiz,legajoBuscar))
    {
        aux=retornarUnaPersonaXLegajo(raiz,legajoBuscar);
        mostrarPersona(aux);
    }
    else
    {
        puts("El legajo buscado no existe");
    }
    return aux;
}

int verificarSiExistePersonaXNombre(nodoArbol* raiz,char nombreBuscar[])
{
    int flag=0;
    if(raiz != NULL)
    {
        if(strcmpi(raiz->dato.nombre,nombreBuscar)==0)
        {
            flag=1;
        }
        else
        {
            flag=verificarSiExistePersonaXNombre(raiz->izquierda,nombreBuscar);
            flag=verificarSiExistePersonaXNombre(raiz->derecha,nombreBuscar);
        }
    }
    return flag;
}


stPersona retornarUnaPersonaXNombre(nodoArbol*raiz,char nombreBuscar[])
{
    stPersona aux;
    if(raiz != NULL)
    {
        if(strcmpi(raiz->dato.nombre,nombreBuscar)==0)
        {
            aux=raiz->dato;
        }
        else
        {
            aux= retornarUnaPersonaXNombre(raiz->izquierda,nombreBuscar);
            aux= retornarUnaPersonaXNombre(raiz->derecha,nombreBuscar);
        }
    }
    return aux;
}

stPersona buscarUnaPersonaXNombreVerificado(nodoArbol*raiz, char nombreBuscar[])
{
    stPersona aux;
    if(verificarSiExistePersonaXNombre(raiz,nombreBuscar))
    {
        aux=retornarUnaPersonaXNombre(raiz,nombreBuscar);
        mostrarPersona(aux);
    }
    else
    {
        puts("Nombre buscado no existe");
    }
}



int calcularAlturaArbol(nodoArbol*raiz)
{
    int rta = 0;

    if (raiz != NULL)
    {


        int rtaI = calcularAltura(raiz->izq);
        int rtaD = calcularAltura(raiz->der);

        if(rtaI > rtaD)
        {

            rta = rtaI + 1;
        }
        else
        {
            rta = rtaD + 1;
        }

    }

    return rta;

}

int contarNodos(nodoArbol*raiz)
{
    int cont=0;

    if(raiz != NULL)
    {
        cont++;
        cont+= contarNodos(raiz->izquierda);
        cont+= contarNodos(raiz->derecha);
    }
    return cont;
}

int contarHojas(nodoArbol*raiz)
{
    int cont=0;
    if(raiz->izquierda == NULL && raiz->derecha == NULL)
    {
        cont++;
    }
    else
    {
        cont+=contarHojas(raiz->izquierda);
        cont+=contarHojas(raiz->derecha);
    }
    return cont;
}
