//选择每个位置上的最长子序列长度，逐个更新到最后
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        vector<int>dp(nums.size(), 1);
//        int ret = 1;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            for (int j = 0; j <= i - 1; j++)
//            {
//                if (nums[i] > nums[j])
//                {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                    ret = dp[i] > ret ? dp[i] : ret;
//                }
//
//
//            }
//            cout << ret << endl;
//        }
//        return ret;
//    }
//};