#include <stdio.h>
#include <stdlib.h>
#include "listas2.h"

int main()
{
    nodo2*lista=inicLista();
    lista=cargarListaDoble(lista);
    mostrarLista(lista);


    //int flag = devolverCapicua(lista,buscarUltimoNodo(lista))?printf("Es capicua\n"):printf("No es capicua\n");
    puts("\n");

    lista=eliminarNodoDelMedio(lista);
    mostrarLista(lista);

    return 0;
}
