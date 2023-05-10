#include<iostream>

using namespace std;
//123. 买卖股票的最佳时机 III
// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票
//
//int main()
//{
//	int a = 10;
//	int b{ 1.1 };
//	return 0;
//}

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.size() == 1)return 0;
//        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
//        dp[0][1] = -prices[0];
//        dp[0][3] = -prices[0];
//        for (int i = 1; i < prices.size(); i++)
//        {
//            dp[i][0] = dp[i - 1][0];
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
//            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
//            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
//            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
//        }
//        return dp[prices.size() - 1][4];
//    }
//};
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.size() == 1)return 0;
//        vector<int>dp(5, 0);
//        dp[0] = 0;
//        dp[1] = -prices[0];
//        dp[2] = 0;
//        dp[3] = -prices[0];
//        dp[4] = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            dp[1] = max(dp[1], dp[0] - prices[i]);
//            dp[2] = max(dp[2], dp[1] + prices[i]);
//            dp[3] = max(dp[3], dp[2] - prices[i]);
//            dp[4] = max(dp[4], dp[3] + prices[i]);
//
//        }
//        return dp[4];
//    }
//};
