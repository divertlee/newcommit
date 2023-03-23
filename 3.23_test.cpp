#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	int max = n > m ? n : m;
	int min = n < m ? n : m;

	while (max % min)
	{
		int tmp = max % min;
		max = min;
		min = tmp;
	}

	cout << "公约数为：" << min << endl;

	return 0;
}

//
//int main()
//{
//    string s;
//    cin >> s;
//    int hash[127] = { 0 };
//    for (int i = 0; i < s.size(); i++)
//    {
//        hash[s[i] ]++;
//    }
//    for (int i = 0; i < s.size(); i++)
//    {
//        if (hash[s[i]] == 1)
//        {
//            cout << s[i] << endl;
//            return 0;
//        }
//  }
//   
//    cout << -1 << endl;
//    return 0;
//
//}

//968.监控二叉树
//给定一个二叉树，我们在树的节点上安装摄像头。
//
//节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
//
//计算监控树的所有节点所需的最小摄像头数量。
// 
//int main()
//{
//	
//	return 0;
//}
//0：节点无覆盖，1：节点有监控，2：节点有覆盖
 //后序遍历（左右中），当遇到叶子节点时，返回2（因为叶子节点不能按监控，得在父节点安）
 //当左右节点都有覆盖，2&&2，父节点返回0（无覆盖）；
 //当左右节点其中一个有监控时，1||1,父节点返回2
 //当左右节点其中一个无覆盖时，0||0,父节点要安监控，父节点返回1
//class Solution {
//public:
//    int num;
//    int recall(TreeNode* root)
//    {
//        if (root == nullptr)return 2;//遇到叶子节点
//        int leftnum = recall(root->left);
//        int rightnum = recall(root->right);
//
//        if (leftnum == 2 && rightnum == 2) return 0;
//        if (leftnum == 0 || rightnum == 0)//其中一个子节点没被覆盖到
//        {
//            num++;
//            return 1;
//        }
//        if (leftnum == 1 || rightnum == 1)
//        {
//            return 2;
//        }
//        return -1;
//    }
//    int minCameraCover(TreeNode* root) {
//        num = 0;
//        if (recall(root) == 0)
//        {
//            num++;
//        }
//        return num;
//    }
//};
//738.单调递增的数字
//当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
//给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
//先从后往前遍历，因为是要求ret的顺序是升序，所以当前一位的数字比当前大时，前一位就减减，flag标记当前位。遍历完后，以标记为flag开始往后遍历，flag位置改为9
//class Solution {
//public:
//    int monotoneIncreasingDigits(int n) {
//        string s = to_string(n);
//        int flag = s.size();
//        for (int i = s.size() - 1; i > 0; i--)
//        {
//            if (s[i - 1] > s[i])
//            {
//                flag = i;
//                s[i - 1]--;
//            }
//        }
//        for (int i = flag; i < s.size(); i++)
//        {
//            s[i] = '9';
//        }
//        int ret = stoi(s);
//        return ret;
//    }
//};

//56.合并区间
//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间
// 先按照左边界从小到大排序，用left记录左边界，right记录右边界，然后遍历元素，当右边界大于上一个左边界时，插入ret，更新左边界；在遍历时右边界实时更新遍历过的最大值；
// 遍历完后最后一个元素没有进ret，补上就好
// 
////先插入再判断
// class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];//按照左边界从小到大排序
//    }
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> ret;
//        sort(intervals.begin(), intervals.end(), cmp);
//        ret.push_back(intervals[0]);//先插入，后续改变再改
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (ret.back()[1] >= intervals[i][0])//上一个元素的右区间大于等于了当前元素的左区间即区间重叠了，
//            //需要更新右区间
//            {
//                ret.back()[1] = max(intervals[i][1], ret.back()[1]);//更新右区间
//            }
//            else
//            {
//                ret.push_back(intervals[i]);
//            }
//
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];//按照左边界从小到大排序
//    }
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> ret;
//        sort(intervals.begin(), intervals.end(), cmp);
//        int left = intervals[0][0];
//        int right = intervals[0][1];
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (intervals[i][0] > right)//如果当前的左边界大于之前的最大右边界
//            {
//                vector<int> tmp;
//                tmp.push_back(left);
//                tmp.push_back(right);
//                ret.push_back(tmp);
//                left = intervals[i][0];
//            }
//            right = max(right, intervals[i][1]);
//        }
//        vector<int> tmp;
//        tmp.push_back(left);
//        tmp.push_back(right);
//        ret.push_back(tmp);
//        return ret;
//    }
//};
//763.划分字母区间
//给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中；且拼凑起来还是s，返回一个表示每个字符串片段的长度的列表


