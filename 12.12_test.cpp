#pragma once

#include<iostream>
#include<list>
#include<vector>
#include<time.h>
#include<algorithm>
#include<assert.h>
using namespace std;
#include"list.h"
//#include"vector.h"






//void test_op()
//{
//	srand(time(0));
//	const int N = 1000000;
//	vector<int> v;
//	v.reserve(N);
//
//	list<int> lt1;
////	list<int> lt2;
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand();
//		//v.push_back(e);
//		lt1.push_back(e);
//		//lt2.push_back(e);
//	}
//
//	// 拷贝到vector排序，排完以后再拷贝回来
//	int begin1 = clock();
//	lt1.sort();
//	int end1 = clock();
//	/*for (auto e : lt1)
//	{
//		v.push_back(e);
//	}*/
//	//sort(v.begin(), v.end());
//	//size_t i = 0;
//	/*for (auto& e : lt1)
//	{
//		e = v[i++];
//	}*/
//	//int end1 = clock();
//	
//	for (int i = 0; i < N; ++i)
//	{
//		auto e = rand();
//	
//		v.push_back(e);
//		
//	}
//	int begin2 = clock();
//	// sort(lt.begin(), lt.end());
//	//lt2.sort();
//	sort(v.begin(), v.end());
//	int end2 = clock();
//
//	printf("list sort:%d\n", end1 - begin1);
//	printf("vector sort:%d\n", end2 - begin2);
//}

//void testlt1()
//{
//listnode::	list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	
//
//}
//
//	void testv()
//	{
//		Vect::vector<int> v;
//		v.push_back(1);
//		v.push_back(2);
//		v.push_back(3);
//		v.push_back(4);
//		v.push_back(5);
//
//		Vect:: vector<int>::iterator vit1 = v.begin();
//for(size_t i=0;i<v.size();i++)
//{
//			cout << *vit1 << " ";
//			++vit1;
//		}
//		cout << endl;
//		for (auto e : v)
//		{
//			cout << e << " ";
//		}
//		cout << endl;
//	}

//void test2()
//{
//	listnode::list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	listnode::list<int> lt2(lt1);
//	//lt2.push_back(12);
//	//lt2.push_back(12);
//	//lt2.push_back(12);
//
//	//lt2 = lt1;
//	
//	//lt1.push_back(5);
//	//lt1.push_front(10);
//	//lt1.push_front(20);
//	//lt1.push_front(30);
//	//lt1.push_front(40);
//	//lt1.pop_back();
//	//lt1.pop_back();
//	//lt1.pop_front();
//	//lt1.pop_front();
//
//	for (auto e : lt2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	//lt1.clear();
//
//	/*for (auto e : lt1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;*/
//
//	//listnode::list<int>::iterator it1 = find(lt1.begin(), lt1.end(), 3);
//	//if (it1 != lt1.end())
//	//{
//	//	lt1.erase(it1);
//	//}
//
//	//(*it1) += 10;
//
//	//for (auto e : lt1)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//}

//void test3() {
//	listnode::list<int> lt1;
//	lt1.push_back(1);
//	lt1.push_back(2);
//	lt1.push_back(3);
//	lt1.push_back(4);
//
//	for (auto e : lt1)
//	{
//		cout << e << " ";
//
//	}
//	cout << endl;
//	/*listnode::list<int>::iterator it1 = find(lt1.begin(), lt1.end(), 3);
//	if (it1 != lt1.end())
//	{
//		cout << *it1 << endl;
//		it1++;
//		cout << *it1 << endl;
//
//	}*/
//	
//}

void test4()
{
	listnode:: list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	for (auto e : lt1)
	{
		cout << e << " ";

	}
	cout << endl;

	listnode::list<int> lt2(lt1);
	
	for (auto e : lt2)
	{
		cout << e << " ";

	}
	cout << endl;
}

int main()
{
	test4();

	//test3();
	//test2();
	//test1();
	//test_op();
	//listnode::testlist1();
	//testv();
	

	return 0;
}