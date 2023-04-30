#include<iostream>
#include<list>
using namespace std;

//struct XandY
//{
//	int _x;
//	int _y;
//	void Print()
//	{
//		cout << _x << ":" << _y << endl;
//	}
//	
//};
//int main()
//{
//	//int a1[] = { 1,2,3,4,5 };//原来的数组初始化
//	//int a2[]{ 11,12,13,14,15 };
//
//	//XandY xy1;
//	//xy1._x = 12;
//	//xy1._y = 23;//之前的初始化，先构造一个对象，然后再赋值初始化
//	//xy1.Print();
//	//XandY xy2{ 33,44 };
//	//xy2.Print();
//
////	int* ptr1 = new int[4]{ 1,2,3,4 };
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

template<class T1,class T2>
void multis(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;//这里ret没有接收返回值，所以不能用auto来推导ret的类型；但可以通过decltype来推导
	cout <<"ret的类型为：" << typeid(ret).name() << endl;
}

int main()
{
	int x = 6;
	double y = 2.66;
	multis(x, y);

	//Date d1(2002, 12, 20);//原来：()传参构造函数初始化
	//Date d2{ 2001,3,28 };//通过{}列表初始化的方式构造函数初始化
	//Date d3 = { 2000,11,24 };//也可带=

	//int a = 10;
	//auto int b = 10 ;
	//auto dou = 1.34;//返回值类型为double，auto推导变量dou的类型也为double
	//auto str = "jinitaimei";//返回值类型为string，auto推导变量str的类型也为string
	//list<int> lt;
	//lt.push_back(11);
	//lt.push_back(12);
	//lt.push_back(13);
	//lt.push_back(14);
	//list<int>::iterator it1 = lt.begin();//这里迭代器的类型是list<int>::iterator
	//cout << *it1 << endl;
	//auto it2 = lt.begin();//这里=的右边的返回值类型是list<int>::iterator，所以auto在等号在=左边自动推导变量it2的类型为list<int>::iterator
	//cout << *it2 << endl;

	//int a = 10;
	//cout << typeid(a).name() << endl;   //变量a的类型：int
	//cout << typeid(typeid(a).name()).name() << endl;   //变量名int的类型：const char *
	//const int b = 7;
	//cout << typeid(b).name() << endl;   //加const不改变类型：int
	//int& c = a;
	//cout << typeid(c).name() << endl;   //加引用&不改变类型：int
	//const int& f = a;  
	//cout << typeid(f).name() << endl;   //int
	//int* d;
	//cout << typeid(d).name() << endl;   //int *
	//const int* e;  
	//cout << typeid(e).name() << endl;   //const int *



	return 0;
}