/*	* @file Ordenamiento.c
 	*  @brief Metodos de Ordenamiento
 	*  @author Fernando Jimenez Ureña
 	*  @details Este es un programa que permite acomodar de forma descendente un arreglo de 
       1500 numeros aleatorios mediante los metodos de BubbleSort y QuickSort
*/

#include<stdio.h>  /** libreria basica para entrada y salida */
#include<stdlib.h> /** libreria para el uso de rand() */
#include<time.h>   /** libreria para el uso de time()*/

void quicksort  (int lista[],int limite_izq,int limite_der){

        /** En esta parte de crea el funcionamiento del QuickSort,

        que es donde se definen la funciones a seguir para el determinado

        rdenamiento que debe seguir para este proceso, por eso se difinen

        la variables y los condicionales para el funcionamiento adecuado

        de la forma QuickSort */
        
    int izq,der,temporal,pivote;
	izq = limite_izq;
	der = limite_der;
	pivote = lista[(izq + der)/2];

	do{
		while(lista[izq] > pivote && izq < limite_der)izq++;
		while(pivote > lista[der] && der > limite_izq)der--;
		if(izq <= der){
			temporal = lista[izq];
			lista[izq] = lista[der];
			lista[der] = temporal;
			izq++;
			der--;
		}
	}

    while(izq <= der);
	if(limite_izq < der){
		quicksort(lista,limite_izq,der);
	}

 	if(limite_der > izq){
		quicksort(lista,izq,limite_der);
	}
}

    /* Se procede a crear la funcion que implementara el
    modelo de ordenamiento del QuickSort */

void qs(int lista[], int n){
	quicksort(lista, 0, n - 1);
}

    /*  A continuacion, se procede a medir el tiempo en el que dura el programa en ejecutarse. Para lograr esto,
    se mide el tiempo en el que se inicia el progama, y luego se mide cuando termina y se procede a realizar 
    una resta para asi obtener el tiempo que tarda el programa */ 

int main(int argc, const char * argv[]){ 

    /*  Se procede a generar los numeros aleatorios. Se desea generar un maximo de 2500 valores aleatorios. Sin embargo,
    cuando se ejecute un ciclo for más adelante, se seleccionará un máximo de 1500 veces recorridas para cumplir con 
    lo solicitado en el laboratorio. */

    int tiempo = time(NULL);
	srand(tiempo);
	int lista[2500];

    int recorrido = 1500;

    /*  Se crea el ciclo for que genera los 1500 valores aleatorios */

    printf("Arreglo generado aleatoriamente: \n");
	for(int i = 0; i < recorrido; i++){
		lista[i] = rand()%100;
		printf("%d ",lista[i]);
	}

    /* Se procede a acomodar el arreglo generado mediante el metodo Quicksort llamando a la funcion */

    printf("\n\n -------- QuickSort --------");

        /** Se imprime de forma ordenada los numeros aleatorios generados para

        el metodo QuickSort */

	clock_t begin1 = clock();

	qs(lista, recorrido);
	printf("\nArreglo Ordenado:  \n");
	for (int i=0; i < recorrido; i++) {
		printf("%d",lista[i]);
		if(i < recorrido - 1)
		printf(" ");
    }

    /* Se toma el tiempo que tarda el programa en ejecutarse*/

	clock_t end1 = clock();
	double tiempo_qs = (double)(end1 - begin1) *1000 / CLOCKS_PER_SEC;

	printf("\n Tiempo que le tomo al metodo QuickSort: %f \n", tiempo_qs);


    /* Se procede a acomodar el arreglo pero por el metodo de BubbleSort */ 

	printf("\n -------- BubbleSort -------- \n");

        

        /* Se definen las variables que se van a utilizar y
           el arreglo aceptará hasta 2500 numeros */

	int paso, aux;

        /* Se utiliza un bucle for para acomodar el arreglo
           en forma descendiente y luego se imprime */ 

	clock_t begin2 = clock();
	for(paso = 0; paso < recorrido-1; paso++)
	for(int i = 0; i < recorrido - paso - 1; i++){

		if(lista[i]<lista[i+1]){
			aux = lista[i];
			lista[i] = lista[i+1];
			lista[i+1] = aux;
		}
	}

    /* Imprime los numeros ordenados */

	printf("Arreglo Ordenado: \n");
	for(int i = 0; i < recorrido; i++)
	printf("%d ",lista[i]);

	/* Se mide el tiempo en el que se inicia el progama*/ 

	clock_t end2 = clock();
	double tiempo_bs = (double) (end2 - begin2) *1000 / CLOCKS_PER_SEC;

    /* Mide el tiempo que tomo al programa en ejecutarse y lo resta al inicial tomado anteriormente, y asi
     se obtiene el tiempo que tarda el programa */

	printf("\n Tiempo que le tomo al metodo BubbleSort: %f \n\n", tiempo_bs);

	/*return 0;*/
	if (tiempo_qs < tiempo_bs){
		printf("QuickSort es mas rapido. \n");
	}

	else if(tiempo_qs > tiempo_bs){
		printf("BubbleSort es mas rapido. \n");
	}
	return 0;
}
