//多重背包问题
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    int N = 0;//物品种数
//    int V = 0;//背包容积
//    cin >> N >> V;
//    vector<int>vi(N, 0);//第i种物品的体积
//    vector<int>wi(N, 0);//第i种物品的价值
//    for (int i; i < N; i++)
//    {
//        cin >> vi[i] >> wi[i];
//    }
//    vector<int>dp(V + 1, 0);
//    for (int i = 0; i < N; i++)//遍历物品
//    {
//        for (int j = vi[i]; j <= V; j++)//遍历背包容积
//        {
//            dp[j] = max(dp[j], dp[j - vi[i]] + wi[i]);
//        }
//    }
//    cout << dp[V] << endl;
//    return 0;
//}

//474.一和零
//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//
//请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
//
//如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
//把字符串看成物品，字符串的0个数和1个数，看成两个维度上的物品质量
// dp[i][j]：i是1的个数，j是0的个数，dp[i][j]是装满i个1j个0的背包最大物品数
// 递推公式：dp[i][j]=max(dp[i][j],dp[i-onenum][j-zeronum]+1),最后返回dp[n][m];dp[i-onenum][j-zeronum]+1:腾出这个物品自带的零一质量背包所能容纳的容积最大物品数+1（这个物品数）
// 初始化都为0
// 遍历思路：先依次取字符串，记录字符串中1的个数onenum,0的个数zeronum，然后从后往前遍历dp
// m，n个背包容量最多容纳多少个物品（字符串），然后到下个字符串到来时，就会在已经记录过的m，n容量的最大物品数上进行更新
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));//行维度是1-n个1，列维度是0，m个0
//        for (auto e : strs)//依次遍历字符串
//        {
//            int onenum = 0;
//            int zeronum = 0;
//            for (auto k : e)//依次记录字符串的01个数
//            {
//                if (k == '0')
//                {
//                    zeronum++;
//                }
//                else
//                {
//                    onenum++;
//                }
//            }
//            //把字符串的01个数匹配算入dp[i][j]：每个字符串（物品）自带n个1，m个0，装满dp[n][m]背包最大字符串（物品）数
//            for (int i = n; i >= onenum; i--)//遍历1
//            {
//                for (int j = m; j >= zeronum; j--)//遍历0
//                {
//                    dp[i][j] = max(dp[i][j], dp[i - onenum][j - zeronum] + 1);
//                }
//            }
//        }
//        return dp[n][m];
//    }
//};