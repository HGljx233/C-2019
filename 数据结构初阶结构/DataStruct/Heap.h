#ifndef _HEAP_H
#define _HEAP_H

//二叉树的顺序存储 --> 堆
#include"Common.h"

#define HeapElemType int
//默认情况 大堆
typedef struct Heap
{
	HeapElemType *heap;
	size_t        capacity;
	size_t        size;
}Heap;

bool HeapIsFull(Heap *php);
bool HeapIsEmpty(Heap *php);
void HeapInit(Heap *php, int sz);
void HeapCreate(Heap *php, HeapElemType ar[], int n);
HeapElemType HeapTop(Heap *php);
void HeapInsert(Heap *php, HeapElemType v);
void HeapRemove(Heap *php);
void HeapShow(Heap *php);
void _AdjustUp(Heap *php, int start);
void _AdjustDown(Heap *php, int start);
void HeapDestroy(Heap* php);
size_t HeapSize(Heap* php);
bool HeapIsFull(Heap *php)
{
	return php->size >= php->capacity;
}
bool HeapIsEmpty(Heap *php)
{
	return php->size == 0;
}

void HeapInit(Heap *php, int sz)
{
	php->capacity = sz;
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * php->capacity);
	assert(php->heap != NULL);
	php->size = 0;
}

void HeapCreate(Heap *php, HeapElemType ar[], int n)
{
	php->capacity = n;
	php->heap = (HeapElemType*)malloc(sizeof(HeapElemType) * php->capacity);
	assert(php->heap != NULL);
	for(int i=0; i<n; ++i)
		php->heap[i] = ar[i];
	php->size = n;
	int CurPos = (n - 1) / 2; //找到二叉树的最后一个分支
	while(CurPos >= 0)
	{
		_AdjustDown(php, CurPos);
		CurPos--;
	}
}
size_t HeapSize(Heap* php) {
	return php->size;
}

HeapElemType HeapTop(Heap *php)
{
	if(HeapIsEmpty(php))
	{
		printf("堆已空，不能取堆顶元素.\n");
		return;
	}
	return php->heap[0];
}

void HeapInsert(Heap *php, HeapElemType v)
{
	if(HeapIsFull(php))
	{
		printf("堆空间已满，%d不能插入\n", v);
		return;
	}
	php->heap[php->size] = v;
	_AdjustUp(php, php->size);
	php->size++;
}

void HeapRemove(Heap *php)
{
	if(HeapIsEmpty(php))
	{
		printf("堆已空，不能删除数据.\n");
		return;
	}
	//删除数据
	HeapElemType tmp = php->heap[0];
	php->heap[0] = php->heap[php->size-1];
	php->heap[php->size-1] = tmp;
	php->size--;

	//从根开始调整堆
	_AdjustDown(php, 0);
}

void HeapShow(Heap *php)
{
	for(int i=0; i<php->size; ++i)
		printf("%d ", php->heap[i]);
	printf("\n");
}

void _AdjustUp(Heap *php, int start)
{
	int j = start;
	int i = (j-1) / 2;

	while(j > 0) //说明没有调整到根节点
	{
		if(php->heap[j] > php->heap[i])
		{
			//交换数据
			HeapElemType tmp = php->heap[j];
			php->heap[j] = php->heap[i];
			php->heap[i] = tmp;

			//向上回溯
			j = i;
			i = (j-1) / 2;
		}
		else
			break;
	}
}


void HeapDestroy(Heap* php)
{
	free(php->heap);
	php->heap = NULL;
	php->capacity = php->size = 0;
}


//void PrintTopK(Heap*php, int n, int k)
//{
//	//建立含有K个元素的堆
//	HeapInit(&php, k);
//
//	for (size_t i = k; i < n; ++i)  // N
//	{
//		//每次和堆顶元素比较，大于堆顶元素，则删除堆顶元素，插入新的元素
//		if (php->heap[i] > HeapTop(&php)) // LogK
//		{
//		    HeapRemove(&php);
//			HeapInsert(&php, php->heap[i]);
//		}
//	}
//	for (int i = 0; i < k; ++i) {
//		printf("%d ", HeapTop(&php));
//		HeapRemove(&php);
//	}
//}

////2. 找最小的K个元素
////假设堆为大堆
//void 1PrintTopK(Heap* php, int n,int k)
//{
//	Heap hp;
//	//建立含有K个元素的堆
//	HeapInit(&hp, k);
//
//	for (size_t i = k; i < n; ++i)  // N
//	{
//		//每次和堆顶元素比较，小于堆顶元素，则删除堆顶元素，插入新的元素
//		if (php->heap[i] < HeapTop(&hp)) // LogK
//		{
//			HeapRemove(&hp);
//			HeapInsert(&hp, php->heap[i]);
//		}
//	}
//	for (int i = 0; i < k; ++i) {
//		printf("%d ", HeapTop(&hp));
//		HeapRemove(&hp);
//	}
//}
void _AdjustDown(Heap* php, int i, int start)
{
	 i = start;
	int j = 2 * i + 1;
	while (j < php->size)
	{
		if (j + 1 < php->size && php->heap[j + 1] > php->heap[j])
			j++;

		if (php->heap[j] > php->heap[i])
		{
			HeapElemType tmp = php->heap[j];
			php->heap[j] = php->heap[i];
			php->heap[i] = tmp;

			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void HeapSort(Heap* php, int n)
{
	int i, temp;
	for(i = n / 2; i >= 0; i--)//通过循环初始化顶堆
	{
		_AdjustDown(&php, i,n);
	}
	for (i = n-1; i > 0; i--)
	{
		Swap(&php->heap[0], &php->heap[i]);
		_AdjustDown(&php,0,i );//重新调整为顶堆
	}
}
#endif /* _HEAP_H */