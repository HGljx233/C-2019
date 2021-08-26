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
	}//设置随机种子;
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
	printf("玩家落子....\n");
	while (1) {
		printf("请输入坐标(row col): ");
		int row = 0;
		int col = 0;
		scanf_s("%d %d", &row, &col);
		// 进行合法性校验, 判定用户输入的内容是否是合法的
		// 如果不合法, 就让用户重新输入
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			// 就是不合法, 于是要让用户重新输入
			printf("您输入的坐标非法! 请重新输入!\n");
			continue;
		}
		// 假设用户输入了1, 1, 但是 1 1 位置已经有子了~~ 
		if (chessBoard[row][col] != ' ') {
			// 该位置已经有子了
			printf("您输入的位置已经有子了, 请重新输入!\n");
			continue;
		}
		// 进行落子~~
		chessBoard[row][col] = 'x';
		break;
	}
}

void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ') {
			// 这个位置已经有子了
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}

// 返回 1 表示满了, 返回 0 表示没满
int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	// 遍历棋盘, 看看有没有空格. 有空格就是没满~~
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

// 此处约定,
// 如果返回 x, 表示 玩家获胜
// 如果返回 o, 表示 电脑获胜
// 如果返回 ' ', 表示胜负未分, 还要继续下棋
// 如果返回 q, 表示和棋
char isGameOver(char chessBoard[MAX_ROW][MAX_COL]) {
	// 扫描所有的行, 所有的列, 以及两个对角线~~
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
	// 判定是否和棋
	if (isFull(chessBoard)) {
		return 'q';
	}
	// 胜负未分
	return ' ';
}

