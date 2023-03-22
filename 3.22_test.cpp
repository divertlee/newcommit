#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//换链表来做换链表为O(nlog(N),N)
//class Solution {
//public:
//	static bool cmp(const vector<int>& a, const vector<int>& b)
//	{
//		if (a[0] == b[0]) return a[1] < b[1];//身高相同，key值少的排前面
//		return a[0] > b[0];//身高高的排前面
//	}
//
//	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//		sort(people.begin(), people.end(), cmp);
//		list<vector<int>> tmp;
//		for (int i = 0; i < people.size(); i++)// 把key相同的身高低的插入到key的位置；此时顺序是高的靠前，那么按顺序遍历矮的就会插入到高前面
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

//vector底层是数组，插入时复杂度为O(Nlog(N)+N^2)，
//class Solution {
//public:
//	static bool cmp(const vector<int>& a, const vector<int>& b)
//	{
//		if (a[0] == b[0]) return a[1] < b[1];//身高相同，key值少的排前面
//		return a[0] > b[0];//身高高的排前面
//	}
//
//	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//		sort(people.begin(), people.end(), cmp);
//		vector<vector<int>> ret;
//		for (int i = 0; i < people.size(); i++)// 把key相同的身高低的插入到key的位置；此时顺序是高的靠前，那么按顺序遍历矮的就会插入到高前面
//		{
//			int pos = people[i][1];
//			ret.insert(ret.begin() + pos, people[i]);
//		}
//		return ret;
//	}
//};
//柠檬水找零
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
//				else if (five > 0)//10快没了
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
//洗牌！
int main()
{
	int n = 0;
	cin >> n;//要洗多少组
	while (n--)
	{
		int num = 0;
		int k = 0;//要洗几次
		cin >> num>>k;//一组多少对
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
				left[i] = orig[i];//左手拿前n张--0 1 2
			}
			for (int j = 0; j < num; j++)
			{
				right[j] = orig[num + j];//右手拿后n张 3 4 5
			}
			vector<int>::reverse_iterator rit = right.rbegin();
			vector<int>::reverse_iterator lit = left.rbegin();
			for (int i = 0; i < 2 * num && rit != right.rend() && lit != left.rend(); i += 2)
			{//5 2 4 1 3 0 
				orig[i] = *rit;//先放右手一张
				orig[i + 1] = *lit;
				rit++;
				lit++;
			}
			if (k != 0)//最后一次不反转让牌按顺序摆放，然后从后往前读
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
	}//洗完一组牌并打印后从新输入牌再次循环
	return 0;
}