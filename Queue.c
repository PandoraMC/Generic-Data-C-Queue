#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitQueue(Queue_t *Queue, int dataLen){
  Queue -> dataLen = dataLen;
  Queue -> Head = NULL;
  Queue -> Tail = NULL;
}

int Enqueue(Queue_t *Queue, Item_t Item){
  int status = 1;
  Node_t *newItem = malloc(sizeof(Node_t));
  if(newItem == NULL){
    status = 0;
  }
  newItem -> Item = malloc(Queue -> dataLen);
  memcpy(newItem -> Item, Item, Queue -> dataLen);
  newItem -> Next = NULL;
  if(Queue -> Tail != NULL){
    Queue -> Tail -> Next = (struct Node_t*)newItem;
  }
  Queue -> Tail = newItem;
  if(Queue -> Head == NULL){
    Queue -> Head = newItem;
  }
  return status;
}

Item_t Dequeue(Queue_t *Queue){
  Item_t data;
  if(Queue -> Head == NULL){
    data = NULL;
  }
  Node_t *rmNode = Queue -> Head;
  data = malloc(Queue -> dataLen);
  memcpy(data, rmNode -> Item, Queue -> dataLen);
  Queue -> Head = (Node_t*)Queue -> Head -> Next;
  if(Queue -> Head == NULL){
    Queue -> Tail = NULL;
  }
  free(rmNode -> Item);
  free(rmNode);
  return data;
}

void PrintQueue(Queue_t *Queue){
  Node_t *shift = Queue -> Head;
  char *dataByte;
  int i;
  while(shift != NULL){
    dataByte = (char*)(shift -> Item);
    for(i = 0; i < Queue -> dataLen; i++){
      printf("%x ", *(dataByte++));
    }
    printf("\t");
    shift = (Node_t*)shift -> Next;
  }
}
