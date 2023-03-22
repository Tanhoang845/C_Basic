#ifndef FILE_CONTACT_HEADER
#define FILE_CONTACT_HEADER
#include "datatypes.h"

void clearLastEnter(char* s);
int readFromKeyboard(DB ** listContact, int* nsize);
int readFromFileText(char *filename, DB ** listContact, int *size);
int readFromFileBinary(char *filename, DB ** listContact, int *size);
int writetoFileText (char *filename, const DB * listContact, int size);
int writetoFileBinary(char *filename, const DB * listContact, int size);
void printAllList(DB *listContact, int size);
DB * seqSearchbyName(const char* name, DB * listContact, int size);
DB * seqSearchbyNameNoCase(const char* name, DB * listContact, int size);
DB * seqSearchbyPhone(const char* sdt, DB * listContact, int size);
void sortList(DB *listContact, int size);
DB * binSearchbyName(const char* name, DB * listContact, int size);
DB * binSearchbyPhone(const char* name, DB * listContact, int size);
#endif
