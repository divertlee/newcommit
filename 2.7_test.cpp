//二叉搜索树的最小绝对值---中序遍历，先遍历到最左结点，然后记录前一个结点，做差选出最小差值

//class Solution {
//public:
//    TreeNode* prev;
//    int ret = INT_MAX;
//    void findminnum(TreeNode* cur)
//    {
//        if (cur == nullptr)return;
//        findminnum(cur->left);
//        if (prev != nullptr && (cur->val - prev->val) < ret)
//        {
//            ret = cur->val - prev->val;
//        }
//        prev = cur;
//        findminnum(cur->right);
//    }
//    int getMinimumDifference(TreeNode* root) {
//
//        findminnum(root);
//        return ret;
//    }
//};

//二叉搜索树中的众数
class Solution {
public:
    int count = 0;
    int maxcount = 0;
    TreeNode* prev;
    vector<int>ret;
    void findmorenum(TreeNode* cur)
    {
        if (cur == nullptr)return;
        findmorenum(cur->left);
        if (prev == nullptr)
        {
            count = 1;
        }
        else if (prev->val == cur->val)
        {
            count++;
        }
        else {
            count = 1;
        }
        prev = cur;
        if (count == maxcount)//等于
        {
            ret.push_back(cur->val);
        }
        if (count > maxcount)
        {//大于
            maxcount = count;
            ret.clear();
            ret.push_back(cur->val);
        }
        findmorenum(cur->right);

    }
    vector<int> findMode(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
        {
            vector<int>rett;
            rett.push_back(root->val);
            return rett;
        }
        prev = nullptr;
        findmorenum(root);
        return ret;
    }
};