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
//	//int a1[] = { 1,2,3,4,5 };//ԭ���������ʼ��
//	//int a2[]{ 11,12,13,14,15 };
//
//	//XandY xy1;
//	//xy1._x = 12;
//	//xy1._y = 23;//֮ǰ�ĳ�ʼ�����ȹ���һ������Ȼ���ٸ�ֵ��ʼ��
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
////	//decltype(t1 * t2) ret;//����retû�н��շ���ֵ�����Բ�����auto���Ƶ�ret�����ͣ�������ͨ��decltype���Ƶ�
////	//cout <<"ret������Ϊ��" << typeid(ret).name() << endl;
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
//	num %= 10;//���ô�ֵ����������������ֵ����
//	
//}
//template<class T>
//T remainder2(const T& num)
//{
//	T ret;
//	ret= num % 10;
//	return ret;//�����÷���
//}
//template<class T>
//const T& remainder3(const T& num)
//{
//	T ret;
//	ret = num % 10;
//	return ret;//�����÷���
//}

//template<class T>
//void fun1(T& object)//����Ͳ���
//{
//	for (size_t i = 0; i < object.size(); i++)
//	{
//		object[i] = i;
//	}
//	//...... �����object
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
//	//...... �����ret���в���
//	return ret;//��ֵ����
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
	// //...... �����ret���в���
	// return ret;//��������������ret���������ڽ��������ˣ�һ�ǲ���ret������ȥ�����Ǵ����÷��ظ������ǲ㣬��ʱ�ٷ��ʵ�����ret����Խ������ˣ�
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
//	//...... �����ret���в���
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
	cout <<"k1����Ϊ��" << k1 << endl;
	int k2 = 19;
	cout <<"k2����Ϊ��" <<remainder2(k2) << endl;
	int k3 = 25;
	cout << "k3����Ϊ��" << remainder3(k3) << endl;*/
//	int x = 10;
//	int y = 90;
//	//��������ֵ
////int&pret=	x + y;//��������
//const int&lret=	x + y;//��������
//const int& lmin = mini(x, y);//��������
//
////int&& rx1 = x;//��������
//int&& rx2 = move(x);//move֮�����ֵ������ֵ����

	//Date d1{ 2002,11,25 };//����Date�Ĺ��캯����ʼ��,����Date�����������Ĺ��캯�������Կ��Դ�����������ȥ��ʼ��
  //����vector��list�ǵ��������Ĺ��캯��������û�ж�������Ĺ��캯����������ô��������ĳ�ʼ���أ�
	//vector<int> vt{ 1,2,3,4,5 };
	//list<int> lt{ 3,4,5,6,7 };

	//auto il = { 1,2,3,4,5 };
	//cout << typeid(il).name() << endl;
	//Vect::testinlist1();
	//int* p = new int(1);
	//int*& rp = p;//��p������
	//int& p_value = *p;//��p�����ú�����ݵ�����
	//int x = 10;
	//int& rx = x;//��x������
	//const int y = 20;
	//const int& ry = y;//��y������
	
	/*string tmp[] = { "this","is","a","test","ohh" };
	for (auto e: tmp)
	{
		cout << e << endl;
	}*/

	//int arr[] = { 1,2,3,4,5 };
	//cout << "C���Ե����飺" << arr[5] << endl;//C���Ե�������Է������������Ԫ��---����Խ������ǳ��
	////arr[5] = 6;//�����޸�
	//array<int, 5> ary{ 1,2,3,4,5 };
	//cout << "array���飺" << ary[5] << endl;//array����Խ��������ϸ��ѯ
	/*int x = 6;
	double y = 2.66;
	multis(x, y);*/

	//Date d1(2002, 12, 20);//ԭ����()���ι��캯����ʼ��
	//Date d2{ 2001,3,28 };//ͨ��{}�б��ʼ���ķ�ʽ���캯����ʼ��
	//Date d3 = { 2000,11,24 };//Ҳ�ɴ�=

	//int a = 10;
	//auto int b = 10 ;
	//auto dou = 1.34;//����ֵ����Ϊdouble��auto�Ƶ�����dou������ҲΪdouble
	//auto str = "jinitaimei";//����ֵ����Ϊstring��auto�Ƶ�����str������ҲΪstring
	//list<int> lt;
	//lt.push_back(11);
	//lt.push_back(12);
	//lt.push_back(13);
	//lt.push_back(14);
	//list<int>::iterator it1 = lt.begin();//�����������������list<int>::iterator
	//cout << *it1 << endl;
	//auto it2 = lt.begin();//����=���ұߵķ���ֵ������list<int>::iterator������auto�ڵȺ���=����Զ��Ƶ�����it2������Ϊlist<int>::iterator
	//cout << *it2 << endl;

	//int a = 10;
	//cout << typeid(a).name() << endl;   //����a�����ͣ�int
	//cout << typeid(typeid(a).name()).name() << endl;   //������int�����ͣ�const char *
	//const int b = 7;
	//cout << typeid(b).name() << endl;   //��const���ı����ͣ�int
	//int& c = a;
	//cout << typeid(c).name() << endl;   //������&���ı����ͣ�int
	//const int& f = a;  
	//cout << typeid(f).name() << endl;   //int
	//int* d;
	//cout << typeid(d).name() << endl;   //int *
	//const int* e;  
	//cout << typeid(e).name() << endl;   //const int *
