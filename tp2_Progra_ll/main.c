#include <stdio.h>
#include <stdlib.h>

int factorialRecursiva(int dato);
int potenciaRecursiva(int dato, int pot);
void mostrarArregloRecursivo(int arr[],int validos, int i);
void mostrarArregloRecursivoInvertido(int arr[],int validos, int i);
int verificarArregloCapicuaRecursivo(int arreglo[],int validos,int i);
int suma (int arreglo[],int validos ,int pos);
int buscarMenorRecursivo(int arr[], int validos, int i);

int main()
{

    /*int datoFactorial = 15;
    int rta = factorialRecursiva(datoFactorial);
    printf("rta: |%i|",rta);*/

    /*int dato= 5, pot=5;///potencia
    int res=potenciaRecursiva(dato,pot);*/

    int arr[10]={34,70,100,45,89,21,34,5,87};

    //mostrarArregloRecursivo(arr,4,0);
    //mostrarArregloRecursivoInvertido(arr,4,0);

    //int flag= verificarArregloCapicuaRecursivo(arr,3,0)? printf("El arreglo no es capicua") : printf("El arreglo SI es capicua");
    int resultado = buscarMenorRecursivo(arr,9,0);
    printf("menor: |%i|\n",resultado);
    return 0;
}
///Calcular el factorial de un número en forma recursiva.
int factorialRecursiva(int dato){

int respuesta;

if(dato != 0){
    respuesta = dato* factorialRecursiva(dato-1);

}else{
respuesta = 1;
}

return respuesta;
}

///Calcular la potencia de un número en forma recursiva.
int potenciaRecursiva(int dato, int pot)
{
    int res=0;
    if(pot != 0)
    {
        pot--;
        res=dato*potenciaRecursiva(dato,pot);
        printf("La potencia de %i a la %i es: %i\n",dato,pot,res);

    }
    else
    {
        res=1;
    }
    return res;
}
///Recorrer un arreglo y mostrar sus elementos en forma recursiva.
void mostrarArregloRecursivo(int arr[],int validos, int i)
{
    if(i < validos)
    {
        printf("arr[%i] = %i \n",i,arr[i]);
        mostrarArregloRecursivo(arr,validos,i+1);

    }
    else
    {
        puts("FIN");
    }


}
///Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
///forma invertida (recursivo).

void mostrarArregloRecursivoInvertido(int arr[],int validos, int i)
{


    if(i < validos)
    {
        mostrarArregloRecursivoInvertido(arr,validos,i+1);
        printf("arr[%i] = %i \n",i,arr[i]);

    }
    else
    {
        puts("FIN");
    }

}
///Determinar en forma recursiva si un arreglo es capicúa.
int verificarArregloCapicuaRecursivo(int arreglo[],int validos,int i)
{

int flag = 0;
int j = validos - 1;

if(arreglo[i] == arreglo[j] && flag == 0){
   verificarArregloCapicuaRecursivo(arreglo,j,i+1);
}else{
flag = 1;
}

return flag;
}
///Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma. }

int suma (int arreglo[],int validos ,int pos){

int total;
int i = pos;
if(i<validos){

    total= arreglo[i];
    total = total+ suma(arreglo,validos,i+1);

}else{
total = 0;

}

return total;
}

///7. Buscar el menor elemento de un arreglo en forma recursiva.

int buscarMenorRecursivo(int arr[], int validos, int i)
{
    int menor;
    if(i < validos)
    {
        menor= buscarMenorRecursivo(arr,validos,i+1);
        if(arr[i]< menor)
         {

            menor = arr[i];
        }
    }
    else
    {
        menor=arr[i-1];
    }


    return menor;
}

///8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)



