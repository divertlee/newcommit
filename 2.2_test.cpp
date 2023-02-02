#pragma once
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int i = 1;
	for (int j = 1; j < i; j++)
	{
		cout << "hello bug" << endl;
	}
	return 0;
}


////遍历多叉树
//class Solution {
//public:
//    vector<vector<int>> levelOrder(Node* root) {
//        if (root == nullptr)return vector<vector<int>>();
//        vector<vector<int>> ret;
//        queue<Node*> qq;
//        qq.push(root);
//        while (!qq.empty())
//        {
//            vector<int> res;
//            int size = qq.size();
//            for (int i = 0; i < size; i++)
//            {
//                Node* cur = qq.front();
//                qq.pop();
//                res.push_back(cur->val);
//                for (auto nodde : cur->children)
//                {
//                    qq.push(nodde);
//                }
//            }
//            ret.push_back(res);
//        }
//        return ret;
//    }
//};

//找每层最大值
//
//class Solution {
//public:
//    void  getforkplaytree(TreeNode* root, vector<vector<int>>& ret, int depth)
//    {
//        if (root == nullptr)return;
//        if (ret.size() == depth)ret.push_back(vector<int>());
//        ret[depth].push_back(root->val);
//        getforkplaytree(root->left, ret, depth + 1);
//        getforkplaytree(root->right, ret, depth + 1);
//        return;
//    }
//    vector<int> largestValues(TreeNode* root) {
//        if (root == nullptr)return vector<int>();
//        vector<vector<int>>ret;
//        getforkplaytree(root, ret, 0);
//        vector<int> result;
//        for (int i = 0; i < ret.size(); i++)
//        {
//            sort(ret[i].begin(), ret[i].end());//排序-从小道大
//            result.push_back(ret[i][ret[i].size() - 1]);
//        }
//        return result;
//
//    }
//};


//填充每个结点的下一个右测结点指针；先层序遍历，把结点装进队列，然后暴力遍历，让后者链接现者，然后最后那个连空
//class Solution {
//public:
//    Node* connect(Node* root) {
//        if (root == NULL)return NULL;
//        vector<vector<Node*>> ret;
//        queue<Node*> qq;
//        qq.push(root);
//        while (!qq.empty())
//        {
//            vector<Node*> tt;
//            int size = qq.size();
//            for (int i = 0; i < size; i++)
//            {
//                Node* cur = qq.front();
//                tt.push_back(cur);
//                qq.pop();
//                if (cur->left) { qq.push(cur->left); }
//                if (cur->right) { qq.push(cur->right); }
//
//            }
//            ret.push_back(tt);
//        }
//        for (int i = 0; i < ret.size(); i++)
//        {
//            int j = 1;
//            for (; j < ret[i].size(); j++)
//            {
//                ret[i][j - 1]->next = ret[i][j];
//            }
//            ret[i][j - 1]->next = NULL;
//        }
//        return root;
//    }
//};

//二叉树最大深度
//class Solution {
//public:
//    int getmaxdepth(TreeNode* cur)
//    {
//        if (cur == nullptr)return 0;
//        int left = getmaxdepth(cur->left) + 1;
//        int right = getmaxdepth(cur->right) + 1;
//        int max = left > right ? left : right;
//        return max;
//    }
//    int maxDepth(TreeNode* root) {
//        if (root == nullptr)return 0;
//        return  getmaxdepth(root);
//    }
//};


