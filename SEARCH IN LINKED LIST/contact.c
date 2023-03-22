#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

const int MAX_LEN = 255;
// doc vao danh sach tu ban phim
void clear (void)
{    
    int c;
    while((c = getchar()) != '\n' && c != EOF); 
}

void clearLastEnter(char* s){
    if(s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
}

int readFromKeyboard(DB ** listContact, int* nsize)
{
	DB * retval;
    int size;
    printf("Kich thuoc danh ba can nhap: ");
    scanf("%d",&size);
    clear();
    retval = (DB*) malloc(sizeof(DB)*size);
    char buff[MAX_LEN];

    for(int i=0; i<size; i++)
    {
        printf("Hoten: ");
        gets(retval[i].hoten);
        //strcpy(retval[i].hoten,buff);
        printf("sdt: ");
        gets(retval[i].sdt);
        printf("email: ");
        gets(retval[i].email);
        printf("zalo: ");
        gets(retval[i].zalo);
    }
    *listContact = retval;
    *nsize = size;
}
// doc danh ba vao tu file TEXT
int readFromFileText(char *filename, DB ** listContact, int *nsize)
{
		int size;
    DB *retval;
    FILE *fptr;
    if ((fptr = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", filename);
		return FAIL;
	}
    fscanf(fptr,"%d\n", &size);
    if(size == 0) return SUCCESS;

    retval = (DB*) malloc(sizeof(DB)*size);
    char temp[10];

    for(int i = 0; i<size; i++)
    {
        fgets(retval[i].hoten, sizeof(retval[i].hoten), fptr); 
        clearLastEnter(retval[i].hoten);
        fgets(retval[i].sdt, sizeof(retval[i].sdt), fptr);
        clearLastEnter(retval[i].sdt);
        fgets(retval[i].email, sizeof(retval[i].email), fptr);
        clearLastEnter(retval[i].email);
        fgets(retval[i].zalo, sizeof(retval[i].zalo), fptr);
        clearLastEnter(retval[i].zalo);
        fgets(temp, sizeof(temp), fptr);
    }
    *listContact = retval;
    *nsize = size;
    
	return SUCCESS;
}
int readFromFileBinary(char *filename, DB ** listContact, int *nsize)
{
	int size;
    DB *retval;
    FILE *fptr;
    if ((fptr = fopen(filename, "rb")) == NULL){
		printf("Cannot open %s.\n", filename);
		return FAIL;
	}
	fread(&size, sizeof(int), 1, fptr);
    
	if(size<=0){  // danh sach rong
	    fclose(fptr); 
	    *nsize =0;
	    return SUCCESS; 
	}
	// cap phat dong mang luu danh sach phan tu
	retval = (DB*) malloc(sizeof(DB)*size);
	fread(retval, sizeof(DB), size, fptr);
	*listContact = retval;
	*nsize = size;
	fclose(fptr);
	return SUCCESS;
}

// ghi danh ba vao file TEXT
int writetoFileText(char *filename, const DB * listContact, int size)
{
    FILE * fptr;
    fptr = fopen(filename, "w");

    fprintf(fptr, "%d\n", size);
	for(int i = 0; i < size; i++)
    {
        fprintf(fptr,"%s\n%s\n%s\n%s\n\n", listContact[i].hoten,
            listContact[i].email, listContact[i].zalo, listContact[i].sdt);
    }
	return SUCCESS;
}
int writetoFileBinary(char *filename, const DB * listContact, int size)
{
    if (size == 0)
        return SUCCESS;
    FILE *fptr;
    if ((fptr = fopen(filename, "wb")) == NULL){
		printf("Cannot open %s.\n", filename);
		return FAIL;
	}
	fwrite(&size, sizeof(int), 1, fptr);
	fwrite(listContact, sizeof(DB), size, fptr);
	fclose(fptr);
	return SUCCESS;
}

void printAllList(DB *listContact, int size)
{
	printf("Danh ba hien tai: \n");
	printf("Number of contacts : %d\n", size);
    for(int i=0;i<size;i++)
    {
        printf("%d %s %s %s %s\n",i+1,listContact[i].hoten,
            listContact[i].sdt,listContact[i].email,listContact[i].zalo);
    }
    printf("================================\n");

}

// tim kiem va tra ve nguoi dau tien co ten 
DB * seqSearchbyName(const char* name, DB * listContact, int size)
{
	for(int i=0;i<size; i++)
	{
		if(strstr(listContact[i].hoten,name)!=NULL)
			return &listContact[i];
	}
	return NULL; // khong thay
}
// tim kiem va tra ve nguoi dau tien co ten 
// khong phan biet hoa/thuong
DB * seqSearchbyNameNoCase(const char* name, DB * listContact, int size)
{
	for(int i=0;i<size; i++)
	{
		if(strstr(listContact[i].hoten,name)!=NULL)
			return &listContact[i];
	}
	return NULL; // khong thay
}

DB * seqSearchbyPhone(const char* sdt, DB * listContact, int size)
{
	for(int i = 0;i < size; i++)
	{
		if(strcmp(listContact[i].sdt,sdt)==0)
			return &listContact[i];
	}
	return NULL;
}

