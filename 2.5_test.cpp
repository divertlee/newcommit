

//110ƽ�������-�ݹ鷨
//class Solution {
//public:
//    int gettreeplace(TreeNode* root)
//    {
//        if (root == nullptr)return 0;
//
//        int left = gettreeplace(root->left);
//        int right = gettreeplace(root->right);
//
//        if (abs(left - right) > 1 || left == -1 || right == -1)
//        {
//            return -1;
//        }
//        int max = left > right ? left : right;
//        return max + 1;
//
//
//    }
//    bool isBalanced(TreeNode* root) {
//        if (root == nullptr)return true;
//        int ret = gettreeplace(root);
//        if (ret < 0)
//        {
//            return false;
//        }
//        else
//        {
//            return true;
//        }
//
//    }
//};


//13.��������ȫ������·��
//class Solution {
//public:
//    void getbinarytree(TreeNode* root, vector<int>& bio_ret, vector<string>& ret)
//    {
//        bio_ret.push_back(root->val);
//        if (root->left == nullptr && root->right == nullptr)
//        {
//            string tts;
//            for (int i = 0; i < bio_ret.size() - 1; i++)
//            {
//                tts += to_string(bio_ret[i]);
//                tts += "->";
//            }
//            tts += to_string(bio_ret[bio_ret.size() - 1]);
//            ret.push_back(tts);
//            return;
//        }
//
//        if (root->left)
//        {
//            getbinarytree(root->left, bio_ret, ret);
//            bio_ret.pop_back();
//        }
//        if (root->right)
//        {
//            getbinarytree(root->right, bio_ret, ret);
//            bio_ret.pop_back();
//        }
//    }
//    vector<string> binaryTreePaths(TreeNode* root) {
//        if (root == nullptr)return vector<string>();
//        vector<int> bio_ret;
//        vector<string> ret;
//        getbinarytree(root, bio_ret, ret);
//        return ret;
//    }
//};


 //����ʵ�֣���ǰ��������ҵ��Ѹ����ϵ��������п���·��push��ջ��pathst�������ʱ�ĸ������������ͽ������������Ǿ�pop������������ʱ�ĸ��������Ŀ���·��
//class Solution {
//public:
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<string> result;//��������
//        if (root == nullptr) { return result; }
//        stack<TreeNode*> treest;
//        stack<string> pathst;
//        treest.push(root);
//        pathst.push(to_string(root->val));
//        while (!treest.empty())
//        {
//            TreeNode* node = treest.top();
//            treest.pop();
//            string path = pathst.top();
//            pathst.pop();
//            if (node->left == nullptr && node->right == nullptr)
//            {
//                result.push_back(path);//�ߵ�Ҷ�ӽ�㣬�ͽ����vector
//            }
//            if (node->right)
//            {
//                treest.push(node->right);
//                pathst.push(path + "->" + to_string(node->right->val));
//            }
//
//            if (node->left)
//            {
//                treest.push(node->left);
//                pathst.push(path + "->" + to_string(node->left->val));
//            }
//
//        }
//        return result;
//    }
//};

//������֮��
//int sumOfLeftLeaves(struct TreeNode* root) {
//    if (root == NULL)return 0;
//
//    int leftnum = sumOfLeftLeaves(root->left);
//    if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)//�ҵ���Ҷ��
//    {
//        leftnum = root->left->val;
//    }
//    int rightnum = sumOfLeftLeaves(root->right);
//    return leftnum + rightnum;
//}
