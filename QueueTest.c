#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Queue_t RxVect;

int main(void){
	unsigned short data;
	int dataLen = sizeof(data);
	Item_t x = NULL;

	InitQueue(&RxVect, dataLen);

	data = 257;
	Enqueue(&RxVect, (void*)&data);

	data = 0x2011;
	Enqueue(&RxVect, (void*)&data);

	printf("data in queue\n");
	PrintQueue(&RxVect);

	x = Dequeue(&RxVect);
	memcpy(&data, x, dataLen);
	free(x);
	printf("\nData dispatch: %x\n", data);

	x = Dequeue(&RxVect);
	memcpy(&data, x, dataLen);
	free(x);
	printf("\nData dispatch: %x\n", data);

	printf("data in queue\n");
	PrintQueue(&RxVect);

	return 0;
}
