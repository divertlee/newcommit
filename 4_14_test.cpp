//518.��Ǯ�һ���
//�����޸���Ǯ�����߸�������ǡ��װ����������Ϊamount�ķ���
//���ر�������
//dp[j]:װ����������Ϊj�ķ�����
//�ȱ�����Ʒ������װ������Ϊj�ķ���������Ψһ�ģ���������ظ���������
//���ƹ�ʽ��dp[j]+=dp[j-coins[i]��dp[0]=1
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        vector<int>dp(amount + 1, 0);
//        dp[0] = 1;//��������Ϊ0װ���ķ�����Ϊ1
//        for (int i = 0; i < coins.size(); i++)//�ȱ�����Ʒ
//        {
//            for (int j = 0; j <= amount; j++)//�ٱ�������
//            {
//                if (j >= coins[i])
//                    dp[j] += dp[j - coins[i]];
//            }
//        }
//        return dp[amount];
//    }
//};