//	return 0;
//}

//namespace pjl
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		string(const char* str="")
//			:_size(strlen(str))//���������Ķ����ǿն���ʱ�������ָ���ǿ�ָ�룬���ʿ�ָ��ΪԽ�籨��
//			, _capacity(_size)
//		{
//			//cout << "string(char* str)" << endl;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		// s1.swap(s2)
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		//string(string&& s) = default;
//		// �ƶ�����
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- �ƶ�����" << endl;
//			swap(s);
//		}
//		// �ƶ���ֵ
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
//			swap(s);
//			return *this;
//		}
//
//		// ��������
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- ���" << endl;
//			string tmp(s._str);
//			swap(tmp);
//		}
//		// ��ֵ����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) --��ֵ���أ�����Ҳ�õ����" << endl;
//			string tmp(s);//
//			swap(tmp);
//			return *this;
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//		//string operator+=(char ch)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//		const char* c_str() const
//		{
//			return _str;
//		}
//	private:
//		char* _str=nullptr;
//		size_t _size=0;
//		size_t _capacity=0; // �������������ʶ��\0
//	};
//}
//
//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//
//	Person(Person&& p) = default;//ǿ������һ��Ĭ�ϵ��ƶ�����
//	Person(const Person& p)//��������
//	:_name(p._name)
//    ,_age(p._age)
//{}
//
//	//Person(Person&& p)
//	//	:_name(std::forward<pjl::string>(p._name))//������������˻�Ϊ��ֵ�����ˣ�������Ҫ����ת��
//	//	, _age(p._age)
//	//{}
///*Person& operator=(const Person& p)
//{
//if(this != &p)
//{
//_name = p._name;
//_age = p._age;
//}
//return *this;
//}*/
///*~Person()
//{}*/
//private:
//	pjl::string _name;
//	int _age;
//};
//int main()
//{
//	Person s1="this is the test";//��ֵ
//	Person s2 = std::move(s1);//����ֵ--���ƶ�������
//	Person s4(s2);//����ֵ--��������
//	return 0;
//
//	//Person s3;
//	//	s3 = std::move(s1);//��ֵ
//}

