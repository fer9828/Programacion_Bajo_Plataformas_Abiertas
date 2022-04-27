
/*	* @file Laberinto.c
 	*  @brief Solucion de un Laberinto
 	*  @author Fernando Jimenez Ureña
 	*  @details Este es un programa que intenta resolver un laberinto
*/

#include <stdio.h>  //Se añanaden las librerias necesarias para resolver el laberinto
#include <stdlib.h>

// Se procede a declarar las variables que se utilizaran durante el programa

char** laberinto;
int** recorrido;
int filas;
int columnas;
int inicio_fila;
int inicio_columna;

// Se declara un enum con las diferentes partes del mapa como lo son las paredes, espacios vacios , etc. 

enum terrain {
	vacio,
	muro,
	meta,
	camino
};

//Se procede a declarar una funcion para asignar el laberinto 

void alloc_maze()
{
	laberinto = malloc(filas * sizeof(char*));
	
	int i;
	for (i = 0; i < filas; ++i){
		laberinto[i] = malloc(columnas * sizeof(char*));
	}
}

// Esta funcion se encarga de leer el archivo de texto plano con el laberinto. Se encarga de leer cuantas filas 
// y columnas posee

void obtener_laberinto(char* nombre_archivo)
{
	char c;
	char filas_s[3] = { '\0' };
	char columnas_s[3] = { '\0' };
	int filas_i = 0;
	int columnas_i = 0;
	int aux = 0;

	FILE* archivo_plano = fopen(nombre_archivo, "r");

	if (archivo_plano) {
		while ((c = getc(archivo_plano)) != EOF) {
			if (c == '\n') {
				break;
			} else if (c == ','){
				aux = 1;
			} else if (!aux) {
				filas_s[filas_i] = c;
				filas_i++;
			} else {
				columnas_s[columnas_i] = c;
				columnas_i++;
			}
		}
	} 
    else {
		printf("No existe el archivo");
		return;
	}

	filas = atoi(filas_s);
	columnas = atoi(columnas_s);

    alloc_maze();

    for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {

			if ((c = getc(archivo_plano)) == '\n') {
				c = getc(archivo_plano);
			}

			laberinto[i][j] = c;

			if (c =='s') {
				inicio_fila = i;
				inicio_columna = j;
			}
		}
	}

	fclose(archivo_plano);
}

//Se procede a crear una funcion que imprima en pantalla el laberinto 

void imprimir_laberinto()
{
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			printf("%c", laberinto[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}


int main(){

    obtener_laberinto("laberinto.txt");
    printf("%d, %d\n", filas, columnas);
    imprimir_laberinto();


    return 0;
}