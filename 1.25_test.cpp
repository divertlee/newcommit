#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main()
{

	return 0;
}

class Solution {
public:
    vector<int> vec;
    void getvec(TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        getvec(root->left);
        vec.push_back(root->val);
        getvec(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        vec.clear();
        getvec(root);//二叉搜索树是有序的，所以把值都装进vec里，然后找到最小差值

        int num = INT_MAX;
        for (int i = 1; i < vec.size(); i++)
        {
            if ((vec[i] - vec[i - 1]) < num)
            {
                num = vec[i] - vec[i - 1];
            }
        }
        return num;

    }
};

class Solution {
public:
    TreeNode* prev;
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        bool left = isValidBST(root->left);
        if (prev != NULL && prev->val >= root->val) { return false; }
        prev = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == val)
        {
            return root;
        }

        if (root->val != val)
        {
            if ((root->left = searchBST(root->left, val)) != NULL)//找到了左孩子是
            {
                return root->left;
            }
            else if (((root->right = searchBST(root->right, val)) != NULL))//没找到去找右孩子
            {
                return root->right;
            }

        }
        return NULL;


    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
        {
            return NULL;
        }
        if (root1 == NULL)
        {
            return root2;
        }

        if (root2 == NULL)
        {
            return root1;
        }
        root1->left = mergeTrees(root1->left, root2->left);
        root1->val += root2->val;
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};