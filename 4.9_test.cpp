//���ر�������
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    int N = 0;//��Ʒ����
//    int V = 0;//�����ݻ�
//    cin >> N >> V;
//    vector<int>vi(N, 0);//��i����Ʒ�����
//    vector<int>wi(N, 0);//��i����Ʒ�ļ�ֵ
//    for (int i; i < N; i++)
//    {
//        cin >> vi[i] >> wi[i];
//    }
//    vector<int>dp(V + 1, 0);
//    for (int i = 0; i < N; i++)//������Ʒ
//    {
//        for (int j = vi[i]; j <= V; j++)//���������ݻ�
//        {
//            dp[j] = max(dp[j], dp[j - vi[i]] + wi[i]);
//        }
//    }
//    cout << dp[V] << endl;
//    return 0;
//}

//474.һ����
//����һ���������ַ������� strs ���������� m �� n ��
//
//�����ҳ������� strs ������Ӽ��ĳ��ȣ����Ӽ��� ��� �� m �� 0 �� n �� 1 ��
//
//��� x ������Ԫ��Ҳ�� y ��Ԫ�أ����� x �Ǽ��� y �� �Ӽ� ��
//���ַ���������Ʒ���ַ�����0������1��������������ά���ϵ���Ʒ����
// dp[i][j]��i��1�ĸ�����j��0�ĸ�����dp[i][j]��װ��i��1j��0�ı��������Ʒ��
// ���ƹ�ʽ��dp[i][j]=max(dp[i][j],dp[i-onenum][j-zeronum]+1),��󷵻�dp[n][m];dp[i-onenum][j-zeronum]+1:�ڳ������Ʒ�Դ�����һ���������������ɵ��ݻ������Ʒ��+1�������Ʒ����
// ��ʼ����Ϊ0
// ����˼·��������ȡ�ַ�������¼�ַ�����1�ĸ���onenum,0�ĸ���zeronum��Ȼ��Ӻ���ǰ����dp
// m��n����������������ɶ��ٸ���Ʒ���ַ�������Ȼ���¸��ַ�������ʱ���ͻ����Ѿ���¼����m��n�����������Ʒ���Ͻ��и���
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));//��ά����1-n��1����ά����0��m��0
//        for (auto e : strs)//���α����ַ���
//        {
//            int onenum = 0;
//            int zeronum = 0;
//            for (auto k : e)//���μ�¼�ַ�����01����
//            {
//                if (k == '0')
//                {
//                    zeronum++;
//                }
//                else
//                {
//                    onenum++;
//                }
//            }
//            //���ַ�����01����ƥ������dp[i][j]��ÿ���ַ�������Ʒ���Դ�n��1��m��0��װ��dp[n][m]��������ַ�������Ʒ����
//            for (int i = n; i >= onenum; i--)//����1
//            {
//                for (int j = m; j >= zeronum; j--)//����0
//                {
//                    dp[i][j] = max(dp[i][j], dp[i - onenum][j - zeronum] + 1);
//                }
//            }
//        }
//        return dp[n][m];
//    }
//};