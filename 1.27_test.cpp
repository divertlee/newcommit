class Solution {
public:
    TreeNode* findfather(TreeNode* cur, TreeNode* p, TreeNode* q)
    {
        if (cur == NULL)return cur;
        if (cur->val > p->val && cur->val > q->val)
        {
            TreeNode* left = findfather(cur->left, p, q);
            if (left != NULL)
            {
                return left;
            }
            else
            {
                return NULL;
            }
        }
        if (cur->val < p->val && cur->val < q->val)
        {
            TreeNode* right = findfather(cur->right, p, q);
            if (right != NULL)
            {
                return right;
            }
            else
            {
                return NULL;
            }
        }
        return cur;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return   findfather(root, p, q);
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root)
        {
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }

            else   if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* parent = new TreeNode(0);
    void forkTree(TreeNode* cur, int val)
    {
        if (cur == NULL)
        {
            TreeNode* prev = new TreeNode(val);
            if (parent->val > val)
            {
                parent->left = prev;
                return;
            }
            if (parent->val < val)
            {
                parent->right = prev;
                return;
            }
            else
            {
                cur = prev;
            }
        }
        parent = cur;
        if (cur->val > val)forkTree(cur->left, val);
        if (cur->val < val)forkTree(cur->right, val);
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* parent = new TreeNode(0);
        if (root == NULL)
        {
            root = new TreeNode(val);
        }
        forkTree(root, val);
        return root;
    }
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;//һ��û�ҵ�
        if (root->val == key)//�ҵ���
        {
            if (root->left == nullptr && root->right == nullptr)//�������Һ��Ӷ�Ϊ��
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr)//��������Ҳ���
            {
                auto cur = root->right;
                delete root;
                return cur;
            }
            else if (root->right == nullptr)//�ġ��󲻿��ҿ�
            {
                auto cur = root->left;
                delete root;
                return cur;
            }
            else {//�塢���Ҷ�����
                TreeNode* cur = root->right;
                while (cur->left != nullptr)//������whle����Ϊroot��������������root��������������Ҫ�ҵ��������������������ߵĺ���
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }



    class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr)return root;
            if (root->val == key)
            {//�ڶ��ν���root��֮ǰroot���������������ӣ�����Ҷ�ӽڵ㣬�����Һ���Ϊ��ʱ���Ͱ����ӵĿպ͸����������Һ��Ӳ�Ϊ�������߼�����������Ҷ�ӽڵ�Ϊֹ
                if (root->right == nullptr)
                {
                    return root->left;

                }
                TreeNode* cur = root->right;
                while (cur->left != nullptr)
                {
                    cur = cur->left;//��һ�ν����ҵ�root��������������ߺ���
                }
                swap(root->val, cur->val);//��һ�ι�������root��ֵ��root�������������ӵ�ֵ����
            }
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }
    };

    class Solution {
    public:

        TreeNode* deletet(TreeNode* root)//������������ҵ�key�ڵ���������������Ҷ�ӽڵ㲢����
        {
            if (root == nullptr)return root;
            if (root->right == nullptr)return root->left;
            TreeNode* cur = root->right;

            while (cur->left)
            {
                cur = cur->left;
            }//�˿̳���cur����key�ڵ��������������Ҷ�ӽ��
            cur->left = root->left;
            return root->right;

        }
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr)return root;
            TreeNode* prev = nullptr;
            TreeNode* cur = root;
            while (cur != nullptr)//�Ҷ�Ӧ�ڵ�
            {
                if (cur->val == key) break;//�ҵ����˳�ѭ��
                //û�ҵ�
                prev = cur;//prev��¼cur���ڵ�
                if (cur->val > key)cur = cur->left;
                else cur = cur->right;
            }
            if (prev == nullptr)//���ڵ����
            {
                return deletet(root);
            }
            if (prev->left && prev->left->val == key)//cur��prev���
            {
                prev->left = deletet(cur);
            }
            if (prev->right && prev->right->val == key)//cur��prev�ұ�
            {
                prev->right = deletet(cur);
            }
            return root;
        }
    };

};


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)return root;

        if (root->val < low)//�����lowС���Ͱѱ�low����Һ��ӵ�ͷ�ڵ㴫����
        {

            return  trimBST(root->right, low, high);
        }
        if (root->val > high)//�����high�󣬾Ͱѱ�highС�����ӵ�ͷ�ڵ㴫����
        {

            return trimBST(root->left, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)return root;
        while (root != nullptr && (root->val<low || root->val>high))
        {
            if (root->val < low)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }//����Ĳ�����rootλ��[low,high]����
            //�ü�����
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            while (cur->left != nullptr && cur->left->val < low)
            {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }

        cur = root;
        while (cur != nullptr)
        {
            while (cur->right != nullptr && cur->right->val > high)
            {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }

        return root;
    }
};



class Solution {
public:
    TreeNode* forktree(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = left + ((right - left) / 2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = forktree(nums, left, mid - 1);
        root->right = forktree(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return forktree(nums, 0, nums.size() - 1);
    }
};

class Solution {
public:
    int prev = 0;
    void forkmantree(TreeNode* cur)
    {
        if (cur == nullptr) return;
        //������
        forkmantree(cur->right);
        cur->val += prev;
        prev = cur->val;
        forkmantree(cur->left);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        forkmantree(root);
        return root;
    }
};


class Solution {
public:
    int prev = 0;
    void forkmantree(TreeNode* root)
    {
        if (root == nullptr)return;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->right;
            }
            else
            {
                cur = st.top();
                st.pop();
                cur->val += prev;
                prev = cur->val;
                cur = cur->left;
            }

        }
        return;

    }
    TreeNode* convertBST(TreeNode* root) {
        forkmantree(root);
        return root;
    }
};









