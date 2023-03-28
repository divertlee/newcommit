// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int N = 0;//物品数量
    int V = 0;//背包体积
    cin >> N >> V;
    vector<int>ve(N, 0);//体积
    vector<int>we(N, 0);//价值
    for (int i = 0; i < N; i++)
    {
        cin >> ve[i] >> we[i];
    }

    vector<vector<int>> dp(N, vector<int>(V + 1, 0));
    for (int j = ve[0]; j <= V; j++)
    {
        if (V >= ve[j])
        {
            dp[0][j] = we[0];
        }
    }

    for (int i = 1; i < dp.size(); i++)//先遍历物品
    {
        for (int j = 0; j <= V; j++)
        {
            if (V < ve[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ve[i]] + we[i]);
            }
        }
    }
    cout << dp[N - 1][V] << endl;

    return 0;
}
//96. 不同的二叉搜索树
//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数 
// class Solution {
//public:
//    //i为二叉搜索树节点的数量且节点值，j为此时树的头节点的值，
//    //j-1为左孩子数量（左边父节点的值或者起始点的值），i-j为右孩子的数量（右边父节点的值或者起始点的值）
//    //dp[0]=1，节点值不能为0，依次遍历i既为从1到n，填充i个节点的二叉树的种数，种数为左子树节点数量*右子树节点数量的加总
//    //即为dp[i]+=dp[j-1][i-j]，在i个节点数量的二叉搜索树中，j值轮流充当头节点，
//    int numTrees(int n) {
//        vector<int> dp(n + 1);
//        dp[0] = 1;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= i; j++)
//            {
//                dp[i] += dp[j - 1] * dp[i - j];
//            }
//        }
//        return dp[n];
//    }
//};
//343.整数拆分
//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。返回 你可以获得的最大乘积 。
// 题目说了整数k从2开始，那么下标i为2的乘积最大为1dp[2]=1；dp为下标数的乘积最大，然后遍历，i从3开始遍历到n，
// 里面再套一层循环，j（j是被拆分的那部分），j<=i/2，当j遍历到i的后半部分的时候会与前面遍历的部分重复
// dp[i]=max(dp[i],max((i-j)*j,dp[i-j]*j)，因为是逐个遍历，必须把前面的dp部分补上，在j的遍历环节中，取dp[i]和被拆分部分j*（i-j）的乘积和被拆分部分j*dp[i-j]乘积的最大值
    //int integerBreak(int n) {
    //    vector<int>dp(n + 1);
    //    dp[2] = 1;
    //    for (int i = 3; i <= n; i++)//dp数组从3开始需要计算
    //    {
    //        int j = 1;
    //        for ( j = 1; j <= (i / 2); j++)
    //        {
    //            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
    //        }
    //    }
    //    return dp[n];

    //}

    //int main()
    //{
    //    int n = 3;
    //    integerBreak(n);
    //    return 0;
    //}


//int main()
//{
//    string n ;
//    cin >> n;
//    int tmp = 0;
//    for (int i = 0; i < n.size(); i++)
//    {
//        tmp += (n[i] - '0');
//    }
//        while (tmp / 10)
//        {
//            int k = tmp / 10;
//            tmp %= 10;
//            tmp += k;
//        }
//        cout << tmp << endl;
//    
//    return 0;
//}