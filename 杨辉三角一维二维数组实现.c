#if 0
#include"SeqList.h"
int main() {
	int v = 0;
	SeqList mylist;
	SeqListInit(&mylist, 8);
	int select = 1;
	ElemType item;
	int pos,value,key;
	while (select) {
		printf("***********************************\n");
		printf("* [1] push_back   [2] push_front  *\n");
		printf("* [3] show_list   [0] quit_system *\n");
		printf("* [4] pop_back    [5] pop_front   *\n");
		printf("* [6] insert_pos  [7] insert_val  *\n");
		printf("* [8] erase_pos   [9] erase_val   *\n");
		printf("* [10] find_pos   [11] find_val   *\n");
		printf("* [12] sort       [13] reverse    *\n");
		printf("* [14] length     [15] capacity   *\n");
		printf("* [16] clear      [17] destroy    *\n");
		printf("***********************************\n");
		printf("��ѡ��:>\n");
		scanf_s("%d", &select);
		if (select == 0)
			break;
		
		switch (select) {
		case 1:
			printf("������Ҫ���������:>");
			while (scanf_s("%d", &item), item != -1) {
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������:>");
			while (scanf_s("%d", &item), item != -1) {
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("������Ҫ�����λ��:>");
			scanf_s("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf_s("%d", &item);
			SeqListinsert_pos(&mylist, pos, item);
			break;
		case 7:
			printf("������Ҫ�����ֵ:>");
			scanf_s("%d", &key);
			SeqListInsertByVal(&mylist, key);
			break;
		case 8:
			printf("������ɾ����λ��:>");
			scanf_s("%d", &pos);
			SeqListEraseByPos(&mylist, pos);
			break;
		case 9:
			printf("������Ҫɾ���е�ֵ:>");
			scanf_s("%d", &key);
			SeqListEraseByVal(&mylist, key);
			break;
		case 10:
			printf("������Ҫ���ҵ�λ��:>");
			scanf_s("%d", &pos);
			value = SeqListFindByPos(&mylist, pos);
			printf("��%dλ�õ�ֵΪ:>%d\n", pos, value);
			break;
		case 11:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf_s("%d", &key);
			pos = SeqListFindByVal(&mylist, key);
			if (pos ==-1) {
				printf("Ҫ���ҵ�%d���ݲ�����.\n", key);
			}
			else
				printf("Ҫ���ҵ�����%d�� %d λ��.\n", key, pos);
			break;
		case 12:
			SeqListBubbleSort(&mylist);
			break;
		case 13:
			SeqListReserve(&mylist);
			break;
		case 14:
			printf("˳���ĳ���Ϊ:>%d\n", Length(&mylist));
		case 15:
			printf("˳��������Ϊ:>%d\n", Capacity(&mylist));
			break;
		case 16:
			SeqListClear(&mylist);
			printf("˳����ѿ�.\n");
			break;
		default:
			break;
		}
	}
	printf("goodbye.\n");
	return 0;
}

//#include"List.h"
#include<stdio.h>
int main() {
	int a[100] = { 0,1 };
	int n = 10;
	int i, l, j, r;
	for (i = 1; i < n; i++)
	{
		l = 0;
		for (j = 1; j < i; j++)
		{
			r = a[j];
			a[j] = r + l;
			printf("%4d", a[j]);
			l = r;
		}
		printf("\n");
	}
	//List mylist;
	//InitList(&mylist);
	//CreatList(&mylist);
	//ShowList(mylist);
}
#endif
int main() {
	int n = 10;
	int arr[100][100] = { 0 };
	for (int row = 0; row < n; row++) {
		if (row == 0) {
			arr[0][0] = 1;
			continue;
		}
		if (row == 1) {
			arr[1][0] = 1;
			arr[1][1] = 1;
			continue;
		}
		for (int col = 0; col < row + 1; col++) {
			if (col == 0 || col == row) {
				arr[row][col] = 1;
			}
			else {
				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
			}
		}
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < row + 1; col++) {
			printf("%-4d", arr[row][col]);
		}
		printf("\n");
	}

}
