#ifndef _LIST_H_
#define _LIST_H_

#include"Common.h"

typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

//函数的申明
ListNode* _Buynode(ElemType v);
void ListInit(List *plist);
void ListShow(List plist);
void ListPushBack(List *plist, ElemType v);
void ListPushFront(List *plist, ElemType v);
void ListPopBack(List *plist);
void ListPopFront(List *plist);

void ListInsertByVal(List *plist, ElemType v);

void ListErase(List *plist, ElemType key);
void ListClear(List *plist);
void ListDestroy(List *plist);

ListNode* ListFind(List plist, ElemType key);
size_t ListLength(List plist);

void ListSort(List *plist);

//函数的实现

ListNode* _Buynode(ElemType v)
{
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = v;
	s->next = NULL;

	return s;
}

void ListInit(List *plist)
{
	*plist = NULL;
}

void ListPushBack(List *plist, ElemType v)
{
	//申请节点
	ListNode *s = _Buynode(v);

	//插入节点
	ListNode *p = *plist;
	if(p == NULL)
	{
		*plist = s;
		return;
	}

	while(p->next != NULL)
		p = p->next;

	p->next = s;
}

void ListPushFront(List *plist, ElemType v)
{
	ListNode *s = _Buynode(v);
	s->next = *plist;
	*plist = s;
}

void ListInsertByVal(List *plist, ElemType v)
{
	ListNode *p = NULL;
	ListNode *s = _Buynode(v);
	if(*plist == NULL) //空链表
	{
		*plist = s;
		return;
	}

	if(v < (*plist)->data)
	{
		s->next = *plist;
		*plist = s;
		return;
	}

	p = *plist;
	while(p->next!=NULL && v>p->next->data)
		p = p->next;

	s->next = p->next;
	p->next = s;
}

void ListPopBack(List *plist)
{
	ListNode *p = *plist;
	ListNode *prev = NULL;

	if(*plist == NULL)
		return;
	
	while(p->next != NULL)
	{
		prev = p;
		p = p->next;
	}

	if(prev == NULL)
		*plist = NULL;
	else
		prev->next = NULL;
	free(p);
}

void ListPopFront(List *plist)
{
	ListNode *p = *plist;
	if(*plist == NULL)
		return;

	*plist = p->next;
	free(p);
}

void ListShow(List plist)
{
	ListNode *p = plist;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

size_t ListLength(List plist)
{
	ListNode *p = plist;
	size_t len = 0;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

ListNode* ListFind(List plist, ElemType key)
{
	ListNode *p = plist;
	while(p!=NULL && p->data!=key)
		p = p->next;
	return p;

	/*
	ListNode *p = plist;
	while(p != NULL)
	{
		if(p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
	*/
}

void ListErase(List *plist, ElemType key)
{
	ListNode *p = *plist;
	ListNode *prev = NULL;
	if(p == NULL)
		return;

	while(p!=NULL && p->data!=key)
	{
		prev = p;
		p = p->next;
	}
	if(p == NULL)
		return;

	if(prev == NULL)
		*plist = p->next;
	else
		prev->next = p->next;
	free(p);
}

void ListClear(List *plist)
{
	ListNode *p = NULL;
	while(*plist != NULL)
	{
		p = *plist;
		*plist = p->next;
		free(p);
	}
}

void ListDestroy(List *plist)
{
	ListClear(plist);
}


void ListSort(List *plist)
{
	ListNode *p;
	if(*plist==NULL || (*plist)->next==NULL)
		return;
	p = (*plist)->next;
	(*plist)->next = NULL; // 断开链表
	while(p != NULL)
	{
		ListNode *q = p->next;
		if(p->data < (*plist)->data)
		{
			p->next = *plist;
			*plist = p;
		}
		else
		{
			ListNode *prev = *plist;
			while(prev->next!=NULL && p->data>prev->next->data)
				prev = prev->next;
			p->next = prev->next;
			prev->next = p;
		}
		p = q;
	}
}

void ListReverse(List *plist)
{
	ListNode *p = NULL;
	if(*plist==NULL || (*plist)->next==NULL)
		return;

	p = (*plist)->next;
	(*plist)->next = NULL; // 断开链表

	while(p != NULL)
	{
		ListNode *q = p->next;

		//头插节点
		p->next = *plist;
		*plist = p;

		p = q;
	}
}

/////////////////////////////////////////////////////////////////////

/*
//定义节点类型
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

//不带头结点
void InitList(List *plist)
{
	*plist = NULL;
}

void CreateList_Tail(List *plist)
{
	ListNode *p = *plist;
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		if(p == NULL)
			*plist = s;
		else
			p->next = s;
		p = s;
	}
}
void ShowList(List plist)
{
	ListNode *p = plist;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

/*
//带头结点
void InitList(List *plist)
{
	//申请头结点
	*plist = (ListNode*)malloc(sizeof(ListNode));
	(*plist)->next = NULL;
}

void CreateList_Tail(List *plist)
{
	ListNode *p = *plist;
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
void ShowList(List plist)
{
	ListNode *p = plist->next;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

/*
//不带头结点
void InitList(List *plist)
{
	*plist = NULL;
}


//1->2->3->4->5->....->10
void CreateList_Tail(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	ListNode *p = *plist;  //尾插法
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//链接节点
		p->next = s;
		p = s;
	}
}

void CreateList_Front(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	//头插法
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = *plist;
		*plist = s;
	}
}

void ShowList(List plist)
{
	ListNode *p = plist;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
*/
#endif /* _LIST_H_ */