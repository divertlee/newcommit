#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//����������������ΪO(nlog(N),N)
//class Solution {
//public:
//	static bool cmp(const vector<int>& a, const vector<int>& b)
//	{
//		if (a[0] == b[0]) return a[1] < b[1];//�����ͬ��keyֵ�ٵ���ǰ��
//		return a[0] > b[0];//��߸ߵ���ǰ��
//	}
//
//	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//		sort(people.begin(), people.end(), cmp);
//		list<vector<int>> tmp;
//		for (int i = 0; i < people.size(); i++)// ��key��ͬ����ߵ͵Ĳ��뵽key��λ�ã���ʱ˳���ǸߵĿ�ǰ����ô��˳��������ľͻ���뵽��ǰ��
//		{
//			int pos = people[i][1];
//			std::list<vector<int>>::iterator it = tmp.begin();
//			while (pos--)
//			{
//				it++;
//			}
//			tmp.insert(it, people[i]);
//		}
//
//		return vector<vector<int>>(tmp.begin(), tmp.end());
//	}
//};

//vector�ײ������飬����ʱ���Ӷ�ΪO(Nlog(N)+N^2)��
//class Solution {
//public:
//	static bool cmp(const vector<int>& a, const vector<int>& b)
//	{
//		if (a[0] == b[0]) return a[1] < b[1];//�����ͬ��keyֵ�ٵ���ǰ��
//		return a[0] > b[0];//��߸ߵ���ǰ��
//	}
//
//	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//		sort(people.begin(), people.end(), cmp);
//		vector<vector<int>> ret;
//		for (int i = 0; i < people.size(); i++)// ��key��ͬ����ߵ͵Ĳ��뵽key��λ�ã���ʱ˳���ǸߵĿ�ǰ����ô��˳��������ľͻ���뵽��ǰ��
//		{
//			int pos = people[i][1];
//			ret.insert(ret.begin() + pos, people[i]);
//		}
//		return ret;
//	}
//};
//����ˮ����
//class Solution {
//public:
//	bool lemonadeChange(vector<int>& bills) {
//		int five = 0;
//		int ten = 0;
//		for (int i = 0; i < bills.size(); i++)
//		{
//			if (bills[i] == 5)
//			{
//				five++;
//			}
//			else if (bills[i] == 10)
//			{
//				if (five == 0)
//				{
//					return false;
//				}
//				ten++;
//				five--;
//			}
//			else if (bills[i] == 20)
//			{
//				if (ten > 0 && five > 0)
//				{
//					ten--;
//					five--;
//				}
//				else if (five > 0)//10��û��
//				{
//					if (five < 3)
//					{
//						return false;
//					}
//					five -= 3;
//				}
//				else
//				{
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//};
//ϴ�ƣ�
int main()
{
	int n = 0;
	cin >> n;//Ҫϴ������
	while (n--)
	{
		int num = 0;
		int k = 0;//Ҫϴ����
		cin >> num>>k;//һ����ٶ�
		vector<int> orig(2*num,0);
		for (int i = 0; i < 2 * num; i++)
		{
			cin >> orig[i];
		}
		
		vector<int> left(num,0);
		vector<int> right(num,0);
		while (k--)
		{
			for (int i = 0; i < num; i++)
			{
				left[i] = orig[i];//������ǰn��--0 1 2
			}
			for (int j = 0; j < num; j++)
			{
				right[j] = orig[num + j];//�����ú�n�� 3 4 5
			}
			vector<int>::reverse_iterator rit = right.rbegin();
			vector<int>::reverse_iterator lit = left.rbegin();
			for (int i = 0; i < 2 * num && rit != right.rend() && lit != left.rend(); i += 2)
			{//5 2 4 1 3 0 
				orig[i] = *rit;//�ȷ�����һ��
				orig[i + 1] = *lit;
				rit++;
				lit++;
			}
			if (k != 0)//���һ�β���ת���ư�˳��ڷţ�Ȼ��Ӻ���ǰ��
			{
				reverse(orig.begin(), orig.end());
			}
		}

		for (int i = 2*num-1; i >=0; i--)
		{
			if (i == 0)
			{
				cout << orig[i];
				break;
			}
			cout << orig[i];
			cout << " ";
		}
		cout << endl;	
	}//ϴ��һ���Ʋ���ӡ������������ٴ�ѭ��
	return 0;
}