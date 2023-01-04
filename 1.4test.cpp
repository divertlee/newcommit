#include<iostream>
#include<deque>
#include<vector>
#include<string.h>
using namespace std;
#include"STack.h"
#include"Queue.h"
int main()
{
	//ljp::STack<int, vector<int>> ST;
	xxx::STack<int> ST;

	ST.push(1);
	ST.push(2);
	ST.push(3);
	ST.push(4);
while(!ST.empty())
	{
		cout << ST.top() << " ";
		ST.pop();
	}
cout << endl;
//xxp:queue<int> Qe;
//	Qe.push(10);
//	Qe.push(20);
//	Qe.push(30);
//	Qe.push(40);
//	while (!Qe.empty())
//	{
//		cout << Qe.front() << " ";
//		Qe.pop();
//	}
//	cout << endl;
return 0;
}


//int main()
//{
//	deque<int> dq1;
//	dq1.push_back(1);
//	dq1.push_back(2);
//	dq1.push_back(3);
//	dq1.push_back(4);
//	dq1.push_back(5);
//	dq1.push_front(10);
//	dq1.push_front(20);
//	dq1.push_front(30);
//	for (auto e : dq1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}