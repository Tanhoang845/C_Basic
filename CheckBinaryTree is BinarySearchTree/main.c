#include "bst.h"
#include <stdio.h>
#include <limits.h>
int main()
{
	BST *root = makeTree('A',10);
	/*
	addNode('B',5,root,1);
	addNode('G',10,root,0);
	addNode('E',4,root->left,1);
	addNode('F',6,root->left,0);
	addNode('H',9,root->right,1);
	addNode('I',18,root->right,0);*/
	/*
	int result = checkBST(root,INT_MIN,INT_MAX);
	if(result ==0) 
		printf("Day KHONG phai cay nhi phan tim kiem!\n");
	else
		printf("Do chinh xac la cay nhi phan tim kiem!\n");
	
	*/
	/*
	BST * illegalNode = NULL;
	int result = checkBST2(root,INT_MIN,INT_MAX, &illegalNode);
	if(result ==0) 
	{
		printf("Day KHONG phai cay nhi phan tim kiem!\n");
		printf("Gia tri nut vi pham %c %d\n", 
			illegalNode->data, illegalNode->key);
	}		
	else
		printf("Do chinh xac la cay nhi phan tim kiem!\n");
	*/
	addNodeBST('B',3,root);
	addNodeBST('C',8,root);
	addNodeBST('D',6,root);
	addNodeBST('E',4,root);
	addNodeBST('F',25,root);
	addNodeBST('H',12,root);
	addNodeBST('G',31,root);
	addNodeBST('I',17,root);
	
	inOrderTraversal(root);
	printf("\n");
	
	BST* leftmost = findLeftMost(root);
	printf("Nut nho nhat %c %d\n",leftmost->data,leftmost->key);
	
	BST *p = searchLoop(root,10);
	removeNode(&root,&p);
	inOrderTraversal(root);
	printf("\n");
	
	printf("Goc hien tai %c %d\n",root->data,root->key);
	
	p = searchLoop(root,12);
	removeNode(&root,&p);
	inOrderTraversal(root);
	printf("\n");
	
	printf("Goc hien tai %c %d\n",root->data,root->key);
	return 0;
}
