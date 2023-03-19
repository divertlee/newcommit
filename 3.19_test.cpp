//606.根据二叉树创建字符串
//给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。
//空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

//class Solution {
//public:
//    string tree2str(TreeNode* root) {
//        if (root == nullptr)
//            return string();
//        string str;
//        str += to_string(root->val);
//        if (root->left)
//        {
//            str += '(';
//            str += tree2str(root->left);
//            str += ')';
//        }
//        else if (root->right)
//        {
//            str += "()";
//        }
//        if (root->right)
//        {
//            str += '(';
//            str += tree2str(root->right);
//            str += ')';
//        }
//        return str;
//    }
//};

//236.二叉树的最近公共祖先---，用空间换时间。时间是O(N);空间可就大了；创建两个stack存储从根节点到要匹配的p，q节点的路径，然后路径不相等：较多元素的栈就pop，当栈的元素数量相等时，栈顶元素不相等就都pop，相等就return
//class Solution {
//public:
//    bool getnode(TreeNode* root, TreeNode* cur, stack<TreeNode*>& path)
//    {
//        if (root == nullptr) return false;
//
//        path.push(root);
//
//        if (root == cur) return true;
//
//        bool left = getnode(root->left, cur, path);
//
//
//        bool right = getnode(root->right, cur, path);
//
//        if (left == false && right == false)
//        {
//            path.pop();
//            return false;
//        }
//        return true;
//
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == p || root == q || root == nullptr)
//            return root;
//
//        stack<TreeNode*> ppath;
//        stack<TreeNode*> qpath;
//        getnode(root, p, ppath);
//        getnode(root, q, qpath);
//
//        while (ppath.size() != qpath.size())
//        {
//            if (ppath.size() > qpath.size())
//            {
//                ppath.pop();
//            }
//            else
//            {
//                qpath.pop();
//            }
//        }
//
//        while (ppath.top() != qpath.top())
//        {
//            ppath.pop();
//            qpath.pop();
//        }
//
//        return ppath.top();
//
//    }
//};

//二叉树搜索树与双向链表---prev指针要用引用，不然就只是一份拷贝；其次当prev不为空的时候才能right链接cur，不然链表死循环了
//class Solution {
//public:
//	void inordernode(TreeNode* cur, TreeNode*& prev)
//	{
//		if (cur == nullptr) return;
//
//		inordernode(cur->left, prev);
//		cur->left = prev;
//
//		if (prev) prev->right = cur;
//
//		prev = cur;
//		inordernode(cur->right, prev);
//
//
//	}
//	TreeNode* Convert(TreeNode* pRootOfTree) {
//		if (pRootOfTree == nullptr)
//			return nullptr;
//
//		TreeNode* prev = nullptr;
//		inordernode(pRootOfTree, prev);
//
//		TreeNode* head = pRootOfTree;
//		while (head->left)
//		{
//			head = head->left;
//		}
//		return head;
//	}
//};

//贪心算法开张
//455.分发饼干假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，
//我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

//O(N^2)写法：两层for循环遍历
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end());
//        sort(s.begin(), s.end());
//        int min = 0;
//        int sum = 0;
//        for (int i = 0; i < g.size(); i++)
//        {
//            for (int j = min; j < s.size(); j++)
//            {
//                if (s[j] >= g[i])
//                {
//                    sum++;
//                    min = j + 1;
//                    break;
//                }
//            }
//        }
//        return sum;
//    }
//};

//O（N）：写法：一、先for循环遍历饼干---饼干从小到大遍历
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end());
//        sort(s.begin(), s.end());
//        int index = 0;//即能用来遍历孩子又能用来计数满足了几个孩子
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (index < g.size() && g[index] <= s[i])
//            {
//                index++;
//            }
//        }
//        return index;
//
//    }
//};

//二、for循环遍历孩子---孩子胃口从大到小遍历
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end(), greater<int>());
//        sort(s.begin(), s.end(), greater<int>());
//        int index = 0;
//        for (int i = 0; i < g.size(); i++)
//        {
//            if (index < s.size() && g[i] <= s[index])
//            {
//                index++;
//            }
//        }
//        return index;
//    }
//};
