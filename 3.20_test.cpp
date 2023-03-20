#pragma once
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;


//55.跳跃游戏
//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标。

//记一个从当点到结束点的范围cover，当cover大于大于之前的cover时就更新，当cover能到达结束点时就返回true
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int cover = 0;
//        if (nums.size() == 1)
//        {
//            return true;
//        }
//        for (int i = 0; i <= cover; i++)
//        {
//            cover = max(nums[i] + i, cover);//更新最大覆盖范围
//            if (cover >= (nums.size() - 1))//如果范围大于要走的步数，就返回true
//            {
//                return true;
//            }
//        }
//        return false;
//    }
//};

    //bool canJump(vector<int>& nums) {
    //    if (nums.size() == 1)
    //    {
    //        return true;
    //    }
    //    for (int i = 0; i < nums.size() - 1; i++)
    //    {
    //        int count = nums.size() - i - 1;
    //        if ((count - nums[i]) <= 0)
    //        {
    //            return true;
    //        }
    //    }
    //    return false;
    //}

    //int main()
    //{
    //    vector<int> nums;
    //    nums.push_back(2);
    //    nums.push_back(0);
    //    bool ttt = canJump(nums);
    //    return 0;
    //}

//void settest1()
//{
//	set<int> st;
//	st.insert(1);
//	st.insert(8);
//	st.insert(3);
//	st.insert(2);
//	st.insert(2);
//	st.insert(16);
//	st.insert(1);
//
//	auto it = st.begin();
//	while (it != st.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	//if (st.find(1)!=st.end())
//	//{
//	//	st.erase(1);
//	//}
////	auto pos = st.find(1);//log(N)
//	//auto pos = find(st.begin(), st.end(),1);//O(N)
//	//st.erase(pos);
//	auto it1 = st.begin();
//	while (it1 != st.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//	//for (auto e : st)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//	cout << st.count(1) << endl;
//}
 
//122.买卖股票的最佳时机二
//你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
//在每一天，你可以决定是否购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
//返回 你能获得的 最大 利润 
// 利润相加最大--可以分成每次利润相加，每次利润都为正就加，那么最后的利润就是最大的
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int ret = 0;
//        for (int i = 0; i < prices.size() - 1; i++)
//        {
//            if ((prices[i + 1] - prices[i]) > 0)
//            {
//                ret += prices[i + 1] - prices[i];//只要比0大的利润就能加
//            }
//        }
//        return ret;
//    }
//};


//53.最大子数组和
//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//子数组 是数组中的一个连续部分。
// 当count即总和小于0时，对后面所加的数会有负数作用，使的总数变小，所以要使count=0，即重新选择起点；只要count还是为正，
// 那么选取最大的那段即最大count的形态---当count为最大正时-部分最大，ret也就会最大-总体最大
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int start = 0;
//        int ret = INT_MIN;
//        int count = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            count += nums[i];
//            if (count > ret)
//            {
//                ret = count;
//            }
//            if (count < 0)
//            {
//                count = 0;
//            }
//        }
//        return ret;
//    }
//};

//void settest2()
//{
//	multiset<int> st;
//	st.insert(1);
//	st.insert(2);
//	st.insert(6);
//	st.insert(1);
//	st.insert(0);
//	st.insert(8);
//
//	for (auto e : st)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << st.count(1) << endl;
//}
//
//int main()
//{
////	settest1();
////	settest2();
//	return 0;
//}




//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world\n" << endl;
//
//	return 0;
//}


//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	int empty = 0;//空瓶子
//	int get = 0;
//
//	while (cin >> n)
//	{
//		if (n == 0)
//		{
//			break;
//		}
//		empty = n;
//		int have = 0;
//		while (empty / 3)
//		{
//			get = empty / 3;
//			have += get;
//			empty -= (get * 3);
//			empty += get;
//		}
//		if ((empty + 1) / 3)
//		{
//			have++;
//		}
//		cout << have << endl;
//	}
//
//	//while (cin>>n)//输入买了多少瓶
//	//{
//	//	have = n;//得到多少瓶可以喝
//	//	int get = have;//喝了多少瓶
//	//	empty = have;
//	//	while (empty / 3)
//	//	{
//	//		have = empty % 3;//换了多少瓶
//	//		get += have;
//	//		empty -= have * 3;
//	//		empty += have;
//	//	}
//	//	cout << get << endl;
//	//}
//
//	return 0;
//}







//376.摆动序列
//如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
// 用prev记录前一对的差值，用cur记录当前对的差值，当prev <= 0 && cur > 0||prev >= 0 && cur < 0时，摆动序列ret++；因为两个数默认也成一对序列，所以ret默认值为1
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        if (nums.size() <= 1) return nums.size();
//        int prev = 0;
//        int cur = 0;
//        int ret = 1;
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            cur = nums[i + 1] - nums[i];
//            if ((prev <= 0 && cur > 0) || (prev >= 0 && cur < 0))
//            {
//                ret++;
//                prev = cur;
//            }
//        }
//        return ret;
//    }
//};