//用hash遍历s字符串，依次把每个字符的最远出现距离更新；然后用left和right划分字符串边界；for循环遍历s字符串，
// 用right更新遍历到的字符的最远距离，当right==i，此时right必然是当前段的字符最远距离，然后ret.push_back进这段的长度，之后更新left=right+1，依次遍历即可
// 
// 2.用左右边界做
  //先用vector<vector<int>(,)>记录每个存在的字符的最早出现位置（左边界）和最晚出现位置（右边界）
 //然后按照左边界从小到大排序，边遍历边更新最大右边界，
 //当下一个字符的左边界大于右边界时，就意味着找到零界点了，然后插入ret，更新左边界
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];
//    }
//    vector<vector<int>> releavess(const string& s)
//    {
//        vector<vector<int>> hash(26, vector<int>(2, INT_MIN));
//        vector<vector<int>> filecon;
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (hash[s[i] - 'a'][0] == INT_MIN)//把字符的第一次出现的位置即左边界填进去
//            {
//                hash[s[i] - 'a'][0] = i;
//            }
//            hash[s[i] - 'a'][1] = i;//更新右边界
//        }
//        for (int i = 0; i < hash.size(); i++)//只取字符出现的位置
//        {
//            if (hash[i][0] != INT_MIN)
//            {
//                filecon.push_back(hash[i]);
//            }
//        }
//        return filecon;
//    }
//    vector<int> partitionLabels(string s) {
//        vector<int> ret;
//        vector<vector<int>> hash = releavess(s);
//
//        sort(hash.begin(), hash.end(), cmp);
//
//        int right = hash[0][1];//记录右边界
//        int left = 0;
//        for (int i = 0; i < hash.size(); i++)
//        {
//            if (hash[i][0] > right)
//            {
//                ret.push_back(right - left + 1);
//                left = hash[i][0];//更新左边界
//            }
//            right = max(right, hash[i][1]);
//        }
//        ret.push_back(right - left + 1);
//        return ret;
//    }
//};
//class Solution {
//public:
//    vector<int> partitionLabels(string s) {
//        int hash[26] = { 0 };
//        for (int i = 0; i < s.size(); i++)
//        {
//            hash[s[i] - 'a'] = i;//记录每个字符最远距离
//        }
//        int left = 0;
//        int right = 0;
//        vector<int> ret;
//        for (int i = 0; i < s.size(); i++)
//        {
//            right = max(right, hash[s[i] - 'a']);//取到每个字符最远的距离；若在最远距离字符前遇到次远距离字符也不怕，
//            //因为在此之前最远字符的个数肯定必次远的多，在遇到次远字符最远距离时，right已经更新到最远字符距离了
//            if (i == right)
//            {
//                ret.push_back(right - left + 1);//遇到分界点，输入分解点前这段的字符个数
//                left = right + 1;
//            }
//        }
//        return ret;
//    }
//};


//    vector<int> partitionLabels(string S) {
//        int hash[27] = { 0 }; // i为字符，hash[i]为字符出现的最后位置
//        for (int i = 0; i < S.size(); i++) { // 统计每一个字符最后出现的位置
//            hash[S[i] - 'a'] = i;
//        }
//        vector<int> result;
//        int left = 0;
//        int right = 0;
//        for (int i = 0; i < S.size(); i++) {
//            right = max(right, hash[S[i] - 'a']); // 找到字符出现的最远边界
//            if (i == right) {
//                result.push_back(right - left + 1);
//                left = i + 1;
//            }
//        }
//        return result;
//    }
//int main()
//{
//    string S = "ababcbacadefegdehijhklij";
//    vector<int> ret= partitionLabels(S);
//    for (auto e : ret)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//    return 0;
//}



//435. 无重叠区间
// 按左边界分：按左边界从小到大排列，如果左边界相同就按右边界从大到小排列；记录重叠数ret；当重叠时，ret++且更新当前右边界：选择二者之间较小右边界（把右边界较大者删除）；
// class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        if (a[0] == b[0])return a[1] > b[1];
//        return a[0] < b[0];
//    }
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(), cmp);
//        int ret = 0;
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (intervals[i - 1][1] > intervals[i][0])
//            {
//                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
//                ret++;
//            }
//        }
//
//        return ret;
//    }
//};
// 
//按右边界分---按右边界从小到大排序，默认一个不重叠；如果不重叠了，就更新end为当前的右边界并且不重叠数++；如果重叠则不变：那么此时的右边界还是较小值（因为是以右边界从大到小排列）
// 最后总数减去不重叠数
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[1] < b[1];//按右边界从小到大排序
//    }
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(), cmp);
//        int count = 1;//记录不重叠个数
//        int end = intervals[0][1];
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (end <= intervals[i][0])//如果左边的终点小于右边的起点，不重叠的个数加加;<=不算重叠
//            {
//                //更新右边界
//                end = intervals[i][1];
//                count++;
//            }		
//        }
//        return intervals.size() - count;
//    }
//};



//452.用最少数量的箭引爆气球
//points = [[10, 16], [2, 8], [1, 6], [7, 12]]；输出2
//局部的气球叠在一起，就只需要一支箭射爆，局部最优-》全局最优；如果左边的气球终点小于右边气球的起点，那么只需要一支箭即可射爆，此时更新右边界最小值，用来继续对右边的气球做比较；
// 若左边的气球终点小于右边气球的起点，那么箭数++
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];
//    }
//
//    int findMinArrowShots(vector<vector<int>>& points) {
//        sort(points.begin(), points.end(), cmp);//快排
//        int ret = 1;//默认气球不为空，所以必须需要一支箭
//        for (int i = 1; i < points.size(); i++)
//        {
//            if (points[i][0] > points[i - 1][1])//如果右边的起点大于左边的终点
//            {
//                ret++;
//            }
//            else
//            {
//                points[i][1] = min(points[i][1], points[i - 1][1]);//不然的话取最小右边界
//            }
//        }
//        return ret;
//    }
//};