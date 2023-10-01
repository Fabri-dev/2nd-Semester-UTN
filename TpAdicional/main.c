#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListasDobles.h"

nodoCancion* menuAdmin(nodoCancion*listaSimple);
void menuUsuario(nodoCancion*listaSimple,nodoListaReproduccion*listaDoble,fila*cola);


int main()
{
    nodoCancion*listaSimple=inicLista();
    nodoListaReproduccion*listaDoble=inicLista();
    fila*cola=inicLista();
    listaSimple=menuAdmin(listaSimple);
    menuUsuario(listaSimple,listaDoble,cola);
    return 0;
}



nodoCancion* menuAdmin(nodoCancion*listaSimple) // lista simple
{
    int opsw=0,borrar=0,dato=0;
    char op;
    char buscar[25];

    nodoCancion*sublista=inicLista();
    do
    {


        puts("1. Crear cancion y agregar ordenada(por duracion) al catalogo");
        puts("2. Borrar una cancion x id");
        puts("3. Sumar uno a la cantidad de reproducciones");
        puts("4. Buscar canciones por titulo(sublista)");
        puts("5. Buscar canciones por genero(sublista)");
        puts("6. Buscar canciones por album(sublista)");
        puts("7. Mostrar todas las canciones");
        puts("8. Retornar cancion por id");
        puts("9. Contar todas las canciones");
        puts("-----------------------------------------------------------------");
        printf("Que desea hacer?: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            listaSimple=agregarOrdenadoPorDuracionSimple(listaSimple,crearNodoCancion(crearCancion(listaSimple)));

            mostrarListaSimple(listaSimple);
            break;
        case 2:
            printf("Ingrese el id de la cancion que quiere borrar: ");
            scanf("%i",&borrar);
            listaSimple=borrarCancionSimple(listaSimple,borrar);
            mostrarListaSimple(listaSimple);
            break;
        case 3:
            listaSimple=aumentarCantidadReproducciones(listaSimple,1);
            break;
        case 4:
            printf("Ingrese el titulo que quiere buscar(le daremos una lista de las canciones que tengan el mismo titulo): ");
            fflush(stdin);
            gets(buscar);
            sublista=buscarCancionesPorTitulo(listaSimple,buscar);
            mostrarListaSimple(sublista);
            break;
        case 5:
            printf("Ingrese el genero que quiere buscar(le daremos una lista de las canciones que tengan el mismo genero): ");
            fflush(stdin);
            gets(buscar);
            sublista=buscarCancionesPorGenero(listaSimple,buscar);
            mostrarListaSimple(sublista);
            break;
        case 6:
            printf("Ingrese el album que quiere buscar(le daremos una lista de las canciones que tengan el mismo album): ");
            fflush(stdin);
            gets(buscar);
            sublista=buscarCancionesPorAlbum(listaSimple,buscar);
            mostrarListaSimple(sublista);
            break;
        case 7:
            mostrarListaSimple(listaSimple);
            break;
        case 8:
            sublista=retornarNodoSimpleXid(listaSimple,1);
            mostrarListaSimple(sublista);
            break;
        case 9:
            dato=contarNodosSimple(listaSimple);
            printf("La cantidad de nodos que tenes son: %i \n",dato);
            break;
        default:
            break;
        }


        printf("Desea volver al menu? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }while(op=='s' || op=='S');
    return listaSimple;
}



void menuUsuario(nodoCancion*listaSimple,nodoListaReproduccion*listaDoble,fila*cola) //lista doble
{
    char op;
    int opsw=0,buscar=0,sum=0;
    char texto[25];
    do
    {
        puts("--------------------- Spotify: Lista de repoduccion :) ----------------");
        puts("1. Agregar una cancion a la lista de reproduccion");
        puts("2. Borrar una cancion por ID (muestro todas las canciones de la lista)");
        puts("3. Mostrar lista de reproduccion");
        puts("4. Duracion total de la playlist");
        puts("5. Contar canciones por genero");
        puts("6. Contar canciones por artista");
        puts("7. Contar canciones por album");
        puts("8. Reproducir una cancion"); //Extraer el id, Sumar +1 a cantidadReproducciones del catálogo, Eliminar la canción, Avisarle al usuario que la lista finalizó y enviarlo al menú
        puts("------------------------------------------------------------------------");
        printf("Que desea hacer?: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            mostrarListaSimple(listaSimple);
            listaDoble=agregarAlPpioDoble(listaDoble,crearNodoListaRepro(preguntarID()));
            mostrarListaDoble(listaDoble);



            break;
        case 2:
            mostrarListaDoble(listaDoble);
            printf("Ingrese el ID de la cancion que quiere borrar de la lista de reproduccion: ");
            scanf("%i",&buscar);
            listaDoble=borrarNodoDoble(listaDoble,buscar);
            mostrarListaDoble(listaDoble);
            break;
        case 3:
            mostrarListaDoble(listaDoble);
            break;
        case 4:
            sum=contarDuracionTotalPlaylistRecursivo(listaSimple,listaDoble);
            printf("La duracion total de tu playlist es: %i\n",sum);
            break;
        case 5:
            printf("Ingrese el genero que quiere contar: ");
            fflush(stdin);
            gets(texto);
            sum=contarCantidadDeCancionesEnPlaylistXGenero(listaSimple,listaDoble,texto);
            printf("Tienes: %i canciones de %s",sum,texto);
            break;
        case 6:
            printf("Ingrese el artista que quiere contar: ");
            fflush(stdin);
            gets(texto);
            sum=contarCantidadDeCancionesEnPlaylistXArtista(listaSimple,listaDoble,texto);
            printf("Tienes: %i canciones de %s",sum,texto);
            break;
        case 7:
            printf("Ingrese el album que quiere contar: ");
            fflush(stdin);
            gets(texto);
            sum=contarCantidadDeCancionesEnPlaylistXAlbum(listaSimple,listaDoble,texto);
            printf("Tienes: %i canciones de %s",sum,texto);
            break;
        case 8:
            listaDoble=reproducirUnaCancion(&cola,&listaSimple,listaDoble);
            break;
        default:
            break;
        }




        printf("Desea volver al menu? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

        system("cls");
    }
    while(op=='s' || op=='S');



}


