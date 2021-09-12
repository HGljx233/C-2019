//#include"SeqList.h"
//#include"List.h"
//#include"SCList.h"
//#include"DCList.h"
//#include"Stack.h"
//#include"Queue.h"
//#include"BinTree.h"
//#include"Heap.h"
#include"交换排序.h"
//#include"treeOJ.h"

int main(){	
	int ar[] = { 3,9,5,6,15,7 }; 
	int left,right;
	QuickSort_Nor(ar,0,6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", ar[i]);
	}
}


//void main()
//{
//	BinTreeNode *p, *pr;
//	char *str = "ABC##D##E##";
//	char *VLR = "ABCDEFGH";
//	char *LVR = "CBEDFAGH";
//	char *LRV = "CEFDBHGA";
//	int n = strlen(VLR);
//
//	BinTree bt;
//	//bt = BinTreeCreate_LVR_LRV(LVR, LRV, n);
//	int index = 0;
//	bt = BinTreeCreate_3(str, &index);
//	bool flag = BinaryTreeComplete(bt);
//}
//void TestTopk()
//{
//	int n = 10000;
//	int* a = (int*)malloc(sizeof(int) * n);
//	srand(time(0));
//	//随机生成10000个数存入数组，保证元素都小于1000000
//	for (size_t i = 0; i < n; ++i)
//	{
//		a[i] = rand() % 1000000;
//	}
//	//确定10个最大的数
//	a[5] = 1000000 + 1;
//	a[1231] = 1000000 + 2;
//	a[531] = 1000000 + 3;
//	a[5121] = 1000000 + 4;
//	a[115] = 1000000 + 5;
//	a[2335] = 1000000 + 6;
//	a[9999] = 1000000 + 7;
//	a[76] = 1000000 + 8;
//	a[423] = 1000000 + 9;
//	a[3144] = 1000000 + 10;
//
//	PrintTopK(&a, n, 10);
//}
//void main() {
//	TestTopk();
//}

//void main()
//{
//	int ar[] = {27, 15, 19, 18, 28, 34, 65, 49, 25, 37,4,5,6,7,7,89,79,8,98,90,9,0};
//	int n = sizeof(ar) / sizeof(ar[0]);
//	Heap hp;
//	HeapCreate(&hp, ar, n);
//	HeapShow(&hp);
//	HeapTop(&hp);
//	printf("%d ", HeapTop(&hp));
//	HeapSort(&hp, 10);
//	HeapShow(&hp);
//}

////
//void main()
//{
//	int ar[] = {27, 15, 19, 18, 28, 34, 65, 49, 25, 37};
//	int n = sizeof(ar) / sizeof(ar[0]);
//	Heap hp;
//	HeapInit(&hp, 10);
//	for(int i=0; i<n; ++i)
//	{
//		HeapInsert(&hp, ar[i]);
//	}
//
//	while(!HeapIsEmpty(&hp))
//	{
//		HeapElemType value = HeapTop(&hp);
//		HeapRemove(&hp);
//		printf("%d ", value);
//	}
//	printf("\n");
//
//	HeapDestroy(&hp);
//}

