#ifndef BINARYSEARCHTREE_HEADER
#define BINARYSEARCHTREE_HEADER

typedef struct BSTNODE
{
	char data;
	int key;
	struct BSTNODE *left, *right, *parent;
} BST;

BST* makeTree(char data, int key);
void addNode(char data, int key, BST *parent, int isLeftChild);


int checkBST(BST* root, int LB, int RB);

// check cay nhi phan co phai la BST,
// neu khong phai thi tra ve nut vi pham dau tien
int checkBST2(BST* root, int LB, int RB, BST** illegalNode);

// them nut vao cay nhi phan tim kiem
// cay do phai khac NULL
void addNodeBST(char data, int key, BST *root);

// p la con tro toi nui can xoa
// root la con tro toi goc
void removeNode(BST** root, BST** p);
BST* removeNode2(BST* root, BST** p);

BST* searchRec(BST* root,int key);
BST* searchLoop(BST* root,int key);

BST* findLeftMost(BST* root);

void inOrderTraversal(const BST *root);
#endif
