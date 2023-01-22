class Solution {
public:
    bool getpathnum(TreeNode* cur, int ret)
    {
        if (cur->left == NULL && cur->right == NULL && ret == 0)
        {
            return true;
        }

        if (cur->left == NULL && cur->right == NULL)
        {
            return false;
        }

        //左
        if (cur->left)
        {
            ret -= cur->left->val;
            if (getpathnum(cur->left, ret))
            {
                return true;
            }
            ret += cur->left->val;
        }

        //右
        if (cur->right)
        {
            ret -= cur->right->val;
            if (getpathnum(cur->right, ret))
            {
                return true;
            }
            ret += cur->right->val;
        }
        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
        {
            return NULL;
        }
        int ret = targetSum;
        return getpathnum(root, ret - root->val);
    }
};



class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>>& ret, int depth)
    {

        if (cur == nullptr)
            return;
        if (ret.size() == depth)
        {
            ret.push_back(vector<int>());
        }
        ret[depth].push_back(cur->val);
        order(cur->left, ret, depth + 1);
        order(cur->right, ret, depth + 1);

    }
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> ret;
        int depth = 0;
        order(root, ret, depth);

        int num = ret[ret.size() - 1][0];
        return num;

    }
};



class Solution {
public:
    void order(TreeNode* cur, vector<vector<double>>& ret, int depth)
    {

        if (cur == nullptr)
            return;
        if (ret.size() == depth)
        {
            ret.push_back(vector<double>());
        }
        ret[depth].push_back(cur->val);
        order(cur->left, ret, depth + 1);
        order(cur->right, ret, depth + 1);

    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>> ret;
        int depth = 0;
        order(root, ret, depth);
        vector<double> rut;
        for (int i = 0; i < ret.size(); i++)
        {
            double sum = 0;
            for (int j = 0; j < ret[i].size(); j++)
            {
                sum += ret[i][j];
            }
            rut.push_back(sum / ret[i].size());
        }
        return rut;
    }
};


int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    int leftval = sumOfLeftLeaves(root->left);
    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
    {
        leftval = root->left->val;
    }



    int rightval = sumOfLeftLeaves(root->right);
    return leftval + rightval;

}


class Solution {
public:
    void getpath(TreeNode* cur, vector<int>& path, vector<string>& ret)
    {
        //中
        path.push_back(cur->val);
        if (cur->left == NULL && cur->right == NULL)//判断终止条件-到叶子节点即返回
        {
            string s_path;
            for (int i = 0; i < path.size() - 1; i++)//先不要最后一个
            {
                s_path += to_string(path[i]);
                s_path += "->";
            }
            s_path += to_string(path[path.size() - 1]);//加入最后一个
            ret.push_back(s_path);//返回给ret
            return;
        }
        //左
        if (cur->left)
        {
            getpath(cur->left, path, ret);//递归
            path.pop_back(); //回溯
        }
        //右
        if (cur->right)
        {
            getpath(cur->right, path, ret);//递归
            path.pop_back(); //回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL)
        {
            return ret;
        }
        vector<int> v;
        getpath(root, v, ret);
        return ret;
    }
};


class Solution {
public:
    int istrue(TreeNode* cur)
    {
        if (cur == NULL)
        {
            return 0;
        }

        int lefth = istrue(cur->left);
        if (lefth == -1)
        {
            return -1;
        }
        int righth = istrue(cur->right);
        if (righth == -1)
        {
            return -1;
        }

        int result = abs(lefth - righth);
        if (result > 1)
        {
            return -1;
        }
        else
        {
            return 1 + max(lefth, righth);
        }

    }
    bool isBalanced(TreeNode* root) {
        int sum = istrue(root);
        if (sum == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        queue<TreeNode*> qq;
        qq.push(root);
        int sum = 0;
        while (!qq.empty())
        {
            TreeNode* cur = qq.front();
            qq.pop();
            sum++;
            if (cur->left)
            {
                qq.push(cur->left);
            }

            if (cur->right)
            {
                qq.push(cur->right);
            }
        }
        return sum;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
        {
            return NULL;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if (cur->left)
            {
                st.push(cur->left);
            }
            if (cur->right)
            {
                st.push(cur->right);
            }

        }
        return root;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        int min_num = INT_MAX;
        if (root->left != NULL)
        {
            min_num = min(minDepth(root->left), min_num);
        }
        if (root->right != NULL)
        {
            min_num = min(minDepth(root->right), min_num);
        }
        return min_num + 1;
    }
};