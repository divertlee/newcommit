#pragma once

#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

class A
{
public:
	A()
	{
		;
	}
	
	//A(A&);//1.�������������������������������γ�Ĭ�Ͽ�������---�����Ӵ���
//private:
	//A(A&);//2.����������ʲ��˿������������
};

int main()
{
	A a;
	A a1(a);
	return 0;
}

//int main()
//{
//	const int a = 10;
//	int* p = (int*)(&a);
//	*p = 20;
//	cout << a << *p << endl;
//	return 0;
//}


//int main()
//{
//	vector<int> v;
//	int even = 0;//����ż��
//	cin >> even;
//	int pri1 = 0;
//	int pri2 = 0;
//	v.push_back(2);
//	int y = 2;
//	for (int x = 3; x < even; x += 2)//ֻ��������
//	{
//		
//		for ( y = 3; y < x; y += 2)//ֻ��������
//		{
//			if (x % y == 0)
//			{
//				break;
//			}
//		}
//		if (x == y)
//		{
//			v.push_back(x);
//		}
//	}
//	
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = i ; j < v.size(); j++)
//		{
//			if ((v[i] + v[j]) == even)
//			{
//				pri1 = v[i];
//				pri2 = v[j];
//				break;
//			}
//		}
//	}
//	cout << pri1 << endl;
//	cout << pri2 << endl;
//
//	return 0;
//}



//int binInsert(int n, int m, int j, int i)
//{
//	for (int x = j; x < i; x++)
//	{
//
//	}
//	return ret;
//}
//
//int main()
//{
//	int n = 1024;
//	int m = 19;
//	int j = 2;
//	int i = 6;
//	int ret = binInsert( n,m,j, i);
//	cout << ret << endl;
//	return 0;
//}



//class A
//{
//protected:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B :protected A
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	B b;
//	//b.swap();  //�����public��Ա��ͨ��������Bprotect�̳У�Ҳ�������������,�������protected��Ա�Ͳ�������������ˣ�
//	return 0;
//}