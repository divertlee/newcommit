//53.最大子数组和
// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 当之前的和值加上当前i位置比i位置大就要，不然就只要当前位置，其中每次记录最大值
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        if (nums.size() == 1)return nums[0];
//        vector<int> dp(nums.size() + 1, 0);
//        int ret = INT_MIN;
//        for (int i = 1; i <= nums.size(); i++)
//        {
//            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
//            if (dp[i] > ret)ret = dp[i];
//        }
//        return ret;
//    }
//};


//392.判断子序列
// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
// 在t里找s的字符，当该字符数等于s的大小时，即s为t的子序列
//class Solution {
//public:
//    bool isSubsequence(string s, string t) {
//        if (s.size() == 0 && t.size() == 0)return true;
//        if (s.size() == 0 && t.size() != 0) return true;
//        if (s.size() != 0 && t.size() == 0) return false;
//
//
//        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
//
//        for (int i = 1; i <= s.size(); i++)
//        {
//            for (int j = 1; j <= t.size(); j++)
//            {
//                if (s[i - 1] == t[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else
//                {
//                    dp[i][j] = dp[i][j - 1];//继承之前的数量
//                }
//            }
//        }
//        if (dp[s.size()][t.size()] == s.size())
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//
//
//    }
//};

//583.两个字符串的删除操作
// 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。每步可以删除任意一个字符串中的一个字符
//若word1[i-1]==word2[i-1]则等于之前的字符串删除字符个数，若不相等，则有三种可能：
//删 word1[i-1]，删word2[j-1],或者两个删，每删除一个为一个步骤
//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//        for (int i = 1; i <= word1.size(); i++)dp[i][0] = i;
//        for (int i = 1; i <= word2.size(); i++)dp[0][i] = i;
//
//        for (int i = 1; i <= word1.size(); i++)
//        {
//            for (int j = 1; j <= word2.size(); j++)
//            {
//                if (word1[i - 1] == word2[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1];
//                }
//                else
//                {
//                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
//                }
//            }
//        }
//        return dp[word1.size()][word2.size()];
//
//    }
//};