#ifndef _DLIST_H_
#define _DLIST_H_

#include"Common.h"

//����ͷ����˫����
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