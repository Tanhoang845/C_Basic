#include "stack.h"
#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstddef>

STACKSV* top;
int count = 0;

void init()
{
	top = nullptr;
	count = 0;
}

int size()
{
	return count;
}

int isEmpty()
{
	return count == 0;
}

void push(SV inputdata)
{
	STACKSV* pNew = (STACKSV*)malloc(sizeof(STACKSV));
	if (nullptr == pNew)
	{
		printf("OUT OF MEM!\n");
		return;
	}
	pNew->data = inputdata;
	pNew->next = top;
	top = pNew;
	count++;
}

// tra ve gia tri data
SV pop()
{
	SV retval;
	STACKSV* p = top;
	top = top -> next;
	retval = p -> data;
	free(p);
	count-- ;
	return retval;
}

// tra ve con tro
STACKSV* pop2()
{
	if (isEmpty()) return nullptr;
	STACKSV* retval = top;
	top = top->next;
	count--;
	return retval;
}