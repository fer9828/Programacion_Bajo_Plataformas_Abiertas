/**     @file punteros_funciones_matrices.c
 *      @author Fernando Jiménez Ureña
 *      @brief Contiene un programa que imprime una matriz 10x10 de numeros aleatorios
 * 
 *      @details Mediante el uso de funciones y punteros se logra desarrollar el programa
 *      @bug por determinar
 */

#include<stdio.h>
#include<stdlib.h> //aqui esta el generador de numeros aleatorios
#include<time.h>



//Prototipos de Funciones

void armarMatriz();

void mostrarMatriz();

// int* buscar(int matrix[][COLS], int filas, int columnas);

int **puntero_matriz;
int filas = 10, columnas = 10;
int matriz[10][10];

int main(){

    armarMatriz();
    mostrarMatriz(puntero_matriz,nFilas,nCol);

    return 0; 
}


void armarMatriz(){

//En esta funcion se definen las variables para generar los numeros aleatorios

    int aleatorio;

//Primero se desea generar el numero aleatorio.

    srand(time(NULL)); //genera el numero


//Este ciclo for se utiliza para rellenar la matriz 
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            //la formula para generar el numero aleatorio es:
            // variable = limite_inferior + rand()% (limite_superior +1 - limite inferior)
            //En este caso se utiliza un rango de 1 a 100
            aleatorio = 1 + rand()%(100);
            matriz[i][j] = aleatorio; // = *(*(puntero_matriz+i)+j); //puntero_matriz[i][j]; 
        }
    }
}


void mostrarMatriz(){
    
    printf("\n\nImprimiendo Matriz:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf(" %d", matriz[i][j]); printf(" "); 
        }
        printf("\n");
    }
}