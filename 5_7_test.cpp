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
			:_size(strlen(str))//���������Ķ����ǿն���ʱ�������ָ���ǿ�ָ�룬���ʿ�ָ��ΪԽ�籨��
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
		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}
		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
			swap(s);
			return *this;
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) --��ֵ���أ�����Ҳ�õ����" << endl;
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
		size_t _capacity=0; // �������������ʶ��\0
	};
}

class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	Person(Person&& p) = default;//ǿ������һ��Ĭ�ϵ��ƶ�����
	Person(const Person& p)//��������
	:_name(p._name)
    ,_age(p._age)
{}

	//Person(Person&& p)
	//	:_name(std::forward<pjl::string>(p._name))//������������˻�Ϊ��ֵ�����ˣ�������Ҫ����ת��
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

int main()
{

	int a = 10;
	int b = 2;
	auto temp = [](int x, int y) {return x > y; };
	cout << temp(a, b) << endl;
	return 0;
}