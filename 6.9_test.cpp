
//739. 每日温度
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替
//class Solution {
//public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        stack<int> st;
//        vector<int>ret(temperatures.size(), 0);
//        st.push(0);
//        for (int i = 1; i < temperatures.size(); i++)
//        {
//            if (temperatures[i] <= temperatures[st.top()])
//            {
//                st.push(i);
//                // cout<<"1st.push: "<<temperatures[i]<<endl;
//            }
//            else
//            {
//                while ((!st.empty()) && (temperatures[i] > temperatures[st.top()]))
//                {
//                    ret[st.top()] = i - st.top();
//                    //  cout<<"ret: "<<ret[i-1]<<"st.pop: "<<temperatures[st.top()]<<endl;
//                    st.pop();
//                }
//                st.push(i);
//                //  cout<<"2st.push: "<<temperatures[i]<<endl;
//            }
//        }
//        return ret;
//    }
//
//};

//516. 最长回文子序列
//给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
//子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
//        for (int i = 0; i < s.size(); i++)dp[i][i] = 1;
//        for (int i = s.size() - 1; i >= 0; i--)
//        {
//            for (int j = i + 1; j < s.size(); j++)
//            {
//                if (s[i] == s[j])
//                {
//                    dp[i][j] = dp[i + 1][j - 1] + 2;
//                }
//                else
//                {
//                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return dp[0][s.size() - 1];
//    }
//};