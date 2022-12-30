#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
//n以内的自守数个数
//bool isret(int n)
//{
//	int m = n;
//	int squ = n * n;
//
//	int count = 1;
//	int sum = 0;
//	while (m / 10)//计算n是几位数
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
//	//while (count--)//得出对于平方的count位数
//	//{
//	//	sum += (squ % 10);
//	//	squ /= 10;
//	//}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);//输入一个整数-求n以内的自守数个数
//	int count = 0;//记录自守数个数
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

//n以内的质数个数

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

//int main()
//{
//
//	string s="We are happy.";
//	
//	cout << s << endl;
//	size_t pos = s.find_first_of(" ");
//	while (pos != std::string::npos)
//	{
//		s.replace(pos, 1,"%20");
//		 pos = s.find_first_of(" ",pos+1);
//	}
//	cout << s << endl;
//	return 0;
//}
int main()
{
	string s1 = "  hello world kk aa bb";
	string s2;
	string::iterator it1 = s1.begin();
	while(s1.begin()!=s1.end())//删前面的空格
	{
		
		if (*it1 == ' ')
		{
			it1=s1.erase(it1);
		}
		else
		{
			break;
		}
	}
	size_t i = 0;
	size_t pos = s1.find(" ");
	while (pos != std::string::npos)
	{
		s2.insert(0, s1, i, pos - i);
		s2.insert(0," ");
		i = pos+1;
		pos = s1.find(" ",pos+1);
	}
	string::reverse_iterator rit1 = s1.rbegin();
	if (*rit1 != ' ')
	{
		s2.insert(0, s1, i,s1.size() - i);
	}
	string::iterator it2 = s2.begin();
	while (s2.begin() != s2.end())//删前面的空格
	{

		if (*it2 == ' ')
		{
			it2 = s2.erase(it2);
		}
		else
		{
			break;
		}
	}

	cout << s2 << endl;
	return 0;
}