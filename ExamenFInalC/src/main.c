/** @file main.c
 * @author Fernado Jiménez Ureña - B74020
 * @brief Función main.c que llama a las funciones ya desarrolladas en "funciones.h" para ejecutar el programa. 
 **/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    //Se crean las listas donde se guardan los datos de los dos polinomios 
    struct node* headPrimerPolinomio = NULL; //En esta lista se introduce el primer polinomio
    struct node* headSegundoPolinomio = NULL; //En esta lista se introduce segundo polinomio


    //En esta seccion se procede a pedir los datos al usuario
    printf("\nEste programa se encarga de crear dos polinomios distintos ingresados por el usuario.\n\n\n");
    printf("Primer Polinomio:\n\n");
    headPrimerPolinomio = solicitar(headPrimerPolinomio); //Se crea la primer lista usando la funcion create 
    printf("\n");
    print(headPrimerPolinomio); //Se imprime primer lista usando funcion print
    printf("\n");
    printf("\nSegundo Polinomio:\n\n");
    headSegundoPolinomio = solicitar(headSegundoPolinomio); //Se crea la segundo lista usando la funcion create
    printf("\n");
    print(headSegundoPolinomio); // Se imprime la segunda lista usando la funcion print
    printf("\n");
    printf("\nSe ingresaron los siguientes polinomios:\n"); //Se imprimen los dos polinomios
    printf("1. ");print(headPrimerPolinomio); 
    printf("2. ");print(headSegundoPolinomio);

    printf("\n\n---A continuación se procede a realizar distintas operaciones con los polinomios ingresados---\n");

    //En esta seccion se realiza la suma de los elementos llamando a la funcion suma
    printf("\n->Suma");
    printf("\nEl resultado de sumar ambos polinomios es:\n");
    suma(headPrimerPolinomio,headSegundoPolinomio);   //Se procede a llamar la funcion suma

    //En esta seccion se realiza la resta de los elementos llamando a la funcion resta
    printf("\n->Resta");
    printf("\nEl resultado de restar ambos polinomios es:\n");
    resta(headPrimerPolinomio,headSegundoPolinomio);   //Se procede a llamar la funcion resta

    //En esta seccion se realiza la multiplicacion de los elementos llamando a la funcion mutliplicacion 
    printf("\n->Multiplicación");
    printf("\nEl resultado de multiplicar ambos polinomios es:\n");
    multiplicacion(headPrimerPolinomio, headSegundoPolinomio); //Se procede a llamar la funcion multiplicacion

    printf("\n\n---Se procede a liberar la memoria utilizada---\n");

    //Finalmente se procede a liberar la memoria utilizada 
    printf("\nLiberando la memoria del primer polinomio:\n");
    freeList(headPrimerPolinomio); //Se llama la funcion freelist para el primer polinomio
    print(headPrimerPolinomio);

    printf("\nLiberando la memoria del segundo polinomio:\n");
    freeList(headSegundoPolinomio); //Se llama la funcion freelist para el segundo polinomio
    print(headSegundoPolinomio);
    printf("\n");

    return 0;

}