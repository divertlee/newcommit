#include<iostream>
#include<list>
#include<vector>
#include<array>
using namespace std;
//#include"1.11_list.h"
#include"12.7_vector.h"
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
//template<class T1,class T2>
////void multis(T1 t1, T2 t2)
////{
////	//decltype(t1 * t2) ret;//这里ret没有接收返回值，所以不能用auto来推导ret的类型；但可以通过decltype来推导
////	//cout <<"ret的类型为：" << typeid(ret).name() << endl;
////}
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//int mini(int x, int y)
//{
//	return x < y ? x : y;
//}
//template<class T>
//void remainder1( T& num)
//{
//	num %= 10;//引用传值进来，函数结束后值还在
//	
//}
//template<class T>
//T remainder2(const T& num)
//{
//	T ret;
//	ret= num % 10;
//	return ret;//传引用返回
//}
//template<class T>
//const T& remainder3(const T& num)
//{
//	T ret;
//	ret = num % 10;
//	return ret;//传引用返回
//}

template<class T>
void fun1(T& object)//输出型参数
{
	//...... 这里对object
}
template<class T>
const T& fun2(const T& object)
{
	//...... 这里对object进行操作
	return object;//传值返回

}
template<class T>
const  T& fun3(const T& object)
{
	T ret;
	//...... 这里对ret进行操作
	return ret;//函数结束，参数ret的生命周期结束，传引用返回给外面那层，此时再访问参数ret算是越界访问了！

}

int main()
{
	vector<int>v;
	fun1(v);
	fun2(v);
	fun3(v);
	/*int k1 = 18;
	remainder1(k1);
	cout <<"k1余数为：" << k1 << endl;
	int k2 = 19;
	cout <<"k2余数为：" <<remainder2(k2) << endl;
	int k3 = 25;
	cout << "k3余数为：" << remainder3(k3) << endl;*/
//	int x = 10;
//	int y = 90;
//	//以下是右值
////int&pret=	x + y;//不能引用
//const int&lret=	x + y;//可以引用
//const int& lmin = mini(x, y);//可以引用
//
////int&& rx1 = x;//不能引用
//int&& rx2 = move(x);//move之后的左值可以右值引用

	//Date d1{ 2002,11,25 };//调用Date的构造函数初始化,由于Date有三个参数的构造函数，所以可以传三个参数过去初始化
  //但是vector和list是单个参数的构造函数，并且没有多个参数的构造函数，那是怎么做到下面的初始化呢？
	//vector<int> vt{ 1,2,3,4,5 };
	//list<int> lt{ 3,4,5,6,7 };

	//auto il = { 1,2,3,4,5 };
	//cout << typeid(il).name() << endl;
	//Vect::testinlist1();
	//int* p = new int(1);
	//int*& rp = p;//对p的引用
	//int& p_value = *p;//对p解引用后的数据的引用
	//int x = 10;
	//int& rx = x;//对x的引用
	//const int y = 20;
	//const int& ry = y;//对y的引用
	
	/*string tmp[] = { "this","is","a","test","ohh" };
	for (auto e: tmp)
	{
		cout << e << endl;
	}*/

	//int arr[] = { 1,2,3,4,5 };
	//cout << "C语言的数组：" << arr[5] << endl;//C语言的数组可以访问数组以外的元素---对于越界访问是抽查
	////arr[5] = 6;//不能修改
	//array<int, 5> ary{ 1,2,3,4,5 };
	//cout << "array数组：" << ary[5] << endl;//array对于越界访问是严格查询
	/*int x = 6;
	double y = 2.66;
	multis(x, y);*/

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