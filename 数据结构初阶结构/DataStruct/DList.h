#ifndef _DLIST_H_
#define _DLIST_H_

#include"Common.h"

//不带头结点的双链表
typedef struct DListNode
{
	ElemType data;
	struct DListNode *next;
	struct DListNode *prev;
}DListNode;

typedef struct DList
{
	DListNode *head;
}DList;

#endif /* _DLIST_H_ */