#include<iostream>
#include<vector>
using namespace std;
//491.递归子数列:一是因为没有排序，得用set判断同层递归中重复出现的数，这里是同层递归。二是必须满足递归序列，这里是上下层递归；两个判断是按位或
// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况

// class Solution {
// public:
// vector<vector<int>>ret;
// vector<int>path;
// void recall(vector<int>&nums,int start)
// {
    // if(path.size()>1)
    // {
        // ret.push_back(path);
    // }
    // unordered_set<int> used;
    // for(int i=start;i<nums.size();i++)
    // {
        // if((!path.empty()&&nums[i]<path.back())||used.find(nums[i])!=used.end())
       // {
          // continue;
       // }
        // path.push_back(nums[i]);
           // used.insert(nums[i]);
           // recall(nums,i+1);
           // path.pop_back();
    // }
// }
    // vector<vector<int>> findSubsequences(vector<int>& nums) {
    // ret.clear();
    // path.clear();
    // recall(nums,0);
    // return ret;
    // }
// };

//子集二：给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//同层用used数组判断，与前面相同元素时为false即同层递归，直接continue
// class Solution {
// public:
// vector<vector<int>> ret;
// vector<int> path;
// void recall(vector<int>&nums,int start,vector<bool>& used)
// {
    // ret.push_back(path);
    // for(int i=start;i<nums.size();i++)
    // {
        // if(i>0&&nums[i-1]==nums[i]&&used[i-1]==false)//处理同层相同的数
        // continue;
        // used[i]=true;
        // path.push_back(nums[i]);
        // recall(nums,i+1,used);
       // used[i]=false;
        // path.pop_back();
    // }
// }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
   // ret.clear();
   // path.clear();
   // vector<bool> used(nums.size(),false);
   // sort(nums.begin(),nums.end());
   // recall(nums,0,used);
   // return ret;
    // }
// };

//int main()
//{
//	vector<int> ret;
//	ret.push_back(1);
//	ret.push_back(2);
//	ret.push_back(3);
//	ret.push_back(4);
//	vector<int>::iterator it = ret.begin();
//	cout << *it << endl;
//	cout << *(it + 1) << endl;
//	return 0;
//}

//78.子集
// class Solution {
// public:
// vector<vector<int>> ret;
// vector<int> path;
// void recall(vector<int>& nums,int start)
// {
    // ret.push_back(path);
    // for(int i=start;i<nums.size();i++)
    // {
        // path.push_back(nums[i]);
        // recall(nums,i+1);
        // path.pop_back();
    // }
// }
    // vector<vector<int>> subsets(vector<int>& nums) {
  // ret.clear();
  // path.clear();
  // recall(nums,0);
  // return ret;
    // }
// };

//void findmin(vector<int> left, vector<int> right, vector<int>::iterator i, vector<int>::iterator j,int lnum,int rnum)
//{
//
//}
//93.复原ip地址---直接用字符串s，横向判断划分起点，纵向划分终点，符合要求的字符串就在后面加'.',不符合直接退出递归。当插入的点数为3时，判断是否正确，正确就进入ret
//判断划分的字符串是否正确：一是起点要小于终点；二是不能是非法数字并且不是0xxx形式；三是sum在0-255之间
//class Solution {
// public:
// vector<string> ret;
// void recall(string&s,int point,int start)
// { if(point==3)
  // {   if(istrue(s,start,s.size()-1))
    // {
        // ret.push_back(s);
    // }
    // return;
   // }
   // for(int i=start;i<s.size();i++)
   // {
       // if(istrue(s,start,i))
       // {
           // s.insert(s.begin()+i+1,'.');//在给的位置插入
           // point++;
           // recall(s,point,i+2);
            // s.erase(s.begin()+i+1);//从第一个参数给的位置起往后删除几个字符
            // point--;
       // }else
       // {
           // break;//如果不符合要求则退出本次递归
       // }

   // } 
 // }

 // bool istrue(string&s,int begin,int end)
 // {
    // if(begin>end)
    // {
        // return false;
    // }
  // if(s[begin]=='0'&&begin!=end)
  // {
      // return false;//0xxx->false
  // }
// int sum=0;
  // for(int i=begin;i<=end;i++)
  // {
      // if(s[i]<'0'||s[i]>'9')//非法字符
      // {
          // return false;
      // }
      // sum=sum*10+(s[i]-'0');
      // if(sum>255)
      // {
          // return false;
      // }
  // }
  // return true;
 // }
    // vector<string> restoreIpAddresses(string s) {
// ret.clear();
// if(s.size()<4||s.size()>12){return ret;}
// recall(s,0,0);
// return ret;
    // }
