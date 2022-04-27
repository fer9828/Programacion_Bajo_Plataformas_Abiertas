/** @file lista.c
 * @author Christopher Bolaños
 * Fernado Jiménez
 * @brief Funciones desarrolladas para el Laboratorio 7
 **/

#include "lista.h"


/**
	*		front
	* 	_________________
	* 	|_____head______|
	* 	|_______________|
	* 	|_______________|
	* 	|_______________|
	*   |_____tail______|
	*
	* 		back
	**/


//Desarrollo de las Funciones



node* createList(int first_value){
	/**
 *  @brief Función que crea una lista.
 *  @details Recibe el valor de la primera posición de la lista y lo guarda.
 **/
	node* head = (node*) malloc(sizeof(node));

	head->data = first_value;  
	
	head->next = NULL;

	return head;

}

int freeList(node* head){
/**
 *  @brief Función que libera la memoria ocupada por la lista.
 *  @details Recibe el primer valor de la lista, la recorre y libera cada nodo.
 **/

  node* temp = head;
  node* next;

  while( temp != NULL)
  {
    next = temp->next;
    free(temp);
    temp = next;
  }
  head = NULL;
  return 0 ;
}

node * readList(const char* filePath){
	/**
 *  @brief Función que lee la lista a partir de un archivo.
 *  @details Recibe la ubicación del archivo y la guarda en un struct.
 **/

	int elementos = 20; //Cantidad de datos que recibe la lista
	int buffer[elementos];
	int i = 1;

	FILE * file;
	file = fopen(filePath, "rb");

	if (file)
	{
		node * temp;
		while (i < elementos)
		{
			fread(&buffer, sizeof *buffer, 1, file);
			i++;
		}
		rewind(file);

		for (int j = 0; j < i; j++)
		{
			fread(&buffer, sizeof *buffer, 1, file);
			if (j==0)
			{
				temp = createList(*buffer);
			}
			
			else
			{
				push_back(temp, *buffer);
			}
		}
		fclose(file);
		return temp;
	}

	else{
		printf("\nNo fue posible hallar el archivo\n");
		return NULL;
	}
}

void writeList(node* head, const char* filePath){
  /**
 *  @brief Función que lee la lista a partir de un archivo.
 *  @details Recibe el primer dato de la lista y la ubicación del archivo donde se guarda la lista.
 **/
    FILE *file;
  file=fopen(filePath,"w");
  if(file!=NULL){
    fprintf(file,"%d\n",head->data); 

  }else{
    printf("No fue posible escribir el primer elemento");
  }
  while(head->next!=NULL){
    head=head->next;
    if(file!=NULL){
      fprintf(file,"%d\n",head->data); 
    }else{
      printf("No fue posible escribir el dato");
    }
  }
  fclose(file);
}

int push_back(node* head, int new_value){
	/**
 *  @brief Función que cambia el último valor de la lista.
 *  @details Recibe el primer dato de la lista y el nuevo valor para el último dato.
 **/

	node * new_node_t = (node *) malloc(sizeof(node));
	node * temp ;

	if(new_node_t == NULL)
	{
		printf("\nNo fue posible reservar memoria\n");
	}

	else{
		new_node_t ->data = new_value;
		new_node_t ->next  = NULL;

		temp = head;

		while(temp ->next != NULL)
		{
			temp = temp ->next;
		}
	}

	temp ->next = new_node_t;

	return 0;
}


int push_front(node** head, int new_value){
	/**
 *  @brief Función que cambia el primer valor de la lista.
 *  @details Recibe el primer dato de la lista y el nuevo valor para el primer dato.
 **/
	node* new_node_t = ( node* ) malloc(sizeof(node));
	new_node_t->data = new_value;
	new_node_t->next = (*head);
	(*head ) = new_node_t ;
	return 0 ;

}


int pop_back(node* head){
	/**
 *  @brief Función que elimina el primer valor de la lista.
 *  @details Recibe el primer dato de la lista.
 **/

	node * ult = head;
	node * ant = head;
	if (head == NULL)
	{
		printf("\n La lista se encuentra vacía \n");
	}

	else
	{
		while (ult ->next != NULL)
		{
			ant = ult;
			ult = ult ->next;
		}
		ant ->next = NULL;
		free(ult);
	}
	return 0;
}


int pop_front(node **head){ 
/**
 *  @brief Función que elimina el primer valor de la lista.
 *  @details Recibe el primer dato de la lista.
 **/
	node* tmp = *head;
	*head = (*head)->next;

	free(tmp);
	return 0;
}


//Segunda parte

int insertElement(node** phead, int pos, int new_value){
	/**
 *  @brief Función que inserta un valor en la lista.
 *  @details Recibe el primer dato de la lista, la posición donde se desea ingresar y el nuevo valor para la posición.
 **/

node * temp = *phead;
if (pos == 0)
{
	push_front(phead, new_value); 
}

else
{
	int index;
	for (index = 0; index < (pos-1); ++index) 
	{
		if(temp == NULL)
		{
			return 1;
		}
		temp = temp -> next;
	}
	node * new_node_t = (node*)malloc(sizeof(node)); 
	new_node_t -> data = new_value; 
	new_node_t -> next = temp -> next; 
	temp -> next = new_node_t;
}
return 0;
}



int removeElement(node** head, int pos){
/**
 *  @brief Función que quita un valor de la lista.
 *  @details Recibe el primer dato de la lista y la posición del dato a extraer.
 **/
node *temp = *head;
node *prev = NULL;

if (temp != NULL && pos == 0){
	*head = temp->next;
	free(temp);
}
else{
	int contador = 0;
	while (temp != NULL && contador != pos){
		prev = temp;
		temp = temp->next;
		++contador;
	}
	if (temp != NULL){
		prev->next = temp->next;
		free(temp);
	}
}
return 0;
}


int getElement(node* head, int index, int* valid){
	/**
 *  @brief Función que muestra un valor de la lista.
 *  @details Recibe el primer dato de la lista y la posición del dato a mostrar.
 **/
	node* temp = head;
	int contador = 0;
	while (temp != NULL)
	{
		if (contador == index)
		{
			return temp -> data;
		}
		temp = temp -> next;
		++contador;
		*valid = 0;
	}
	*valid = 1;
	return -1;
}


int printElement(const int value){
	/**
 *  @brief Función que imprime valores.
 *  @details Recibe el primer dato de la lista y la posición del dato a extraer.
 **/
	printf("%d \n", value);
	return 0;
}

/*
void sort(node* head, char dir){
	
	
}
*/


void printList(node * head){
	/**
 *  @brief Función que imprime toda la lista.
 *  @details Recibe el primer dato de la lista.
 **/
	while (head != NULL)
	{
		printElement((const int)head -> data);
		head = head->next;
	}
}