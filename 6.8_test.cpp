
//72.�༭����
//������������ word1 �� word2�� �뷵�ؽ� word1 ת���� word2 ��ʹ�õ����ٲ����� 
//����Զ�һ�����ʽ����������ֲ�����
// ����һ���ַ�
//ɾ��һ���ַ�
//�滻һ���ַ�
// dp[i][j]:dp[i][j]:��word1i-1Ϊ��β����word2j-1Ϊ��β�ĵ�word1=word2��Ҫ�����ٱ༭����
// 
//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
//        //dp[i][j]:��word1��i-1Ϊ��β��word2��j-1Ϊ��β,ʹ��word1=word2��Ҫ�����ٱ༭����dp[i][j]
//        for (int i = 1; i <= word1.size(); i++)dp[i][0] = i;
//        for (int j = 1; j <= word2.size(); j++)dp[0][j] = j;
//
//        for (int i = 1; i <= word1.size(); i++)
//        {
//            for (int j = 1; j <= word2.size(); j++)
//            {
//                if (word1[i - 1] == word2[j - 1])//�ַ���ͬ
//                {
//                    dp[i][j] = dp[i - 1][j - 1];
//                }
//                else//�ַ�����ͬ-�滻��ɾ��������
//                {
//                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//                }
//            }
//        }
//        return dp[word1.size()][word2.size()];
//
//    }
//};

//647.�����Ӵ�
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