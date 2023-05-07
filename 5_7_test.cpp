#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include<vector>
#include<array>
#include<assert.h>
#include<string>
using namespace std;
//#include"1.11_list.h"
//#include"12.7_vector.h"
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

//template<class T>
//void fun1(T& object)//输出型参数
//{
//	for (size_t i = 0; i < object.size(); i++)
//	{
//		object[i] = i;
//	}
//	//...... 这里对object
//}
//template<class T>
// T fun2( T& object)
//{
//	T ret;
//	ret.resize(object.size());
//	for (size_t i = 0; i < ret.size(); i++)
//	{
//		ret[i] = i;
//	}
//	//...... 这里对ret进行操作
//	return ret;//传值返回
//		
//}

 //template<class T>
 //const  T& fun3(const T& object)
 //{
	// T ret;
	// ret.resize(object.size());
	// for (size_t i = 0; i < ret.size(); i++)
	// {
	//	 ret[i] = i;
	// }
	// //...... 这里对ret进行操作
	// return ret;//函数结束，参数ret的生命周期结束销毁了，一是参数ret传不出去，二是传引用返回给外面那层，此时再访问到参数ret算是越界访问了！
 //}

//template<class T>
//void fun3(const T& object,T&retu)
//{
//	T ret;
//	ret.resize(object.size());
//	for (size_t i = 0; i < ret.size(); i++)
//	{
//		ret[i] = i;
//	}
//	//...... 这里对ret进行操作
//	retu = ret;
//}

//int main()
//{
//	//fun1(v);
//	//v.clear();
//	//v.resize(10, 0);
//	vector<int>v(10,0);
//	vector<int> ret2;
//  fun2(v);
////  vector<int> ret3 = fun3(v);
//  vector<int> ret3;
// 	fun3(v,ret3);
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
//	return 0;
//}

namespace pjl
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str="")
			:_size(strlen(str))//当传进来的对象是空对象时，对象的指针是空指针，访问空指针为越界报错
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		//string(string&& s) = default;
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			swap(s);
		}
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) --赋值重载，这里也用到深拷贝" << endl;
			string tmp(s);//
			swap(tmp);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str=nullptr;
		size_t _size=0;
		size_t _capacity=0; // 不包含最后做标识的\0
	};
}

class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	Person(Person&& p) = default;//强制生成一个默认的移动构造
	Person(const Person& p)//拷贝构造
	:_name(p._name)
    ,_age(p._age)
{}

	//Person(Person&& p)
	//	:_name(std::forward<pjl::string>(p._name))//传对象过来后，退化为左值属性了，这里需要完美转发
	//	, _age(p._age)
	//{}
/*Person& operator=(const Person& p)
{
if(this != &p)
{
_name = p._name;
_age = p._age;
}
return *this;
}*/
/*~Person()
{}*/
private:
	pjl::string _name;
	int _age;
};
//int main()
//{
//	Person s1="this is the test";//左值
//	Person s2 = std::move(s1);//传右值--（移动）构造
//	Person s4(s2);//传左值--拷贝构造
//	return 0;
//
//	//Person s3;
//	//	s3 = std::move(s1);//赋值
//}

//class A
//{
//public:
//	A() {}
//	
//	~A()
//	{
//		delete []p;//析构函数只析构一次，若对象不止一个int大小调用则报错
//	}
//	A(const A& aa) = delete;
//private:
//	
//	int* p = new int[10];
//};
//
//int main()
//{
//	A aa;
//	A bb(aa);
//	return 0;
//}


//void func1(bit::string s)
//{}
//void func2(const bit::string& s)
//{}

