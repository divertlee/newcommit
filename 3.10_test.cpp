#include<iostream>
using namespace std;


//93.��ԭip��ַ

//class Solution {
//public:
//    vector<string> ret;
//
//    void recall(string& s, int pointnum, int startindex)
//    {
//        if (pointnum == 3)
//        {
//            if (isvalid(s, startindex, s.size() - 1))//����������ﵽ3ʱ����ʱ�жϵ��ĶΣ���ȷ����vector
//            {
//                ret.push_back(s);
//
//            }
//            return;
//        }
//
//        for (int i = startindex; i < s.size(); i++)
//        {
//            if (isvalid(s, startindex, i))//���ж�-�Ϸ��Ż���
//            {
//                s.insert(s.begin() + i + 1, '.');//�ӵ�
//                pointnum++;
//                recall(s, pointnum, i + 2);
//                pointnum--;
//                s.erase(s.begin() + i + 1);
//            }
//            else {
//                break;
//            }
//        }
//
//
//
//
//    }
//    //�����һλΪ0���������֡���Ӵ���255��Ϊfalse
//    bool isvalid(const string& s, int begin, int end)
//    {
//        if (begin > end)
//        {
//            return false;
//        }
//        if (s[begin] == '0' && begin != end)
//        {
//            return false;
//        }
//        int num = 0;
//        for (int i = begin; i <= end; i++)
//        {
//
//            if (s[i] < '0' || s[i]>'9')
//            {
//                return false;//��������
//            }
//            num = 10 * num + (s[i] - '0');
//            if (num > 255)
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    vector<string> restoreIpAddresses(string s) {
//        ret.clear();
//        if (s.size() < 4 || s.size() > 12)
//        {
//            return ret;
//        }
//        recall(s, 0, 0);
//        return ret;
//    }
//};




//class A
//{};
//class B: public A
//{};
//class Person {
//public:
//	virtual A* BuyTicket()//����ֵ������Person
//	{   cout << "��Ʊ-ȫ��" << endl;
//		return nullptr;}};
//class Student : public Person {
//public:
//	virtual B* BuyTicket()//����ֵ������Student
//	{   cout << "��Ʊ-���" << endl;
//		return nullptr;}};
//void fun(Person* p)
//{p->BuyTicket();}
//int main()
//{   Person pe;
//	Student st;
//	fun(&pe);
//	fun(&st);
//	return 0;
//}
//class Person {
//public:
//	virtual  ~Person()
//	{cout << "~Person()" << endl;
//	delete[] _p;}
//protected:
//	int *_p = new int[10];
//};
//class Student : public Person {
//public:
//	~Student()
//	{   cout << "~Student()" << endl;
//		delete[] _s;}
//protected:
//	int* _s = new int[20];};
//int main()
//{
//	/*Person per;
//	Student st;*/
//	Person* ptr1 = new Person;
//	Person* ptr2 = new Student;
//	delete ptr1;
//	delete ptr2;
//	return 0;
//}
//
//class fans
//{
//public:
//	/*fans()
//	{	cout << "fans-waitwaitwait" << endl;}*/
//	virtual void Drive() = 0;
//};
//class ikun :public fans
//{
//public:
//	/*ikun()
//	{
//		cout << "ikun-jntm" << endl;}*/
//	virtual void Drive() { cout<<"ikun-jntm" << endl; }
//
//};
//int main()
//{
//	
//	ikun* ptr = new ikun;
//	ptr->Drive();
//	
//	return 0;
//}

 
//class A
//{
//public:
//	virtual void dave1(){}
//	virtual void dave2(){}
//	virtual void dave3(){}
//private:
//	
//	int _a;
//	char _b;
//};
//
//int main()
//{
//	A aa;
//	cout << "�����麯������Ĵ�С��" << sizeof(aa) << endl;
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void Func1()
//	{
//		cout << "A::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "A::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "A::Func3()" << endl;
//	}
//private:
//	int _a = 1;
//};
//class B : public A
//{
//public:
//	virtual void Func1()
//	{
//		cout << "B::Func1()" << endl;
//	}
//private:
//	int _b = 2;
//};
//
//int main()
//{
//	/*int a = 0;
//	cout << "ջ:" << &a << endl;
//
//	int* p1 = new int;
//	cout << "��:" << p1 << endl;
//
//	const char* str = "hello world";
//	cout << "�����/������:" << (void*)str << endl;
//
//	static int b = 0;
//	cout << "��̬��/���ݶ�:" << &b << endl;*/
//
//	A aa;
//	cout << "���:" << (void*)*((int*)&aa) << endl;
//
//	A aa1;
//	cout << "���:" << (void*)*((int*)&aa1) << endl;
//
//	A aa2;
//	cout << "���:" << (void*)*((int*)&aa2) << endl;
//
//	/*Base* ptr1 = &be;
//	int* ptr2 = (int*)ptr1;
//	printf("���:%p\n", *ptr2);
//
//	Derive de;
//	cout << "���:" << (void*)*((int*)&de) << endl;*/
//
//	/*Base b1;
//	Base b2;*/
//
//
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	printf("ջ��%p\n", &a);
//	int* p1 = new int;
//	printf("�ѣ�%p\n", p1);
//	const char* str = "hello world";
//	printf("����Σ�%p\n", &str);
//	static int b = 0;
//	printf("��������%p\n", &b);
//	A aa;
//	printf("���%p\n", &aa);
//	return 0;
//}
//int main()
//{
//	//cout << sizeof(A) << endl;
//	A a;
//	B b;
//	//��ͨ���ã�fun3���Ƕ�̬����ͨ����---����ʱ/��̬ ��
//	A* ptr = &a;
//	ptr->Func3();
//	ptr = &b;
//	ptr->Func3();
//	//��̬���ã�fun1�Ƕ�̬������ʱ/��̬ ��
//	ptr = &a;
//	ptr->Func1();
//	ptr = &b;
//	ptr->Func1();
//	return 0;
//}

