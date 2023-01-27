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
        if (root == nullptr) return root;//一、没找到
        if (root->val == key)//找到了
        {
            if (root->left == nullptr && root->right == nullptr)//二、左右孩子都为空
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr)//三、左空右不空
            {
                auto cur = root->right;
                delete root;
                return cur;
            }
            else if (root->right == nullptr)//四、左不空右空
            {
                auto cur = root->left;
                delete root;
                return cur;
            }
            else {//五、左右都不空
                TreeNode* cur = root->right;
                while (cur->left != nullptr)//这里用whle，因为root的右子树都大于root的左子树，所以要找到右子树的最下面的最左边的孩子
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
            {//第二次进来root是之前root的右子树的最左孩子，且是叶子节点，当他右孩子为空时，就把左孩子的空和根交换，若右孩子不为空往下走继续换，换到叶子节点为止
                if (root->right == nullptr)
                {
                    return root->left;

                }
                TreeNode* cur = root->right;
                while (cur->left != nullptr)
                {
                    cur = cur->left;//第一次进来找到root的右子树的最左边孩子
                }
                swap(root->val, cur->val);//第一次过来，把root的值和root的右子树的左孩子的值交换
            }
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
            return root;
        }
    };

    class Solution {
    public:

        TreeNode* deletet(TreeNode* root)//这个函数负责找到key节点的右子树的最左边叶子节点并返回
        {
            if (root == nullptr)return root;
            if (root->right == nullptr)return root->left;
            TreeNode* cur = root->right;

            while (cur->left)
            {
                cur = cur->left;
            }//此刻出来cur就是key节点右子树的最左边叶子结点
            cur->left = root->left;
            return root->right;

        }
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr)return root;
            TreeNode* prev = nullptr;
            TreeNode* cur = root;
            while (cur != nullptr)//找对应节点
            {
                if (cur->val == key) break;//找到了退出循环
                //没找到
                prev = cur;//prev记录cur父节点
                if (cur->val > key)cur = cur->left;
                else cur = cur->right;
            }
            if (prev == nullptr)//根节点就是
            {
                return deletet(root);
            }
            if (prev->left && prev->left->val == key)//cur在prev左边
            {
                prev->left = deletet(cur);
            }
            if (prev->right && prev->right->val == key)//cur在prev右边
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

        if (root->val < low)//如果比low小，就把比low大的右孩子的头节点传给根
        {

            return  trimBST(root->right, low, high);
        }
        if (root->val > high)//如果比high大，就把比high小的左孩子的头节点传给根
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
        }//上面的操作让root位于[low,high]区间
            //裁剪子树
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
        //右中左
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









