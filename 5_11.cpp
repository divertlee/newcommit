//213. 打家劫舍 II
//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

//给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        if (nums.size() == 1)return nums[0];
//        if (nums.size() == 2)return max(nums[0], nums[1]);
//
//        int ret1 = getmonymax(nums, 0, nums.size() - 2);
//        int ret2 = getmonymax(nums, 1, nums.size() - 1);
//        return max(ret1, ret2);
//    }
//    int getmonymax(vector<int>& nums, int start, int end)
//    {
//        vector<int>dp(nums.size(), 0);
//        dp[start] = nums[start];
//        dp[start + 1] = max(nums[start], nums[start + 1]);
//        for (size_t i = start + 2; i <= end; i++)
//        {
//            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//        return dp[end];
//    }
//};