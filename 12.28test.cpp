#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
//n���ڵ�����������
//bool isret(int n)
//{
//	int m = n;
//	int squ = n * n;
//
//	int count = 1;
//	int sum = 0;
//	while (m / 10)//����n�Ǽ�λ��
//	{
//		++count;//
//		m /= 10;
//
//	}
//	int tenmul = 1;
//	while (count--)
//	{
//		tenmul *= 10;
//	}
//
//	sum += (squ % tenmul);
//	if (sum == n)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//
//	//while (count--)//�ó�����ƽ����countλ��
//	//{
//	//	sum += (squ % 10);
//	//	squ /= 10;
//	//}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);//����һ������-��n���ڵ�����������
//	int count = 0;//��¼����������
//	int ret = 0;
//	for (; n >= 0; --n)
//	{
//		if (isret(n))
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

//n���ڵ���������

//int main()
//{
//	int n = 0;
//	cin >> n;
//	int count = 0;
//	for (int i = 2; i <= n; ++i)
//	{
//		int flag = 0;
//		for (int j = 2; j <= sqrt(i); ++j)
//		{
//			if (i % j == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			++count;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

int main()
{

	string s="We are happy.";
	
	cout << s << endl;
	size_t pos = s.find_first_of(" ");
	while (pos != std::string::npos)
	{
		s.replace(pos, 1,"%20");
		 pos = s.find_first_of(" ",pos+1);
	}
	cout << s << endl;
	return 0;
}