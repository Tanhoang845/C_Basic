#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int main()
{
	DB * listSV;
    int size;
    //readFromKeyboard(&listSV,&size);
    //writetoFile ("output.dat", listSV, size);
    readFromFileText("contactList.txt", &listSV, &size);
    printAllList(listSV, size);
    
    char name[50],sdt[20];
    printf("SDT can tim: ");
    fgets(sdt, sizeof(sdt), stdin);
    clearLastEnter(sdt);

    DB * result = seqSearchbyPhone(sdt, listSV, size);
    if(result==NULL)
    	printf("Khong co SDT %s trong danh ba!\n", sdt);
    else
    	printf("Thong tin tim duoc : %s %s %s %s\n",result->hoten, 
		result->sdt, result->email, result->zalo);
    return 0;

}
