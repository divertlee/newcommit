// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int N = 0;//��Ʒ����
    int V = 0;//�������
    cin >> N >> V;
    vector<int>ve(N, 0);//���
    vector<int>we(N, 0);//��ֵ
    for (int i = 0; i < N; i++)
    {
        cin >> ve[i] >> we[i];
    }

    vector<vector<int>> dp(N, vector<int>(V + 1, 0));
    for (int j = ve[0]; j <= V; j++)
    {
        if (V >= ve[j])
        {
            dp[0][j] = we[0];
        }
    }

    for (int i = 1; i < dp.size(); i++)//�ȱ�����Ʒ
    {
        for (int j = 0; j <= V; j++)
        {
            if (V < ve[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ve[i]] + we[i]);
            }
        }
    }
    cout << dp[N - 1][V] << endl;

    return 0;
}
//96. ��ͬ�Ķ���������
//����һ������ n ����ǡ�� n ���ڵ�����ҽڵ�ֵ�� 1 �� n ������ͬ�� ���������� �ж����֣�������������Ķ��������������� 
// class Solution {
//public:
//    //iΪ�����������ڵ�������ҽڵ�ֵ��jΪ��ʱ����ͷ�ڵ��ֵ��
//    //j-1Ϊ������������߸��ڵ��ֵ������ʼ���ֵ����i-jΪ�Һ��ӵ��������ұ߸��ڵ��ֵ������ʼ���ֵ��
//    //dp[0]=1���ڵ�ֵ����Ϊ0�����α���i��Ϊ��1��n�����i���ڵ�Ķ�����������������Ϊ�������ڵ�����*�������ڵ������ļ���
//    //��Ϊdp[i]+=dp[j-1][i-j]����i���ڵ������Ķ����������У�jֵ�����䵱ͷ�ڵ㣬
//    int numTrees(int n) {
//        vector<int> dp(n + 1);
//        dp[0] = 1;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= i; j++)
//            {
//                dp[i] += dp[j - 1] * dp[i - j];
//            }
//        }
//        return dp[n];
//    }
//};
//343.�������
//����һ�������� n ��������Ϊ k �� ������ �ĺͣ� k >= 2 ������ʹ��Щ�����ĳ˻���󻯡����� ����Ի�õ����˻� ��
// ��Ŀ˵������k��2��ʼ����ô�±�iΪ2�ĳ˻����Ϊ1dp[2]=1��dpΪ�±����ĳ˻����Ȼ�������i��3��ʼ������n��
// ��������һ��ѭ����j��j�Ǳ���ֵ��ǲ��֣���j<=i/2����j������i�ĺ�벿�ֵ�ʱ�����ǰ������Ĳ����ظ�
// dp[i]=max(dp[i],max((i-j)*j,dp[i-j]*j)����Ϊ����������������ǰ���dp���ֲ��ϣ���j�ı��������У�ȡdp[i]�ͱ���ֲ���j*��i-j���ĳ˻��ͱ���ֲ���j*dp[i-j]�˻������ֵ
    //int integerBreak(int n) {
    //    vector<int>dp(n + 1);
    //    dp[2] = 1;
    //    for (int i = 3; i <= n; i++)//dp�����3��ʼ��Ҫ����
    //    {
    //        int j = 1;
    //        for ( j = 1; j <= (i / 2); j++)
    //        {
    //            dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
    //        }
    //    }
    //    return dp[n];

    //}

    //int main()
    //{
    //    int n = 3;
    //    integerBreak(n);
    //    return 0;
    //}


//int main()
//{
//    string n ;
//    cin >> n;
//    int tmp = 0;
//    for (int i = 0; i < n.size(); i++)
//    {
//        tmp += (n[i] - '0');
//    }
//        while (tmp / 10)
//        {
//            int k = tmp / 10;
//            tmp %= 10;
//            tmp += k;
//        }
//        cout << tmp << endl;
//    
//    return 0;
//}