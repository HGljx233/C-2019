#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 3
#define MAX_COL 3
void init(char chess[MAX_ROW][MAX_COL]) {
	for (int i = 0; i < MAX_ROW; i++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess[i][col] = ' ';
		}
	}//�����������;
	srand(time(0));
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
		scanf_s("%d %d", &row, &col);
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
		//��ӡ����֮ǰ����
		system("cls");
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
	print(chessBoard);
	if (winner == 'x') {
		printf("��ϲ��Ӯ��!\n");
	}
	else if (winner == 'o') {
		printf("��զ���˹����϶��²���!\n");
	}
	else {
		printf("����˹��������忪!\n");
	}


	system("pause");
	return 0;
}
//char chessBoard[MAX_ROW][MAX_COL];
//void init() {
//	for (int row = 0; row < MAX_ROW; row++) {
//		for (int col = 0; col < MAX_COL; col++) {
//			chessBoard[row][col] = ' ';
//		}
//	}
//}
//void print(char chessBoard[MAX_ROW][MAX_COL]) {
//	printf("+---+---+---+\n");
//	for (int row = 0; row < MAX_ROW;row++) {
//			printf("| %c | %c | %c |\n", chessBoard[row][0], chessBoard[row][1], chessBoard[row][2]);
//		    printf("+---+---+---+\n");
//		}
//}
//void playerMove(char chessBoard[MAX_ROW][MAX_ROW]) {
//	printf("�������......\n");
//	while (1) {
//		printf("����������(row,col): ");
//		int row = 0;
//		int col = 0;
//		scanf_s("%d %d", &row, &col);
//		//һ��Ҫ���û�����sb;,���кϷ���У��,�ж��û�����������Ƿ�Ϸ�
//		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
//			printf("�����������Ƿ�!����������!\n");
//			continue;
//		}
//		if (chessBoard[row][col] != '0 ') {
//			printf("�������λ���Ѿ�������,����������!\n");
//			continue;
//		}
//		chessBoard[row][col] = 'x';//��������--
//		break;
//	}
//}
//
//void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
//	while (1) {
//		int row = rand() % MAX_ROW;
//		int col = rand() % MAX_COL;
//		if (chessBoard[row][col] != ' ') {
//			continue;
//		}
//		chessBoard[row][col] = 'x';
//		break;
//	}
//}
////�˴�Լ��,
////�������x,��ʾ��һ�ʤ
////�������0,��ʾ���Ի�ʤ
////
//char isGameOver() {
//	for (int row = 0; row < MAX_ROW; row++) {
//		if (chessBoard[row][0] != ' '
//			&& chessBoard[row][0] == chessBoard[row][1]
//			&& chessBoard[row][0] == chessBoard[row][2]) {
//			return chessBoard[row][0];
//		}
//	}
//}
//int main(){
//	//������ʹ��ȫ�ֱ���
//	char chessBoard[MAX_ROW][MAX_COL] = { o };
//	//1.�����̽��г�ʼ��
//	init(chessBoard);
//	//2.��ӡ����
//	while (1) {
//		print(chessBoard);
//		//3.�������.
//		playerMove(chessBoard);
//		//4.�ж�ʤ��
//		//TODO
//		//5.��������
//		computerMove(chessBoard);
//	}
//
//	system("pause");
//	return 0;
//}

//void bubbleSort(int arr[], int size) {
//	//дһ�´Ӻ���ǰ�����İ汾
//	//bound=>�߽� ʹ�����������ֵ����ʾ����������ʹ���������ķֽ���
//	//[0,bound)����������
//	//[bound,size)����������
//	int bound = 0;
//	for (; bound < size; bound++) {
//		//ͨ�����ѭ���������ƺ����ıȽ�����Ԫ�صıȽ�����
//		//������ʵ��һ�˱ȽϽ����Ĺ���
//		for (int cur = size - 1; cur > bound; cur--) {
//			//����Ԫ�أ������� cur Ϊ��׼
//			if (arr[cur - 1] > arr[cur]) {
//				//�����������������ͽ��н�����
//				int tmp = arr[cur - 1];
//				arr[cur - 1] = arr[cur];
//				arr[cur] = tmp;
//			}
//		}
//	}
//}
//int main() {
//	//����ð�ݺͿ�������;
//	int arr[] = { 9,5,6,8,2,4 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	bubbleSort(arr,size);
//	for (int i = 0; i < size; ++i) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
	//���ٸ��ı�����shift+alt=r;

	/*int i, j, a = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		} a++;
	}
	printf("%d\n", a);*/
