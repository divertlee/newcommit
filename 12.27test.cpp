#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

bool isret(int n)
{
	int squ = n * n;
	int count = 1;
	int sum = 0;
	while (n / 10)
	{
		++count;
	}

	while (count--)
	{
		sum += (squ % 10);
		squ /= 10;
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);//����һ������-��n���ڵ�����������
	int count = 0;//��¼����������
	int ret = 0;
	for (; n >= 0; --n)
	{
		if (isret(n))
		{
			count++;
		}
	}
	return 0;
}