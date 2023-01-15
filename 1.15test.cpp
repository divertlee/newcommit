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
	
	//A(A&);//1.拷贝构造的声明，声明后编译器不再形成默认拷贝构造---报链接错误
//private:
	//A(A&);//2.在这里则访问不了拷贝构造的声明
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
//	int even = 0;//输入偶数
//	cin >> even;
//	int pri1 = 0;
//	int pri2 = 0;
//	v.push_back(2);
//	int y = 2;
//	for (int x = 3; x < even; x += 2)//只产生奇数
//	{
//		
//		for ( y = 3; y < x; y += 2)//只产生奇数
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
//	//b.swap();  //基类的public成员，通过派生类Bprotect继承，也可以在类外调用,但基类的protected成员就不能在类外调用了，
//	return 0;
//}