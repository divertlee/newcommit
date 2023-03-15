
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	for (int i = 1; i < 1; i++)
	{
		cout << i << endl;
	}
}

//131.分割字符串
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//回文串 是正着读和反着读都一样的字符串。
// 回溯：横向确定分割字符串的终点，纵向确定分割字符串的起点;如果不是回文就continue往后找字符串终点延长字符串；当分割的起点到达判断字符串的末尾时就插入ret
// class Solution {
//public:
//    vector<vector<string>> ret;
//    vector<string> path;
//    void recall(string& s, int start)
//    {
//        if (start >= s.size())//如果起点已经到字符串的末尾，说明分割完毕，往ret里面插入
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        for (int i = start; i < s.size(); i++)
//        {
//            string tmp = s.substr(start, i - start + 1);//划分字符串
//            if (istrue(tmp))
//            {
//                path.push_back(tmp);
//            }
//            else
//            {
//                continue;
//            }
//            recall(s, i + 1);
//            path.pop_back();
//        }
//    }
//    bool istrue(string& tmp)
//    {
//        for (int i = 0, j = tmp.size() - 1; i < j; i++, j--)
//        {
//            if (tmp[i] != tmp[j])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//    vector<vector<string>> partition(string s) {
//        ret.clear();
//        path.clear();
//        recall(s, 0);
//        return ret;
//    }
//};
//int main()
//{
//	string s = { "aab" };
//	for (int i = 1; i <= s.size(); i++)
//	{
//		string tmp(s.begin(), s.begin() + i);
//		cout << tmp << endl;
//	}
//	
//	return 0;
//}
//40.组合总和二给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的每个数字在每个组合中只能使用 一次 。
//注意：解集不能包含重复的组合。 
//回溯：依次递归candidate内的元素让target减去，当target为0时即push进ret；元素不能重复使用并且不能出现重复组合即当candidate内有重复元素时，横向遍历取
//起点的时后前后元素相同要跳过（用到used数组判断)纵向上有start使纵向上一直向前递归不能在原地重复使用同个位置的值

//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    void recall(vector<int>& candidates, int target, int start, vector<bool>& used)
//    {
//        if (target < 0)
//        {
//            return;
//        }
//        if (target == 0)
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        for (int i = start; i < candidates.size() && candidates[i] <= target; i++)
//        {
//            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)//同样的元素起点得跳过
//            {
//                continue;
//            }
//            used[i] = true;
//            target -= candidates[i];
//            path.push_back(candidates[i]);
//            recall(candidates, target, i + 1, used);
//            target += candidates[i];
//            path.pop_back();
//            used[i] = false;
//        }
//
//    }
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        ret.clear();
//        path.clear();
//        vector<bool> used(candidates.size(), false);
//        sort(candidates.begin(), candidates.end());
//        recall(candidates, target, 0, used);
//        return ret;
//    }
//};

//39.组合总和：给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，
//并以列表形式返回。你可以按 任意顺序 返回这些组合。
//思路：回溯依次用target减去candidate的元素，当target等于0时push进ret；要有可以重复但不能往回递归：要有起始点i，这样可以重复递归i位置的元素但是不能
//往回递归i-1甚至往前位置的元素

//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    void recall(vector<int>& candidates, int target, int start)
//    {
//        if (target < 0)
//        {
//            return;
//        }
//        if (target == 0)
//        {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = start; i < candidates.size() && candidates[i] <= target; i++)
//        {
//            target -= candidates[i];
//            path.push_back(candidates[i]);
//            recall(candidates, target, i);
//            path.pop_back();
//            target += candidates[i];
//        }
//    }
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        ret.clear();
//        path.clear();
//        sort(candidates.begin(), candidates.end());
//        recall(candidates, target, 0);
//        return ret;
//    }
//};

//216.组合总和三
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    void recall(int k, int n, int start)
//    {
//        if (n < 0)
//        {
//            return;
//        }
//        if (path.size() == k)
//        {
//            if (n == 0)
//            {
//                ret.push_back(path);
//                return;
//            }
//        }
//
//        for (int i = start; i <= 9 - (k - path.size()) + 1; i++)//剪枝：求start的最远起点--即横向递归的最远起点
//        {
//            n -= i;
//            path.push_back(i);
//            recall(k, n, i + 1);
//            n += i;
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> combinationSum3(int k, int n) {
//        ret.clear();
//        path.clear();
//        recall(k, n, 1);
//        return ret;
//    }
//};