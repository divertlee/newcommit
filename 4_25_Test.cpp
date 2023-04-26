#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
#include"C++_vector.h"
#include"C++_Iterator.h"

//template<class T1,class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;//根据变量类型推导表达式的类型
//	cout << typeid(ret).name() << endl;
//}
double getmin(double x, double y)
{
	return min(x, y);
}
int main()
{
	double x = 1.26;
	double y = 3.28;
	//int& pxy = x + y;//左值引用不行---x和y是一个常量，没有地址--不能获取地址
	double&& rxy = x + y;//右值引用
	//int& ten = 10;//10是一个常量，不能获取地址--不能左值引用
	int&& rten = 10;//右值引用
	//int& pmin = getmin(x, y);//函数的返回值出了函数作用域就被销毁了---不能获取地址--不能左值引用
	int&& rmin = getmin(x, y);//可以用来右值引用
	/*F(1, 3);
	F(2.22, 4);*/
	const int& pmin = getmin(x, y);//const左值引用能引用右值
	//Vect::test_vector();
	return 0;
}
//struct Point
//{
//	int _x;
//	int _y;
//};
//
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
//
//int main()
//{
//	Date d1(2002, 11, 28);//调用构造函数
//	// C++11支持的列表初始化，这里会调用构造函数初始化
//	Date d2{ 2002,11,27 };
//	Date d3 = { 2001,1,1 };
//	auto il = { 1,2,3 };
//	cout << typeid(il).name() << endl;
//	map<string, string> stt{ {"sort","排序"},{"bloomfilter","布隆过滤器"} };
//	//int x1 = 2;
//	//int x2{ 2 };
//	//Point p1;
//	//p1._x = 1;
//	//p1._y = 2;
//	//Point p2= { 1,2 };//与上相同
//	//int arr1[] = { 1,2,3,4,5 };
//	//int arr2[]{ 1,2,3,4,5,6 };//与上相同
//	//return 0;
//}