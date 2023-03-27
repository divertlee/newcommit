#include<iostream>
#include<vector>
//63.不同路径二
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//网格中的障碍物和空位置分别用 1 和 0 来表示。
// 记行数为m，列数为n
// 若起点[0,0] 或者终点[m-1,n-1]有障碍，就返回0-有脏东西完不了
// 构建一个vector<vector<int>>dp(m,vector<int>(n,0)) 即二维数组类似题目地图
// 下标i，j为题目地图的格子，dp[i][j]为该格子的可通行路径数，dp[i][j]=dp[i-1][j]+dp[i][j-1];
// 首先初始化第一行和第一列，若遇到障碍，立刻跳出循环即障碍后面的各自都不初始化了，初始化可通行路径数为1，若有障碍则为0不动
// 然后遍历地图，行和列都从1开始，若遇到障碍就跳过，没遇到就做dp[i][j]=dp[i-1][j]+dp[i][j-1]递增未知区域格子的路径数，最后返回终点路径数即可
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
//        {
//            return 0;
//        }
//        vector<vector<int>> dp(m, vector<int>(n, 0));
//        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
//        {
//            dp[i][0] = 1;
//        }
//        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
//        {
//            dp[0][j] = 1;
//        }
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                if (obstacleGrid[i][j] == 1)
//                {
//                    continue;
//                }
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};
//using namespace std;
//int main()
//{
//	vector<int>ret;
//	ret.push_back(0);
//	ret.push_back(0);
//	ret.push_back(1);
//	ret.push_back(0);
//	int vv = 0;
//	for (int i = 0; i < ret.size()&&ret[i]==0; i++)
//	{
//		vv++;
//	}
//	cout << vv << endl;
//	return 0;
//}
//62.不同路径
// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
// 制定一个二维数组与题目相似，第dp[i,j]的路径总数为dp[i-1,j],dp[i,j-1]的和；而且首先同一行或咧的路径数为1，所以要先初始话第0行和第0列的路径数。	
//问总共有多少条不同的路径
// class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>>dp(m, vector<int>(n, 0));
//        for (int i = 0; i < m; i++)
//        {
//            dp[i][0] = 1;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            dp[0][i] = 1;
//        }
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};
//746.使用最小花费爬楼梯
//给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//请你计算并返回达到楼梯顶部的最低花费
//i是第i阶楼梯，初始的下标为0和下标为1阶楼梯花费数为0；dp0记录爬到i-2阶楼梯的花费数，dp1记录爬到第i-1阶楼梯的花费数，dp1记录爬到第-1阶楼梯的花费数，
// 第i阶的花费数取min(dp0+cost[i-2],dp1+cost[i-1])
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        int dp0 = 0;
//        int dp1 = 0;
//        for (int i = 2; i <= cost.size(); i++)
//        {
//            int dpi = min(dp0 + cost[i - 2], dp1 + cost[i - 1]);
//            dp0 = dp1;
//            dp1 = dpi;
//        }
//        return dp1;
//    }
//};
//70.爬楼梯
// class Solution {
//public:
//    int climbStairs(int n) {
//        if (n <= 2)return n;
//        vector<int>dp(n + 1);
//        dp[1] = 1;
//        dp[2] = 2;
//        for (int i = 3; i <= n; i++)
//        {
//            dp[i] = dp[i - 2] + dp[i - 1];
//        }
//        return dp[n];
//    }
//};
//class Solution {
//public:
//    int climbStairs(int n) {
//        if (n <= 2)return n;
//        vector<int>dp(2);
//        dp[0] = 1;
//        dp[1] = 2;
//        for (int i = 3; i <= n; i++)
//        {
//            int sum = dp[0] + dp[1];
//            dp[0] = dp[1];
//            dp[1] = sum;
//        }
//        return dp[1];
//    }
//};

