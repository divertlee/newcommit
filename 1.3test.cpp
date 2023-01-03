#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int> dq1;
	dq1.push_back(1);
	dq1.push_back(2);
	dq1.push_back(3);
	dq1.push_back(4);
	dq1.push_back(5);
	dq1.push_front(10);
	dq1.push_front(20);
	dq1.push_front(30);
	for (auto e : dq1)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}