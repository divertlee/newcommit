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
//	decltype(t1 * t2) ret;//���ݱ��������Ƶ����ʽ������
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
	//int& pxy = x + y;//��ֵ���ò���---x��y��һ��������û�е�ַ--���ܻ�ȡ��ַ
	double&& rxy = x + y;//��ֵ����
	//int& ten = 10;//10��һ�����������ܻ�ȡ��ַ--������ֵ����
	int&& rten = 10;//��ֵ����
	//int& pmin = getmin(x, y);//�����ķ���ֵ���˺���������ͱ�������---���ܻ�ȡ��ַ--������ֵ����
	int&& rmin = getmin(x, y);//����������ֵ����
	/*F(1, 3);
	F(2.22, 4);*/
	const int& pmin = getmin(x, y);//const��ֵ������������ֵ
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
//	Date d1(2002, 11, 28);//���ù��캯��
//	// C++11֧�ֵ��б��ʼ�����������ù��캯����ʼ��
//	Date d2{ 2002,11,27 };
//	Date d3 = { 2001,1,1 };
//	auto il = { 1,2,3 };
//	cout << typeid(il).name() << endl;
//	map<string, string> stt{ {"sort","����"},{"bloomfilter","��¡������"} };
//	//int x1 = 2;
//	//int x2{ 2 };
//	//Point p1;
//	//p1._x = 1;
//	//p1._y = 2;
//	//Point p2= { 1,2 };//������ͬ
//	//int arr1[] = { 1,2,3,4,5 };
//	//int arr2[]{ 1,2,3,4,5,6 };//������ͬ
//	//return 0;
//}