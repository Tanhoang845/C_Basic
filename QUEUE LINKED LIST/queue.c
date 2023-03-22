#include "queue.h"
#include "datatypes.h"
#include <stdlib.h>
int count;
QNODE *front,*rear;

// khoi tao queue rong
void initQueue()
{
	front = NULL;
	rear = NULL;
	count=0;
}

int isEmpty()
{
	return count==0; 
}

int size()
{
	return count;
}

// tuong duong insertLast - chen vao cuoi DSLK don
void enqueue(SV data)
{
	QNODE *pNew = (QNODE *)malloc(sizeof(QNODE));
	pNew->data = data;
	pNew->next=NULL;
	if(count==0)//hang doi dang rong
	{
		front = pNew;
		rear = pNew;
	}
	else // hang doi khac rong, them vao cuoi
	{
		rear->next = pNew;
		rear = pNew;
	}
	count++;
}
// tuong duong removeFirst
SV dequeue()
{
	
	SV retVal = front->data;
	QNODE *p = front;
	
	if(count==1)//chi con 1 phan tu, sau khi xoa thanh rong
	{
		front = NULL;
		rear=NULL;
	}
	else
	{
		front = front->next;
	}
	count--;
	free(p); // do cap phat cac phan tu dong
	return retVal;
}
