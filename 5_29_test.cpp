//718. 最长重复子数组
//dp[i][j]:每个i位置上最长重复子数组长度
// i是nums1上的位置，j是nums2上的位置，其实还是暴力遍历，当nums[i-1]==nums[j-1]时，dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1)
////class Solution {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2) {
//        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
//        int ret = 0;
//        for (int i = 1; i <= nums1.size(); i++)
//        {
//            for (int j = 1; j <= nums2.size(); j++)
//            {
//                if (nums1[i - 1] == nums2[j - 1])
//                {
//                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
//                    if (dp[i][j] > ret)
//                    {
//                        ret = dp[i][j];
//                    }
//                }
//            }
//        }
//        return ret;
//    }
//};


//class Solution {
//public:
//    int findLengthOfLCIS(vector<int>& nums) {
//        vector<int>dp(nums.size(), 1);
//        int ret = 1;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (nums[i] > nums[i - 1])
//            {
//                dp[i] = max(dp[i], dp[i - 1] + 1);
//                ret = dp[i] > ret ? dp[i] : ret;
//            }
//
//        }
//        return ret;
//    }
//};