//	int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 }, * q[4], k;
//	for (k = 0; k < 4; k++) {
//		q[k] = &a[k * 3];
//	} printf("%d\n", q[3][1]);
//}
	
	/*int arr[3][4] = { 2,4,5 };
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
	}*/
	//int arr[3][4] = { 0 };//����ĳ�ʼ��
	/*int arr[3][4] = {
		(1,2),
		(3,4),
		(5)
	};*/
	/*int arr[] = { 1,2,3,4,5,6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", num);*/
	//arr =>array ����
	//C++��׼����һ��std::array �������
	//int arr[3][4] = { 0 };
	//printf("hehe");
	/*char arr[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		printf("%p\n", &arr[i]);
	}*/
	/*char arr[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		arr[i] = i + 1;
	}
		for (int i = 0; i < 10; ++i) {
			printf("%d\n", arr[i]);
		}
	//char str1[] = { 'a','b','c' };
	//char str2[] = { 'a',98,'c' };
	//char str3[] = "abc";
	//strlen(str1);
	//strlen(str2);
	//strlen(str3);
	//printf("%d\n", sizeof(str2));
	/*const int n = 4;
	int arr[n] = { 0 };
	system("pause");
	return 0;*/
//ͨ��ѭ����д�Ʋ���������
//int fib2(int n) {
//	if (n == 1 || n == 2) {
//		return 1;
//	}
//	int last1 = 1; 
//	int last2 = 1;
//	int cur = 0;
//	for (int i = 3; i <= n; ++i) {
//		cur = last1 + last2;
//		last1 = last2;
//		last2 = cur;
//	}
//	return cur;
//}
//int fib(int n) {
//	if (n == 1 || n == 2) {
//		return 1;
//	}
//	return fib(n - 1) + fib(n - 2);
//}
/*int main() {
	printf("%d\n", fib2(30));
}*///쳲���������
//int mystrlen(char* str) {
//	int count = 0;
//	while (str[count] != '\0') {
//		count++;
//	}
//	return count;
//}
////������ô����ֲ����������߲���ʹ��ѭ�����Ϳ��Կ����µݹ飻
//int myStrlen2(char* str) {
//	if (str[0] == '\0') {
//		return 0;
//	}
//	return (1 + myStrlen2(str + 1));
//}
//int main() {
//	printf("%d\n", myStrlen2("abcd"));
//}
//void printNum(unsigned  int num) {
//	if (num > 9) {
//		printNum(num / 10);
//	}
//	printf("%d ", num % 10); 
//}
//int main() {
//	printNum(20023);
//}
//#include"test.h"
//int main() {
//	int num = 0;
//	func(&num);
//	printf("%d\n", num);
//} 
//void func(int* num) {
//	(*num)++;
// }
//���� arr ��ʾ�����ҵ�����
//����toFind ��ʾҪȥ���ҵ�����
//int binarySearch(int arr[],int size, int toFind) {
//	int left = 0;
//	int right = size-1;
//	while (left < right) {
//		int mid = (left + right) / 2;
//		if (toFind < arr[mid]) {
//			//ȥ������
//			right = mid - 1;
//		}
//		else if (toFind > arr[mid]) {
//			//ȥ�Ҳ���
//			left = mid + 1;
//		}
//		else {
//			//�ҵ��ˣ��˴�ʹ�ú�������ֵ��ʾ�ҵ�Ԫ���±�λ��
//			//��Ҫֱ�Ӵ�ӡ��
//			return mid;
//		}
//	}
//	//��������ѭ�����Ҳû�ҵ����ʵ�Ԫ�أ���Ϊû�ҵ�������һ����Ч���±�-1;
//
//	return -1;
//}
//void func(int* num) {
//	(*num)++;
//}
//int main() {
//	int num = 0;
//	func(&num);
//	printf("%d\n", num);
//}
//	int arr[] = { 1,2,3,4,5,6,7 };
//	int size=sizeof(arr) / sizeof(arr[0]);
//	int ret = binarySearch(arr, size, 6);
//	printf("ret = %d\n", ret);
//}
//int isleapYear(int year) {
	//if (year % 100 == 0) {
		//��������
	//	if (year % 400 == 0) {
	//		return 1;
	//	}
	//	return 0;
	//}
	//else {
	//	//��ͨ����
	//	if (year % 4 == 0) {
	//		return 1;
	//	}
	//	return 0;
	//}
