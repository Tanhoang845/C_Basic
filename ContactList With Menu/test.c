#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

void menu()
{
	DB * listSV;
    int size, selection;
    
    printf("Danh ba hien tai:\n");
    readFromFileBinary("contactList.dat", &listSV, &size);
    printAllList(listSV, size);
    do
    {
    	printf("Moi ban lua chon chuc nang:\n");
	    printf("1. Nap lai du lieu tu file\n");
	    printf("2. Tim kiem theo ten\n");
	    printf("3. Them contact moi vao danh ba\n");
	    printf("4. Xoa mot Contact trong danh ba\n");
	    printf("5. Hien thi noi dung danh ba hien tai\n");
	    printf("6. Luu noi dung danh ba hien tai ra file\n");
	    printf("7. Thoat\n");
	    printf("Lua chon: ");
	    scanf("%d",&selection);
	    fflush(stdin);
	    char name[20],sdt[20];
	    
	    switch(selection)
	    {
	    	case 1: readFromFileBinary("contactList.dat", &listSV, &size);
	    	printf("Load file thanh cong!\n");
	    	break;
	    	
	    	case 2: 
				    printf("Ten can tim: ");
				    //clear();
				    gets(name);
				    DB * result = seqSearchbyNameNoCase(name,listSV,size);
				    if(result==NULL)
				    	printf("Khong co ten can tim trong danh ba!\n");
				    else
				    	printf("Thong tin tim duoc : %s %s %s %s\n",result->hoten, 
						result->sdt, result->email, result->zalo);
					
					break;
			case 3: printf("Nhap them danh ba:\n");
					int dem = addContactFromKeyboard(listSV,&size);
					if(dem!=0) {
						printf("Danh ba moi la:\n");
						printAllList(listSV, size);
					}
					break;
			case 4: 
				    printf("Ten can xoa: ");
				    //clear();
				    gets(name);
				    removeContactbyName(name,listSV, &size);
				    printAllList(listSV, size);
					break;
			case 5: printAllList(listSV, size);
					break;
			case 6: writetoFileBinary("contactList.dat", listSV, size);
					printf("Ghi thanh cong!\n");
					break;
			default: return;
		}
	}
	while(1);
	
}


int main()
{
	menu();
	return 0;

}
