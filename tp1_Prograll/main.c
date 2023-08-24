#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <string.h>
void inicializarEnMenosUno(int arreglo[],int dimension);
void mostrarArreglo(int arreglo[],int validos);

int cargarArreglo(int arreglo[],int dimension);
int validarNegativo(int num);

int sumarContenido(int arreglo[], int validos);
float calcularPromedio(int arreglo[], int validos);

int cargarArregloCaracteres(char arreglo[], int dimension);
void invertirArregloCaracter(char arreglo[],int validos);

void mostrarCaracteres(char arreglo[],int validos);

void convertirAdecimal(int arregloEnteros[], int validos);
int encontrarMayor(int arreglo[],int validos);

void cargarMatriz(int matriz[12][31]);

int retornarDiaDeMayorPrecipitacion(int matriz[12][31],int mes);

int determinarPalindromo(char cadena[]);

void intercambiarValorVariablesPorReferencia(int * datoUno, int * datoDos);
int retornarMenor(int arr1[], int arr2[], int validos, int pos);
void ordenarArreglos(int arr1[], int arr2[], int validos,int arregloTres[]);


int main()
{

srand(time(NULL));
//int dimension = 10;
//int dimensionCaracter = 26;
//
//int arreglo[dimension];
//int arregloEntero[] = {5,3,1,9,8};
//char arregloCaracter[dimension];
//
//float promedio=0;

/*inicializarEnMenosUno(arreglo,dimension);
int validos = cargarArreglo(arreglo,dimension);
promedio= calcularPromedio(arreglo,validos);
printf("El promedio de todos los elementos del arreglo es: %.2f",promedio);
//mostrarArreglo(arreglo,validos);*/


//mostrarCaracteres(arregloCaracter,validosCaracter);
//invertirArregloCaracter(arregloCaracter,validosCaracter);
//mostrarCaracteres(arregloCaracter,validosCaracter);

//convertirAdecimal(arregloEntero,5);

//int mayor= encontrarMayor(arregloEntero,5);
//printf("POS DEL NUMERO MAYOR: arr[%i]=%i",mayor,arregloEntero[mayor]);*/

//    int matriz[12][31];
//    cargarMatriz(matriz);
//    int mes;
//    printf("\n Ingrese el numero de mes: ");
//    fflush(stdin);
//    scanf("%i",&mes);
//    int mayor = retornarDiaDeMayorPrecipitacion(matriz,mes);
//
//
//    printf("Matriz: |%i|",matriz[mes][mayor]);



//    int flag=determinarPalindromo("orejero")? printf("La palabra no es palindromo") : printf("La palabra es palindromo");

    int arr1[10],arr2[10];
    int validos=cargarArreglo(arr1,10);
    validos=cargarArreglo(arr2,10);
    int arr3[6];
    ordenarArreglos(arr1,arr2,validos,arr3);
    return 0;
}
///1_a_ Hacer una función que inicialice las celdas del arreglo en –1.

void inicializarEnMenosUno(int arreglo[],int dimension){

for(int i = 0;i<dimension;i++){
arreglo[i] = -1;
}
}

void mostrarArreglo(int arreglo[],int validos){

for(int i = 0;i<validos;i++)
    printf("Arreglo en la posicion|%d|: %d\n",i,arreglo[i]);

}

///1_b. Hacer una función que permita al usuario ingresar los valores. No se conoce la cantidad de antemano.

int cargarArreglo(int arreglo[],int dimension){

int i = 0;
char op = 's';

do{
do{
puts("Ingrese un valor al arreglo: ");
fflush(stdin);
scanf("%i",&arreglo[i]);
}while(validarNegativo(arreglo[i]));
i++;

puts("(S/N) para continuar la carga de valores");
fflush(stdin);
scanf("%c",&op);

}while((op == 's'|| op =='S') && i < dimension);

return i;
}

int validarNegativo(int num){

int flag = 0;

if(num < 0){
    puts("No se pueden ingresar numero negativos,REINTENTE...");
    flag = 1;
}

return flag;
}

int sumarContenido(int arreglo[], int validos)
{
    int sum=0;

    for(int i=0; i < validos; i++)
    {
        sum+=arreglo[i];
    }

    return sum;
}

float calcularPromedio(int arreglo[], int validos)
{
    float prom=0;
    int sum=sumarContenido(arreglo,validos);
    prom=(float)sum/validos;

    return prom;
}
///2.a Hacer una función para la carga del arreglo.