//}
//	if (year % 100 != 0 && year % 4 == 0) {
//		return 1;
//	}
//	return 0;
//}
//int main() {
//	printf("%d\n", isleapYear(1600));
//}
//int isPrime(int num) {
//	if (num == 1 || num == 0) {
//		return 0;
//	}
//	for(int i=2;i<num;i++)
//		if (num % i == 0) {
//			//�ҵ�������
//			return 0;
//		}
//	//ѭ��������Ҳû�ҵ���������ǰ����Ϊ������
//	return 1;
//}
//int main() {
//	printf("%d\n", isPrime(0));
//}
//int getmax(int x, int y) {
//	if (x > y) {
//		return x;
//	}
//	return y;
//}
//void swap(int* x, int* y) {
//	int tmp = *x;
//	*x =*y;
//	*y = tmp;
//}
//void swap2(int* x, int* y) {
//	int* tmp = x;
//	x = y;
//	y = tmp;
//}
//int main() {
//	int a = 10;
//	int b = 20;
//	swap(&a, &b);
//	printf("a = %d,b = %d\n", a,b);
//}
////int main() {
//	//����һ���о���ʾ1min֮��ػ�22
//    // ���� ������ ȡ���ػ�
//	    system("shutdown -s -t 600");
//		while (1) {
//			printf("���ĵ��Խ���1min��ػ������� ������ ȡ���ػ���\n");
//			char input[1024] = { 0 };
//			scanf_s("%s", input,1023);
//			if (strcmp(input, "������") == 0) {
//				system("shutdown -a");
//				printf("�����..�ػ���ȡ��\n");
//			}
//		}
//		system("pause");
//		return 0;
//}
//	else {
//	;
//		//�ٸ����û�һ�λ���
//		//AGAIN��һ����ǩ��label���ͱ�ʾ һ�������λ��
//		//goto AGAIN;
//	}
//}
////void��ʾ����û�з���ֵ
////ʹ�ú�����ʾһ����Ϸ
//void game() {
//	printf("��ʼһ�ֲ�������Ϸ\n");
//	//1.������һ��1��100���������
//	int toGuess = rand() % 100 + 1;
//	//2.��ʾ�û����н���
//	while (1) {
//		printf("������һ������[1,100]:");
//		int inputNum = 0;
//		scanf_s("%d", &inputNum);
//		if (inputNum < toGuess) {
//			printf("����!\n");
//		}
//		else if (inputNum> toGuess) {
//			printf("����!\n");
//		}
//		else {
//			printf("�¶���!\n");
//			break;
//		}
//	}
//}
//int menu() {
//	printf("=============\n");
//	printf("��ӭ������������Ϸ!\n\n");
//	printf("1.��ʼ��Ϸ!\n");
//	printf("0.�˳���Ϸ!\n");
//	printf("=============\n");
//	printf("����������ѡ��:");
//	int choice = 0;
//	scanf_s("%d", &choice);
//	return choice;
//}
//int main() {
//	//ֻҪ��ÿ�����г���ʱ�����õ�������Ӳ�һ������
//	//ʱ���
//	//ʹ��time(0)��ȡ��ǰʱ���
//	srand((unsigned int)time(0));//ǿ��ת�����ͣ����ǻᶪʧ����.
//	//game();
//	//����һ�����û������Ĳ˵�
//	while (1) {
//		int choice = menu();
//		if (choice == 1) {
//			game();
//		}
//		else if (choice == 0) {
//			printf("goodbye!\n");
//			break;
//		}else {
//			printf("������������!\n");
//		}
//	}
//	system("pause");
//	return 0;
//