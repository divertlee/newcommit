//518.零钱兑换二
//给有限个零钱面额，无线个数量，恰好装满背包容量为amount的方法
//多重背包问题
//dp[j]:装满背包容量为j的方法数
//先遍历物品，这样装满容量为j的方法数就是唯一的，不会出现重复排列问题
//递推公式：dp[j]+=dp[j-coins[i]，dp[0]=1
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        vector<int>dp(amount + 1, 0);
//        dp[0] = 1;//背包容量为0装满的方法数为1
//        for (int i = 0; i < coins.size(); i++)//先遍历物品
//        {
//            for (int j = 0; j <= amount; j++)//再遍历容量
//            {
//                if (j >= coins[i])
//                    dp[j] += dp[j - coins[i]];
//            }
//        }
//        return dp[amount];
//    }
//};