// };
//找手套傻逼暴力法---超时了---直接计算总数即可
void Gloves(int n, vector<int> left, vector<int>right,int &lnum,int&rnum)
{
	 vector<int>:: iterator i = left.begin();
	 vector<int>::iterator lcur = left.begin();
	 vector<int>::iterator lprev = left.begin();
	 vector<int>::iterator lmin = left.begin();
	 vector<int>::iterator j = right.begin();
	 vector<int>::iterator rcur = right.begin();
	 vector<int>::iterator rprev = right.begin();
	 vector<int>::iterator rmin = right.begin();
	 
	while(i!=left.end()&&j!=right.end())
	{
		if (*i == 0 && *j == 0)//左右手套颜色都为0则跳过
		{
			i++;
			j++;
		}
		else if (*i == 0)//左边手套数为0则右边挑选最小的
		{
			rcur = j;
			rmin = rcur;
			rprev = rcur + 1;
			while (rprev != right.end())//找最小
			{
				if (*rprev <= *rcur)
				{
					
					rmin = rprev;
					break;//找到比当前位置更少的手套数
				}
				rprev++;
			}
			if (rmin != rcur)//在后面找到了比当前位置还少的数量--此位置的手套数是最大的--取一个
			{
				rnum += 1;//数量加等当前手套位的1
			}
			else//此位置的手套数是最小的--取全部
			{
				rnum += *rcur;
			}

		}
		else if(*j==0)//右边手套位为0
		{
			lcur = i;
			lmin = lcur;
			lprev = lcur + 1;
			while (lprev != left.end())//左边找最小
			{
				if (*lprev <= *lcur)
				{

					lmin = lprev;
					break;//找到比当前位置更少的手套数
				}
				lprev++;
			}
			if (lmin != lcur)//找到了--此位置的手套数是最大的--取一个
			{
				lnum += 1;//数量加等当前手套位的1
			}
			else//此位置的手套数是最小的--取全部
			{
				lnum += *lcur;
			}
		}
		else//左右都不为0
		{
			lcur = i;
			rcur = j;
			//对比两边求最小
			if (lcur!=left.end() &&rcur!=right.end() &&*lcur < *rcur)//左边小-左边再找小，找到了当前位置就取1，没找到当前位置取全部；右边取1
			{
				lmin = lcur;
				lprev = lcur+1;
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				while (lprev != left.end())
				{
					if (*lprev <= *lcur)//在此位置往后找到了还小的，此位置为最大--取1
					{
						lmin = lprev;
						break;
					}
				}
				if (lmin != lcur)//此位置为最大--取1
				{
					lnum += 1;
				}
				else//此位置为最小
				{
					lnum += *lmin;
				}
				rnum++;
			}
			else//右边小-右边再找小，找到了当前位置就取1，没找到当前位置取全部；左边取1
			{
				rmin = rcur;
				rprev = rcur + 1;
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				while (rprev != right.end())
				{
					if (*rprev <= *rcur)//在此位置往后找到了还小的，此位置为最大--取1
					{
						rmin = rprev;
						break;
					}
				}
				if (rmin != rcur)//此位置为最大--取1
				{
					rnum += 1;
				}
				else//此位置为最小
				{
					rnum += *rmin;
				}
				lnum++;
			}
			
		}
		i++;
		j++;
	}
}
int main()
{
	int n = 0;
	vector<int> left_hand;
	vector<int>right_hand;
	left_hand.push_back(0);
	left_hand.push_back(7);
	left_hand.push_back(1);
	left_hand.push_back(6);
	right_hand.push_back(1);
	right_hand.push_back(5);
	right_hand.push_back(0);
	right_hand.push_back(6);
	int lnum = 0;
	int rnum = 0;
	Gloves(n, left_hand, right_hand,lnum,rnum);
	cout << lnum << " " << rnum << " " << lnum + rnum << endl;
	return 0;
	
}


//int main()
//{
//    int n = 0;
//    while (cin >> n)
//    {
//        int k = 1;
//        int num = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            if (n & 1 == 1)
//            {
//                num++;
//            }
//            n=(n>>1);
//        }
//        cout << num << endl;
//    }
//
//    return 0;
//}
//
//class A {
//
//public:
//	void foo()
//	{
//		printf("A_foo");
//	}
//};
//
//class B :public A
//{
//public:
//	void foo()
//	{
//		printf("B_foo");
//	}
//};
//
//int main()
//{
//	A* ptr = new B;
//	ptr->foo();
//	B*ptr1=new B;
//	ptr1->foo();
//
//
//	return 0;
//}