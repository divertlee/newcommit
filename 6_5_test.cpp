//53.����������
// ����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
// ��֮ǰ�ĺ�ֵ���ϵ�ǰiλ�ñ�iλ�ô��Ҫ����Ȼ��ֻҪ��ǰλ�ã�����ÿ�μ�¼���ֵ
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


//392.�ж�������
// �����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
// ��t����s���ַ��������ַ�������s�Ĵ�Сʱ����sΪt��������
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
//                    dp[i][j] = dp[i][j - 1];//�̳�֮ǰ������
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

//583.�����ַ�����ɾ������
// ������������ word1 �� word2 ������ʹ�� word1 ��  word2 ��ͬ�������С������ÿ������ɾ������һ���ַ����е�һ���ַ�
//��word1[i-1]==word2[i-1]�����֮ǰ���ַ���ɾ���ַ�������������ȣ��������ֿ��ܣ�
//ɾ word1[i-1]��ɾword2[j-1],��������ɾ��ÿɾ��һ��Ϊһ������
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