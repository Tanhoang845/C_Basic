#ifndef FILE_QUEUE_HEADER
#define FILE_QUEUE_HEADER
#include "datatypes.h"


void initQueue();
int isEmpty();
int isFull();
int size();
void enqueue(SV data);
SV dequeue();
#endif
