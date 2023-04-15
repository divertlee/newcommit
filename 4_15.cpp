//377.组合总和四
//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//题目数据保证答案符合 32 位整数范围。
//排列--先遍历背包容积再遍历物品保证出现全排列
//class Solution {
//public:
//    int combinationSum4(vector<int>& nums, int target) {
//        vector<int>dp(target + 1, 0);
//        dp[0] = 1;
//        for (int i = 0; i <= target; i++)//先遍历背包容积
//        {
//
//            for (int j = 0; j < nums.size(); j++)
//            {
//                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
//                {
//                    dp[i] += dp[i - nums[j]];
//                }
//            }
//        }
//        return dp[target];
//    }
//};

//70.爬楼
////假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//转化为完全背包：m阶楼梯有前m中爬法（爬1阶、2阶、3.。。。m阶到第m阶楼梯），当m为为1、2时符合题意
//class Solution {
//public:
//    int climbStairs(int n) {
//        vector<int>dp(n + 1, 0);
//        dp[0] = 1;
//        for (int i = 0; i <= n; i++)//先遍历背包容积
//        {
//            for (int j = 1; j <= 2; j++)
//            {
//                if (i >= j)
//                    dp[i] += dp[i - j];
//            }
//        }
//        return dp[n];
//    }
//};

//322.零钱兑换
//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回  - 1 。
//
//你可以认为每种硬币的数量是无限的。
//
	//class Solution {
	//public:
	//    int coinChange(vector<int>& coins, int amount) {
	//        vector<int>dp(amount + 1, INT_MAX);//装满背包容积为amount的最少物品数
	//        dp[0] = 0;//先给非0部分初始化为最大值，那么后面第一次填充这个背包额度的时候必然是满状态且有数的
	//        for (int i = 0; i < coins.size(); i++)
	//        {
	//            for (int j = coins[i]; j <= amount; j++)
	//            {
	//                if (dp[j - coins[i]] != INT_MAX)//若装入物品i之前的空间没有合适的物品存放也不能算
	//                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
	//            }
	//        }
	//        if (dp[amount] == INT_MAX)
	//            return -1;
	//
	//        return dp[amount];
	//    }
	//};