//class A
//{
//public:
//	A() {}
//	
//	~A()
//	{
//		delete []p;//��������ֻ����һ�Σ�������ֹһ��int��С�����򱨴�
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
//	cout << "��������" << endl;
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
	//fun1(x);//����ֵ��ƥ����ֵ�汾
	//fun1(std::forward<int>(x));//������ת��---���ֲ���������ֵ����
	//fun1(18);//����ֵ��ƥ����ֵ�汾
	//int x = 10;
	//int y = 18;
	//int& rx = x;
	//int&& ry = x + y;
	//ry++;
	//cout << &x << endl;
	//cout << &ry << endl;//����ֵ����������ֵ����ֵ����Դ��ת���ˣ����ʷ����ı䣬�������ֵ����ȡ��ַ
	//cout << &(x + y) << endl;//��ֵȡ������ַ

	//pjl::string s1 = { "xxxxxxx" };
	//pjl::string s2;
	//s2 = move(s1);//move֮�����ֵΪ��ֵ
	//int flag = 0;//���λ
	/*pjl::string ret = pjl::to_string(1234);
	ret = pjl::to_string(2456);*/
	//pjl::string ret1;
	//ret1 = move(ret);//move֮�����ֵΪ��ֵ
	//pjl::string tmp("xxxxxxx");
	//ret = move(tmp);
	//int num1 = 1235;
	//int* pnum1 = new int{ 1234 };
	//pjl::string ret = pjl::to_string(*pnum1);
	//pjl::string str1 = "abcdef";
	////pjl::string ret = pjl::func(str1);//��ֵ
	////pjl::string ret1 = pjl::func();//��ֵ
	//pjl::string ret=pjl::to_string(str1);
	//pjl::string ret1(ret);//����ֵ--��������
	//pjl::string ret2 = ("xxxxxxx");
	//ret2 = ret;//����ֵ--��ֵ����

	//pjl::string ret3 = pjl::to_string(1234);//����ֵ--��������
	// ret3 = pjl::string("bbbbbbbbbb");//���������󣬴�����ֵ--��ֵ����
    //pjl::string ret2(ret);
	//pjl::string s1{ "xxxxx" };//��ֵ
	//pjl::string ret1(s1);//s1Ϊ��ֵ���õ���������
	//pjl::string s2{ "aaaaa" };
	//s2 = s1;//s1Ϊ��ֵ���õ���ֵ����
	//pjl::string s3(move(s1));//move֮�����ֵΪ��ֵ
 //s3 = "bbbbb";//��ֵ
	//pjl::string ret = pjl::to_string(1233);
	
	// func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
	//func1(s1);
	//func2(s1);
	// string operator+=(char ch) ��ֵ���ش������
	// string& operator+=(char ch) ����ֵ����û�п��������Ч��
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
//	//...... �����ret���в���
//	return ret;//��������������ret���������ڽ��������ˣ�һ�ǲ���ret������ȥ�����Ǵ����÷��ظ������ǲ㣬��ʱ�ٷ��ʵ�����ret����Խ������ˣ�
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
//	//...... �����ret���в���
//	return ret;//��������������û�����٣�ͨ��ת�ƿ����Ѷ����˻�ȥ
//}
//int main()
//{
//	vector<int>v(10, 0);
//	vector<int> ret3 = fun3(v);//������ֵ��ȥ
//	int flag1 = 0;//���λ
//	//vector<int> ret4 = fun3(vector<int>(5,0));//������ֵ��ȥ
//	//int flag2 = 0;
//	//int x = 2;
//	//int& lx = x;
//	//int y = lx;
//	//y++;//y�ı�x��lx����ı�
//	//cout<<fun1(x) << endl;
//	return 0;
//}

//void Testin(int& x)//��ֵ����
//{
//	cout << "��ֵ����:" << x << endl;
//}
//
//void Testin(int&& x)//��ֵ����
//{
//	cout << "��ֵ����:" << x << endl;
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
//	temp(x);////����ֵ
//	temp(100);//����ֵ
//
//	return 0;
//}

//void Func(int& x)
//{
//	cout << "��ֵ����" << endl;
//}
//void Func(const int& x)
//{
//	cout << "const ��ֵ����" << endl;
//}
//void Func(int&& x)
//{
//	cout << "��ֵ����" << endl;
//}
//void Func(const int&& x)
//{
//	cout << "const ��ֵ����" << endl;
//}
//template<class T>
//void PerfectForward(T&& t)
//{
//	Func(std::forward<T>(t));
//}
//int main()
//{
//	int a = 10;
//	PerfectForward(a);       //��ֵ
//	PerfectForward(move(a)); //��ֵ
//
//	const int b = 20;
//	PerfectForward(b);       //const ��ֵ
//	PerfectForward(move(b)); //const ��ֵ
//
//	return 0;
//}

//int main()
//{
//
//	//int a = 10;
//	//int b = 2;
//	//auto temp = [](int x, int y)-> bool {return x > y; };
//	//cout << temp(a, b) << endl;
//
//	
//	cout << "��lambda�⽻��ǰ" << ":" << c << ":" << d << endl;
//	auto swaps = [&c,&d]()
//	{
//		cout << "��lambda�ڽ���ǰ" <<":" << c << ":" << d << endl;
//		int tmp = c;
//		c = d;
//		d = tmp;
//		cout << "��lambda�ڽ�����" << ":" << c << ":" << d << endl;
//	};
//	int c = 3, d = 6;
//	swaps();
//	cout << "��lambda�⽻����" << ":" << c << ":" << d << endl;
//	return 0;
//}