/*
void main()
{
	int ar[] = {27, 15, 19, 18, 28, 34, 65, 49, 25, 37};
	int n = sizeof(ar) / sizeof(ar[0]);
	Heap hp;
	HeapInit(&hp, 10);
	for(int i=0; i<n; ++i)
	{
		HeapInsert(&hp, ar[i]);
	}
	HeapShow(&hp);

	HeapRemove(&hp);
	HeapShow(&hp);

	HeapRemove(&hp);
	HeapShow(&hp);
}

/*
//ABC##DE##F##G#H##
//ABC####
void main()
{
	BinTreeNode *p, *pr;
	char *str = "ABC##DE##F##G#H##";
	char *VLR = "ABCDEFGH";
	char *LVR = "CBEDFAGH";
	char *LRV = "CEFDBHGA";
	int n = strlen(VLR);

	//char *str = "AB#DF###CE###";
	int index = 0;
	BinTree bt, bt1;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	//BinTreeCreate(&bt);
	//bt = BinTreeCreate_1();
	//bt = BinTreeCreate_3(str, &index);
	
	bt = BinTreeCreate_VLR_LVR(VLR, LVR, n);

	printf("VLR : ");
	//BinTreePreOrder(bt);
	BinTreePreOrder_NoR(bt);
	printf("\n");
	printf("LVR : ");
	//BinTreeInOrder(bt);
	BinTreeInOrder_NoR(bt);
	printf("\n");
	printf("LRV : ");
	//BinTreePostOrder(bt);
	BinTreePostOrder_NoR(bt);
	printf("\n");
	printf("Level : ");
	BinTreeLevelOrder(bt);
	printf("\n");

	printf("Size : %d\n", Size(bt));
	printf("LeafSize : %d\n", LeafSize(bt));
	printf("KSize : %d\n", LevelKSize(bt, 5));
	printf("Height : %d\n", Height(bt));

	p = Find(bt, 'A');
	pr = Parent(bt, p);

	//bt1 = Clone(bt);
	bool flag = Equal(bt, bt1);

	BinTreeDestroy(&bt);
}

/*
void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q, 6);

	SeqQueuePush(&Q, 1);
	SeqQueuePush(&Q, 2);
	SeqQueuePush(&Q, 3);
	SeqQueuePush(&Q, 4);
	SeqQueuePush(&Q, 5);
	SeqQueuePush(&Q, 6);
	SeqQueuePush(&Q, 7);

	SeqQueueShow(&Q);

	SeqQueuePop(&Q);
	SeqQueueShow(&Q);
	SeqQueuePush(&Q, 7);
	SeqQueueShow(&Q);
}

/*
void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);

	LinkQueuePush(&Q, 1);
	LinkQueuePush(&Q, 2);
	LinkQueuePush(&Q, 3);
	LinkQueuePush(&Q, 4);
	LinkQueuePush(&Q, 5);

	LinkQueueShow(&Q);
	LinkQueuePop(&Q);
	LinkQueuePop(&Q);
	LinkQueuePush(&Q, 10);
	LinkQueueShow(&Q);
}

/*
void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q, 10);

	SeqQueuePush(&Q, 1);
	SeqQueuePush(&Q, 2);
	SeqQueuePush(&Q, 3);
	SeqQueuePush(&Q, 4);
	SeqQueuePush(&Q, 5);

	SeqQueueShow(&Q);
	printf("队头:>%d\n", SeqQueueFront(&Q));
	printf("队尾:>%d\n", SeqQueueBack(&Q));

	SeqQueuePop(&Q);
	SeqQueueShow(&Q);

	printf("队头:>%d\n", SeqQueueFront(&Q));
	printf("队尾:>%d\n", SeqQueueBack(&Q));
}

/*
void main()
{
	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);

	LinkStackShow(&st);
	printf("======\n");
	
	LinkStackPop(&st);
	LinkStackPop(&st);
	LinkStackShow(&st);
	printf("======\n");

	int value = LinkStackTop(&st);
	printf("栈顶元素为:>%d\n", value);
}

/*
void main()
{
	SeqStack st;
	SeqStackInit(&st, 8);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 10);
	SeqStackShow(&st);
	printf("=========\n");
	SeqStackPop(&st);
	SeqStackShow(&st);
	printf("=========\n");
	SeqStackPop(&st);
	SeqStackPop(&st);
	SeqStackShow(&st);
	printf("=========\n");

	int value = SeqStackTop(&st);
	printf("栈顶元素为:>%d\n", value);
}


/*
int main(int argc, char *argv[])
{
	//顺序表
	//SeqList mylist;
	//SeqListInit(&mylist, 8);

	//单链表
	//List mylist;
	//ListInit(&mylist);

	//单循环链表
	//SCList mylist;
	//SCListInit(&mylist);

	//双循环链表
	DCList mylist;
	DCListInit(&mylist);

	ElemType item, value, key;
	DCListNode *p = NULL;
	int pos;
	int select = 1;
	while(select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [*6] insert_pos         [7] insert_val   *\n");
		printf("* [*8] erase_pos          [9] erase_val    *\n");
		printf("* [*10] find_pos          [11] find_val    *\n");
		printf("* [12] sort               [13] reverse     *\n");
		printf("* [14] length             [*15] capacity   *\n");
		printf("* [16] clear              [*17] destroy    *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;

		switch(select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			DCListErase(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			//value = SeqListFindByPos(&mylist, pos);
			printf("在%d位置的值为:> %d\n", pos, value);
			break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if(p == NULL)
				printf("要查找的%d数据不存在.\n", key);
			else
				printf("%d数据已被查找到.\n", key);
			break;
		case 12:
			DCListSort(&mylist);
			break;
		case 13:
			DCListReverse(&mylist);
			break;
		case 14:
			printf("顺序表的长度为:> %d\n", DCListLength(&mylist));
			break;
		case 15:
			//printf("顺序表的容量为:> %d\n", SeqListCapacity(&mylist));
			break;
		case 16:
			DCListClear(&mylist);
			break;
		default:
			break;
		}
	}

	DCListDestroy(&mylist);
	printf("GoodBye.\n");
	return 0;
}
*/