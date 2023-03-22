#include "stack.h"
#include <stdlib.h>


SV* S;
int top;

void init()
{
	top = 0;
	S = (SV*)malloc(sizeof(SV) * MAX_LEN);
}
int isFull()
{
	return top == MAX_LEN;
}
int isEmpty()
{
	return top == 0;
}
void push(SV data)
{
	if (isFull())
	{
		//printf("Stack is FULL!");
		return;
	}
	S[top] = data;
	top++;
}
SV pop()
{
	top--;
	return S[top];
}