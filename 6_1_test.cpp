//1143. �����������
//dp[i][j]:text1���鳤��Ϊiʱtext2���鳤��Ϊjʱ����󹫹������г���
// dp(1.size()+1,(2.size()+1,0)):��dp[i][j]ӳ��text1[i-1]��text2[j-1]������λ�ã���������λ�õ�Ԫ����ȣ�
// ��dp[i][j]=dp[i-1][j-1]+1����֮ǰ��ǰ���ϼӶ�һλ�����г���
// Ȼ��������Ԫ�ص�λ�ò����ʱ��dp[i][j]=max(dp[i][j-1],dp[i-1][j])��������֮ǰ�ĳ��ȣ�
// ����text1��ǰλ����text2��ǰλ��֮ǰ��Ԫ��λ�õĳ��Ȼ��ߵ�����
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