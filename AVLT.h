#pragma once

template<class K, class V>
class AVLTreeNode
{
public:
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> node;
public:
	//bool Insert(const pair<K, V>& kv)
	//{

	//}
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)//如果根节点是空
		{
			_root = new node(kv);
			return true;
		}
		node* cur = _root;
		node* parent = nullptr;
		while(cur)//没找到空不出去
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;//比大往右边走
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;//比小往左边走
			}
			else
			{
				return false;//找到相同的
			}
		}
		
		//找到位置-链接
		cur = new node(kv);
		if (cur->_kv.first < parent->_kv.first)//cur在parent的左边
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else {
			parent->_right = cur;
			cur->_parent = parent;
		}
		//调整平衡因子
		while (parent)//最坏情况调整到根
		{
			if (cur == parent->_left)
			{
				parent->_bf--;//cur在parent的左边，平衡因子--
			}
			else
			{
				parent->_bf++;//cur在parent的右边，平衡因子++
			}
			//调整
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}else if(parent->_bf==2||parent->_bf==-2)
			{ 
			 if (parent->_bf == 2 && cur->_bf == 1)//此时cur为新插入节点的parent
			{
				//左正旋
				RotateL(parent);//旋谁传谁
			}
			else if (parent->_bf == -2 && cur->_bf == -1)//此时cur为新插入节点的parent
			{
				//右正旋
				RotateR(parent);
			}
			else if (parent->_bf == -2 && cur->_bf == 1)//左右正旋
			{
				RotateLR(parent);
			}
			else if (parent->_bf == 2 && cur->_bf == -1)//右左正旋
			{
				RotateRL(parent);
			 }
			else
			 {
				 assert(false);
			 }
			 break;
			}
			else {
				assert(false);
			}
		}
		return true;
	}
	void RotateL(node* parent)
	{
		node* ppnode = parent->_parent;
		node* subR = parent->_right;
		node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL != nullptr)
		{
			subRL->_parent = parent;
		}
		parent->_parent = subR;
		subR->_left = parent;
		if (ppnode == nullptr)//父父节点为空
		{
			_root = subR;
			subR->_parent = __nullptr;
		}
		else
		{
			if (parent == ppnode->_left)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
		subR->_bf = parent->_bf = 0;
	}
	void RotateR(node* parent)
	{
		node* ppnode = parent->_parent;
		node* subL = parent->_left;
		node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		parent->_parent = subL;
		subL->_right = parent;
		if (ppnode == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == ppnode->_left)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
		subL->_bf = parent->_bf = 0;
	}
	void RotateLR(node* parent)//左右正旋
	{
		node* subL = parent->_left;
		node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);//左正旋
		RotateR(parent);//右正旋
		if (bf == 1)//新增节点在subLR的右边
		{
			subLR->_bf = parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)//新增节点在subLR的左边
		{
			subLR->_bf = subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)//subLR自己就是新增节点
		{
			subLR->_bf = subL->_bf = parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateRL(node* parent)//右左正旋
	{
		node* subR = parent->_right;
		node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);
		if (bf == 1)//新增节点在subRL的右边
		{
			subRL->_bf = subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)//新增节点在subRL的左边
		{
			subRL->_bf = parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)//subRL自己就是新增节点
		{
			subRL->_bf = subR->_bf = parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void Inorder()
	{
		_Inorder(_root);
	}

	void _Inorder(node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.second << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}
	int hight(node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int lh = hight(root->_left);
		int rh = hight(root->_right);
		return lh > rh ? lh + 1 : rh + 1;
	}
	bool Isbalance()
	{
		return _Isbalance(_root);
	}
	bool _Isbalance(node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int lefth = hight(root->_left);
		int righth = hight(root->_right);
		if (righth -lefth  != root->_bf)
		{
			cout << root->_kv.first << ":" << "平衡因子异常" << endl;
			return false;
		}
		return abs(lefth - righth) < 2
			&& _Isbalance(root->_left)
			&& _Isbalance(root->_right);
	}
private:
	node* _root = nullptr;
};

void TestAVLTree()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> at;
	for (auto e : a)
	{
		at.Insert(make_pair(e, e));
		at.Isbalance();
	}
	at.Inorder();
	
}

//void TestAVLTree()
//{
//	srand(time(0));
//	const size_t  N = 10000;
//	AVLTree<int, int> t;
//	for (size_t i = 0; i < N; ++i)
//	{
//			size_t x = rand();
//		t.Insert(make_pair(x, x));
//	//	t.Isbalance();
//	}
//
//	t.Inorder();
//	
//	
//}