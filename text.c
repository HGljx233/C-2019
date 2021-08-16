#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void menu() {
	printf("=================\n");
	printf("1.��ʼ��Ϸ!\n");
	printf("0.�˳���Ϸ!\n");
	printf("=================\n");
}
void init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]) { 
	memset(showMap, '*', MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);

	srand((unsigned int)time(0));
	int mineCount = 0;
	while (mineCount < MINE_COUNT) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			continue;
		}
		mineMap[row][col] = '1';
		mineCount++;
	}
}

void print(char theMap[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ", theMap[row][col]);
		}
		printf("\n");
	}
}

void update(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL) {
			
				continue;
			}
			if (r == row && c == col) {
			
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	showMap[row][col] = '0' + count;
}
int main() {
	int choice = 0;
	menu();
	while (1)
	{
		printf("��ѡ��:");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("������Ϸ\n");
			char showMap[MAX_ROW][MAX_COL] = { 0 };
			char mineMap[MAX_ROW][MAX_COL] = { 0 };
			init(showMap, mineMap);
			int openedCount = 0;
			while (1) {

				print(showMap);
				int row = 0;
				int col = 0;
				printf("����������(row, col):");
				scanf("%d %d", &row, &col);
				if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
					printf("���������������! ����������!\n");
					continue;
				}
				if (showMap[row][col] != '*') {
					printf("�������λ���Ѿ�������! ����������!\n");
					continue;
				}
				if (mineMap[row][col] == '1') {
					printf("��������!! ��Ϸ����!\n");
					print(mineMap);
					break;
				}
				update(showMap, mineMap, row, col);
				openedCount++;
				system("cls");
				if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
					printf("��ϲ��, ��ʤ��!\n");
					print(mineMap);
					break;
				}
			}
			break;
		}
		else if (choice == 0)
		{
			printf("�˳���Ϸ��\n");
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
//void init(int arr[])
//{
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[])
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("arr[%d]=%d\n", i, arr[i]);
//	}
//}
//void reverse(int arr[])
//{
//	for (int i = 9; i >= 0; i--)
//	{
//		printf("%d\n", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10];
//	init(arr);
//	print(arr);
//	reverse(arr);
//	return 0;
//}
//void Init(int arr[], int sz, int set)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = set;
//	}
//}
//int main() {
//	int arr;
//	Init(&arr,6,0);
//	return 0;
//}

#if 0
 int main()
 {
	 int a[10] = { 0 };
	 int b[10] = { 0 };
	 int i = 0;
	 printf("������10������:>");
	 for (i = 0; i < 10; i++)
	 {
		 scanf("%d", &a[i]);
	 }
	 printf("������10������:>");
	 for (i = 0; i < 10; i++)
	 {
		 scanf("%d", &b[i]);
	 }
	    for (int i = 0; i <10; i++)
		    {
		        printf("%d %d\n", a[i], b[i]);
		    }
	    for (int i = 0; i <10; i++)     {
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
	         printf("%d %d\n", a[i], b[i]);
	     }

		     return 0;
 }


{
}
#define MAX_ROW 3
#define MAX_COL 3
void init(char chess[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess[row][col] = ' ';
		}
	}
}

void print(char chess[MAX_ROW][MAX_COL]) {
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|");
		for (int col = 0; col < MAX_COL; col++) {
			printf(" %c |", chess[row][col]);
		}
		printf("\n+---+---+---+\n");
	}
}

void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("�������....\n");
	while (1) {
		printf("����������(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);

		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			// ���ǲ��Ϸ�, ����Ҫ���û���������
			printf("�����������Ƿ�! ����������!\n");
			continue;
		}
		// �����û�������1, 1, ���� 1 1 λ���Ѿ�������~~ 
		if (chessBoard[row][col] != ' ') {
			// ��λ���Ѿ�������
			printf("�������λ���Ѿ�������, ����������!\n");
			continue;
		}
		// ��������~~
		chessBoard[row][col] = 'x';
		break;
	}
}

void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ') {
			// ���λ���Ѿ�������
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}

// ���� 1 ��ʾ����, ���� 0 ��ʾû��
int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// ��������, ������û�пո�. �пո����û��~~
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

// �˴�Լ��,
// ������� x, ��ʾ ��һ�ʤ
// ������� o, ��ʾ ���Ի�ʤ
// ������� ' ', ��ʾʤ��δ��, ��Ҫ��������
// ������� q, ��ʾ����
char isGameOver(char chessBoard[MAX_ROW][MAX_COL]) {
	// ɨ�����е���, ���е���, �Լ������Խ���~~
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	// �ж��Ƿ����
	if (isFull(chessBoard)) {
		return 'q';
	}
	// ʤ��δ��
	return ' ';
}

int main() {
	// ������ʹ��ȫ�ֱ���
	// ������
	char chessBoard[MAX_ROW][MAX_COL];
	// 1. �����̽��г�ʼ��
	init(chessBoard);
	char winner = ' ';
	while (1) {
		// 2. ��ӡ����
		print(chessBoard);
		// 3. �������
		playerMove(chessBoard);
		// 4. �ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// ��Ϸ����
			break;
		}
		// 5. ��������
		computerMove(chessBoard);
		// 6. �ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// ��Ϸ����
			print(chessBoard);
			break;
		}
	}
	if (winner == 'x') {
		printf("��ϲ��Ӯ��!\n");
		print(chessBoard);
	}
	else if (winner == 'o') {
		printf("��զ���˹����϶��²���!\n");
		print(chessBoard);
	}
	else {
		printf("����˹��������忪!\n");
		print(chessBoard);
	}
	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h> 