//#include<thread>
//int i = 0;
//int main()
//{
////	int i = 0;
//	//thread d1([&i]()
//	thread d1([](int i=0)
//	{
//			for (; i <= 100; i++)
//			{
//				cout << "thread1: " << i << endl;//��lambda���ʽ����������߳�
//			}
//		});
//
//	char ch = 'a';
//	thread d2([&ch]() {
//
//		for (; ch < 'z'; ch++)
//		{
//			cout << "thread2: " << ch << endl;
//		}
//		});
//	d1.join();
//	d2.join();//�����߳�
//
//	return 0;
//}

//#include<thread>
//int main()
//{
//	vector<thread> vd1;
//	int n;
//	cin >> n;
//	vd1.resize(n);
//	int x = 0;
//	int i = 0;//����������ӡ֪�����̼߳�
//	for (auto& e: vd1)
//	{//�̲߳�����ʹ�ÿ������죬������ʹ���ƶ����죬=�ұ�����ֵ���ƶ������߳�e
//		e = thread([&i, x]()mutable {
//			while (x < 100)
//			{
//				cout << "thread" << i << "->" << x << endl;
//				x++;
//			}
//			i++;
//			}
//		
//		);
//	}
//
//	for (auto& e : vd1)
//	{
//		e.join();
//	}
//	return 0;
//}

//class Rate
//{
//public:
//	Rate(double rate) : _rate(rate)
//	{}
//
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//
//private:
//	double _rate;
//};
//
//int main()
//{
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);//�����ʹ�ȥ
//	r1(10000, 2);//���÷º���
//
//	// lambda
//	auto r2 = [=](double monty, int year)->double {return monty * rate * year; };
//	r2(10000, 2);
//
//	auto r3 = [=](double monty, int year)->double {return monty * rate * year; };
//	r3(10000, 2);
//	return 0;
//}

//template<class ...Args>//Args�ɱ�ģ�����args�ɱ������
//void showlist(Args...args)
//{
//	//��ӡ�ж��ٸ�����
//	cout << sizeof...(args) << endl;
//
//}
//
//int main()
//{
//	showlist();
//	showlist(1);
//	showlist(1, 1.1);
//	showlist(1, 1.1, string("xxx"));
//	return 0;
//}

//template<class T, class ...Args>
//void showlist(const T& t)
//{
//	cout << t << endl;//�ݹ���ֹ����
//}
//
//template<class T, class ...Args>
//void showlist(T value, Args ...args)
//{
//	
//	cout << value << " ";
//	showlist(args...);
//}
//template<class ...Args>//Args�ɱ�ģ�����args�ɱ������
//void showlist(Args...args)
//{
//	//��ӡ�ж��ٸ�����
//	cout << sizeof...(args) << endl;
//
//}
//int main()
//{
//	showlist(1);
//	showlist(1,1.1);
//	showlist(1, 1.1, string("xxx"));
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

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str) -- ����" << endl;

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

		// ��������
		string(const string& s)
		{
			cout << "string(const string& s) -- ���" << endl;

			/*string tmp(s._str);
			swap(tmp);*/
			reserve(s._capacity);
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// �ƶ�����
		string(string&& s)
		{
			cout << "string(const string& s) -- �ƶ�����" << endl;

			swap(s);
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string s) -- �ƶ���ֵ" << endl;
			swap(s);

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
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
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
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0; // �������������ʶ��\0
	};

	string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		pjl::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

//int main()
//{
//	// ����������һ�´��п���������ƶ������bit::string����������
//	// ���ǻᷢ����ʵ���Ҳ������emplace_back��ֱ�ӹ����ˣ�push_back���ȹ��죬���ƶ�����
//	//std::list< std::pair<int, pjl::string> > mylist;
//	//pair<int, pjl::string> lt1(10, "find");//�������
//	//mylist.emplace_back(lt1);//��ֵ--���
//	//mylist.emplace_back(20, "find");//��ʼ���б�-��ֵ--ֱ�ӹ���
//	//mylist.emplace_back(make_pair(30, "find"));//��ֵ--ֱ�ӹ���
//
////	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
//	std::list< std::pair<int, pjl::string> > mylist;
//	pair<int, pjl::string> lt2(11, "sort");//�������
//	mylist.push_back(lt2);//��ֵ--���
//	mylist.push_back(make_pair(30, "sort"));//��ֵ--����+�ƶ�����
//	mylist.push_back({ 40, "sort" });//��ֵ--����+�ƶ�����
//	return 0;
//}


