//��������������С����ֵ---����������ȱ����������㣬Ȼ���¼ǰһ����㣬����ѡ����С��ֵ

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

//�����������е�����
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
        if (count == maxcount)//����
        {
            ret.push_back(cur->val);
        }
        if (count > maxcount)
        {//����
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