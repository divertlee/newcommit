#include<iostream>
#include<list>
using namespace std;

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

template<class T1,class T2>
void multis(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;//����retû�н��շ���ֵ�����Բ�����auto���Ƶ�ret�����ͣ�������ͨ��decltype���Ƶ�
	cout <<"ret������Ϊ��" << typeid(ret).name() << endl;
}

int main()
{
	int x = 6;
	double y = 2.66;
	multis(x, y);

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



	return 0;
}