/**     @file puntero_simple.c
 *      @author Fernando Jiménez Ureña
 *      @brief Contiene un programa que intercambia el valor de dos variables mediante el método de cambio por valor y otro por el método de los punteros
 * 
 *      @details Mediante el uso de funciones y punteros se logra desarrollar el programa
 *      @bug por determinar
 */

#include<stdio.h>

//Prototipos de Funciones

void CambioPorValor(int,int);

void CambioPorPuntero(int *, int *);

int a = 10, b = 75, c = 45, d = 90;

int main(){

    printf("\nUtilizando el método por Valor\n\n");

    printf("El valor del primer numero es %d\n", a);
    printf("El valor del segundo numero es %d\n", b);

    CambioPorValor(a,b);

    printf("El nuevo valor del primer numero es %d\n", b);
    printf("El nuevo valor del segundo numero es %d\n", a);

    printf("\n-------------------------\n");

    printf("\nUtilizando el método de Punteros\n\n");

    printf("El valor del primer numero es %d\n", c);
    printf("El valor del segundo numero es %d\n", d);

    CambioPorPuntero(&c,&d);

    printf("El nuevo valor del primer numero es %d\n", c);
    printf("El nuevo valor del segundo numero es %d\n", d);

    return 0;
}


void CambioPorValor(int a, int b){

    int aux;
    
    aux = a;
    a = b;
    b = aux;

}

void CambioPorPuntero(int *dirNum1, int *dirNum2){

    int aux;

    //Intercambiar los valores de los variables

    aux = *dirNum1;
    *dirNum1 = *dirNum2;
    *dirNum2 = aux;
}