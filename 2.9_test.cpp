//ɾ���������еĽ��---���������--�ҵ�������ֵΪkeyʱ�����ڵ�Ϊ��-���ؿգ�����������������Ϊ��-���ؿգ�
//����Ҳ���-�������������ҿ��󲻿�-���������������Ҷ�����-����ʱ�����������ӵ������������Ӵ�
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
//            else//���Ҷ���Ϊ��
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

//�ڶ��ַ���
//class Solution {
//public:
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        if (root == nullptr)return nullptr;
//
//        if (root->val == key)
//        {
//            if (root->right == nullptr)//��һ���������һ���ҵ���Ӧ�ĸ��ڵ㣬��������Ϊ�գ�����������Ϊʲô�����أ��ڶ����������ʱ�Ѿ���֮ǰ�ĸ��ڵ������������ײ���ڵ㽻���ˣ�����ڵ�����ڵ�����ӽ��ֵ��ӽ�����Ȼ��ѿպͽ�����ĸ��ڵ㸲��
//            {
//                return root->left;
//            }
//            TreeNode* cur = root->right;
//            while (cur->left)
//            {
//                cur = cur->left;
//            }
//            swap(root->val, cur->val);//����Ӧ�ĸ��ڵ������������ײ���ڵ���key��ͬ�ĸ��ڵ��ֵ����
//        }
//        root->left = deleteNode(root->left, key);
//
//        root->right = deleteNode(root->right, key);
//        return root;
//    }
//};

//�޽�������������low��high��Χ�ڣ���һֱ�ҵ��շ��ؿ�
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
//������
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
///�������Թ�������������left��right�߽绮�ָ�����������������
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

//�Ѷ�������Ϊ�ۼ���
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