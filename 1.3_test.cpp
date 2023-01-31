//�������������
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //������
        if (root == nullptr)return vector<int>();
        vector<int>result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            if (cur != nullptr)
            {

                st.pop();
                st.push(cur);
                st.push(nullptr);
                if (cur->right) { st.push(cur->right); }

                if (cur->left) { st.push(cur->left); }
            }
            else
            {
                st.pop();
                cur = st.top();
                result.push_back(cur->val);
                st.pop();

            }
        }
        return result;
    }
};
//�������������
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //������
        if (root == nullptr)return vector<int>();
        vector<int>result;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            if (cur != nullptr)
            {
                st.pop();
                if (cur->right) { st.push(cur->right); }
                st.push(cur);
                st.push(nullptr);
                if (cur->left) { st.push(cur->left); }
            }
            else
            {
                st.pop();
                cur = st.top();
                result.push_back(cur->val);
                st.pop();
            }
        }
        return result;
    }
};
