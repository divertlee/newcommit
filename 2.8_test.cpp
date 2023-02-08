//�������������
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (p == root || q == root || root == NULL)return root;
//
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//
//        if (left != NULL && right != NULL)
//        {
//            return root;
//        }
//        else if (left == NULL && right != NULL)
//        {
//            return right;
//        }
//        else if (left != NULL && right == NULL)
//        {
//            return left;
//        }
//        else
//        {
//            return NULL;
//        }
//
//    }
//};

//����������������ڵ�---�ݹ�ʵ�֣�������㲻�����ֽڵ��м䣬�͵ݹ�

//class Solution {
//public:
//    TreeNode* findfather(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (root == NULL)return root;
//
//        if (root->val > p->val && root->val > q->val)
//        {
//            TreeNode* left = findfather(root->left, p, q);
//            if (left != NULL)
//            {
//                return left;
//            }
//        }
//
//        if (root->val < p->val && root->val < q->val)
//        {
//            TreeNode* right = findfather(root->right, p, q);
//            if (right != NULL)
//            {
//                return right;
//            }
//        }
//        return root;
//    }
//
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        return findfather(root, p, q);
//    }
//};

//������
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        while (root)
//        {
//            if (root->val > p->val && root->val > q->val)
//            {
//                root = root->left;
//            }
//            else if (root->val < p->val && root->val < q->val)
//            {
//                root = root->right;
//            }
//            else
//            {
//                return root;
//            }
//        }
//        return     NULL;
//    }
//};

//�ݹ鷨
//class Solution {
//public:
//    TreeNode* parent;
//    void forknewson(TreeNode* cur, int val)
//    {
//        if (cur == nullptr)
//        {
//            TreeNode* node = new TreeNode(val);
//            if (node->val > parent->val)
//            {
//                parent->right = node;
//            }
//            else
//            {
//                parent->left = node;
//            }
//            return;
//        }
//        parent = cur;
//        if (cur->val > val)
//        {
//            forknewson(cur->left, val);
//        }
//        if (cur->val < val)
//        {
//            forknewson(cur->right, val);
//        }
//        return;
//    }
//    TreeNode* insertIntoBST(TreeNode* root, int val) {
//        parent = new TreeNode(0);
//        if (root == nullptr)
//        {
//            parent->val = val;
//            return parent;
//        }
//        forknewson(root, val);
//
//        return root;
//
//    }
//};