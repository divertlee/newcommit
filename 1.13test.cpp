#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int a = 0;
	cin >> a;
	string str[32];
	for (int i = 0; i < 32; i++)
	{
		str[32 - 1 - i] = (char)(((a >> i) & 1) + '0');

	}
	int sum = 0;
	
	int prev = 0;
	for (int cur = 0; cur < 32; cur++)
	{
		if (str[cur] == "1")
		{
			prev++;
			sum = sum > prev ? sum : prev;
		}
		else
		{
			prev = 0;
		}
}
	cout << sum << endl;
	return 0;
}



//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,T2>" << endl;
//	}
//
//};
//
//template<class T1, class T2>
//class Data<T1*,T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1*,T2*>" << endl;
//	}
//
//};
//
//template<class T1>
//class Data<T1, char>
//{
//public:
//	Data()
//	{
//		cout << "Data<T1,char>" << endl;
//	}
//
//};
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int*, int*> d2;
//	Data<char, char> d3;
//	return 0;
//}


//int main()
//{
//	string s = "38$@NoNoN";
//	int sum = 0;
//	//ÅĞ¶ÏÃÜÂë³¤¶È
//	if (s.size() <= 4)
//	{
//		sum += 5;
//	}
//	else if(s.size()>=5&&s.size()<=7)
//	{
//		sum += 10;
//	}
//	else
//	{
//		sum += 25;
//	}
//
//	//ÅĞ¶Ï×ÖÄ¸
//	int flag = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (islower(s[i]) == 1)
//		{
//			flag++;//ÅĞ¶ÏĞ¡Ğ´×ÖÄ¸
//			break;
//		}	
//	}
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (isupper(s[i]) == 1)
//		{
//			flag++;//ÅĞ¶Ï´óĞ´×ÖÄ¸
//			break;
//		}
//	}
//	if (flag == 2)
//	{
//		sum += 20;
//	}
//	else if (flag == 1)
//	{
//		sum += 10;
//	}
//	 
//	//ÅĞ¶ÏÊı×Ö
//	flag = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (isdigit(s[i]) != 0)
//		{
//			flag++;
//		}
//	}
//	if (flag > 1)
//	{
//		sum += 20;
//	}
//	else if (flag == 1)
//	{
//		sum += 10;
//	}
//	//ÅĞ¶Ï·ûºÅ
//	flag = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if(s[i]>)
//	}
//
//	return 0;
//}
