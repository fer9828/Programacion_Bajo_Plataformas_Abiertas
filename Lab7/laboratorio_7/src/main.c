/** @file main.c
 *  @author Cristopher Bolaños - Fernando Jiménez
 *  @brief Función main() donde se llaman las funciones desarrolladas en el arcivo lista.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]){


/**
 *  @details Se inicia la funcion "main" llamando a la función readList(). Esto debido a que dicha funcion contiene a las funciones
 *  createList() y pushback() dentro de ella. A esta funcion readList se le pasa como argumento la lista de enteros separados por 
 *  linea en forma de archivo binario.
 **/

    node * head = NULL;
    head = readList(argv[1]); 
    node ** phead = &head;
    

/**
 *  @details Ya una vez que las funciones logran leer el archivo binario con la lista de elementos, se procede a imprimir en pantalla dicha
 *  lista. Para este procedimiento se llama la funcion printList(). Cabe destacar que la funcion printList() es la encargada de llamar
 *  a la funcion printElement() por lo tanto solo se llama a la función printList() en el main.
 **/

    printf("\nLa lista contiene los elementos: \n\n");
    printList(head);
    printf("\n");
    
    

/**
 *  @details Ya una vez generada la lista e impresa en pantalla, se procede a probar las distintas funciones. En este caso se procede a 
 *  agregar un elemento utilizando la funcion insertElement(). Además dicha funcion llama a la funcion push_front() ya que se desea agregar
 *  este nuevo elemento en el inicio de la lista. La funcion push_front() reserva memoria para este nuevo elemento que se desea agregar al 
 * incio de la lista. 
 **/

    int posicion = 0; //Primera posicion de la lista
    int new_value1 = 786; //Valor que se desea agregar

    insertElement(phead, posicion, new_value1);
    
    printf("La lista despues de llamar a la funcion insertElement() y dicha funcion implementando a la funcion push_front(): \n");
    printf("\n");
    printList(head);
    printf("\n");
    
    

/**
 *  @details Se procede a seguir implementando y probando las funciones a la lista enlazada. En este caso, se llaman las funciones
 *  pop_front() y pop_back(). Dichas funciones eliminan el primer y útlimo elemento de la lista respectivamente además de liberar la memoria.
 **/

    pop_front(phead);
    pop_back(head);

    printf("Luego de llamar a las funciones pop_front() y pop_back(), la lista es:\n");
    printf("\n");
    printList(head);
    printf("\n");

    

/**
 *  @details Se procede a llamar a las funciones getElement() y removeElement().  En este caso, la funcion getElement() imprime en 
 *  pantalla el valor de la posicion que se elige en indice2 mientras que removeElement() elimina el valor que se encuentra en la posicion elegida 
 *  en indice1
 **/

    int valid;
    int * pvalid = &valid;
    
    int indice1 = 11;
    int indice2 = 15;

    removeElement(phead, indice1);
    printf("La lista luego de eliminar el elemento utilizando la funcion removeElement() es: \n\n");
    printList(head);
    printf("\n");
    
    int valor_obtenido;

    valor_obtenido = getElement(head, indice2, pvalid);
    printf("La posicion %i llamada con la funcion getElement(), contiene el valor: %i\n", indice2, valor_obtenido);
    printf("\n");

    
/**
 *  @details  Luego se desea implementar la función writeList(). Para esto, se debe pasar como argumento el head de la lista y luego  
 *  como segundo argumento la ruta del archivo donde se desea guardar la lista de texto plano.
 **/

    writeList(head, argv[2]);
    




/**
 *  @details sort
 * 
 **/



/**
 *  @details  La función de freeList() se encarga de liberar la memoria que fue localizada para la lista
 **/

    freeList(head);
    printf("Los elementos de la lista tras usar la función freeList() son: \n\ns");
    printList(head);
    printf("\n");

    return 0;   
    
}