//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//	// emplace_back֧�ֿɱ�������õ�����pair����Ĳ������Լ�ȥ��������
//	// ��ô���������ǿ��Կ��������÷��ϣ���push_backûʲô̫�������
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//	return 0;
//}
//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
////չ������
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'T');
//	ShowList(1, 'T', std::string("fortunate"));
//	return 0;
//}

//#include<functional>
//template<class F, class T>//
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)//����
//{
//	return i / 2;
//}
//struct Functor//�º���
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//int main()
//{
//	// ������
//	cout << useF(f, 11.11) << endl;
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber���ʽ
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}

//// ʹ�÷������£�
//#include <functional>
//
//int f(int a, int b)//����
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)//�º���
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	static int plusi(int a, int b)//���о�̬��Ա
//	{
//		return a + b;
//	}
//	int plusd(int a, int b)
//	{
//		return a + b;
//	}
//
//};
//int main()
//{
//	// ������(����ָ��)
//	std::function<int(int, int)> func1 = f;
//	cout << func1(1, 2) << endl;
//	// ��������
//	std::function<int(int, int)> func2 = Functor();
//	cout << func2(1, 2) << endl;
//	// lamber���ʽ
//	std::function<int(int, int)> func3 = [](const int a, const int b)	{return a + b; };
//	cout << func3(1, 2) << endl;
//	// ��ĳ�Ա����
//	std::function<int(int, int)> func4 = &Plus::plusi;
//	cout << func4(1, 2) << endl;
//	std::function<double(Plus, double, double)> func5 = &Plus::plusd;
//	cout << func5(Plus(), 1.1, 2.2) << endl;
//	return 0;
//}

#include <functional>
template<class F, class T>
T useF(F f, T x)
{
	static int count = 0;
	cout << "count:" << ++count << endl;
	cout << "count:" << &count << endl;
	return f(x);
}
double f(double i)
{
	return i / 2;
}
struct Functor
{
	double operator()(double d)
	{
		return d / 3;
	}
};

//int main()
//{
//// ������
//cout << useF(f, 11.11) << endl;
//// ��������
//cout << useF(Functor(), 11.11) << endl;
//// lamber���ʽ
//cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//return 0;
//}

//int main()
//{
//// ������
//std::function<double(double)> func1 = f;
//cout << useF(func1, 11.11) << endl;
//// ��������
//std::function<double(double)> func2 = Functor();
//cout << useF(func2, 11.11) << endl;
//// lamber���ʽ
//std::function<double(double)> func3 = [](double d)->double { return d /
//4; };
//cout << useF(func3, 11.11) << endl;
//return 0;
//}

int Plus(int a, int b)
{
	return a + b;
}

int SubFunc(int a, int b)
{
	return a - b;
}

class Sub
{
public:
	int sub(int a, int b)
	{
		return a - b * x;
	}
private:
	int x = 20;
};

int main()
{
//	//��ʾ�󶨺���plus �����ֱ��ɵ��� func1 �ĵ�һ����������ָ��
//	function<int(int, int)>fun1 = bind(Plus, placeholders::_1, placeholders::_2);
//	cout << fun1(2, 3) << endl;

	//// ����������˳��
	//function<int(int, int)>fun2 = bind(SubFunc, placeholders::_2, placeholders::_1);
	//cout << fun2(7, 4) << endl;
//	
	// �󶨹̶�����
	function<int(Sub, int, int)> fun3 = &Sub::sub;
cout<<	"ԭ�ȵİ�װ�����ã�" << fun3(Sub(), 10, 13) << endl;

function<int(int, int)>fun4 = bind(&Sub::sub, Sub(), placeholders::_1, placeholders::_2);

cout << "���ڵ�bind�󶨹̶��������ã�" << fun4(10, 13) << endl;

	return 0;
}