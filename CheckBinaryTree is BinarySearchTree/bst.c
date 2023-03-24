#include "bst.h"
#include<stdlib.h> // malloc
#include<stdio.h>
// ham tao cay voi 1 nut goc
BST* makeTree(char data, int key)
{
	BST* root = (BST*) malloc(sizeof(BST));
	root->data = data;
	root->key = key;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	return root;
}
// isLeftChild = 1 -> la con trai cua parent
// nguoc lai, la con phai cua parent
void addNode(char data, int key, BST *parent, int isLeftChild)
{
	BST* pNew = (BST*) malloc(sizeof(BST));
	pNew->data = data;
	pNew->key = key;
	pNew->left = NULL;
	pNew->right = NULL;
	pNew->parent = parent;
	if(isLeftChild) parent->left = pNew;
	else  parent->right = pNew;
}
// kiem tra cay nhi phan co phai la cay nhi phan tim kiem
int checkBST(BST* root, int LB, int RB)
{
	if(NULL == root) return 1;
	if(root->key<RB && root->key>LB)
		return checkBST(root->left,LB,root->key) &&
			checkBST(root->right,root->key,RB);
	else
		return 0;
}

int checkBST2(BST* root, int LB, int RB, BST** illegalNode)
{
	if(NULL == root) {
		*illegalNode = NULL;
		return 1;		
	}
	if(root->key<RB && root->key>LB)
	{
		// nhan trai vi pham truoc
		if (!checkBST2(root->left,LB,root->key,illegalNode))
		{
			return 0;
		}
		else if(!checkBST2(root->right,root->key,RB,illegalNode))
			return 0;
		else
		{
			*illegalNode = NULL;
			return 1;
		}		
	}	
	else
	{
		*illegalNode = root;
		return 0;
	}
}

int checkBST3(BST* root, int LB, int RB, BST** illegalNode)
{
	
	if(NULL == root) {
		*illegalNode = NULL;
		return 1;		
	}
	if(root->key<RB && root->key>LB)
	{
		BST* illegalleft, *illegalright;
		int lRet = checkBST3(root->left,LB,root->key,&illegalleft);
		int rRight = checkBST3(root->left,LB,root->key,&illegalright);
		
		if(lRet && rRight)	// con trai va phai OK 
		{
			*illegalNode = NULL;
			return 1;
		}
		else if(lRet==0) // con trai vi pham
		{
			*illegalNode = illegalleft;
			return 0;
		}
		else 
		{
			*illegalNode = illegalright;
			return 0;
		}
	}	
	else
	{
		*illegalNode = root;
		return 0;
	}
}

// them nut moi: left, right cua nut moi la NULL
// mac dinh gan not parent la NULL, se chinh o ham gan nut 
BST * createNode(char data, int key)
{
	BST* pNew = (BST*) malloc(sizeof(BST));
	pNew->data = data;
	pNew->key = key;
	pNew->left = NULL;
	pNew->right = NULL;
	pNew->parent = NULL;
	return pNew;
}
void addtoTree(BST *parent, BST *pNew, int isLeftChild)
{
	if(isLeftChild)
	{
		if(NULL==parent->left) // them vao
		{
			pNew->parent = parent;
			parent->left = pNew;
		}
		else // tim vi tri gan tiep xuong con trai
		{
			if(pNew->key<parent->left->key) isLeftChild =1;
			else isLeftChild = 0;
			addtoTree(parent->left, pNew, isLeftChild);
		}
	}
	else  //isLeftChild = 0 --> them nhanh phai
	{
		if(NULL==parent->right) // them vao
		{
			pNew->parent = parent;
			parent->right = pNew;
		}
		else // tim vi tri gan tiep xuong con phai
		{
			if(pNew->key<parent->right->key) isLeftChild =1;
			else isLeftChild = 0;
			addtoTree(parent->right, pNew, isLeftChild);
		}
	}
}

