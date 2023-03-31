#include<iostream>
#include<vector>
using namespace std;


////494.目标和
//给你一个整数数组 nums 和一个整数 target 。
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
// dp[i][j]为从i件物品中任取，（每一件只取一次）放满容量为j的背包
// i为在前i件物品中任取，j为背包容量
// 这里的数字集可以分成正数集left和负数集right，left+right=sum,left-right=target
// 可以得出关系式：正数集left=(sum+target)/2,负数集right=(sum-target)/2
// 且(sum+-target)%2必须等于0-》符合正负数集的标准且abs(target)<=sum
// vector<vector<int>>dp(nums.size()+1,vector<int>(left+1(right+1),0)
// 此前，nums.size()+1即初始化物品件数从0——nums.size()，背包容积为left+1(right+1)即为背包容积从0——left/right
// 遍历物品件数从1开始即为件数1-nums.size(),背包容积从0-left/right
// 当不选取i物品，dp[i][j]为当不选取i物品即只从i-1件物品任取，填满容积为j的背包的方法数，dp[i][j]=dp[i-1][j]
// 当选取i物品，dp[i][j]为当选取i物品即从前i件物品中任取，填满容积为j的背包的方法数,     dp[i][j]+=dp[i-1][j-nums[i-1]]
// dp[i-1][j-nums[i-1]]为背包里已经存在物品i即nums[i-1]，再从前i-1件物品中任取填满容积为j-nums[i-1]的背包的方法数
// class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        int sum = 0;
//        for (auto e : nums)
//        {
//            sum += e;
//        }
//
//        if ((sum - target) % 2 != 0)return 0;
//        if ((sum - target) < 0) return 0;
//        int right = (sum - target) / 2;
//        vector<vector<int>>dp(nums.size() + 1, vector<int>(right + 1, 0));
//        dp[0][0] = 1;
//        for (int i = 1; i <= nums.size(); i++)
//        {
//            for (int j = 0; j <= right; j++)
//            {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= nums[i - 1])//当背包容量j大于等于第i元素的重量时才能装进背包
//                {
//                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
//                    //加上背包已经装上了第i元素，剩余的空间再能用i-1前元素任取来装满背包为j-nums[i-1]的方法数
//                }
//            }
//        }
//        return dp[nums.size()][right];
//    }
//};
//class Solution {
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        int sum = 0;
//        for (auto e : nums)
//        {
//            sum += e;
//        }
//        if ((sum + target) % 2 != 0)
//            return 0;
//        if (abs(target) > sum) return 0;
//        int left = (sum + target) / 2;
//        vector<vector<int>>dp(nums.size() + 1, vector<int>(left + 1, 0));
//
//        dp[0][0] = 1;
//        for (int i = 1; i <= nums.size(); i++)
//        {
//            for (int j = 0; j <= left; j++)
//            {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= nums[i - 1])
//                {
//                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
//                }
//            }
//        }
//        return dp[nums.size()][left];
//    }
//};

    //int findTargetSumWays(vector<int>& nums, int target) {
    //    int sum = 0;
    //    for (auto e : nums)
    //    {
    //        sum += e;
    //    }
    //    if ((sum + target) % 2 != 0)//不符合正数堆的定义
    //    {
    //        return 0;
    //    }
    //    if ((sum - target) < 0)//都是正整数，相加减必然大于等于0
    //    {
    //        return 0;
    //    }
    //    int flag = (sum + target) / 2;//正数堆
    //    vector<vector<int>>dp(nums.size() + 1, vector<int>(flag + 1, 0));
    //    for (int j = 0; j <= flag; j++)//物品数为0，放进容量为j的背包的方法数都为1
    //    {
    //        dp[0][j] = 1;
    //    }

    //    for (int i = 1; i <= nums.size(); i++)
    //        //求当前前i元素的方法数即为求前i-1元素任取放满容积为j的背包的方法数+已经放i的重量的背包再在前i-1元素任取放满容积为j的背包的方法数
    //        //先遍历物品---i=1开始，即物品数从1开始，放进容量为j的背包求放满的方法数dp[i][j]
    //    {
    //        for (int j = 0; j <= flag; j++)
    //        {
    //            dp[i][j] = dp[i - 1][j];
    //            if (j >= nums[i - 1])//当背包容量大于等于物品重量时
    //            {
    //                dp[i][j] += dp[i - 1][j - nums[i - 1]];
    //            }

    //        }
    //    }
    //    return dp[nums.size()][target];
    //}

    //int main()
    //{
    //    vector<int>nums;
    //    nums.push_back(1);
    //    nums.push_back(1);
    //    nums.push_back(1);
    //    nums.push_back(1);
    //    nums.push_back(1);
    //    int target = 3;
    //    int ret = findTargetSumWays(nums, target);
    //    cout << ret << endl;
    //    return 0;
    //}