#include "queue.h"
#include "datatypes.h"


int front,rear, count;
int MAX_LEN = 100;
SV Q[100];

void initQueue()
{
	front = 0;
	rear = 0;
	count=0;
}

int isEmpty()
{
	return count==0; 
}

int isFull()
{
	return count==MAX_LEN;
}

int size()
{
	return count;
}

void enqueue(SV data)
{
	if(isFull()) return;
	Q[rear] = data;
	rear = (rear+1)%MAX_LEN;
	count++;
}

SV dequeue()
{
	count--;
	int curr = front;
	front = (front+1)%MAX_LEN;
	return Q[curr];
}
