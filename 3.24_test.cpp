#pragma once
#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<map>
using namespace std;

//349. 两个数组的交集
//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序
// 双指针法：先排序；当两个元素相等时，插入set（set可以去重），不然的话小的先走，后面可以遇到对面此时较大的；当其中一个走到end就结束
//class Solution {
//public:
//	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//		set<int> st;
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		auto it1 = nums1.begin();
//		auto it2 = nums2.begin();
//		while (it1 != nums1.end() && it2 != nums2.end())
//		{
//			if (*it1 == *it2)
//			{
//				st.insert(*it1);
//				it1++;
//				it2++;
//			}
//			else if (*it1 > *it2)
//			{
//				it2++;
//			}
//			else
//			{
//				it1++;
//			}
//		}
//		vector<int>ret;
//		for (auto e : st)
//		{
//			ret.push_back(e);
//		}
//		return ret;
//	}
//};
//692.前k个高频单词
// 给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序。
//class Solution {
//public:
//	static bool cmp(const pair<int, string>& a, const pair<int, string>& b)
//	{
//		return a.first > b.first;
//	}
//	vector<string> topKFrequent(vector<string>& words, int k) {
//		map<string, int> mp;
//		for (auto e : words)
//		{
//			mp[e]++;
//		}//插入完了
//
//		vector<pair<int, string>> v;
//		for (auto e : mp)
//		{
//			v.push_back(make_pair(e.second, e.first));
//		}
//		stable_sort(v.begin(), v.end(), cmp);  //排序---稳定排序，排序的稳定性stable_sort---归并排序；sort---快排
//
//		vector<string> ret;
//		for (int i = 0; i < k; i++)
//		{
//			ret.push_back(v[i].second);
//		}
//		return ret;
//
//	}
//};


//int main()
//{
//
//	 map<string, string> dict;
//	dict.insert(pair<string, string>("蔡徐坤", "cxk"));
//	dict.insert(pair<string, string>("小黑子", "ikun"));
//	dict.insert(make_pair("爆炸", "boom"));
//	dict.insert(make_pair("篮球", "basketbll"));
//	for (auto e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	dict.insert(make_pair("蔡徐坤","哎呦你干嘛"));//插入失败，key相同且key与value一一对应
//	cout << dict["蔡徐坤"] << endl;//查找
//	dict["蔡徐坤"] = "caixukun";//修改
//	cout << dict["蔡徐坤"] << endl;//查找



	/*string arr[] = { "草莓", "冬瓜", "香蕉", "草莓", "草莓", "冬瓜", "草莓", "苹果", "冬瓜", "草莓", "香蕉", "草莓", "香蕉" };
	map<string, int> dict;
	
	for (auto e : arr)
	{
		dict[e]++;
	}

	for (auto e : dict)
	{
		cout << e.first << ":" << e.second << endl;
	}*/
	//for (auto e : arr)
	//{
	//	auto it = dict.find(e);
	//	if (it == dict.end())
	//	{
	//		dict.insert(make_pair(e, 1));
	//	}
	//	else
	//	{
	//		it->second++;
	//	}

	//}
	



	//map<string, string> dict;
	//dict.insert(pair<string, string>("蔡徐坤", "cxk"));
	//dict.insert(pair<string, string>("小黑子", "ikun"));
	//dict.insert(make_pair("爆炸", "boom"));
	//dict.insert(make_pair("篮球", "basketbll"));

	////map<string, string>::iterator it = dict.begin();
	//auto it = dict.begin();
	//while (it != dict.end())
	//{
	//	//cout << (*it).first << ":" << (*it).second << endl;
	//	cout << it->first << ":" << it->second << endl;
	//	it++;
	//}
	//




		//std::multiset<int> mymultiset;
		//std::multiset<int>::iterator itlow, itup;

		//for (int i = 1; i < 8; i++) mymultiset.insert(i * 10); // 10 20 30 40 50 60 70

		//itlow = mymultiset.lower_bound(35);             //传入35，返回>=35的元素的迭代器即40的迭代器  
		//cout << "返回小于等于35元素迭代器："<<*itlow<<"的迭代器" << endl;
		//itup = mymultiset.upper_bound(40);              // 传入40，返回>40的元素的迭代器即50的迭代器
		//cout << "返回大于40元素迭代器："<<*itup<<"的迭代器" << endl;
		//for (auto e : mymultiset)
		//{
		//	cout << e << " ";
		//}
		//cout << endl;
		//mymultiset.erase(itlow, itup);                    // 删除区间[40,50）的元素，打印 10 20 30  50 60 70
		//for (std::multiset<int>::iterator it = mymultiset.begin(); it != mymultiset.end(); ++it)
		//	std::cout << ' ' << *it;
		//std::cout << '\n';


	//multiset<int> mt;
	//mt.insert(5);
	//mt.insert(2);
	//mt.insert(1);
	//mt.insert(7);
	//mt.insert(6);
	//mt.insert(3);
	//mt.insert(3);
	//
	//for (auto e : mt)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//auto pos = mt.find(3);
	//while (pos != mt.end())
	//{
	//	cout << *pos << " ";
	//	pos++;
	//}
	//cout << endl;

	//set<int>st;
	//st.insert(1);
	//st.insert(7);
	//st.insert(5);
	//st.insert(3);
	//st.insert(2);
	//st.insert(1);
	//cout << "set:" << endl;
	//for (auto e : st)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//cout <<"set里value为1对应的个数： " << st.count(1) << endl;
	//multiset<int>mt;
	//mt.insert(1);
	//mt.insert(7);
	//mt.insert(5);
	//mt.insert(3);
	//mt.insert(2);
	//mt.insert(1);
	//cout << "multiset:" << endl;
	//for (auto e : mt)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//cout << "multiset里value为1对应的个数： " << mt.count(1) << endl;
	return 0;
}