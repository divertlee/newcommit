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

template<class T>
void fun1(T& object)//����Ͳ���
{
	//...... �����object
}
template<class T>
const T& fun2(const T& object)
{
	//...... �����object���в���
	return object;//��ֵ����

}
template<class T>
const  T& fun3(const T& object)
{
	T ret;
	//...... �����ret���в���
	return ret;//��������������ret���������ڽ����������÷��ظ������ǲ㣬��ʱ�ٷ��ʲ���ret����Խ������ˣ�

}

int main()
{
	vector<int>v;
	fun1(v);
	fun2(v);
	fun3(v);
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




	return 0;
}