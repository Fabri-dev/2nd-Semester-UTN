#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombreYapellido[40];
    char sector[30]; ///los sectores son (y estan escritos tal cual): "ropa","muebles","electro"
    int ventasDiarias;
} stVendedor;

typedef struct
{
    stVendedor dato;
    struct nodoS*siguiente;
} nodoS;

typedef struct{
    stVendedor dato;
    struct nodoD*siguiente;
    struct nodoD*anterior;
}nodoD;

stVendedor crearVendedor(char archivo[]);
int buscarUltimoId(char archivo[]);
nodoS*crearNodo(stVendedor aux);
nodoS*inicLista();
void cargarArchivo(char archi[]);
void mostrarVendedor(stVendedor p);
void mostrarArchivo(char archi[]);
nodoS*agregarAlPpio(nodoS*listaS,nodoS*nuevoNodo);
nodoS*agregarEnOrden(nodoS*listaS,nodoS*nuevoNodo);
nodoS*archivoToLista(char archi[],nodoS*listaS);
void mostrarLista(nodoS*listaS);
void mostrarListaInversaRecursivo(nodoS*listaS);
int contarVendedoresEspecificoRecursivo(nodoS*listaS, char sectorBuscado[]);
nodoD*crearNodoDoble(stVendedor aux);
nodoD*inicListaDoble();
nodoD*agregarAlPpioDoble(nodoD*listaD,nodoD*nuevoNodo);
void agregarAlFinalDobleRefe(nodoD**listaD,nodoD*nuevoNodo);
void crearTopDiez(nodoD**listaD,nodoS**listaS);
void mostrarListaDoble(nodoD*listaD);


int main()
{
    char archivo[]="vendedores";
    char op;
    int dato=0;
    nodoS*listaSimple=inicLista();
    nodoD*listaDoble=inicListaDoble();
//    do
//    {
//        cargarArchivo(archivo);
//        printf("Desea seguir cargando vendedores? s/n: ");
//        fflush(stdin);
//        scanf("%c",&op);
//    }while(op=='s'|| op=='S');
//    mostrarArchivo(archivo);

    listaSimple=archivoToLista(archivo,listaSimple);
    mostrarLista(listaSimple);
    puts("\n\n\n");
//    mostrarListaInversaRecursivo(listaSimple);
//
//    dato=contarVendedoresEspecificoRecursivo(listaSimple,"progra");
//    printf("La cantidad de vendedores que hay es: %i",dato);
    crearTopDiez(&listaDoble,&listaSimple);
    mostrarListaDoble(listaDoble);
    return 0;
}

void cargarArchivo(char archi[])
{
    char op;
    stVendedor aux;
    FILE*buffer=fopen(archi,"ab");
    if(buffer != NULL)
    {
            aux=crearVendedor(archi);
            fwrite(&aux,sizeof(stVendedor),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}

stVendedor crearVendedor(char archivo[])
{
    stVendedor aux;

    aux.id=1+buscarUltimoId(archivo);

    printf("Ingrese el nombre y apellido: ");
    fflush(stdin);
    gets(aux.nombreYapellido);

    printf("Ingrese el sector: ");
    fflush(stdin);
    gets(aux.sector);

    printf("Ingrese las ventas diarias: ");
    scanf("%i",&aux.ventasDiarias);

    return aux;
}

int buscarUltimoId(char archivo[])
{
    int ultimo=0;
    FILE*buffer=fopen(archivo,"rb");
    stVendedor aux;

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stVendedor),1,buffer)>0)
        {
            if(aux.id > ultimo)
            {
                ultimo=aux.id;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return ultimo;

}

nodoS*crearNodo(stVendedor aux)
{
    nodoS*nuevoNodo=(nodoS*)malloc(sizeof(stVendedor));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

nodoS*inicLista()
{
    return NULL;
}

void mostrarVendedor(stVendedor p)
{
    printf("Id del Vendedor................: %d \n", p.id);
    printf("Apellido y nombre:.............: %s \n", p.nombreYapellido);
    printf("Sector:........................: %s \n", p.sector);
    printf("Ventas diarias:................: %d \n", p.ventasDiarias);
    puts("----------------------------------------------");

}

void mostrarArchivo(char archi[])
{
    FILE*buffer=fopen(archi,"rb");
    stVendedor aux;

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stVendedor),1,buffer)>0)
        {
            mostrarVendedor(aux);
        }
        fclose(buffer);
    }
    else
    {
        puts("Error");
    }

}

nodoS*agregarAlPpio(nodoS*listaS,nodoS*nuevoNodo)
{
    nuevoNodo->siguiente=listaS;
    return nuevoNodo;
}

nodoS*agregarEnOrden(nodoS*listaS,nodoS*nuevoNodo)
{
    if(listaS != NULL)
    {
        if(listaS->dato.ventasDiarias < nuevoNodo->dato.ventasDiarias)
        {
            listaS=agregarAlPpio(listaS,nuevoNodo);
        }
        else
        {
            nodoS*ante=listaS;
            nodoS*seg=listaS->siguiente;

            while(seg != NULL && seg->dato.ventasDiarias > nuevoNodo->dato.ventasDiarias)
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

nodoS*archivoToLista(char archi[],nodoS*listaS)
{
    FILE*buffer=fopen(archi,"rb");
    stVendedor aux;
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stVendedor),1,buffer)>0)
        {
            listaS=agregarEnOrden(listaS,crearNodo(aux));
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return listaS;
}

void mostrarLista(nodoS*listaS)
{
    while(listaS != NULL)
    {
        mostrarVendedor(listaS->dato);
        listaS=listaS->siguiente;
    }
}

void mostrarListaInversaRecursivo(nodoS*listaS)
{
    if(listaS != NULL)
    {
        mostrarListaInversaRecursivo(listaS->siguiente);
        mostrarVendedor(listaS->dato);
    }
}

int contarVendedoresEspecificoRecursivo(nodoS*listaS, char sectorBuscado[])
{
    int sum=0;

    if(listaS != NULL)
    {
        if(strcmpi(listaS->dato.sector,sectorBuscado)==0)
        {
            sum=1;
        }
        sum+=contarVendedoresEspecificoRecursivo(listaS->siguiente,sectorBuscado);
    }

    return sum;
}

//////////////////////////////////////////////////


nodoD*crearNodoDoble(stVendedor aux)
{
    nodoD*nuevoNodo=(nodoD*)malloc(sizeof(nodoD));
    nuevoNodo->dato=aux;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    return nuevoNodo;
}

nodoD*inicListaDoble()
{
    return NULL;
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


void agregarAlFinalDobleRefe(nodoD**listaD,nodoD*nuevoNodo)
{
    if((*listaD) != NULL)
    {
        nodoD*ante=(*listaD);
        nodoD*seg=(*listaD)->siguiente;
        while(seg != NULL)
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
    else
    {
        (*listaD)=nuevoNodo;
    }

}

void crearTopDiez(nodoD**listaD,nodoS**listaS)
{
    int i=0;
    nodoS*aux=(*listaS);
    while(aux != NULL && i < 10)
    {
        agregarAlFinalDobleRefe(listaD,crearNodoDoble(aux->dato));
        aux=aux->siguiente;
        i++;
    }
}

void mostrarListaDoble(nodoD*listaD)
{
    while(listaD != NULL)
    {
        mostrarVendedor(listaD->dato);
        listaD=listaD->siguiente;
    }
}
