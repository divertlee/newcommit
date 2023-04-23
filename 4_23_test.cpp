#include<iostream>
#include<vector>

using namespace std;

bool twofind(vector<int>& path,int x,int n,int& start,int& end)
{
	int mid = (start + end) / 2;
	if (x <= mid)//要猜的数在左半边
	{
		if (x > n)
		{
			cout << "猜小了" << endl;
			end = mid+1;
			cout << "范围是：" << start << ":" << end << endl;
			return false;
		}
		else if (x < n)
		{
			cout << "猜大了" << endl;
			end = mid + 1;
			cout << "范围是：" << start << ":" << end << endl;
			return false;
		}
		else
		{
			cout << "猜对了" << endl;
			return true;
		}
	}
	else//x>mid--在右半边
	{
		if (x > n)
		{
			cout << "猜小了" << endl;
			start = mid;
			cout << "范围是：" << start << ":" << end << endl;
			return false;
		}
		else if (x < n)
		{
			cout << "猜大了" << endl;
			start = mid;
			cout << "范围是：" << start << ":" << end << endl;
			return false;
		}
		else
		{
			cout << "猜对了" << endl;
			return true;
		}
	}
	

}

int main()
{
	vector<int> path;
	path.resize(100);
	for (int i = 0; i < 100; i++) {
		path[i] = i;
	}
	int x = 25;//要猜的数
	int n = 0;//输入的数
	int start = 0;
	int end = path.size() - 1;
	cout << "猜数字：" << endl;
	cin >> n;
	while (!twofind(path, x, n, start, end))
	{
		cin >> n;
	}
	return 0;

}