#include <stdio.h>
#include <stdlib.h>
#include "listas.h"


int main()
{
    char archivoPersonas[]="archivoPersonas";

    nodo*cabeza=inicLista();

    //cargarArchivoPersonas(archivoPersonas);
    cabeza= archivoToLista(cabeza,archivoPersonas);
    mostrarLista(cabeza);
    //cabeza=ArchivoToListaOrdenado(cabeza,archivoPersonas);
    //mostrarLista(cabeza);
    stPersona aux=crearPersona();

    buscarPersonaLista(cabeza,aux)?printf("Persona encontrada") : printf("Error persona no encontrada");
    return 0;
}
