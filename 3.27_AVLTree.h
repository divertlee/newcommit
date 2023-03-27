#pragma once
#include<assert.h>
#include<time.h>
template<class K,class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K,class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new node(kv);
			return true;
		}
		node* parent = nullptr;
		node* cur = _root;
		while (cur)//找链接位置
		{
			if (cur->_kv.first < kv.first)//比它大，往右边走
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)//比它小，往左边走
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到相同元素。return false
				return false;
			}
		}
		//链接--cur找到空的位置
			cur = new node(kv);
			if (parent->_kv.first < cur->_kv.first)//比它大，链接右边
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
		
			
			//传给父亲平衡因子做调整
			while (parent)//最坏情况，传到根节点
			{
				if (cur == parent->_left)//链接在左边 _bf--
				{
					parent->_bf--;
				}
				else//链接在右边_bf++
				{
					parent->_bf++;
				}
				//传完了平衡因子，看父节点要不要再往上传做调整
				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//治病--旋转
					if (parent->_bf == -2 && cur->_bf == -1)//右旋
					{
						RotateR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == 1)//左旋
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)//左右正旋
					{
						RotateLR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)//右左正旋
					{
						RotateRL(parent);
					}
					else {
						assert(false);
					}
					break;
				}
				else
				{
					assert(false);
				}
			}
			return true;
		}
	void  RotateR(node*parent)//右旋
	{
		node* ppnode = parent->_parent;
		node* subL = parent->_left;
		node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		parent->_parent = subL;
		if (ppnode == nullptr)//父节点的父节点为空
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else//父节点的父节点不为空
		{
		 if (parent == ppnode->_left)//parent为父父节点的左
		{
			ppnode->_left = subL;
		}
		else//parent为父父节点的右
		{
			ppnode->_right = subL;
		}
		 subL->_parent = ppnode;
		}
		subL->_bf = parent->_bf = 0;
	}

	void RotateL(node* parent)//左旋
	{
		node* ppnode = parent->_parent;
		node* subR = parent->_right;
		node*subRL= subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;
		if (ppnode == nullptr)//父父节点为空
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else//父父节点不为空
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

	void RotateLR(node* parent)//左右正旋
	{
		node* subL = parent->_left;
		node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		if (bf == -1)//新增节点在subLR的左边
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)//新增节点在subLR的右边
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 0)//subLR自己新增
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
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
		if (bf == -1)//subRL的左边增加节点
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)//subRL的右边增加节点
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == 0)//subRL自增
		{
			subR->_bf = 0;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}

	}
	//后面手搓，出bug了--3.26，晚上10点
	void Inorder()
	{
		_Inorder(_root);
	}
	void _Inorder(node* root)//中序遍历打印
	{
		if (root == nullptr)
		{
			return ;
		}
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}
	int Height(node* root)//返回子树最大高度
	{
		if (root == nullptr)
			return 0;

		int lh = Height(root->_left);
		int rh = Height(root->_right);

		return lh > rh ? lh + 1 : rh + 1;
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		if (rightHeight - leftHeight != root->_bf)//左右子树高度查不符合此时根的平衡因子
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		return abs(rightHeight - leftHeight) < 2//验证该子树是否是平衡树
			&& IsBalance(root->_left)
			&& IsBalance(root->_right);
	}
private:
	node* _root = nullptr;
};
//{16, 3, 7, 11, 9, 26, 18, 14, 15}
void TestAVLTree1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> avt;
	for (auto e : a)
	{
		avt.Insert(make_pair(e, e));
		avt.IsBalance();
}
	avt.Inorder();
}

//void TestAVLTree()
//{
//	srand(time(0));
//	const int N = 10000;
//	AVLTree<int, int> t;
//	for (int i = 0; i < N; ++i)
//	{
//		int x = rand();
//		t.Insert(make_pair(x, x));
//		//cout << t.IsBalance() << endl;
//	}
//
//	//t.Inorder();
//
//	cout << t.IsBalance() << endl;
//}