//开动态规划
// 动归五部曲
// 1、确定动归数组下标和数组含义、
// 2、确定地推公式
// 3、dp数组如何初始化
// 4、确定遍历顺序
// 5、推导dp数组
//509.斐波那契数列---dp[0]=0,dp[1]=1;2开始dp[i]=dp[i-2]+dp[i-1] 
//class Solution {
//public:
//    int fib(int n) {
//        if (n <= 1)return n;
//        vector<int> dp(n + 1);
//        dp[0] = 0;
//        dp[1] = 1;
//        for (int i = 2; i <= n; i++)
//        {
//            dp[i] = dp[i - 2] + dp[i - 1];
//        }
//        return dp[n];
//    }
//};

//968.监视二叉树
// 若碰到空姐点，返回2；若2&&2，返回0；若0||0即左右孩子有一个没被覆盖，此节点就安摄像头，ret++；返回1；若1||1为左右孩子其中一个安了摄像头，此节点为有覆盖，返回2；遍历顺序不能变
// class Solution {
//public:
//    int ret;
//    int recall(TreeNode* root)
//    {
//        if (root == nullptr)return 2;
//        int left = recall(root->left);
//        int right = recall(root->right);
//
//        if (left == 2 && right == 2)
//        {
//            return 0;
//        }
//        if (left == 0 || right == 0)//左右孩子其中一个为无覆盖，都需安摄像头
//        {
//            ret++;
//            return 1;
//        }
//        if (left == 1 || right == 1)//左右孩子其中一个安了摄像头，父节点即为有覆盖
//        {
//            return 2;
//        }
//
//
//        return -1;
//
//    }
//    int minCameraCover(TreeNode* root) {
//        ret = 0;
//        if (recall(root) == 0)
//        {
//            ret++;
//        }
//        return ret;
//    }
//};
//738.单调递增的数字
// 从后往前遍历，若前一位比这一位打，那么前一位减减，用flag记录这一位的下标；遍历完后，flag从这为往后遍历，遍历到的位置的数字都变9
//class Solution {
//public:
//    int monotoneIncreasingDigits(int n) {
//        string tmp = to_string(n);
//        int flag = tmp.size();
//        for (int i = tmp.size() - 1; i > 0; i--)
//        {
//            if (tmp[i - 1] > tmp[i])
//            {
//                tmp[i - 1]--;
//                flag = i;
//            }
//        }
//        for (int i = flag; i < tmp.size(); i++)
//        {
//            tmp[i] = '9';
//        }
//        int ret = stoi(tmp);
//        return ret;
//
//    }
//};


//56.合并区间
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];//按左区间从小到大排序
//    }
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(), cmp);
//        vector<vector<int>> ret;
//        ret.push_back(intervals[0]);
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (ret.back()[1] >= intervals[i][0])//重叠更新最大右边界
//            {
//                ret.back()[1] = max(intervals[i][1], ret.back()[1]);
//
//            }
//            else//不重叠
//            {
//                ret.push_back(intervals[i]);
//            }
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];//按左区间从小到大排序
//    }
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(), cmp);
//        vector<vector<int>> ret;
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (intervals[i - 1][1] >= intervals[i][0])//重叠更新最大右边界
//            {
//                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
//                intervals[i][0] = min(intervals[i - 1][0], intervals[i][0]);
//
//            }
//            else//不重叠
//            {
//                ret.push_back(intervals[i - 1]);
//            }
//        }
//        ret.push_back(intervals[intervals.size() - 1]);
//        return ret;
//    }
//};


