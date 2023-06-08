
//72.编辑距离
//给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 
//你可以对一个单词进行如下三种操作：
// 插入一个字符
//删除一个字符
//替换一个字符
// dp[i][j]:dp[i][j]:以word1i-1为结尾，以word2j-1为结尾的的word1=word2需要的最少编辑步骤
// 
//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//        //dp[i][j]:以word1的i-1为结尾，word2的j-1为结尾,使得word1=word2需要的最少编辑步骤dp[i][j]
//        for (int i = 1; i <= word1.size(); i++)dp[i][0] = i;
//        for (int j = 1; j <= word2.size(); j++)dp[0][j] = j;
//
//        for (int i = 1; i <= word1.size(); i++)
//        {
//            for (int j = 1; j <= word2.size(); j++)
//            {
//                if (word1[i - 1] == word2[j - 1])//字符相同
//                {
//                    dp[i][j] = dp[i - 1][j - 1];
//                }
//                else//字符不相同-替换，删除，增加
//                {
//                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//                }
//            }
//        }
//        return dp[word1.size()][word2.size()];
//
//    }
//};

//647.回文子串
//class Solution {
//public:
//    int countSubstrings(string s) {
//        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//        int ret = 0;
//        for (int i = s.size() - 1; i >= 0; i--)
//        {
//            for (int j = i; j <= s.size() - 1; j++)
//            {
//                if (s[i] == s[j])
//                {
//                    if (j - i <= 1)
//                    {
//                        ret++;
//                        dp[i][j] = true;
//                    }
//                    else if (dp[i + 1][j - 1])
//                    {
//                        ret++;
//                        dp[i][j] = true;
//                    }
//                }
//            }
//        }
//
//        return ret;
//    }
//};

class Solution {
//public:
//    int countSubstrings(string s) {
//        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//        int ret = 0;
//        for (int i = 0; i < s.size(); i++)
//        {
//            for (int j = i; j >= 0; j--)
//            {
//                if (s[i] == s[j])
//                {
//                    if (i - j <= 1)
//                    {
//                        ret++;
//                        dp[i][j] = true;
//                    }
//                    else if (dp[i - 1][j + 1])
//                    {
//                        ret++;
//                        dp[i][j] = true;
//                    }
//                }
//            }
//        }
//
//        return ret;
//    }
//};