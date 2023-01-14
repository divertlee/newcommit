#include<iostream>
#include<array>
using namespace std;

class Person
{
public:
	Person(const char* name)
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person & p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};


class Student : public Person
{
public:
	Student( const char* name, int num)
		: Person(name)
		 ,_num(num)
	{}

	Student(const Student& s)
: Person(s)
, _num(s ._num)
{
cout<<"Student(const Student& s)" <<endl ;
}
Student& operator = (const Student& s )
{
cout<<"Student& operator= (const Student& s)"<< endl;
if (this != &s)
{
Person::operator =(s);//����Ҫ��ʾ�����򡪻����operator=���������operator=���ɺ������أ�����Ҫ��ʾ������
_num = s ._num;
}
return *this ;
}

~Student()
{
	cout << "~Student()" << endl;
}
protected:
	int _num; //ѧ��
};
int main()
{
	Student s1("zs", 18);
	Student s3("pjl", 19);
	s3 = s1;
	return 0;
}
/*Student s2(s1);*/
//class A
//{
//public:
//	void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//};
//class B: public A
//{
//public:
//	void fun(int)
//	{
//		cout << "B::fun(int)" << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.A::fun();
//	return 0;
//}

//void test()
//{
//	B b;
//	b.A::fun();
//}
// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���
//Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿�
//�Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�
//struct Teacher:public Person
//{
//protected:
//	int _teachnum;//��ʦѧ��
//};
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name: " << _name << endl;
//		cout << "age: " << _age << endl;
//	}
//private:
//	string _name = "pjl";
//	int _age = 18;
//};
//class Student: public Person
//{
//public:	
//protected:
//	int studnum;//ѧ��
//};
//int main()
//{
//	Student st;
//	Person per1 = st;
//	Person& per2 = st;
//	Person* per3 = &st;
//	
//}

//int main()
//{
//	Student st;
//	Teacher te;
//	//st.Print();
//	te.Print();
//	return 0;
//}

//int main()
//{
//	array<int,5> a1;
//	int arr[5];
//	return 0;
//}

//template<class T,size_t N>
//class Array
//{
//public:
//	void Print()
//	{
//		cout <<"���ٵ�Array��С��" << N << endl;
//	}
//private:
//	T _a[N];
//};
//
//int main()
//{
//	Array<int,100> n1;
//	n1.Print();
//	Array<int, 1000> n2;
//	n2.Print();
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Date<class T,class T>" << endl;
//	}
//};
//template<>
//class Data<int,char>
//{
//public:
//	Data()
//	{
//		cout << "ȫ�ػ�" << "Date<int,char>" << endl;
//	}
//};
//template<class T>
//class Data<T, double*>
//{
//public:
//	Data()
//	{
//		cout << "�����ػ�" << "Date<int,double*>" << endl;
//	}
//};
//
//template<class T1,class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data()
//	{
//		cout << "������һ������" << "Date<T1&,T2&>" << endl;
//	}
//};
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int, char>d2;//ȫ�ػ�
//	Data<int, double*>d3;//ƫ�ػ�-�����ػ�
//	Data<int&, double&>d4;//ƫ�ػ�-������һ������
//	return 0;
//}

//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	//cout << Less(1, 2) << endl;
//	Date d1(2022, 1, 1);
//	Date d2(2022, 1, 14);
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl;
//	return 0;
//}