int cargarArregloCaracteres(char arreglo[], int dimension){

int i = 0;
char op = 's';
do{

puts("Ingrese un caracter al arreglo: ");
fflush(stdin);
scanf("%c",&arreglo[i]);

i++;

puts("(S/N) para continuar la carga de valores");
fflush(stdin);
scanf("%c",&op);

}while((op == 's'|| op =='S') && i < dimension);

return i;
}

///2.b Hacer una función para invertir el arreglo

void invertirArregloCaracter(char arreglo[],int validos){

int j = validos-1;
int i =0;
char aux;

while(i < j){
    aux = arreglo[j];
    arreglo[j] = arreglo[i];
    arreglo[i] = aux;
    i++;
    j--;

}
}
void mostrarCaracteres(char arreglo[],int validos)
{

for(int i = 0;i<validos;i++){

    printf("CARACTER |%c|\n",arreglo[i]);

    }
}

//3

void convertirAdecimal(int arregloEnteros[], int validos)
{

   int i = 0;
   int multiplicador = pow(10,validos - 1);
   int numeroEntero = 0;

   for(i;i<validos;i++){
    numeroEntero += arregloEnteros[i] * multiplicador;
    multiplicador = multiplicador / 10;

   }

   printf("numero: |%i|",numeroEntero);

}

//4.Hacer una función que retorne la posición del valor máximo de un arreglo de números enteros.

int encontrarMayor(int arreglo[],int validos)
{

int i = 0;
int max = 0,posmayor=0;

while(i<validos){
if(arreglo[i]>max){
    max = arreglo[i];
    posmayor=i;
}
    i++;
}

return posmayor;
}




void cargarMatriz(int matriz[12][31]){

for(int i = 0;i<12;i++){
    for(int j=0; j<31; j++)
    {
        matriz[i][j]= rand() % 100;
    }

}

for(int i=0; i < 12; i++)
{
    printf("\t\n|");
    for(int j=0; j<31;j++)
    {

    printf("%i|",matriz[i][j]);

    }
}


}


int retornarDiaDeMayorPrecipitacion(int matriz[12][31],int mes)
{
    int maxDia=0,posDia=0;



    for(int j=0; j<31; j++)
    {
        if(maxDia < matriz[mes][j])
        {
            maxDia=matriz[mes][j];
            posDia=j;
        }
    }
return posDia;
}


//6. Dada una cadena de caracteres, hacer una función que determine si dicha cadena
//es palíndromo (se lee de igual forma de adelante para atrás como viceversa) o no.
//La función recibe como parámetro la cadena y retorna 1 o 0 según sea la respuesta.

int determinarPalindromo(char cadena[])
{
    int i=0, j=strlen(cadena)-1, flag=0;



    while(i < j && flag==0)
    {
        if(cadena[i] != cadena[j])
        {
            flag=1;
        }

        i++;
        j--;
    }

    return flag;
}


//7. Hacer una función que intercambie el contenido de dos variables. (pasaje de parámetros por referencia)


void intercambiarValorVariablesPorReferencia(int * datoUno, int * datoDos)
{
    int aux=0;
    aux = *datoUno;
    *datoUno= *datoDos;
    *datoDos= aux;
}

//8. Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba como parámetros
//y retorne un tercer arreglo que contenga los datos de los arreglos anteriores, también ordenados. Se los debe intercalar.


int retornarMenor(int arr1[], int arr2[], int validos, int pos)
{
    int menor=arr1[pos];

    for(int i=pos-1; i < validos; i++)
    {
        if(arr1[i] < menor)
        {
            menor= arr1[i];
        }

    }

//    for(int i=pos; i < validos; i++)
//    {
//        if(arr2[i] < menor)
//        {
//            menor= arr2[i];
//        }
//
//    }

    return menor;

}

void ordenarArreglos(int arr1[], int arr2[], int validos,int arregloTres[])
{
    int i=0,j=0, menor=0;

    for(int i=0; i < 3; i++)
    {


        menor= retornarMenor(arr1,arr2,validos,i);

        arregloTres[i]=menor;
        i++;
    }


    for (int i=0; i < 3; i++)
    {

        printf("Arr[%i]= %i \n",i,arregloTres[i]);

    }
}