#define MAX_ROW 3
#define MAX_COL 3
void init(char chess[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess[row][col] = ' ';
		}
	}
}
void print(char chess[MAX_ROW][MAX_COL]) {
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|");
		for (int col = 0; col < MAX_COL; col++) {
			printf(" %c |", chess[row][col]);
		}
		printf("\n+---+---+---+\n");
	}
}

void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("�������....\n");
	while (1) {
		printf("����������(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		// ���кϷ���У��, �ж��û�����������Ƿ��ǺϷ���
		// ������Ϸ�, �����û���������
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			// ���ǲ��Ϸ�, ����Ҫ���û���������
			printf("�����������Ƿ�! ����������!\n");
			continue;
		}
		// �����û�������1, 1, ���� 1 1 λ���Ѿ�������~~ 
		if (chessBoard[row][col] != ' ') {
			// ��λ���Ѿ�������
			printf("�������λ���Ѿ�������, ����������!\n");
			continue;
		}
		// ��������~~
		chessBoard[row][col] = 'x';
		break;
	}
}

void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ') {
			// ���λ���Ѿ�������
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}

// ���� 1 ��ʾ����, ���� 0 ��ʾû��
int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// ��������, ������û�пո�. �пո����û��~~
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

// �˴�Լ��,
// ������� x, ��ʾ ��һ�ʤ
// ������� o, ��ʾ ���Ի�ʤ
// ������� ' ', ��ʾʤ��δ��, ��Ҫ��������
// ������� p, ��ʾ����
char isGameOver(char chessBoard[MAX_ROW][MAX_COL]) {
	// ɨ�����е���, ���е���, �Լ������Խ���~~
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	// �ж��Ƿ����
	if (isFull(chessBoard)) {
		return 'p';
	}
	// ʤ��δ��
	return ' ';
}

int main() {
	// ������ʹ��ȫ�ֱ���
	// ������
	char chessBoard[MAX_ROW][MAX_COL];
	// 1. �����̽��г�ʼ��
	init(chessBoard);
	char winner = ' ';
	while (1) {
		// 2. ��ӡ����
		print(chessBoard);
		// 3. �������
		playerMove(chessBoard);
		// 4. �ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// ��Ϸ����
			break;
		}
		// 5. ��������
		computerMove(chessBoard);
		// 6. �ж�ʤ��
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// ��Ϸ����
			break;
		}
	}
	if (winner == 'x') {
		printf("ʤ��!\n");
	}
	else if (winner == 'o') {
		printf("ʧ��!\n");
	}
	else {
		printf("����!\n");
	}
	system("pause");
	return 0;
}
//int fbnqNum(int n){
//	if (n < 3) {
//		return 1;
//	}
//	int first = 1;
//	int second= 1;
//	int sum = 0;
//	for (int i = 3; i <= n; i++) {
//		sum = first+ second;
//		second = first;
//		first = sum;
//	}
//	return sum;
//}
//int main() {
//	int ret = fbnqNum(10);
//	printf("%d\n", ret);
//	return 0;
//}
//int fbnqNum(int n) {
//	if (n < 3) {
//		return 1;
//	}
//	return fbnqNum(n - 1) + fbnqNum(n - 2);
//}
//int main() {
//	int ret = fbnqNum(10);
//	printf("%d\n", ret);
//	return 0;
//}
//int  ciFangnum(int n, int k) {
//	if (k==0){
//		return 1;
//	}
//	return n *ciFangnum(n,k-1);
//}
//int main() {
//	int ret=ciFangnum(2, 12);
//	printf("%d\n", ret);
//	return 0;
//}
//int DigitSum(int n) {
//	if (n <= 9) {
//		return n;
//	}
//	return DigitSum(n / 10)+ n % 10;
//}
//int main() {
//	int sum=DigitSum(1729);
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}
//void reverse_string(char* arr) {
//	int len = strlen(arr);
//	char tmp = *arr;
//	*arr = *(arr + len - 1);
//	*(arr + len - 1) = '\0';
//	if(strlen(arr + 1) >= 2) {
//		reverse_string(arr + 1);
//	}
//	*(arr + len - 1) = tmp;
//}
//int main() {
//	char str[] = "abcde";
//	reverse_string(str);
//	printf("%s\n", str);
//	return 0;
//}
//{
//	char* left = arr;
//	char* right = arr + strlen(arr) - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main() {
//	char str[] = "abcde";
//	reverse_string(str);
//	printf("%s\n", str);
//	return 0;
//}

//int myStrlen(char* str)
//{
//	if ('\0' == *str)
//		return 0;
//	else
//		return  myStrlen(1 + str)+1;
//}
//int main() {
//	char* str = "tanglaoshi";
//	int ret = myStrlen(str);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//int myStrlen(char* str)
//{
//	int count = 0;
//	while ('\0' != *str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main() {
//	char* str = "tanglaoshi";
//	int ret = myStrlen(str);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//long long jieCheng(int n) {
//	if (n == 1) {
//		return 1;
//	}
//	else {
//		return n * jieCheng(n - 1);
//	}
//}
//int main() {
//     	int n;
//		printf("������n�׽׳�: ");
//    	scanf("%d", &n);
//		long long  sum = jieCheng(n);
//		printf("%I64d\n", sum);
//		return 0;
//}
//int main() {
//	int sum = 1;
//	int n;
//	printf("������n�׽׳�: ");
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		 sum *= i;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}
#endif