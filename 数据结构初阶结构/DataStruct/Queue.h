#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"Common.h"

//顺序队列 --> 循环队列
typedef struct SeqQueue
{
	ElemType *base;
	size_t    capacity;
	int       front;
	int       rear;
}SeqQueue;

bool SeqQueueIsFull(SeqQueue *pq);
bool SeqQueueIsEmpty(SeqQueue *pq);
void SeqQueueInit(SeqQueue *pq, int sz);
void SeqQueuePush(SeqQueue *pq, ElemType v);
void SeqQueuePop(SeqQueue *pq);
ElemType SeqQueueFront(SeqQueue *pq);
ElemType SeqQueueBack(SeqQueue *pq);
void SeqQueueShow(SeqQueue *pq);

bool SeqQueueIsFull(SeqQueue *pq)
{
	return (pq->rear+1)%(pq->capacity+1) == pq->front;
}

bool SeqQueueIsEmpty(SeqQueue *pq)
{
	return pq->rear == pq->front;
}

void SeqQueueInit(SeqQueue *pq, int sz)
{
	pq->capacity = sz;
	pq->base = (ElemType*)malloc(sizeof(ElemType) * (pq->capacity+1)); //多出来的空间主要用于满和空状态的区分 
	assert(pq->base != NULL);
	pq->front = pq->rear = 0;
}

void SeqQueuePush(SeqQueue *pq, ElemType v)
{
	if(SeqQueueIsFull(pq))
	{
		printf("队列已满, %d不能入队.\n", v);
		return;
	}
	pq->base[pq->rear] = v;
	pq->rear = (pq->rear + 1) % (pq->capacity+1);
}

void SeqQueuePop(SeqQueue *pq)
{
	if(SeqQueueIsEmpty(pq))
	{
		printf("队列已空，不能出队.\n");
		return;
	}
	pq->front = (pq->front + 1) % (pq->capacity+1);
}

ElemType SeqQueueFront(SeqQueue *pq)
{
	if(SeqQueueIsEmpty(pq))
	{
		printf("队列已空，不能取队头元素.\n");
		return;
	}
	return pq->base[pq->front];
}

ElemType SeqQueueBack(SeqQueue *pq)
{
	if(SeqQueueIsEmpty(pq))
	{
		printf("队列已空，不能取队尾元素.\n");
		return;
	}
	return pq->base[(pq->rear-1+(pq->capacity+1)) % (pq->capacity+1)];
}
void SeqQueueShow(SeqQueue *pq)
{
	for(int i=pq->front; i!=pq->rear; )
	{
		printf("%d ", pq->base[i]);
		i = (i+1) % (pq->capacity+1);
	}
	printf("\n");
}

//链队列
struct BinTreeNode;
#define QueueElemType struct BinTreeNode*
typedef struct LinkQueueNode
{
	QueueElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

void LinkQueueInit(LinkQueue *pq);
bool LinkQueueEmpty(LinkQueue *pq);
void LinkQueuePush(LinkQueue *pq, QueueElemType v);
void LinkQueuePop(LinkQueue *pq);
QueueElemType LinkQueueFront(LinkQueue *pq);
QueueElemType LinkQueueBack(LinkQueue *pq);
void LinkQueueShow(LinkQueue *pq);

void LinkQueueInit(LinkQueue *pq)
{
	pq->front = pq->rear = NULL;
}
bool LinkQueueEmpty(LinkQueue *pq)
{
	return pq->front == NULL;
}
void LinkQueuePush(LinkQueue *pq, QueueElemType v)
{
	LinkQueueNode *s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = v;
	s->link = NULL;

	if(pq->front == NULL)
		pq->front = pq->rear = s;
	else
	{
		pq->rear->link = s;
		pq->rear = s;
	}
}
void LinkQueuePop(LinkQueue *pq)
{
	LinkQueueNode *p;
	if(pq->front == NULL)
		return;
	p = pq->front;
	pq->front = p->link;
	free(p);
}

QueueElemType LinkQueueFront(LinkQueue *pq)
{
	if(pq->front == NULL)
		return;
	return pq->front->data;
}
QueueElemType LinkQueueBack(LinkQueue *pq)
{
	if(pq->front == NULL)
		return;
	return pq->rear->data;
}
void LinkQueueShow(LinkQueue *pq)
{
	LinkQueueNode *p = pq->front;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}


#endif /* _QUEUE_H_ */