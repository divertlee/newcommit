//二叉树的最小深度
//class Solution {
//public:
//    int minDepth(TreeNode* root) {
//        if (root == nullptr)return 0;
//        if (root->left == nullptr && root->right == nullptr)
//        {
//            return 1;
//        }
//        int min_num = INT_MAX;
//        if (root->left != nullptr)
//        {
//            int left = minDepth(root->left);
//            min_num = min_num < left ? min_num : left;
//        }
//        if (root->right != nullptr)
//        {
//            int right = minDepth(root->right);
//            min_num = min_num < right ? min_num : right;
//        }
//        return min_num + 1;
//    }
//};

//翻转二叉树-递归
//class Solution {
//public:
//    TreeNode* getforktree(TreeNode* cur)
//    {
//        if (cur == nullptr)return nullptr;
//        TreeNode* left = getforktree(cur->right);
//        TreeNode* right = getforktree(cur->left);
//        cur->left = left;
//        cur->right = right;
//        return cur;
//    }
//    TreeNode* invertTree(TreeNode* root) {
//        if (root == nullptr)return nullptr;
//        return getforktree(root);
//    }
//};、

////翻转二叉树--迭代
//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        if (root == nullptr)return root;
//        stack<TreeNode*> st;
//        st.push(root);
//        while (!st.empty())
//        {
//            TreeNode* cur = st.top();
//            st.pop();
//            swap(cur->left, cur->right);
//            if (cur->left) { st.push(cur->left); }
//
//            if (cur->right) { st.push(cur->right); }
//        }
//        return root;
//    }
//};
//对称二叉树--//递归实现
//class Solution {
//public:
//    bool symtree(TreeNode* left, TreeNode* right)
//    {
//        if (left == nullptr && right == nullptr)
//        {
//            return true;
//        }
//
//        if ((left == nullptr || right == nullptr) || (left->val != right->val))
//        {
//            return false;
//        }
//
//        bool fact1;
//
//        if (left->val == right->val)
//        {
//            fact1 = symtree(left->left, right->right) && symtree(left->right, right->left);
//        }
//        return fact1;
//    }
//    bool isSymmetric(TreeNode* root) {
//        if (root == nullptr)return true;
//        return  symtree(root->left, root->right);
//    }
//};


//队列迭代法

//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        if (root == nullptr)return true;
//        queue<TreeNode*> qq;
//        qq.push(root->left);
//        qq.push(root->right);
//        while (!qq.empty())
//        {
//            TreeNode* left = qq.front();
//            qq.pop();
//            TreeNode* right = qq.front();
//            qq.pop();
//            if (left == nullptr && right == nullptr)
//            {
//                continue;
//            }
//            if ((left == nullptr || right == nullptr) || (left->val != right->val))
//            {
//                return false;
//            }
//            qq.push(left->left);
//            qq.push(right->right);
//            qq.push(left->right);
//            qq.push(right->left);
//        }
//        return true;
//    }
//};


//结点个数

//class Solution {
//public:
//    int countNodes(TreeNode* root) {
//        if (root == nullptr)return 0;
//        queue<TreeNode*> qq;
//        qq.push(root);
//        int sum = 0;
//        while (!qq.empty())
//        {
//            TreeNode* cur = qq.front();
//            if (cur != nullptr)
//            {
//                qq.pop();
//                sum++;
//                if (cur->left) { qq.push(cur->left); }
//
//                if (cur->right) { qq.push(cur->right); }
//            }
//        }
//        return sum;
//    }
//
//};