#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

///LISTAS SIMPLES

///1.
int verificarSiExisteDniRecursivo(nodoPersona*listaS,int dniBuscar)
{
    int flag=0;
    if(listaS != NULL)
    {
        if(listaS->dato.DNI == dniBuscar)
        {
            flag=1;
        }
        else
        {
            flag=verificarSiExisteDniRecursivo(listaS->siguiente,dniBuscar);
        }
    }
    return flag;
}

//crear persona
stPersona crearPersona(nodoPersona*listaS)
{
    stPersona aux;
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(aux.nombre);




    printf("Ingrese el telefono: ");
    fflush(stdin);
    scanf("%s",&aux.telefono);

    do
    {
        printf("Ingrese el DNI: ");
        scanf("%i",&aux.DNI);
    }
    while(validarDNI(aux.DNI,listaS));

    return aux;
}

//validar DNI que el usuario no se pase de los limites

int validarDNI(int dato,nodoPersona*listaS)
{
    int flag=0;
    if(dato > 100 || dato < 1)
    {
        puts("Ingrese un DNI valido");
        flag=1;
    }

    if(verificarSiExisteDniRecursivo(listaS,dato))
    {
        puts("DNI ya existe");
        flag=1;
    }


    return flag;
}

//iniciar lista simple
nodoPersona*inicListaSimple()
{
    return NULL;
}