int main() {
	// 不建议使用全局变量
	// 搜索树
	char chessBoard[MAX_ROW][MAX_COL];
	// 1. 对棋盘进行初始化
	init(chessBoard);
	char winner = ' ';
	while (1) {
		//打印棋盘之前清屏
		system("cls");
		// 2. 打印棋盘
		print(chessBoard);
		// 3. 玩家落子
		playerMove(chessBoard);
		// 4. 判定胜负
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// 游戏结束
			break;
		}
		// 5. 电脑落子
		computerMove(chessBoard);
		// 6. 判定胜负
		winner = isGameOver(chessBoard);
		if (winner != ' ') {
			// 游戏结束
			break;
		}
	}
	print(chessBoard);
	if (winner == 'x') {
		printf("恭喜你赢了!\n");
	}
	else if (winner == 'o') {
		printf("你咋连人工智障都下不过!\n");
	}
	else {
		printf("你和人工智障五五开!\n");
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
//	printf("玩家落子......\n");
//	while (1) {
//		printf("请输入坐标(row,col): ");
//		int row = 0;
//		int col = 0;
//		scanf_s("%d %d", &row, &col);
//		//一定要把用户当成sb;,进行合法性校验,判定用户输入的内容是否合法
//		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
//			printf("您输入的坐标非法!请重新输入!\n");
//			continue;
//		}
//		if (chessBoard[row][col] != '0 ') {
//			printf("您输入的位置已经有子了,请重新输入!\n");
//			continue;
//		}
//		chessBoard[row][col] = 'x';//进行落子--
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
////此处约定,
////如果返回x,表示玩家获胜
////如果返回0,表示电脑获胜
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
//	//不建议使用全局变量
//	char chessBoard[MAX_ROW][MAX_COL] = { o };
//	//1.对棋盘进行初始化
//	init(chessBoard);
//	//2.打印棋盘
//	while (1) {
//		print(chessBoard);
//		//3.玩家落子.
//		playerMove(chessBoard);
//		//4.判定胜负
//		//TODO
//		//5.电脑落子
//		computerMove(chessBoard);
//	}
//
//	system("pause");
//	return 0;
//}

//void bubbleSort(int arr[], int size) {
//	//写一下从后往前遍历的版本
//	//bound=>边界 使用这个变量的值，表示已排序区间和待排序区间的分界线
//	//[0,bound)已排序区间
//	//[bound,size)待排序区间
//	int bound = 0;
//	for (; bound < size; bound++) {
//		//通过这个循环，来控制后续的比较相邻元素的比较趟数
//		//接下来实现一趟比较交换的过程
//		for (int cur = size - 1; cur > bound; cur--) {
//			//相邻元素，就是以 cur 为基准
//			if (arr[cur - 1] > arr[cur]) {
//				//不符合升序条件，就进行交换；
//				int tmp = arr[cur - 1];
//				arr[cur - 1] = arr[cur];
//				arr[cur] = tmp;
//			}
//		}
//	}
//}
//int main() {
//	//排序，冒泡和快速排序;
//	int arr[] = { 9,5,6,8,2,4 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	bubbleSort(arr,size);
//	for (int i = 0; i < size; ++i) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
	//快速更改变量名shift+alt=r;

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
	//int arr[3][4] = { 0 };//数组的初始化
	/*int arr[3][4] = {
		(1,2),
		(3,4),
		(5)
	};*/
	/*int arr[] = { 1,2,3,4,5,6 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", num);*/
	//arr =>array 数组
	//C++标准库有一个std::array 这个东西
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
//通过循环来写菲波那切数列
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
}*///斐波那契数列
//int mystrlen(char* str) {
//	int count = 0;
//	while (str[count] != '\0') {
//		count++;
//	}
//	return count;
//}
////如果不让创建局部变量，或者不让使用循环，就可以考虑下递归；
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
//其中 arr 表示待查找的数组
//其中toFind 表示要去查找的数字
//int binarySearch(int arr[],int size, int toFind) {
//	int left = 0;
//	int right = size-1;
//	while (left < right) {
//		int mid = (left + right) / 2;
//		if (toFind < arr[mid]) {
//			//去左侧查找
//			right = mid - 1;
//		}
//		else if (toFind > arr[mid]) {
//			//去右侧找
//			left = mid + 1;
//		}
//		else {
//			//找到了，此处使用函数返回值表示找到元素下标位置
//			//不要直接打印；
//			return mid;
//		}
//	}
//	//如果上面的循环最后也没找到合适的元素，认为没找到，返回一个无效的下标-1;
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
		//世纪闰年
	//	if (year % 400 == 0) {
	//		return 1;
	//	}
	//	return 0;
	//}
	//else {
	//	//普通闰年
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
//			//找到反例了
//			return 0;
//		}
//	//循环结束，也没找到反例，当前就认为是素数
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
//	//程序一运行就提示1min之后关机22
//    // 输入 我是猪 取消关机
//	    system("shutdown -s -t 600");
//		while (1) {
//			printf("您的电脑将在1min后关机，输入 我是猪 取消关机：\n");
//			char input[1024] = { 0 };
//			scanf_s("%s", input,1023);
//			if (strcmp(input, "我是猪") == 0) {
//				system("shutdown -a");
//				printf("您真乖..关机已取消\n");
//			}
//		}
//		system("pause");
//		return 0;
//}
//	else {
//	;
//		//再给给用户一次机会
//		//AGAIN是一个标签（label）就表示 一个代码的位置
//		//goto AGAIN;
//	}
//}
////void表示函数没有返回值
////使用函数表示一局游戏
//void game() {
//	printf("开始一局猜数字游戏\n");
//	//1.先生成一个1到100的随机整数
//	int toGuess = rand() % 100 + 1;
//	//2.提示用户进行交互
//	while (1) {
//		printf("请输入一个整数[1,100]:");
//		int inputNum = 0;
//		scanf_s("%d", &inputNum);
//		if (inputNum < toGuess) {
//			printf("低了!\n");
//		}
//		else if (inputNum> toGuess) {
//			printf("高了!\n");
//		}
//		else {
//			printf("猜对了!\n");
//			break;
//		}
//	}
//}
//int menu() {
//	printf("=============\n");
//	printf("欢迎来到猜数字游戏!\n\n");
//	printf("1.开始游戏!\n");
//	printf("0.退出游戏!\n");
//	printf("=============\n");
//	printf("请输入您的选择:");
//	int choice = 0;
//	scanf_s("%d", &choice);
//	return choice;
//}
//int main() {
//	//只要让每次运行程序时，设置的随机种子不一样即可
//	//时间戳
//	//使用time(0)获取当前时间戳
//	srand((unsigned int)time(0));//强制转换类型，还是会丢失数据.
//	//game();
//	//加上一个和用户交互的菜单
//	while (1) {
//		int choice = menu();
//		if (choice == 1) {
//			game();
//		}
//		else if (choice == 0) {
//			printf("goodbye!\n");
//			break;
//		}else {
//			printf("您的输入有误!\n");
//		}
//	}
//	system("pause");
//	return 0;
//