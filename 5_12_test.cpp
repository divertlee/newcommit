#include<iostream>
#include<string>
using namespace std;
//337. 打家劫舍 III
//小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
//
//除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
//
//给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
//用vector<int>[0]:表示不偷当前结点的最大现金数，vector<int>[1]:表示偷当前结点的最大现金数
// 通过后续遍历，保证每个结点只遍历一次，若偷当前结点val=root->val+left[0]+right[0]，若不偷则考虑左右孩子结点val=max(left[0],left[1])+max(right[0],right[1])
// 最后返回二者的最大值即可
//class Solution {
//public:
//    int rob(TreeNode* root) {
//        vector<int>ret = gettwobill(root);
//        return max(ret[0], ret[1]);
//    }
//    vector<int> gettwobill(TreeNode* root)
//    {
//        if (root == nullptr)return vector<int>{0, 0};
//        vector<int> leftn = gettwobill(root->left);
//        vector<int> rightn = gettwobill(root->right);
//
//        int val2 = root->val + leftn[0] + rightn[0];//偷当前结点
//        int val1 = max(leftn[0], leftn[1]) + max(rightn[0], rightn[1]);
//        return vector<int>{val1, val2};
//    }
//};
// 
//121. 买卖股票的最佳时机
//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//
//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.size() == 1)return 0;
//        vector<vector<int>>dp(prices.size(), vector<int>(3, 0));
//        dp[0][1] = -prices[0];
//        for (size_t i = 1; i < prices.size(); i++)
//        {
//            dp[i][0] = dp[i - 1][0];
//            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
//            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
//        }
//        return dp[prices.size() - 1][2];
//
//    }
//};

//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.size() == 1)return 0;
//        vector<int>dp(3, 0);
//        dp[1] = -prices[0];
//        for (size_t i = 1; i < prices.size(); i++)
//        {
//            dp[1] = max(dp[1], dp[0] - prices[i]);
//            dp[2] = max(dp[2], dp[1] + prices[i]);
//        }
//        return dp[2];
//    }
//};


double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";// 若抛异常，则后续代码都不执行了
	

	cout << "this is a test" << endl;
		return ((double)a / (double)b);


}
void Func()
{
	int len, time;
	cin >> len >> time;
	try{
		cout << Division(len, time) << endl;
	}
	catch (const char* errmsg)//抛出的异常若匹配上，后续的catch就不执行了
	{
		cout << errmsg << endl;
		cout << ">>>>>" << endl;
	}
}
int main()
{
	try {
		Func();
	}
	catch (const char* errmsg)//抛出的异常若匹配上，后续的catch就不执行了
	{
		cout << errmsg << endl;
	}
	catch (...)
	{
		cout << "unkown exception" << endl;
	}
		return 0;
}