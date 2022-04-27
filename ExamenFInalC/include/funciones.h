/** @file funciones.h
 * @author Fernado Jiménez Ureña - B74020
 * @brief Funciones desarrolladas para el Examen Final en C
 **/

#include <stdio.h>
#include <stdlib.h>


//  Se desarrolla un struct para definir la estructura del polinomio el cual será utilizado en las funciones 

struct node{

    double coeficiente;
    int exponente;
    struct node* next; 
};



//Funcion insert que se encarga de crear los polinomios 

struct node* insert(struct node* head, float i, int j){
/**
* @brief Funcion insert
* @details Encargada de crear los polinomios
**/

    //Aquí se crean las condiciones necesarias para crear los polinomios 
    struct node* temp;                                  
    struct node* nuevo = malloc(sizeof(struct node));
    nuevo->coeficiente = i;        
    nuevo->exponente = j;          
    nuevo->next = NULL;         

    //En caso que el node no se encuentre en la lista o el node exponente es mayor que el primero node exponent
    //Este if se encarga de determinar si se cumplen esas condiciones entonces se realizan cambios en el head
    if(head == NULL || j > head->exponente)
    {
        nuevo->next = head;
        head = nuevo;
    }
    else
    {
        temp = head;
        while (temp->next !=NULL && temp->next->exponente>=j)
          temp = temp->next;
        nuevo->next = temp->next;
        temp->next =nuevo;
    }
    return head;
}


//  Esta funcion se encarga de preguntarle al usuario la cantidad de coficientes y sus respectivos exponentes de los polinomios
//  que desea utilizar para las funciones

struct node* solicitar(struct node* head){
/**
* @brief Función solicitar
* @details Encargada de solicitar al usuario los polinomios, sus coeficientes y exponentes
**/

    int i, n;
    double coeficiente;
    int exponente;

    printf("Digite la cantidad de coeficientes que desea agregar al polinomio:  ");
    scanf("%d", &n);

    for (i=0; i<n; i++) //Se utiliza un bucle for para guardar los valores en el polinomio
    {
        printf("Digite el coeficiente %d: ",i+1);         
        scanf("%lf", &coeficiente);

        printf("Digite el exponente del coeficiente %d: ", i+1);
        scanf("%d", &exponente);

        head = insert(head,coeficiente,exponente);
    }
    return head;
}


// Funcion print que se encarga de imprimir el polinomio ingresado 

void print(struct node* head){
/**
* @brief Función print
* @details Encargada de imprimir el polinomio ingresado por el usuario
**/

    if(head == NULL)             //Condiciones para poder imprimir la lista que contiene los polinomios
      printf("No corresponde a un polinomio\n");           
    else{
        struct node* temp=head;
        while(temp != NULL)
        {
         printf("%.1fx^%d", temp->coeficiente, temp->exponente); //Los simbolos %.1f y %d imprimen el coeficiente y el exponente ya en el polinomio acompañando a la x
         temp = temp->next;
         if(temp!=NULL)
             printf(" + ");
         else 
             printf("\n");
          }
      }
}

// Funcion Suma que se encarga de sumar los polinomios ingresados por el usuario

void suma(struct node* headPrimerPolinomio, struct node* headSegundoPolinomio){
/**
* @brief Función suma
* @details Encargada de sumar los polinomios ingresados por el usuario
**/
    //Se procede a establecer los punteros del struct
    struct node* primero = headPrimerPolinomio; 
    struct node* segundo = headSegundoPolinomio;                        
    struct node* headTercerPolinomioResultado = NULL; //Un tercer head es creado para poder obtener el resultado de las distintas operaciones como la suma, resta
                                     //multiplicacion y liberacion de espacio
    while (primero!= NULL && segundo !=NULL)             
    {
        if(primero->exponente == segundo->exponente)    //Este if representa que si los exponentes de dos términos de los polinomios son iguales
                                            //entonces, se proceden a sumarse entre ellos
        {
            headTercerPolinomioResultado = insert(headTercerPolinomioResultado, primero->coeficiente+segundo->coeficiente,primero->exponente);
            primero=primero->next;
            segundo=segundo->next;
        }
        else if(primero->exponente > segundo->exponente)
        {
            headTercerPolinomioResultado= insert(headTercerPolinomioResultado, primero->coeficiente, primero->exponente);
            primero=primero->next;
        }
        else if(primero->exponente < segundo->exponente)
        {
            headTercerPolinomioResultado = insert(headTercerPolinomioResultado,segundo->coeficiente,segundo->exponente);
            segundo =segundo->next;
        }
        }
        while (primero!=NULL)
        {
            headTercerPolinomioResultado=insert(headTercerPolinomioResultado, primero->coeficiente, primero->exponente);
            primero = primero->next;           
        }
        while(segundo!=NULL)
        {
            headTercerPolinomioResultado=insert(headTercerPolinomioResultado, segundo->coeficiente, segundo->exponente);
            segundo=segundo->next;
        }
        print(headTercerPolinomioResultado);
    }


