#pragma once
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<vector<int>> ret;
	vector<int> res1;
	res1.push_back(1);
	res1.push_back(2);
	res1.push_back(3);
	ret.push_back(res1);
	vector<int> res2;
	res2.push_back(10);
	res2.push_back(20);
	res2.push_back(30);
	ret.push_back(res2);
	cout << ret[0][1] << endl;
	reverse(ret.begin(), ret.end());
	return 0;
}


//层序遍历迭代
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        if (root == nullptr)return vector<vector<int>>();
//
//        vector<vector<int>>ret;
//        queue<TreeNode*> qq;
//        qq.push(root);
//        while (!qq.empty())
//        {
//            int size = qq.size();
//            vector<int>res;
//            for (int i = 0; i < size; i++)
//            {
//                TreeNode* cur = qq.front();
//                qq.pop();
//
//                res.push_back(cur->val);
//                if (cur->left) { qq.push(cur->left); }
//                if (cur->right) { qq.push(cur->right); }
//            }
//            ret.push_back(res);
//        }
//        return ret;
//    }
//};
//
//
////层序遍历递归实现
class Solution {
public:

    void  getforkplaytree(TreeNode* root, vector<vector<int>>& ret, int depth)
    {
        if (root == nullptr)return;
        if (ret.size() == depth)ret.push_back(vector<int>());
        ret[depth].push_back(root->val);
        getforkplaytree(root->left, ret, depth + 1);
        getforkplaytree(root->right, ret, depth + 1);
        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        getforkplaytree(root, ret, 0);
        return ret;
    }
};

//从下到上层序遍历
//class Solution {
//public:
//	void getforktreeplay(TreeNode* cur, vector<vector<int>>& ret, int depth)
//	{
//		if (cur == nullptr)return;
//		if (ret.size() == depth)ret.push_back(vector<int>());//到了下一层
//		ret[depth].push_back(cur->val);
//		getforktreeplay(cur->left, ret, depth + 1);
//		getforktreeplay(cur->right, ret, depth + 1);
//		return;
//	}
//	vector<vector<int>> levelOrderBottom(TreeNode* root) {
//		vector< vector<int>> ret;
//		getforktreeplay(root, ret, 0);
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};

//二叉树的右视图---先层序遍历，选择每层最后一个元素
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr)return vector<int>();
		vector< vector<int>> ret;
		queue<TreeNode*> qq;
		qq.push(root);
		while (!qq.empty())
		{
			vector<int>res;
			int size = qq.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = qq.front();
				qq.pop();
				res.push_back(cur->val);
				if (cur->left) { qq.push(cur->left); }
				if (cur->right) { qq.push(cur->right); }

			}
			ret.push_back(res);
		}
		vector<int>result;
		for (int i = 0; i < ret.size(); i++)
		{
			result.push_back(ret[i][ret[i].size() - 1]);
		}
		return result;
	}
};



//二叉树的层平均值---先层序遍历进数组，然后暴力for算出层平均值
class Solution {
public:
	void  getforkplaytree(TreeNode* root, vector<vector<double>>& ret, int depth)
	{
		if (root == nullptr)return;
		if (ret.size() == depth)ret.push_back(vector<double>());
		ret[depth].push_back(root->val);
		getforkplaytree(root->left, ret, depth + 1);
		getforkplaytree(root->right, ret, depth + 1);
		return;
	}
	vector<double> averageOfLevels(TreeNode* root) {
		if (root == nullptr)return vector<double>();
		vector<vector<double>> ret;
		getforkplaytree(root, ret, 0);
		vector<double> result;
		for (int i = 0; i < ret.size(); i++)
		{
			double sum = 0;
			for (int j = 0; j < ret[i].size(); j++)
			{
				sum += ret[i][j];
			}
			sum /= ret[i].size();
			result.push_back(sum);
		}
		return result;
	}
};

