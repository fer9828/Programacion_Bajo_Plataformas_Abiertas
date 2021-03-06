/** @file lista.h
 *  @brief ...
 *
 *  @details ....
 */

#ifndef LISTA_HPP
#define LISTA_HPP

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data; //**< data */
	struct node* next; //**< pointer to next element */
} node;

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
node* createList(int first_value);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
node* readList(const char* filePath);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
void writeList(node* head, const char* filePath);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int push_back(node* head, int new_value);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int push_front(node** head, int new_value);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int pop_back(node* head);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int pop_front(node** head);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int insertElement(node** head, int pos, int new_value);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int removeElement(node** head, int pos);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int freeList(node* head);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int getElement(node* head, int index, int* valid);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
int printElement(const int value);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
void sort(node* head, char dir);

/**
 *  @brief ...
 *  @details ...
 *  @param ...
 *  @return ...
 **/
void printList(node* head);

#endif
