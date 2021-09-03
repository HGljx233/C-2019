#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void findTwoNumsWithOthersHas2Times(int s[], int len)
{

	if (len < 2) return;
	//����������ΪA B �����A^B
	int ab = s[0];
	for (int i = 1; i < len; ++i)
	{
		ab ^= s[i];
	}
	//���� A^B �����������һ��1��λ��K���������������Ϊ���飬��һ�����ֵ�Kλ�ö���1,�ڶ���Kλ����0
	int k = 0;
	while ((ab & 1 << k) == 0)
		++k;
	//���飬��ʵ������ķ֡�
	k = (1 << k); //��K���棬��λ���ֵ,�Ա�Ƶ����λ
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