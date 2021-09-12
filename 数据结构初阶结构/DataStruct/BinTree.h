#ifndef _BINTREE_H_
#define _BINTREE_H_

#include"Common.h"
#include"Queue.h"
#include"Stack.h"

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef  BinTreeNode* BinTree;
void BinTreeInit(BinTree *t); 

//二叉树的创建
void BinTreeCreate_1(BinTree *t);
BinTree BinTreeCreate_2();
BinTree BinTreeCreate_3(char *str, int *i);
BinTree BinTreeCreate_VLR_LVR(char *VLR, char *LVR, int n);
BinTree BinTreeCreate_LVR_LRV(char *LVR, char *LRV, int n);

//二叉树的遍历 递归
void BinTreePreOrder(BinTree t);
void BinTreeInOrder(BinTree t);
void BinTreePostOrder(BinTree t);
void BinTreeLevelOrder(BinTree t);

//二叉树的遍历 非递归
void BinTreePreOrder_NoR(BinTree t);
void BinTreeInOrder_NoR(BinTree t);
void BinTreePostOrder_NoR(BinTree t);

//二叉树的功能
size_t Size(BinTree t);
size_t LeafSize(BinTree t);
size_t LevelKSize(BinTree t, int k);
size_t Height(BinTree t);
BinTreeNode* Find(BinTree t, ElemType key);
BinTreeNode* Parent(BinTree t, BinTreeNode *p);
BinTreeNode* Clone(BinTree t);
bool Equal(BinTree t1, BinTree t2);
void BinTreeDestroy(BinTree *t);
bool BinaryTreeComplete(BinTree t);

void BinTreeInit(BinTree *t)
{
	*t = NULL;
}
void BinTreeCreate_1(BinTree *t)
{
	ElemType item;
	scanf("%c", &item);
	if(item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate_1(&(*t)->leftChild);
		BinTreeCreate_1(&(*t)->rightChild);
	}
}

BinTree BinTreeCreate_2()
{
	BinTreeNode *t;
	ElemType item;
	scanf("%c", &item);
	if(item == '#')
		return NULL;
	
	t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = item;
	t->leftChild = BinTreeCreate_2();
	t->rightChild = BinTreeCreate_2();
	return t;
}

BinTree BinTreeCreate_3(char *str, int *i)
{
	BinTreeNode *t;
	if(str[*i]=='#' || str[*i]=='\0')
		return NULL;
	t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = str[*i];
	(*i)++;
	t->leftChild = BinTreeCreate_3(str, i);
	(*i)++;
	t->rightChild = BinTreeCreate_3(str, i);
	return t;
}

BinTree BinTreeCreate_VLR_LVR(char *VLR, char *LVR, int n)
{
	if(n == 0)
		return NULL;
	int k = 0;
	while(VLR[0] != LVR[k])
		k++;

	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = LVR[k];

	t->leftChild = BinTreeCreate_VLR_LVR(VLR+1, LVR, k);
	t->rightChild = BinTreeCreate_VLR_LVR(VLR+k+1, LVR+k+1, n-k-1);
	return t;
}

BinTree BinTreeCreate_LVR_LRV(char *LVR, char *LRV, int n)
{
	if(n == 0)
		return NULL;
	//寻找根节点
	int k = 0;
	while(LVR[k] != LRV[n-1])
		k++;

	//创建根节点
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = LVR[k];

	//递归创建右树
	t->rightChild = BinTreeCreate_LVR_LRV(LVR+k+1, LRV+k, n-k-1);

	//递归创建左树
	t->leftChild = BinTreeCreate_LVR_LRV(LVR, LRV, k);

	//返回树
	return t;
}

size_t Size(BinTree t)
{
	if(t == NULL)
		return 0;
	
	return Size(t->leftChild) + Size(t->rightChild) + 1;
}

size_t LeafSize(BinTree t)
{
	if(t == NULL)
		return 0;
	if(t->leftChild==NULL && t->rightChild==NULL)
		return 1;
	return LeafSize(t->leftChild) + LeafSize(t->rightChild);
}

size_t LevelKSize(BinTree t, int k)
{
	if(t == NULL)
		return 0;
	if(k == 1)
		return 1;
	return LevelKSize(t->leftChild, k-1) + LevelKSize(t->rightChild, k-1);
}

size_t Height(BinTree t)
{
	size_t left_h, right_h;
	if(t == NULL)
		return 0;

	left_h = Height(t->leftChild);
	right_h = Height(t->rightChild);
	return (left_h > right_h ? left_h : right_h) + 1;
}

BinTreeNode* Find(BinTree t, ElemType key)
{
	BinTreeNode *p;
	if(t==NULL || t->data==key)
		return t;
	p = Find(t->leftChild, key);
	if(p != NULL)
		return p;
	return Find(t->rightChild, key);
}

BinTreeNode* Parent(BinTree t, BinTreeNode *p)
{
	BinTreeNode *ret;
	if(t==NULL || t->leftChild==p || t->rightChild==p)
		return t;
	ret = Parent(t->leftChild, p);
	if(ret != NULL)
		return ret;
	return Parent(t->rightChild, p);
}

