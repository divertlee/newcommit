//找树下最左边孩子的值，层序遍历，返回最后一个元素的第一个元素
//class Solution {
//public:
//    void getdeepnode(TreeNode* root, vector<vector<int>>& ret, int depth)
//    {
//        if (root == nullptr)return;
//        if (depth == ret.size()) ret.push_back(vector<int>());
//        ret[depth].push_back(root->val);
//        getdeepnode(root->left, ret, depth + 1);
//        getdeepnode(root->right, ret, depth + 1);
//        return;
//    }
//    int findBottomLeftValue(TreeNode* root) {
//        if (root == nullptr)return 0;
//
//        vector<vector<int>> ret;
//        getdeepnode(root, ret, 0);
//
//        return ret[ret.size() - 1][0];
//
//    }
//};

////递归回溯，全局遍历记录最大深度，和该深度结点值，递归更新
//class Solution {
//public:
//    int result = 0;
//    int maxdepth = INT_MIN;
//    void finddeepleftson(TreeNode* root, int depth)
//    {
//        if (root->left == nullptr && root->right == nullptr)
//        {
//            if (depth > maxdepth)
//            {
//                result = root->val;
//                maxdepth = depth;
//            }
//        }
//
//        if (root->left)
//        {
//            depth++;
//            finddeepleftson(root->left, depth);
//            depth--;
//        }
//
//        if (root->right)
//        {
//            depth++;
//            finddeepleftson(root->right, depth);
//            depth--;
//        }
//        return;
//    }
//    int findBottomLeftValue(TreeNode* root) {
//        finddeepleftson(root, 0);
//        return result;
//    }
//};

//路径总和 回溯，count--为0时返回true
//递归回溯，全局遍历记录最大深度，和该深度结点值，递归更新
//class Solution {
//public:
//    int result = 0;
//    int maxdepth = INT_MIN;
//    void finddeepleftson(TreeNode* root, int depth)
//    {
//        if (root->left == nullptr && root->right == nullptr)
//        {
//            if (depth > maxdepth)
//            {
//                result = root->val;
//                maxdepth = depth;
//            }
//        }
//
//        if (root->left)
//        {
//            depth++;
//            finddeepleftson(root->left, depth);
//            depth--;
//        }
//
//        if (root->right)
//        {
//            depth++;
//            finddeepleftson(root->right, depth);
//            depth--;
//        }
//        return;
//    }
//    int findBottomLeftValue(TreeNode* root) {
//        finddeepleftson(root, 0);
//        return result;
//    }
//};

//中序和后序构建二叉树---后序遍历找根，中序遍历分割左右子树，后序遍历根据分割后的中序左右子树区间分割
//class Solution {
//public:
//    TreeNode* forktree(vector<int>& inorder, vector<int>& postorder)
//    {
//        if (postorder.size() == 0) return nullptr;
//        int newval = postorder[postorder.size() - 1];
//        TreeNode* root = new TreeNode(newval);
//        if (postorder.size() == 1) return root;
//
//        //切割中序
//        int putval = 0;
//        for (int i = 0; i < inorder.size(); i++)//在中序遍历里找根结点
//        {
//            if (inorder[i] == newval)
//            {
//                putval = i;
//                break;
//            }
//        }
//        vector<int> leftinorder(inorder.begin(), inorder.begin() + putval);
//        vector<int> rightinorder(inorder.begin() + putval + 1, inorder.end());
//        //切割后序
//        postorder.resize(postorder.size() - 1);
//        vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size());
//        vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end());
//        root->left = forktree(leftinorder, leftpostorder);
//        root->right = forktree(rightinorder, rightpostorder);
//        return root;
//    }
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
//        return    forktree(inorder, postorder);
//    }
//};

//最大二叉树--找到vector里面的最大值，然后起根，左右分割为左右数组，然后连接，递归实现
//class Solution {
//public:
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        if (nums.size() == 0)return nullptr;
//        TreeNode* root = new TreeNode(0);
//        if (nums.size() == 1)
//        {
//            root->val = nums[0];
//            return root;
//        }
//        int maxnum = 0;
//        int numleg = 0;
//        for (int i = 0; i < nums.size(); i++)//找最大值
//        {
//            if (nums[i] > maxnum)
//            {
//                maxnum = nums[i];
//                numleg = i;
//            }
//        }
//        root->val = maxnum;
//        vector<int>leftnums(nums.begin(), nums.begin() + numleg);
//        vector<int> rightnums(nums.begin() + numleg + 1, nums.end());
//        root->left = constructMaximumBinaryTree(leftnums);
//        root->right = constructMaximumBinaryTree(rightnums);
//        return root;
//    }
//};

//合并二叉树

//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//        if (root1 == nullptr && root2 == nullptr) return nullptr;
//        if (root1 == nullptr)return root2;
//        if (root2 == nullptr) return root1;
//        int newval = root1->val + root2->val;
//        TreeNode* cur = new TreeNode(newval);
//        cur->left = mergeTrees(root1->left, root2->left);
//        cur->right = mergeTrees(root1->right, root2->right);
//        return cur;
//    }
//};

//二叉搜索树的搜索
//class Solution {
//public:
//    TreeNode* searchtree(TreeNode* root, int val)
//    {
//        if (root->val == val)return root;
//        if (val < root->val)//在左边
//        {
//            if (root->left != nullptr)
//            {
//                return searchtree(root->left, val);
//            }
//        }
//        else
//        {
//            if (root->right != nullptr)
//            {
//                return searchtree(root->right, val);
//            }
//        }
//        return nullptr;
//    }
//    TreeNode* searchBST(TreeNode* root, int val) {
//        return searchtree(root, val);
//    }
//};

//判断二叉搜索树---中序遍历，把元素一个个插入数组，此时数组是有序的，然后判断是不是从小到大即可
//class Solution {
//public:
//    vector<int> result;
//    void forktree(TreeNode* root)
//    {
//        if (root == nullptr)return;
//        forktree(root->left);
//        result.push_back(root->val);
//        forktree(root->right);
//    }
//    bool isValidBST(TreeNode* root) {
//        result.clear();
//        forktree(root);
//        for (int i = 1; i < result.size(); i++)
//        {
//            if (result[i - 1] >= result[i])
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};

//迭代：模仿中序遍历，记录前一个结点pre，若pre大于cur（当前结点）就false，否则遍历完就true
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        TreeNode* prev = nullptr;
//        while (cur != nullptr || !st.empty())
//        {
//            if (cur != nullptr)
//            {
//                st.push(cur);
//                cur = cur->left;
//            }
//            else
//            {
//                cur = st.top();
//                st.pop();
//                if (prev != nullptr && prev->val >= cur->val)
//                    return false;
//                prev = cur;
//                cur = cur->right;
//            }
//        }
//        return true;
//    }
//};