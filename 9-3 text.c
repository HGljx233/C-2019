#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void findTwoNumsWithOthersHas2Times(int s[], int len)
{

	if (len < 2) return;
	//假设两个数为A B 先求出A^B
	int ab = s[0];
	for (int i = 1; i < len; ++i)
	{
		ab ^= s[i];
	}
	//再求 A^B 二进制中最后一个1的位置K。这样，把数组分为两组，第一组数字的K位置都是1,第二组K位置是0
	int k = 0;
	while ((ab & 1 << k) == 0)
		++k;
	//分组，其实不用真的分。
	k = (1 << k); //用K保存，移位后的值,以避频繁移位
	int t1 = ab, t2 = ab;
	for (int i = 0; i < len; ++i)
	{
		if ((s[i] & k) == k)
			t1 ^= s[i];
	}
	for (int i = 0; i < len; ++i)
	{
		if ((s[i] & k) == 0)
			t2 ^= s[i];
	}
	printf("%s %s\n", t1, t2);
}
int main() {
	int s[] = { 1,2,7,4,5,4,5,2,6,1 };
	int len = sizeof(s) / sizeof(int);
	findTwoNumsWithOthersHas2Times(s, len);
	return 0;
}