//  Funcion Resta que se encarga de restar los polinomios ingresados por el usuario

void resta(struct node* headPrimerPolinomio, struct node* headSegundoPolinomio){
/**
* @brief Función resta
* @details Encargada de restar los polinomios ingresados por el usuario
**/
    //Se procede a establecer los punteros del struct
    struct node* primero = headPrimerPolinomio;
    struct node* segundo = headSegundoPolinomio;                     
    struct node* headTercerPolinomioResultado = NULL;

    //En este caso, se utiliza la misma funcion implementada para la suma, únicamente
    //se cambian los signos dentro de la función para poder restar
    while (primero!= NULL && segundo !=NULL)
    {
        if(primero->exponente == segundo->exponente)

        {
            //Aqui se cambia el signo por ejemplo
            headTercerPolinomioResultado = insert(headTercerPolinomioResultado, primero->coeficiente - segundo->coeficiente,primero->exponente);
    
    
            primero=primero->next;
    
    
            segundo=segundo->next;
        }
        else if(primero->exponente > segundo->exponente)

        {
            headTercerPolinomioResultado= insert(headTercerPolinomioResultado, primero->coeficiente, primero->exponente);
    
    
            primero=primero->next;
    
    
        }
        else if(primero->exponente < segundo->exponente)

        {
            headTercerPolinomioResultado = insert(headTercerPolinomioResultado,segundo->coeficiente,segundo->exponente);
            segundo =segundo->next;
        }
        }
        while (primero!=NULL)

        {
            headTercerPolinomioResultado=insert(headTercerPolinomioResultado, primero->coeficiente, primero->exponente);
    
    
            primero = primero->next;           
    
    
        }
        while(segundo!=NULL)
        {
            headTercerPolinomioResultado=insert(headTercerPolinomioResultado, segundo->coeficiente, segundo->exponente);
            segundo=segundo->next;
        }
        print(headTercerPolinomioResultado);
    }


//Funcion multiplicacion se encarga de multiplicar los polinomios introducidos por el usuario

void multiplicacion(struct node* headPrimerPolinomio, struct node* headSegundoPolinomio){
/**
* @brief Función suma
* @details Encargada de multiplicar los polinomios ingresados por el usuario
**/
    struct node* primero = headPrimerPolinomio;
    struct node* segundo = headSegundoPolinomio;             //Se relacionan los punteros con los structs
    struct node* headTercerPolinomioResultado = NULL;

    //Se revisa primero si el primer o segundo polinomio es NULL
    if(headPrimerPolinomio == NULL || headSegundoPolinomio == NULL)
    {
        printf("Se tiene un polinomio cero\n");
        return;
    }
    //Inicia condiciones para suma
    while(primero != NULL)         //Condiciones para multiplicar los polinomios
    {
        while(segundo != NULL)
        {
            headTercerPolinomioResultado = insert(headTercerPolinomioResultado, primero->coeficiente * segundo->coeficiente, primero->exponente + segundo->exponente);
            segundo= segundo->next;
        }
        primero = primero->next;
        segundo=headSegundoPolinomio;
    }
    print(headTercerPolinomioResultado);
}


//Finalmente se procede a liberar la memoria utilizada con la funcion freeList
//Esta funcion ya fue implementada en el Laboratorio 7

int freeList(struct node* head){
/**
* @brief Función freeList
* @details Encargada de limpiar la memoria utilizada por el programa
**/
    struct node* temp = head;          
    struct node* next;               
    
    while (temp != NULL)
    {
        next = temp -> next;
        free(temp);
        temp = next;
    }

    head= NULL;
    return 0;
}