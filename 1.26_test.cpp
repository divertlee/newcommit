class Solution {
public:
    TreeNode* prev = NULL;
    int count = 0;
    int maxcount = 0;
    vector<int> result;
    void findnum(TreeNode* cur)
    {
        if (cur == NULL)
        {
            return;
        }
        findnum(cur->left);//��
        if (prev == NULL)//��һ���ڵ�
        {
            count = 1;
        }
        else if (prev->val == cur->val)
        {
            count++;//��Ⱦ�++
        }
        else
        {
            count = 1;//�����
        }
        prev = cur;
        if (count == maxcount)
        {
            result.push_back(cur->val);
        }
        if (count > maxcount)
        {
            maxcount = count;
            result.clear();
            result.push_back(cur->val);
        }

        findnum(cur->right);

        return;



    }
    vector<int> findMode(TreeNode* root) {
        TreeNode* prev = NULL;
        findnum(root);
        return result;
    }
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        TreeNode* prev = NULL;
        int count = 0;
        int maxcount = 0;
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;//һֱ����
            }
            else
            {
                cur = st.top();
                st.pop();
                if (prev == NULL)//��һ���ڵ�
                {
                    count = 1;
                }
                else if (prev->val == cur->val)
                {
                    count++;
                }
                else {
                    count = 1;
                }
                prev = cur;
                if (count == maxcount)
                {
                    result.push_back(cur->val);
                }
                if (count > maxcount)
                {
                    result.clear();
                    result.push_back(cur->val);
                    maxcount = count;

                }
                cur = cur->right;
            }
        }
        return result;
    }
};