void BinTreePreOrder(BinTree t)
{
	if(t != NULL)
	{
		printf("%c ", t->data); 
		BinTreePreOrder(t->leftChild);
		BinTreePreOrder(t->rightChild);
	}
}

void BinTreeInOrder(BinTree t)
{
	if(t != NULL)
	{
		BinTreeInOrder(t->leftChild);
		printf("%c ", t->data); 
		BinTreeInOrder(t->rightChild);
	}
}

void BinTreePostOrder(BinTree t)
{
	if(t != NULL)
	{
		BinTreePostOrder(t->leftChild);
		BinTreePostOrder(t->rightChild);
		printf("%c ", t->data); 
	}
}

void BinTreeLevelOrder(BinTree t)
{
	if(t != NULL)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);
		LinkQueuePush(&Q, t);
		while(!LinkQueueEmpty(&Q))
		{
			BinTreeNode *node = LinkQueueFront(&Q);
			LinkQueuePop(&Q);
			printf("%c ", node->data);
			if(node->leftChild != NULL)
				LinkQueuePush(&Q, node->leftChild);
			if(node->rightChild != NULL)
				LinkQueuePush(&Q, node->rightChild);
		}
	}
}

bool BinaryTreeComplete(BinTree t)
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueuePush(&Q, t);
	while(!LinkQueueEmpty(&Q))
	{
		BinTreeNode *p = LinkQueueFront(&Q);
		LinkQueuePop(&Q);
		if(p != NULL)
		{
			LinkQueuePush(&Q, p->leftChild);
			LinkQueuePush(&Q, p->rightChild);
		}
		else
		{
			while(!LinkQueueEmpty(&Q))
			{
				p = LinkQueueFront(&Q);
				LinkQueuePop(&Q);
				if(p != NULL)
					return false;
			}
		}
	}
	return true;
}

BinTreeNode* Clone(BinTree t)
{
	BinTreeNode *p;
	if(t == NULL)
		return NULL;

	p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(p != NULL);
	p->data = t->data;
	p->leftChild = Clone(t->leftChild);
	p->rightChild = Clone(t->rightChild);
	return p;
}

bool Equal(BinTree t1, BinTree t2)
{
	if(t1==NULL && t2==NULL)
		return true;
	if(t1==NULL || t2==NULL)
		return false;

	return ((t1->data==t2->data) && Equal(t1->leftChild, t2->leftChild) && Equal(t1->rightChild, t2->rightChild));
}

void BinTreeDestroy(BinTree *t)
{
	if(*t != NULL)
	{
		BinTreeDestroy(&(*t)->leftChild);
		BinTreeDestroy(&(*t)->rightChild);
		free(*t);
		*t = NULL;
	}
}

void BinTreePreOrder_NoR(BinTree t)
{
	if(t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);
		LinkStackPush(&st, t);
		while(!LinkStackEmpty(&st))
		{
			BinTreeNode *p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);
			if(p->rightChild != NULL)
				LinkStackPush(&st, p->rightChild);
			if(p->leftChild != NULL)
				LinkStackPush(&st, p->leftChild);
		}
	}
}

void BinTreeInOrder_NoR(BinTree t)
{
	if(t != NULL)
	{
		LinkStack st;
		LinkStackInit(&st);

		do
		{
			while(t != NULL)
			{
				LinkStackPush(&st, t);
				t = t->leftChild;
			}
			BinTreeNode *p = LinkStackTop(&st);
			LinkStackPop(&st);
			printf("%c ", p->data);
			if(p->rightChild != NULL)
				t = p->rightChild;
		}while(!LinkStackEmpty(&st) || t!=NULL);
	}
}

void BinTreePostOrder_NoR(BinTree t)
{
	if(t != NULL)
	{
		BinTreeNode *prev = NULL;
		LinkStack st;
		LinkStackInit(&st);

		do
		{
			while(t != NULL)
			{
				LinkStackPush(&st, t);
				t = t->leftChild;
			}
			BinTreeNode *p = LinkStackTop(&st);
			if(p->rightChild==NULL || prev==p->rightChild)
			{
				LinkStackPop(&st);
				printf("%c ", p->data);
				prev = p;
			}
			else
				t = p->rightChild;
		}while(!LinkStackEmpty(&st));
	}
}



/*
BinTree BinTreeCreate_3(char *str)
{
	BinTreeNode *t;
	if(*str=='#' || *str=='\0')
		return NULL;
	t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert(t != NULL);
	t->data = *str;
	t->leftChild = BinTreeCreate_3(++str);
	t->rightChild = BinTreeCreate_3(++str);
	return t;
}

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root; //树根
}BinTree;

void BinTreeInit(BinTree *t);
void _BinTreeCreate(BinTreeNode **t);
void BinTreeCreate(BinTree *t);

void BinTreeInit(BinTree *t)
{
	t->root = NULL;
}

void _BinTreeCreate(BinTreeNode **t)
{
	ElemType item;
	scanf("%c", &item);
	if(item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		_BinTreeCreate(&(*t)->leftChild);
		_BinTreeCreate(&(*t)->rightChild);
	}
}
void BinTreeCreate(BinTree *t)
{
	_BinTreeCreate(&(t->root));
}
*/

#endif /* _BINTREE_H_ */