///2.
//crear nodo persona
nodoPersona*crearNodoPersona(stPersona aux)
{
    nodoPersona*nuevoNodo=(nodoPersona*)malloc(sizeof(nodoPersona));
    nuevoNodo->dato=aux;

    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

//agregar al principio de la lista de persona
nodoPersona*agregarAlPpio(nodoPersona*listaS,nodoPersona*nuevoNodo)
{
    nuevoNodo->siguiente=listaS;
    return nuevoNodo;
}

//agregar muchas personas al principio
nodoPersona*agregarAlPpioMuchos(nodoPersona*listaS)
{
    char op;
    do
    {
        listaS=agregarAlPpio(listaS,crearNodoPersona(crearPersona(listaS)));

        printf("Desea seguir ingresando  personas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }while(op=='S' || op=='s');


    return listaS;
}


//mostrar una sola persona
void mostrarPersona(stPersona aux)
{
    printf("El nombre es: %s \n",aux.nombre);
    printf("El telefono es: %s \n",aux.telefono);
    printf("El DNI es: %i \n",aux.DNI);
    puts("-----------------------------");
}



///3.
//mostrar lista recursivo

void mostrarListaSimpleRecursivo(nodoPersona*listaS)
{
    if(listaS != NULL)
    {
        mostrarPersona(listaS->dato);
        mostrarListaSimpleRecursivo(listaS->siguiente);
    }
}

///4.
//cargar muchos al final
nodoPersona*cargarMuchosAlFinal(nodoPersona*listaS)
{
    char op;
    do
    {
        listaS=agregarAlFinal(listaS,crearNodoPersona(crearPersona(listaS)));
        printf("Desea seguir ingresando  personas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(op == 's' || op=='S');
    return listaS;
}


//agrego una persona al final de la lista
nodoPersona*agregarAlFinal(nodoPersona*listaS,nodoPersona*nuevoNodo)
{

    if(listaS != NULL)
    {
        nodoPersona*seg=listaS; // debo guardarme listaS para no perderla de "vista"
        while(seg->siguiente != NULL)
        {
            seg=seg->siguiente; // me muevo hasta el anteultimo
        }
        seg->siguiente=nuevoNodo; // al siguiente del anteultimo le asigno el nuevoNodo
    }
    else
    {
        listaS=nuevoNodo;
    }
    return listaS;
}


///LISTAS DOBLES

///5. INICIO del 5
//creo primero el contacto
stContacto crearContacto(nodoPersona*listaS)
{
    stContacto aux;

    do
    {
        puts("1. Familia ");
        puts("2. Trabajo ");
        puts("3. Amigos ");
        puts("-------------------");
        printf("Ingrese el tipo de contacto: ");
        scanf("%i",&aux.tipoContacto);
        printf("\n");
    }
    while(validarTipoContacto(aux.tipoContacto));

    do
    {
        puts("0. No ");
        puts("1. Si ");
        puts("-----------------------------");
        printf("El contacto esta activo?: ");
        scanf("%i",&aux.activo);
        printf("\n");
    }
    while(validarActivo(aux.activo));


    do
    {
        mostrarDNIDisponibles(listaS);
        printf("Ingrese el DNI del contacto: ");
        scanf("%i",&aux.DNI);
        printf("\n");
    }
    while(verificarSiExisteDniRecursivo(listaS,aux.DNI) == 0);



    return aux;
}
void mostrarDNIDisponibles(nodoPersona*listaS)
{
    while(listaS != NULL)
    {
        printf("(Dni: %i) \n",listaS->dato.DNI);
        listaS=listaS->siguiente;
    }
}
//valido si el contacto esta activo
int validarActivo(int dato)
{
    int flag=0;
    if(dato >1 || dato <0)
    {
        puts("Ingrese un dato valido");
        flag=1;
    }
    return flag;
}

//valido el tipo de contacto
int validarTipoContacto(int dato)
{
    int flag=0;
    if(dato > 3 || dato < 1)
    {
        puts("Ingrese un dato valido");
        flag=1;
    }
    return flag;
}
///FIN del 5


//inicio la lista doble
nodoContacto*inicListaDoble()
{
    return NULL;
}


//creo el nodo
nodoContacto*crearNodoContacto(stContacto aux)
{
    nodoContacto*nuevoNodo=(nodoContacto*)malloc(sizeof(nodoContacto)); // el casteo es para asegurarme de que lo que me devolvio malloc es de tipo nodoContacto
    nuevoNodo->dato=aux;
    nuevoNodo->anterior=NULL;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}

//agrego al principio
nodoContacto*agregarAlPpioDoble(nodoContacto*listaD,nodoContacto*nuevoNodo)
{
    nuevoNodo->siguiente=listaD;
    if(listaD != NULL) // la logica es la misma que el de simple pero tengo que verificar si la lista es null para poder enlazar el anterior de este nodo con el nuevoNodo
    {
        listaD->anterior=nuevoNodo;
    }
    return nuevoNodo;
}
//agrego muchos al principio

nodoContacto*agregarAlPpioMuchosDoble(nodoPersona*listaD,nodoPersona*listaS)
{
    char op;
    do
    {
        listaD=agregarAlPpioDoble(listaD,crearNodoContacto(crearContacto(listaS)));

        printf("Desea seguir ingresando  personas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }while(op=='S' || op=='s');


    return listaD;
}


void mostrarContacto(stContacto aux)
{
    printf("El DNI es: %i \n",aux.DNI);
    printf("El tipo de contacto es: %i \n",aux.tipoContacto);
    printf("Activo: %i \n",aux.activo);
    puts("---------------------------------------");
}
///6.
nodoContacto*agregarOrdenado(nodoContacto*listaD,nodoContacto*nuevoNodo)
{
    if(listaD != NULL)
    {
        if(listaD->dato.DNI > nuevoNodo->dato.DNI) // si es el primero agrego al ppio
        {
            listaD=agregarAlPpioDoble(listaD,nuevoNodo);
        }
        else // si esta en el medio o final
        {
            nodoContacto*ante=listaD;
            nodoContacto*seg=listaD->siguiente; // como ya verifique el primero me muevo al siguiente
            while(seg != NULL && seg->dato.DNI < nuevoNodo->dato.DNI) // mientras que el siguiente no sea NULL o el nuevoNodo sea mayor a seg me muevo
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->anterior=ante; // enlazo el anterior del nuevoNodo con el anterior de seg
            nuevoNodo->siguiente=seg; //el siguiente del nuevoNodo es seg

            if(seg != NULL)
            {
                seg->anterior=nuevoNodo; // y si seg tiene datos(osea es un nodo y no NULL) enlazo su anterior con el nuevoNodo
            }

        }
    }
    else //si esta vacia entonces es el primero
    {
        listaD=nuevoNodo;
    }
    return listaD;
}

nodoContacto*agregarMuchosOrdenados(nodoContacto*listaD,nodoPersona*listaS)
{

    char op;
    do
    {
        listaD=agregarOrdenado(listaD,crearNodoContacto(crearContacto(listaS)));

        printf("Desea seguir ingresando  personas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }while(op=='S' || op=='s');


    return listaD;
}

///7.
void mostrarListaDobleRecursivoInverso(nodoContacto*listaD)
{
    if(listaD != NULL)
    {
        mostrarListaDobleRecursivoInverso(listaD->siguiente); // primero me muevo hasta al final
        mostrarContacto(listaD->dato); // despues muestro
    }
}
///8.
//contar contactos
int contarContactos(nodoContacto*listaD,int pedido)
{
    int sum=0;
    while(listaD != NULL)
    {
        if(listaD->dato.activo == pedido)
        {
            sum+=1;
        }
        listaD=listaD->siguiente;
    }
    return sum;
}

//agregar al final doble
nodoContacto*agregarAlFinalDoble(nodoContacto*listaD,nodoContacto*nuevoNodo)
{

    if(listaD != NULL) // si la lista tiene datos
    {
        nodoContacto*seg=listaD;
        while(seg->siguiente != NULL) // me muevo hasta el anteultimo
        {
            seg=seg->siguiente;
        }

        seg->siguiente=nuevoNodo; // enlazo el siguiente del anteultimo con el nuevoNodo
        nuevoNodo->anterior=seg; // y enlazo el anterior del nuevoNodo con el anteultimo
        //(Como el siguiente de nuevoNodo es NULL no me tengo que preocupar por declararlo yo, ya que fue declarado anteriormente)
    }
    else
    {
        listaD=nuevoNodo; // si la lista esta vacia
    }
    return listaD;
}

nodoContacto*cargarMuchosAlFinalDoble(nodoContacto*listaD,nodoPersona*listaS)
{
    char op;
    do
    {
        listaD=agregarAlFinalDoble(listaD,crearNodoContacto(crearContacto(listaS)));

        printf("Desea seguir ingresando  personas? s/n: ");
        fflush(stdin);
        scanf("%c",&op);
    }while(op=='S' || op=='s');


    return listaD;
}

//mostrar lista doble normal
void mostrarListaDoble(nodoContacto*listaD)
{
    while(listaD != NULL)
    {
        mostrarContacto(listaD->dato);
        listaD=listaD->siguiente;
    }
}
