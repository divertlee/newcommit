#include<iostream>
using namespace std;
#include"Iterator.h"
//#include"list.h"
#include"vector.h"

int main()
{
	Vect::vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	Vect::vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	Vect::vector<int>::reverse_iterator it2 = v1.rbegin();
	while (it2 != v1.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;


		return 0;
}
//int main()
//{
//	ljp::list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	lt1.push_back(5);
//
//	ljp::list<int>::iterator it1 = lt1.begin();
//	while (it1 != lt1.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//	ljp::list<int>::reverse_iterator it2 = lt1.rbegin();
//	while (it2 != lt1.rend())
//	{
//	
//		cout << *it2 << " ";
//		it2--;
//
//	}
//	cout << endl;
//	return 0;
//}