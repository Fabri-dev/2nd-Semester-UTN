#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


int main()
{
//    char archivoPersonas[]="archivoPersonas";
//
//    nodo*cabeza=inicLista();
//
//    cargarArchivoPersonas(archivoPersonas);
//    cabeza= archivoToLista(cabeza,archivoPersonas);
//    mostrarLista(cabeza);
//    cabeza=ArchivoToListaOrdenado(cabeza,archivoPersonas);
//    mostrarLista(cabeza);
//    stPersona aux=crearPersona();
//
//    buscarPersonaLista(cabeza,aux)?printf("Persona encontrada") : printf("Error persona no encontrada");

    nodo*lista1=inicLista();
//    nodo*lista2=inicLista();
//    nodo*lista3=inicLista();
//
    lista1=cargarLista(lista1);
//    mostrarLista(lista1);
//
//    lista2=cargarLista(lista2);
//    mostrarLista(lista2);
//
//
//    lista3=intercalarListasXedad(lista1,lista2);
//    mostrarLista(lista3);

//    lista1=borrarNodoXNombre(lista1,"cgsdfgerger");
//    mostrarLista(lista1);

//    nodo*lista1=inicLista();
//    nodo*listaInvertida=inicLista();
//    lista1=cargarLista(lista1);
//    mostrarLista(lista1);
//    listaInvertida=invertirElementosLista(lista1);
//    mostrarLista(listaInvertida);

    //mostrarListaInvertidaRecursiva(lista1);
    //int rta=sumarElementosListaRecursivo(lista1);
    //printf("rta: %i",rta);

//mostrarPares(lista1);

//lista1 = borrarNodoRecursivo(lista1,"leo");

//mostrarLista(lista1);

//    lista1=insertarNodoRecursivo(lista1,crearNodo(crearPersona()));
//    mostrarLista(lista1);


    lista1=invertirListaRecursivo(lista1);
    mostrarLista(lista1);
    return 0;
}
