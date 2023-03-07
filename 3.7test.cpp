#include<iostream>
#include<string.h>
using namespace std;

class father
{public:
	static int password;
protected:
	int _money = 1000;
};
 int father:: password = 2;
class son :public father
{
protected:
	int money = 100;
};
int main()
{
	father fa;
	son s;
	fa.password++;
	s.password++;
	cout << "fa的密码 " << fa.password <<"取地址：" << &fa.password << endl;
	cout << "s的密码 " << s.password << "取地址：" << &s.password << endl;
	
	return 0;
}
//class laowang;
//class father
//{
//	friend void laowang( son&s);
//protected:
//	int _money = 1000;
//};
//
//class son :public father
//{
//	friend void laowang(son& s);
//protected:
//	int money = 100;
//};
//void laowang( son& s)
//{
//	fa._money -= 900;
//	
//	
// }
//int main()
//{
//	father fa;
//
//	son s;
//	
//	laowang(s);
//	return 0;
//}
//class A { 
//private:int a;
//friend class C;
//};
//class B :public A { 
//  private:int b;
//}; 
//
//class C{
//public:
//	int f(A a) { return a.a; }
//};
//	  //正确，因为C是A的友元，可以访问其任何成员
//	  int f2(B b) { return b.a; }; //正确，因为B继承了A，所以B中也包含了A的a
//	 // int f3(B b) { return b.b; }; //错误，C不是B的友元，不能访问其私有成员};


//class Student;//类友元要先声明类，防止下面的友元类不认识
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//父类的友元函数
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	int _flag;//子类的公有成员
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{   cout << p._name << endl;
//	cout << s._stuNum << endl;}
//int main()
//{   Person p;
//	Student s;
//	Display(p, s);
//	return 0;}


//class Person
//{
//public:
//	friend void Display(const Person& p, const student& s);//友元函数声明
//	Person(const char* name="Peter")//基类的构造函数
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)//基类的拷贝构造函数
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)//基类的赋值重载函数
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()//基类的析构函数
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class student :public Person
//{
//public:
//	friend void Display(const Person& p, const student& s);//友元函数声明
//	student(const char* name,int age)//派生类的构造函数
//	:Person(name)//显示调用基类的构造函数,不使用初始化列表等同于不把在main函数传过来的值传去给基类来初始化，则用基类的缺省值
//	{
//
//		cout << "student()" << endl;
//	}
//	student(const student& s)//派生类的拷贝构造函数
//		:Person(s)
//		,_age(s._age)
//	{
//		cout << "student(const & s)" << endl;
//	}
//
//	student& operator=(const student& s)//派生类的赋值重载函数
//	
//	{
//		cout << "student& operator=(const student&s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_age = s._age;
//		}
//		return *this;
//	}
//	~student()//派生类的析构函数
//	{
//		//Person::~Person();
//		cout << "~student()" << endl;
//	}
//protected:
//	int _age;//年龄
//};
//void Display(const Person& p, const student& s)
//{
//	cout << p._name << endl;
//	cout << s._age << endl;
//}
//int main()
//{ 
//	Person p;
//	student s;
//	Display(p, s);
////	student s1("tt",19);
////	s1 = s;
//	return 0;
//}

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
//class Student :public Person
//{
//protected:
//	int studnum;//学号
//};
//
//class Teacher :public Person
//{
//protected:
//	int _teachnum;//教师学号
//};
//
//int main()
//{
//	Student st;
//	Teacher te;
//	st.Print();
//	te.Print();
//	return 0;
//}}