// currNode de check xem da toi nut la rong hay chua?
// neu toi la NULL thi gan nut pNew vao vi tri do
// nguoc lai, di chuyen tiep
void addtoTree2(BST *parent, BST* currNode, BST *pNew)
{
	if(NULL==currNode) // toi la NULL thi gan nut pNew vao vi tri do
	{
		pNew->parent = parent;
		if(pNew->key<parent->key) parent->left = pNew;
		else parent->right = pNew;
	}
	else // di chuyen tiep toi khi gap la NULL
	{
		if(pNew->key<currNode->key)
			addtoTree2(currNode, currNode->left,pNew);
		else
			addtoTree2(currNode, currNode->right,pNew);
	}	
}


void addNodeBST(char data, int key, BST *root)
{
	// tao nut moi bang cap phat dong
	BST *pNew = createNode(data, key);
	// goi de quy de gan nut moi vao vi tri phu hop
	/*
	int isLeftChild;
	if(key<root->key) isLeftChild =1;
	else isLeftChild = 0;
	addtoTree(root, pNew, isLeftChild);
	*/
	if(key<root->key) addtoTree2(root,root->left,pNew);
	else addtoTree2(root,root->right,pNew);
}

void inOrderTraversal(const BST *root)
{
	if(NULL==root) return;	
	inOrderTraversal(root->left);
	printf("(%c|%d)", root->data,root->key);
	inOrderTraversal(root->right);
}

BST* findLeftMost(BST* root)
{
	BST *p = root->left;
	while(p->left!=NULL) p = p->left;
	return p;
}

void removeLeaf(BST** root, BST** p)
{
	if(*p==*root)
	{
		*root = NULL;
		free(*p);
		*p = NULL; // cho p ko dc tai su dung nua
		return;
	}
	BST *parent = (*p)->parent;
	
	// tuy thuoc p la con trai hay con phai cua nut cha no
	// de ngat ket noi cho thich hop
	if(*p == parent->left) parent->left = NULL;
	else parent->right= NULL;
	free(*p);
	*p = NULL; // cho p ko dc tai su dung nua
}
void removeNode1Child(BST** root, BST** p)
{
	if(*p==*root)
	{
		if((*root)->left!=NULL) 
			*root = (*root)->left;
		else
			*root = (*root)->right;
		//update lai con tro cha
		(*root)->parent = NULL;
		
		free(*p);
		*p = NULL; // cho p ko dc tai su dung nua
		return;
	}
	BST *parent = (*p)->parent;
	
	// tuy thuoc p la con trai hay con phai cua nut cha no
	// de ngat ket noi cho thich hop
	if(*p == parent->left) 
	{
		if((*p)->left!=NULL)// no co con trai
		{
			parent->left = (*p)->left;
			(*p)->left->parent = parent;
		}	
		else  // co con phai
		{
			parent->left = (*p)->right;
			(*p)->right->parent = parent;
		}
	}
	else {
		if((*p)->left!=NULL)// no co con trai
		{
			parent->right = (*p)->left;
			(*p)->left->parent = parent;
		}	
		else  // co con phai
		{
			parent->right = (*p)->right;
			(*p)->right->parent = parent;
		}
	}
	free(*p);
	*p = NULL; // cho p ko dc tai su dung nua
}

// con tro toi nut can xoa van giu nguyen
void removeNodeFullChildren(BST** root, BST* p)
{
	BST *leftMost = findLeftMost(p->right);
	p->data = leftMost->data;
	p->key = leftMost->key;
	if(leftMost->left==NULL && leftMost->right==NULL)
		removeLeaf(root, &leftMost);
	else
		removeNode1Child(root,&leftMost);
}


void removeNode(BST** root, BST** p)
{
	if((*p)->left == NULL && (*p)->right == NULL)
		removeLeaf(root, p);
	else if((*p)->left != NULL &&(*p)->right != NULL)
		removeNodeFullChildren(root, *p);
	else
		removeNode1Child(root, p);
}

BST* searchRec(BST* root,int key)
{
	if(NULL==root) return NULL;
	if(root->key == key) return root;
	if(root->key > key) 
		return searchRec(root->left,key);
	else 
		return searchRec(root->right,key);
}

BST* searchLoop(BST* root,int key)
{
	while (NULL!=root)
	{
		if(root->key == key) return root;
		if(root->key > key) 
			root = root->left;
		else 
			root = root->right;
	}
	return NULL;
}
