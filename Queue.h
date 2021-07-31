#ifndef QUEUE_H
#define QUEUE_H

typedef void *Item_t;

typedef struct{
  Item_t Item;
  struct Node_t *Next;
}Node_t;

typedef struct{
  int dataLen;
  Node_t *Head;
  Node_t *Tail;
}Queue_t;

void InitQueue(Queue_t *Queue, int dataLen);
int Enqueue(Queue_t *Queue, Item_t Item);
Item_t Dequeue(Queue_t *Queue);
void PrintQueue(Queue_t *Queue);

#endif
