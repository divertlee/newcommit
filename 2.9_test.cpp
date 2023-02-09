//删除二叉树中的结点---有五种情况--找到根结点的值为key时，根节点为空-返回空；左子树和右子树都为空-返回空；
//左空右不空-返回右子树；右空左不空-返回左子树；左右都不空-》此时把左子树连接到右子树最底最孩子处
//class Solution {
//public:
//    TreeNode* deletepoint(TreeNode* cur, int key)
//    {
//        if (cur == nullptr) return cur;
//
//        if (cur->val == key)
//        {
//            if (cur->left == nullptr && cur->right == nullptr)
//            {
//
//                return nullptr;
//            }
//            else if (cur->right == nullptr && cur->left != nullptr)
//            {
//                return cur->left;
//            }
//            else if (cur->left == nullptr && cur->right != nullptr)
//            {
//                return cur->right;
//            }
//            else//左右都不为空
//            {
//                TreeNode* right = cur->right;
//                while (right->left != nullptr)
//                {
//                    right = right->left;
//                }
//                right->left = cur->left;
//                cur = cur->right;
//                return cur;
//            }
//        }
//
//        cur->left = deletepoint(cur->left, key);
//
//        cur->right = deletepoint(cur->right, key);
//        return cur;
//    }
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        if (root == nullptr)return nullptr;
//        return deletepoint(root, key);
//    }
//};

//第二种方法
//class Solution {
//public:
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        if (root == nullptr)return nullptr;
//
//        if (root->val == key)
//        {
//            if (root->right == nullptr)//第一种情况，第一次找到对应的根节点，右子树就为空，不管左子树为什么都返回；第二章情况，此时已经把之前的根节点和右子树的最底部左节点交换了（该左节点与根节点的左子结点值最接近），然后把空和交换后的根节点覆盖
//            {
//                return root->left;
//            }
//            TreeNode* cur = root->right;
//            while (cur->left)
//            {
//                cur = cur->left;
//            }
//            swap(root->val, cur->val);//把相应的根节点的右子树的最底部左节点与key相同的根节点的值交换
//        }
//        root->left = deleteNode(root->left, key);
//
//        root->right = deleteNode(root->right, key);
//        return root;
//    }
//};

//修建二叉树，不在low，high范围内，就一直找到空返回空
//class Solution {
//public:
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        if (root == nullptr)return nullptr;
//        if (root->val < low)
//        {
//            root = trimBST(root->right, low, high);
//        }
//        else if (root->val > high)
//        {
//            root = trimBST(root->left, low, high);
//        }
//        else {
//            root->left = trimBST(root->left, low, high);
//            root->right = trimBST(root->right, low, high);
//        }
//        return root;
//
//    }
//};
//迭代法
//class Solution {
//public:
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        if (root == nullptr)return nullptr;
//
//        while (root != nullptr && (root->val<low || root->val>high))
//        {
//            if (root->val < low)
//            {
//                root = root->right;
//            }
//            else
//            {
//                root = root->left;
//            }
//        }
//
//        TreeNode* cur = root;
//        while (cur != nullptr)
//        {
//            while (cur->left != nullptr && cur->left->val < low)
//            {
//                cur->left = cur->left->right;
//            }
//            cur = cur->left;
//        }
//        cur = root;
//        while (cur != nullptr)
//        {
//            while (cur->right != nullptr && cur->right->val > high)
//            {
//                cur->right = cur->right->left;
//            }
//            cur = cur->right;
//        }
//        return root;
//    }
//};
///有序数对构建二叉树，用left和right边界划分跟，左子树和右子树
//class Solution {
//public:
//    TreeNode* forknewtree(vector<int>& nums, int left, int right)
//    {
//        if (left > right)return nullptr;
//
//        int mid = (right + left) / 2;
//        TreeNode* root = new TreeNode(nums[mid]);
//        root->left = forknewtree(nums, left, mid - 1);
//        root->right = forknewtree(nums, mid + 1, right);
//        return root;
//    }
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* root = forknewtree(nums, 0, nums.size() - 1);
//        return root;
//    }
//};

//把二叉树变为累加数
//class Solution {
//public:
//    TreeNode* prev = nullptr;
//    TreeNode* convertBST(TreeNode* root) {
//        if (root == nullptr)return nullptr;
//        root->right = convertBST(root->right);
//        if (prev != nullptr)
//        {
//            root->val += prev->val;
//        }
//        prev = root;
//        convertBST(root->left);
//        return root;
//    }
//};