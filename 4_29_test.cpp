#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
//#include"4_19_HashTable.h"
//#include"4_19_Unordered_Set.h"
//int main()
//{
//	string str[] = { "string","sort","find" };
//	pjl::Unordered_Set<string> wordset;
//	for (auto& e : str)
//	{
//		wordset.Insert(e);
//	}
//	
//	string s1 = "s";
// auto it1 = wordset.Find(s1);
// //cout << *it1 << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 2;
//	//auto comp = [](int x, int y) {return x > y; };
//	//auto comp = [=]() {return a > b; };//ͨ����׽�б��ȡ����;=:��׽����ı�����ֻ��׽���ģ�
//	//cout << comp() << endl;
//	//cout << comp(a, b) << endl;
//	//auto swap1 = [&a, &b]()//&val����׽�������������
//	auto swap1=[&]()//&����׽�������б���������
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};//������û�����ɹ�
//
//	swap1();
//
//	return 0;
//}
//void ShowList()
//{
//	cout << endl;
//}
//
//template<class T,class ...Args>
//void ShowList(T value, Args... args)//�ݹ�չ��������
//{
//	cout << value << " ";
//	ShowList(args...);
//}
template<class T>
void PrintArgs(T value)
{
	cout << value << " ";
}

template<class ...Args>
void ShowList(Args ...args)
{
	int arr[] = { (PrintArgs(args),0)... };//���ű��ʽչ����������arr[]���ܷ��䳣����СΪ0������
	cout << endl;
}

int main()
{
	//ShowList();
	ShowList(1);
	ShowList(1,'a');
	ShowList(1,'a',"������");
	
}