//void temp( int& x)
//{
//	cout << "int &x" << ":" << x << endl;
//}
//
//void temp(int&& x)
//{
//	cout << "int &&x" << ":" << x <<endl;
//	
//}
//
////void fun1(t&& x)
////{
////	cout << "fun1::int& x" << endl;
////	temp(std::forward<int>(x));
////}
//template<class T>
//void fun1(T&& x)
//{
//	cout << "完美引用" << endl;
//	temp(std::forward<T>(x));
//}
//
//
//int main()
//{
//	int x = 10;
//	fun1(x);
//	fun1(20);
//	return 0;
//}
	//fun1(15);
	//fun1(x);//传左值就匹配左值版本
	//fun1(std::forward<int>(x));//用万能转发---保持参数的左右值属性
	//fun1(18);//传右值就匹配右值版本
	//int x = 10;
	//int y = 18;
	//int& rx = x;
	//int&& ry = x + y;
	//ry++;
	//cout << &x << endl;
	//cout << &ry << endl;//用右值引用引用右值后，右值的资源被转移了，性质发生改变，变成了左值可以取地址
	//cout << &(x + y) << endl;//右值取不到地址

	//pjl::string s1 = { "xxxxxxx" };
	//pjl::string s2;
	//s2 = move(s1);//move之后的左值为右值
	//int flag = 0;//标记位
	/*pjl::string ret = pjl::to_string(1234);
	ret = pjl::to_string(2456);*/
	//pjl::string ret1;
	//ret1 = move(ret);//move之后的左值为右值
	//pjl::string tmp("xxxxxxx");
	//ret = move(tmp);
	//int num1 = 1235;
	//int* pnum1 = new int{ 1234 };
	//pjl::string ret = pjl::to_string(*pnum1);
	//pjl::string str1 = "abcdef";
	////pjl::string ret = pjl::func(str1);//左值
	////pjl::string ret1 = pjl::func();//右值
	//pjl::string ret=pjl::to_string(str1);
	//pjl::string ret1(ret);//传左值--拷贝构造
	//pjl::string ret2 = ("xxxxxxx");
	//ret2 = ret;//传左值--赋值重载

	//pjl::string ret3 = pjl::to_string(1234);//传右值--拷贝构造
	// ret3 = pjl::string("bbbbbbbbbb");//传匿名对象，传的右值--赋值重载
    //pjl::string ret2(ret);
	//pjl::string s1{ "xxxxx" };//左值
	//pjl::string ret1(s1);//s1为左值，用到拷贝构造
	//pjl::string s2{ "aaaaa" };
	//s2 = s1;//s1为左值，用到赋值重载
	//pjl::string s3(move(s1));//move之后的左值为右值
 //s3 = "bbbbb";//右值
	//pjl::string ret = pjl::to_string(1233);
	
	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
	//func1(s1);
	//func2(s1);
	// string operator+=(char ch) 传值返回存在深拷贝
	// string& operator+=(char ch) 传左值引用没有拷贝提高了效率
	//s1 += '!';
//	return 0;
//}

//template<class T>
//T& temp(T&& x)
//{
//	T tmp = x;
//	
//	tmp++;
//	return tmp;
//}



//template<class T>
//const  T& fun3(T& object)
//{
//	T ret = object;
//	//ret.resize(object.size());
//	for (size_t i = 0; i < ret.size(); i++)
//	{
//		ret[i] = i;
//	}
//	//...... 这里对ret进行操作
//	return ret;//函数结束，参数ret的生命周期结束销毁了，一是参数ret传不出去，二是传引用返回给外面那层，此时再访问到参数ret算是越界访问了！
//}
//template<class T>
//const T& fun1(T& x)
//{
//	T ret = x;
//	ret += 3;
//	return ret;
//}
//

//template<class T>
//const  T& fun3( T&& object)
//{
//	T ret = object;
//	for (size_t i = 0; i < ret.size(); i++)
//	{
//		ret[i] = i;
//	}
//	//...... 这里对ret进行操作
//	return ret;//函数结束，对象没有销毁，通过转移拷贝把对象传了回去
//}
//int main()
//{
//	vector<int>v(10, 0);
//	vector<int> ret3 = fun3(v);//传了左值过去
//	int flag1 = 0;//标记位
//	//vector<int> ret4 = fun3(vector<int>(5,0));//传了右值过去
//	//int flag2 = 0;
//	//int x = 2;
//	//int& lx = x;
//	//int y = lx;
//	//y++;//y改变x和lx不会改变
//	//cout<<fun1(x) << endl;
//	return 0;
//}

//void Testin(int& x)//左值引用
//{
//	cout << "左值引用:" << x << endl;
//}
//
//void Testin(int&& x)//左值引用
//{
//	cout << "右值引用:" << x << endl;
//}
//
////template<class T>
////void temp(T&& x)
////{
////	cout << "T&&:temp:" << x << endl;
////	Testin(x);
////}
//
//template<class T>
//void temp(const T& x)
//{
//	cout << "const T&:temp:" << x << endl;
//	Testin(x);
//}
//
//int main()
//{
//	int x = 25;
//	temp(x);////传左值
//	temp(100);//传右值
//
//	return 0;
//}

//void Func(int& x)
//{
//	cout << "左值引用" << endl;
//}
//void Func(const int& x)
//{
//	cout << "const 左值引用" << endl;
//}
//void Func(int&& x)
//{
//	cout << "右值引用" << endl;
//}
//void Func(const int&& x)
//{
//	cout << "const 右值引用" << endl;
//}
//template<class T>
//void PerfectForward(T&& t)
//{
//	Func(std::forward<T>(t));
//}
//int main()
//{
//	int a = 10;
//	PerfectForward(a);       //左值
//	PerfectForward(move(a)); //右值
//
//	const int b = 20;
//	PerfectForward(b);       //const 左值
//	PerfectForward(move(b)); //const 右值
//
//	return 0;
//}

int main()
{

	int a = 10;
	int b = 2;
	auto temp = [](int x, int y) {return x > y; };
	cout << temp(a, b) << endl;
	return 0;
}