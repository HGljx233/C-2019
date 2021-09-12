#ifndef _STACK_H_
#define _STACK_H_

#include"Common.h"

#define SEQ_STACK_DEFAULT_SIZE 8

//顺序栈
typedef struct SeqStack
{
	ElemType *base; //栈空间
	size_t    capacity;
	size_t    top; //栈顶指针
}SeqStack;

bool IsFull(SeqStack *pst);
bool IsEmpty(SeqStack *pst);
void SeqStackInit(SeqStack *pst, int sz);
void SeqStackPush(SeqStack *pst, ElemType v);
void SeqStackPop(SeqStack *pst);
ElemType SeqStackTop(SeqStack *pst);
//void SeqStackTop(SeqStack *pst, ElemType *v);
void SeqStackShow(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);

bool SeqStackIsFull(SeqStack *pst)
{
	return pst->top >= pst->capacity;
}
bool SeqStackIsEmpty(SeqStack *pst)
{
	return pst->top == 0;
}
void SeqStackInit(SeqStack *pst, int sz)
{
	pst->capacity = sz > SEQ_STACK_DEFAULT_SIZE ? sz : SEQ_STACK_DEFAULT_SIZE;
	pst->base = (ElemType *)malloc(sizeof(ElemType) * pst->capacity);
	assert(pst->base != NULL);
	pst->top = 0;
}

void SeqStackPush(SeqStack *pst, ElemType v)
{
	if(SeqStackIsFull(pst))
	{
		printf("栈已满,%d不能入栈.\n", v);
		return;
	}
	pst->base[pst->top++] = v;
}

void SeqStackPop(SeqStack *pst)
{
	if(SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}

ElemType SeqStackTop(SeqStack *pst)
//void SeqStackTop(SeqStack *pst, ElemType *v) //出参
{
	if(SeqStackIsEmpty(pst))
	{
		printf("栈已空，没有栈顶元素.\n");
		return;
	}
	return pst->base[pst->top-1];
	//*v = pst->base[pst->top-1];
}

void SeqStackShow(SeqStack *pst)
{
	for(int i=pst->top-1; i>=0; --i)
		printf("%d\n", pst->base[i]);
}

void SeqStackDestroy(SeqStack *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

//链栈
struct BinTreeNode;
//#define StackElemType struct BinTreeNode*
#define StackElemType int


typedef struct LinkStackNode
{
	StackElemType data;
	struct LinkStackNode *next;
}LinkStackNode;
typedef struct LinkStack
{
	LinkStackNode *head;
}LinkStack;

void LinkStackInit(LinkStack *pst);
void LinkStackPush(LinkStack *pst, StackElemType v);
void LinkStackPop(LinkStack *pst);
StackElemType LinkStackTop(LinkStack *pst);
void LinkStackShow(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);
bool LinkStackEmpty(LinkStack *pst);

void LinkStackInit(LinkStack *pst)
{
	pst->head = NULL;
}

void LinkStackPush(LinkStack *pst, StackElemType v)
{
	LinkStackNode *s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(s != NULL);
	s->data = v;

	s->next = pst->head;
	pst->head = s;
}

void LinkStackPop(LinkStack *pst)
{
	LinkStackNode *p;
	if(pst->head == NULL)
		return;
	p  = pst->head;
	pst->head = p->next;
	free(p);
}

StackElemType LinkStackTop(LinkStack *pst)
{
	assert(pst->head != NULL);
	return pst->head->data;
}

void LinkStackShow(LinkStack *pst)
{
	LinkStackNode *p = pst->head;
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void LinkStackDestroy(LinkStack *pst)
{
	LinkStackNode *p = pst->head;
	while(p != NULL)
	{
		pst->head = p->next;
		free(p);
		p = pst->head;
	}
}

bool LinkStackEmpty(LinkStack *pst)
{
	return pst->head == NULL;
}

#endif /* _STACK_H_ */