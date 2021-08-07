/**
 * @file Queue.h
 * @author Miguel Ángel Castillo Martínez (miguel.castillo.pandora@outlook.com)
 * @brief Estructura cola para el manejo de tipos de datos arbitrarios
 * @version 0.1
 * @date 2021-08-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef QUEUE_H
#define QUEUE_H

/**
 * @typedef Item_t void*
 * @brief Puntero Genérico
 */
typedef void *Item_t;

/**
  * @struct Node_t
  * @brief Nodo con enlace unilateral para la composición de estructuras
  * @param Item Puntero genérico a los datos utilizados en la estructura
 * @param Next Puntero al siguiente nodo en la estructura
 */
typedef struct{
  Item_t Item;
  struct Node_t *Next;
}Node_t;

/**
 * @struct Queue_t
 * @brief Cola de datos genéricos
 * @param dataLen Tamaño en Bytes de los datos a utilizar
 * @param Head Primer elemento de la Cola
 * @param Tail Último elemento de la Cola
 */
typedef struct{
  int dataLen;
  Node_t *Head;
  Node_t *Tail;
}Queue_t;

/**
 * @fn void InitQueue(Queue_t *Queue, int dataLen);
 * @brief Inicialización de la estructura Cola
 * 
 * @param Queue Puntero a la estructura Cola que será utilizada
 * @param dataLen Tamaño de los datos a usar
 * @note Se debe inicializar la estructura antes de operar con ella
 * @see Enqueue Dequeue PrintQueue
 * @code {.c}
 * Queue_t RxVect;
 * unsigned short data;
 * int dataLen = sizeof(data);
 * InitQueue(&RxVect, dataLen);
 * @endcode
 */
void InitQueue(Queue_t *Queue, int dataLen);

/**
 * @fn int Enqueue(Queue_t *Queue, Item_t Item);
 * @brief Añadir a la cola un dato
 * 
 * @param Queue Puntero a la estructura que está siendo utilizada
 * @param Item Puntero generico al dato a añadir
 * @return int, si se ha logrado añadir el dato se retorna 1, de lo contrario 0
 * @code {.c}
 * data = 0x2011;
 * Enqueue(&RxVect, (void*)&data);
 * @endcode
 * 
 */
int Enqueue(Queue_t *Queue, Item_t Item);

/**
 * @fn Item_t Dequeue(Queue_t *Queue);
 * @brief Retirar datos de la cola
 * 
 * @param Queue Puntero a la estructura que está siendo utilizada
 * @return Item_t, Puntero generico que contiene el dato, si no hay datos presentes es NULL
 * @code {.c}
 * Item_t x = NULL;
 * x = Dequeue(&RxVect);
 * memcpy(&data, x, dataLen);
 * free(x);
 * @endcode
 * 
 */
Item_t Dequeue(Queue_t *Queue);

/**
 * @fn void PrintQueue(Queue_t *Queue);
 * @brief Muestra los datos de la Cola utilizada en formato hexadecimal
 * 
 * @param Queue Puntero a la estructura que está siendo utilizada
 */
void PrintQueue(Queue_t *Queue);

#endif