#include<iostream>
#include<vector>

using namespace std;

bool twofind(vector<int>& path,int x,int n,int& start,int& end)
{
	int mid = (start + end) / 2;
	if (x <= mid)//Ҫ�µ���������
	{
		if (x > n)
		{
			cout << "��С��" << endl;
			end = mid+1;
			cout << "��Χ�ǣ�" << start << ":" << end << endl;
			return false;
		}
		else if (x < n)
		{
			cout << "�´���" << endl;
			end = mid + 1;
			cout << "��Χ�ǣ�" << start << ":" << end << endl;
			return false;
		}
		else
		{
			cout << "�¶���" << endl;
			return true;
		}
	}
	else//x>mid--���Ұ��
	{
		if (x > n)
		{
			cout << "��С��" << endl;
			start = mid;
			cout << "��Χ�ǣ�" << start << ":" << end << endl;
			return false;
		}
		else if (x < n)
		{
			cout << "�´���" << endl;
			start = mid;
			cout << "��Χ�ǣ�" << start << ":" << end << endl;
			return false;
		}
		else
		{
			cout << "�¶���" << endl;
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
	int x = 25;//Ҫ�µ���
	int n = 0;//�������
	int start = 0;
	int end = path.size() - 1;
	cout << "�����֣�" << endl;
	cin >> n;
	while (!twofind(path, x, n, start, end))
	{
		cin >> n;
	}
	return 0;

}