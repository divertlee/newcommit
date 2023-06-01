//1143. 最长公共子序列
//dp[i][j]:text1数组长度为i时text2数组长度为j时的最大公共子序列长度
// dp(1.size()+1,(2.size()+1,0)):用dp[i][j]映射text1[i-1]和text2[j-1]这两个位置，若这两个位置的元素相等，
// 则dp[i][j]=dp[i-1][j-1]+1即在之前的前提上加多一位子序列长度
// 然而这两个元素的位置不相等时，dp[i][j]=max(dp[i][j-1],dp[i-1][j])：即延续之前的长度，
// 延续text1当前位置与text2当前位置之前的元素位置的长度或者倒过来
//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
//        for (int i = 1; i <= text1.size(); i++)
//        {
//            for (int j = 1; j <= text2.size(); j++)
//            {
//                if (text1[i - 1] == text2[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                    //   cout<<text1[i-1]<<" : "<<text2[j-1]<<endl;
//                    //   cout<<"=num: "<<dp[i][j]<<endl;
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//                    //   cout<<"!=num: "<<dp[i][j]<<endl;
//                }
//            }
//        }
//        return dp[text1.size()][text2.size()];
//    }
//};