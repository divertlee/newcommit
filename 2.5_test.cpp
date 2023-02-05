

//110平衡二叉树-递归法
//class Solution {
//public:
//    int gettreeplace(TreeNode* root)
//    {
//        if (root == nullptr)return 0;
//
//        int left = gettreeplace(root->left);
//        int right = gettreeplace(root->right);
//
//        if (abs(left - right) > 1 || left == -1 || right == -1)
//        {
//            return -1;
//        }
//        int max = left > right ? left : right;
//        return max + 1;
//
//
//    }
//    bool isBalanced(TreeNode* root) {
//        if (root == nullptr)return true;
//        int ret = gettreeplace(root);
//        if (ret < 0)
//        {
//            return false;
//        }
//        else
//        {
//            return true;
//        }
//
//    }
//};


//13.二叉树的全部所有路径
//class Solution {
//public:
//    void getbinarytree(TreeNode* root, vector<int>& bio_ret, vector<string>& ret)
//    {
//        bio_ret.push_back(root->val);
//        if (root->left == nullptr && root->right == nullptr)
//        {
//            string tts;
//            for (int i = 0; i < bio_ret.size() - 1; i++)
//            {
//                tts += to_string(bio_ret[i]);
//                tts += "->";
//            }
//            tts += to_string(bio_ret[bio_ret.size() - 1]);
//            ret.push_back(tts);
//            return;
//        }
//
//        if (root->left)
//        {
//            getbinarytree(root->left, bio_ret, ret);
//            bio_ret.pop_back();
//        }
//        if (root->right)
//        {
//            getbinarytree(root->right, bio_ret, ret);
//            bio_ret.pop_back();
//        }
//    }
//    vector<string> binaryTreePaths(TreeNode* root) {
//        if (root == nullptr)return vector<string>();
//        vector<int> bio_ret;
//        vector<string> ret;
//        getbinarytree(root, bio_ret, ret);
//        return ret;
//    }
//};


 //迭代实现：以前序遍历，找到把根以上的树的所有可能路劲push进栈的pathst，如果此时的根就是子树，就进结果；如果不是就pop出，继续进此时的根的子树的可能路径
//class Solution {
//public:
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<string> result;//存放最后结果
//        if (root == nullptr) { return result; }
//        stack<TreeNode*> treest;
//        stack<string> pathst;
//        treest.push(root);
//        pathst.push(to_string(root->val));
//        while (!treest.empty())
//        {
//            TreeNode* node = treest.top();
//            treest.pop();
//            string path = pathst.top();
//            pathst.pop();
//            if (node->left == nullptr && node->right == nullptr)
//            {
//                result.push_back(path);//走到叶子结点，就结果进vector
//            }
//            if (node->right)
//            {
//                treest.push(node->right);
//                pathst.push(path + "->" + to_string(node->right->val));
//            }
//
//            if (node->left)
//            {
//                treest.push(node->left);
//                pathst.push(path + "->" + to_string(node->left->val));
//            }
//
//        }
//        return result;
//    }
//};

//左子树之和
//int sumOfLeftLeaves(struct TreeNode* root) {
//    if (root == NULL)return 0;
//
//    int leftnum = sumOfLeftLeaves(root->left);
//    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)//找到左叶子
//    {
//        leftnum = root->left->val;
//    }
//    int rightnum = sumOfLeftLeaves(root->right);
//    return leftnum + rightnum;
//}
