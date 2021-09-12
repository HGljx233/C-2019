#ifndef _SCLIST_H_
#define _SCLIST_H_

#include"Common.h"

typedef struct SCListNode
{
	ElemType data;
	struct SCListNode *next;
}SCListNode;

typedef struct SCList
{
	SCListNode *phead;
}SCList;

void SCListInit(SCList *plist);
void SCListPushBack(SCList *plist, ElemType v);
void SCListShow(SCList *plist);

void SCListInit(SCList *plist)
{
	plist->phead = NULL;
}

void SCListPushBack(SCList *plist, ElemType v)
{
	SCListNode *s = (SCListNode *)malloc(sizeof(SCListNode));
	assert(s != NULL);
	s->data = v;
	s->next = NULL;

	SCListNode *p = plist->phead;
	if(p == NULL)
	{
		plist->phead = s;
		plist->phead->next = plist->phead;
		return;
	}

	while(p->next != plist->phead)
		p = p->next;

	s->next = plist->phead;
	p->next = s;
}

void SCListShow(SCList *plist)
{
	SCListNode *p = plist->phead;
	while(p->next != plist->phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("%d->Over.\n", p->data);
}

#endif /* _SCLIST_H_ */