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
	cout << "fa������ " << fa.password <<"ȡ��ַ��" << &fa.password << endl;
	cout << "s������ " << s.password << "ȡ��ַ��" << &s.password << endl;
	
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
//	  //��ȷ����ΪC��A����Ԫ�����Է������κγ�Ա
//	  int f2(B b) { return b.a; }; //��ȷ����ΪB�̳���A������B��Ҳ������A��a
//	 // int f3(B b) { return b.b; }; //����C����B����Ԫ�����ܷ�����˽�г�Ա};


//class Student;//����ԪҪ�������࣬��ֹ�������Ԫ�಻��ʶ
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);//�������Ԫ����
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//public:
//	int _flag;//����Ĺ��г�Ա
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
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
//	friend void Display(const Person& p, const student& s);//��Ԫ��������
//	Person(const char* name="Peter")//����Ĺ��캯��
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)//����Ŀ������캯��
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)//����ĸ�ֵ���غ���
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()//�������������
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//class student :public Person
//{
//public:
//	friend void Display(const Person& p, const student& s);//��Ԫ��������
//	student(const char* name,int age)//������Ĺ��캯��
//	:Person(name)//��ʾ���û���Ĺ��캯��,��ʹ�ó�ʼ���б��ͬ�ڲ�����main������������ֵ��ȥ����������ʼ�������û����ȱʡֵ
//	{
//
//		cout << "student()" << endl;
//	}
//	student(const student& s)//������Ŀ������캯��
//		:Person(s)
//		,_age(s._age)
//	{
//		cout << "student(const & s)" << endl;
//	}
//
//	student& operator=(const student& s)//������ĸ�ֵ���غ���
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
//	~student()//���������������
//	{
//		//Person::~Person();
//		cout << "~student()" << endl;
//	}
//protected:
//	int _age;//����
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
//	int studnum;//ѧ��
//};
//
//class Teacher :public Person
//{
//protected:
//	int _teachnum;//��ʦѧ��
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
