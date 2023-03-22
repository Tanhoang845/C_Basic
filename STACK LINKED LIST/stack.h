#ifndef FILE_STACK
#define FILE_STACK
#include "datatypes.h"

void init();
//int isFull();
int size();
int isEmpty();
void push(SV data);
// tra ve chi lay data
SV pop();
STACKSV* pop2();
#endif