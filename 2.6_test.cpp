//����������ߺ��ӵ�ֵ������������������һ��Ԫ�صĵ�һ��Ԫ��
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

////�ݹ���ݣ�ȫ�ֱ�����¼�����ȣ��͸���Ƚ��ֵ���ݹ����
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

//·���ܺ� ���ݣ�count--Ϊ0ʱ����true
//�ݹ���ݣ�ȫ�ֱ�����¼�����ȣ��͸���Ƚ��ֵ���ݹ����
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

//����ͺ��򹹽�������---��������Ҹ�����������ָ���������������������ݷָ�������������������ָ�
//class Solution {
//public:
//    TreeNode* forktree(vector<int>& inorder, vector<int>& postorder)
//    {
//        if (postorder.size() == 0) return nullptr;
//        int newval = postorder[postorder.size() - 1];
//        TreeNode* root = new TreeNode(newval);
//        if (postorder.size() == 1) return root;
//
//        //�и�����
//        int putval = 0;
//        for (int i = 0; i < inorder.size(); i++)//������������Ҹ����
//        {
//            if (inorder[i] == newval)
//            {
//                putval = i;
//                break;
//            }
//        }
//        vector<int> leftinorder(inorder.begin(), inorder.begin() + putval);
//        vector<int> rightinorder(inorder.begin() + putval + 1, inorder.end());
//        //�и����
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

//��������--�ҵ�vector��������ֵ��Ȼ����������ҷָ�Ϊ�������飬Ȼ�����ӣ��ݹ�ʵ��
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
//        for (int i = 0; i < nums.size(); i++)//�����ֵ
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

//�ϲ�������

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

//����������������
//class Solution {
//public:
//    TreeNode* searchtree(TreeNode* root, int val)
//    {
//        if (root->val == val)return root;
//        if (val < root->val)//�����
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

//�ж϶���������---�����������Ԫ��һ�����������飬��ʱ����������ģ�Ȼ���ж��ǲ��Ǵ�С���󼴿�
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

//������ģ�������������¼ǰһ�����pre����pre����cur����ǰ��㣩��false������������true
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