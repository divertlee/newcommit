class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr)return vector<int>();
        stack<TreeNode*> st;
        vector<int> result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            if (cur != nullptr)
            {
                st.pop();
                result.push_back(cur->val);
                if (cur->right != nullptr)
                {
                    st.push(cur->right);
                }
                if (cur->left != nullptr)
                {
                    st.push(cur->left);
                }
            }
        }
        return result;
    }
};