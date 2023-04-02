#pragma once
#include<assert.h>
template<class K,class V>
struct AVLTreeNode
{
	
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> node;
public:
	bool Insert(const pair(K, V)& kv)
	{
		if (_root == nullptr)//如果根节点是空
		{
			_root = new node(kv);
			return true;
		}
		node* cur = _root;
		node* parent = nullptr;

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
		//找到位置-链接
		cur = new node(kv);
		if (cur == parent->_left)
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
			else if (parent->_bf == 1|| parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if (parent->_bf == 2&&cur->_bf==1)//此时cur为新插入节点的parent
			{
				//左正旋
				RotateL(parent);//旋谁传谁
			}
			else if (parent->_bf == -2&&cur==-1)//此时cur为新插入节点的parent
			{
				//右正旋
				RotateR(parent);
			}
			else
			{
				assert(false);
			}
		}
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
	}
private:
	node* _root = nullptr;
};