//19.划分字母区间
// 通过哈希表记录每个字符出现的最远距离，然后再次遍历，当字符串的下标为字符最远距离时，即到区间末尾了，记录结果-区间长度，然后更新下一个区间的起点
// class Solution {
//public:
//    vector<int> partitionLabels(string s) {
//        vector<int> ret;
//        int hash[26] = { 0 };
//        for (int i = 0; i < s.size(); i++)
//        {
//            hash[s[i] - 'a'] = i;//记录字符最远出现下标
//        }
//        int left = 0;
//        int right = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//            right = max(right, hash[s[i] - 'a']);//取这个区间里面最远字符的最远下标
//            if (i == right)
//            {
//                ret.push_back(right - left + 1);//插入区间字符串长度
//                left = right + 1;//更新区间起点
//            }
//        }
//        return ret;
//    }
//};
// 
// 通过vector<vector<int>(left,right))记录每个字符的左右边界，转化为射气球问题。
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];//按左边界从小到大排序
//    }
//    vector<vector<int>> getleftandright(string& s)
//    {
//        vector<vector<int>>hash(26, vector<int>(2, INT_MIN));
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (hash[s[i] - 'a'][0] == INT_MIN)//记录字符出现的气点
//            {
//                hash[s[i] - 'a'][0] = i;
//            }
//            hash[s[i] - 'a'][1] = i;//更新并记录字符最远出现下标
//
//        }
//        vector<vector<int>>result;
//        for (int i = 0; i < hash.size(); i++)
//        {
//            if (hash[i][0] != INT_MIN)
//            {
//                result.push_back(hash[i]);
//            }
//        }
//        return result;
//    }
//    vector<int> partitionLabels(string s) {
//        vector<vector<int>>ret = getleftandright(s);
//        sort(ret.begin(), ret.end(), cmp);
//        vector<int> orig;
//        int left = 0;
//        int right = ret[0][1];
//        for (int i = 1; i < ret.size(); i++)
//        {
//            if (right < ret[i][0])
//            {
//                orig.push_back(right - left + 1);
//                left = ret[i][0];
//            }
//            right = max(right, ret[i][1]);
//        }
//        orig.push_back(right - left + 1);
//        return orig;
//    }
//};


//452.用最少箭数引爆气球，同区间的气球只需一支箭，区间最少箭数，总箭数最少，局部推全局--贪心算法
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];//按照左边界从小到大排序
//    }
//    int findMinArrowShots(vector<vector<int>>& points) {
//        sort(points.begin(), points.end(), cmp);
//        int ret = 1;
//        for (int i = 1; i < points.size(); i++)
//        {
//            if (points[i - 1][1] < points[i][0])//前一个区间的气球和这个气球不重叠
//            {
//                ret++;
//            }
//            else//前一个区间的气球和这个气球重叠，需要更新最小end
//            {
//                points[i][1] = min(points[i - 1][1], points[i][1]);
//            }
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[1] < b[1];//按照右边界从小到大排序
//    }
//    int findMinArrowShots(vector<vector<int>>& points) {
//        sort(points.begin(), points.end(), cmp);
//        int end = points[0][1];
//        int ret = 1;//默认需要射出一支箭
//        for (int i = 1; i < points.size(); i++)
//        {
//            if (end < points[i][0])//前一个区间的气球和此个气球不重叠了，箭数加加
//            {
//                ret++;
//                end = points[i][1];
//            }
//        }
//        return ret;
//    }
//};

//435.无重叠区间
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[0] < b[0];//按左区间从小到大排序
//    }
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(), cmp);
//        int ret = 0;
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (intervals[i - 1][1] > intervals[i][0])//区间重叠，取右区间较小的，相当于删除了右区间较大者
//            {
//                ret++;
//                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
//            }
//        }
//        return ret;
//    }
//};
//
//class Solution {
//public:
//    static bool cmp(vector<int>& a, vector<int>& b)
//    {
//        return a[1] < b[1];//按右区间从小到大排序
//    }
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        sort(intervals.begin(), intervals.end(), cmp);
//        int ret = 0;
//        for (int i = 1; i < intervals.size(); i++)
//        {
//            if (intervals[i - 1][1] > intervals[i][0])//区间重叠，取右区间较小的，相当于删除了右区间较大者
//            {
//                ret++;
//                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
//            }
//        }
//        return ret;
//    }
//};

