class Solution {
public:
    void prevtreeget(TreeNode* cur, vector<int>& result)
    {
        if (cur == nullptr)return;

        result.push_back(cur->val);
        prevtreeget(cur->left, result);
        prevtreeget(cur->right, result);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)return vector<int>();
        vector<int> result;
        prevtreeget(root, result);
        return result;
    }
};

class Solution {
public:
    void afterforkget(TreeNode* cur, vector<int>& result)
    {
        if (cur == nullptr)return;
        afterforkget(cur->left, result);
        afterforkget(cur->right, result);
        result.push_back(cur->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)return vector<int>();
        vector<int> result;
        afterforkget(root, result);
        return result;
    }
};


class Solution {
public:
    void retreeget(TreeNode* root, vector<int>& result)
    {
        if (root == nullptr)return;

        retreeget(root->left, result);
        result.push_back(root->val);
        retreeget(root->right, result);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)return vector<int>();
        vector<int>result;
        retreeget(root, result);
        return result;
    }
};


