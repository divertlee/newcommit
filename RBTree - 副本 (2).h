#pragma once

enum Colour
{
	RED,
	Black,
};

template<class T>
struct RBTreeNode
{
	T _data;
	RBTreeNode<T>* _parent;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	Colour _col;
	RBTreeNode(const T& data)
		:_data(data)
		,_parent(nullptr)
		,_left(nullptr)
		,_right(nullptr)
		,_col(RED)
	{}
};
//template<class T>
//struct __RBTreeIterator//红黑树的迭代器
//{
//	typedef RBTreeNode<T> node;//红黑树结点
//	typedef __RBTreeIterator<T> self;//迭代器本身
//	node* _node;
//	
//	__RBTreeIterator(node* node)
//		:_node(node)
//	{}
//
//	T& operator*()//返回对象解引用：某个数据的引用--即对象数据本身
//	{
//		return _node->_data;
//	}
//
//	T* operator->()// 返回对象某个数据的地址
//	{
//		return &_node->_data ;
//	}
//
//	self& operator++()
//	{
//		//中序遍历：左 根右
//		//此时begin已经是红黑树的最左结点了，++回到根或者往右走
//		if (_node->_right)
//		{
//			node* min = _node->_right;
//			while ( min->_left)
//			{
//				min = min->_left;//找右子树的最左结点
//			}
//			_node = min;//找到
//		}
//		else
//		{
//			node* repat = _node;
//			node* parent = repat->_parent;
//			while (parent && repat == parent->_right)
//			{
//				repat = parent;
//				parent = repat->_parent;
//			}
//			_node = parent;
//		}
//		return *this;
//	}
//
//	bool operator!=(const self& s)
//	{
//		return _node!=s._node;
//	}
//};


template<class T,class Self,class Ptr>//依次是T，T&，T*
class __RBTreeIterator
{	
	typedef RBTreeNode<T> node;
public:
	typedef __RBTreeIterator<T,Self,Ptr> self;//typedef迭代器本身
	typedef __RBTreeIterator<T, T&, T*> iterator;//typedef迭代器本身
	node* _node;

	__RBTreeIterator( node* node)//迭代器构造函数---结点构造迭代器
		:_node(node)
	{}

	__RBTreeIterator(const iterator & s)
//上层要const迭代器时，就是传入普通迭代器构造const迭代器；
//当上层要普通迭代器时，这个就是普通迭代器的构造
		:_node(s._node)
	{}

	Self operator*()const
	{
		return _node->_data;//解引用返回数据本身
	}

	Ptr operator->()const
	{
		return &(_node->_data);//※，取地址--返回数据的地址
	}
	
	self operator++()//迭代器++
	{
		if (_node->_right)
		{
			node* min = _node->_right;
			while (min->_left)
			{
				min = min->_left;
			}
			_node = min;
		}
		else//右空了，找parent
		{
			node* cur = _node;
			node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	self operator--()
	{
		if (_node->_left)
		{
			node* max = _node->_left;
			while (max->_right)
			{
				max = max->_right;
			}
			_node = max;
		}
		else//左完了回空
		{
			node* cur = _node;
			node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	bool operator!=(const self&s)const
	{
		return _node != s._node;
	}

	bool operator==(const self& s)const
	{
		return _node == s._node;
	}

};


template<class K,class T,class KeyofT>
class RBTree
{
	typedef RBTreeNode<T> node;

public:
	typedef __RBTreeIterator<T,T&,T*> iterator;//给外部使用，得放进公有
	typedef  __RBTreeIterator<T,const T&,const T*> const_iterator;
	iterator begin()
	{
		node* left = _root->_left;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	const_iterator begin()const
	{
		node* left = _root->_left;
		while (left && left->_left)
		{
			left = left->_left;
		}
		return const_iterator(left);
	}

	const_iterator end()const
	{
		return const_iterator(nullptr);
	}

	pair<iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new node(data);
			_root->_col = Black;
			return make_pair(iterator(_root),true);
	//第一个参数是返回迭代器，先用结点构造迭代器再返回；如果不存在该值的结点，就插入新结点，并且返回这个新结点的迭代器，第二个参数返回true
		}
		node* parent = nullptr;
		node* cur = _root;
		KeyofT kot;//根据模板函数创建对象
		while (cur)//找链接位置
		{
			if ( kot(cur->_data)<kot(data))//比它大，往右边走
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))//比它小，往左边走
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到相同元素。返回这个已存在节点的迭代器，返回false
				return make_pair(iterator(cur),false);
			}
		}
		//链接--cur找到空的位置
		cur = new node(data);
		cur->_col = RED;
		node* newnode = cur;//后期cur的指向会变化，先记录新建结点的地址
		if (kot(parent->_data) < kot(cur->_data))//比它大，链接右边
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//做调整
		while (parent && parent->_col == RED)//红色
		{
			
			node* grandparent = parent->_parent;
			if (grandparent)//g不为空
			{
				if (parent == grandparent->_left)//parent在左，uncle在右？
				{
					node* uncle = grandparent->_right;
					//情况一:uncle存在且为红
					if (uncle && uncle->_col == RED)
					{
						parent->_col = uncle->_col = Black;//p和u变黑
						grandparent->_col = RED;//g变红
						cur = grandparent;
						parent = cur->_parent;//往上调整
					}
					else 
					{
						if (cur == parent->_left)//情况二,此时不需要考虑uncle结点了
						{
							RotateR(grandparent);
							parent->_col = Black;
							grandparent->_col = RED;
						}
						else//cur在parent的右孩子，呈现折现形式，情况三
						{
							RotateL(parent);
							RotateR(grandparent);
							cur->_col = Black;
							grandparent->_col = RED;
						}
						break;
					}
				}
				else//parent在右，uncle在左？
				{
					node* uncle = grandparent->_left;
					if (uncle && uncle->_col == RED)//情况一
					{
						parent->_col = uncle->_col = Black;
						grandparent->_col = RED;
						cur = grandparent;
						parent=cur->_parent;
					}
					else
					{
						if (cur == parent->_right)//情况二
						{
							RotateL(grandparent);
							parent->_col = Black;
							grandparent->_col = RED;
						}
						else//情况三
						{
							RotateR(parent);
							RotateL(grandparent);
							cur->_col = Black;
							grandparent->_col = RED;
						}
						break;
					}
				}
			}
		}
		_root->_col = Black;
		return make_pair(iterator(newnode),true);
//第一个参数是返回迭代器，先用结点构造迭代器再返回；如果不存在该值的结点，就插入新结点，并且返回这个新结点的迭代器，第二个参数返回true
	}

	void  RotateR(node* parent)//右旋
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

	}

	void RotateL(node* parent)//左旋
	{
		node* ppnode = parent->_parent;
		node* subR = parent->_right;
		node* subRL = subR->_left;
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
	}

	void Inorder()
	{
		_Inorder(_root);
	}
	void _Inorder(node* root)//中序遍历打印
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << ":" << root->_col << endl;
		_Inorder(root->_right);
	}

	bool check(node* root, int blacknum, int _ref)
	{
		if (root == nullptr)
		{
			if (blacknum != _ref)
			{
				cout << "每条路径上的黑色结点数量不相同，违反了规则4" << endl;
				return false;
			}
			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "红色结点连续出现，违背了规则3" << endl;
			return false;
		}
		if (root->_col == Black)
			blacknum++;
		
		return check(root->_left, blacknum, _ref)
			&& check(root->_right, blacknum, _ref);

	}

	bool Isbalance()
	{
		if (_root == nullptr)
		{
			return true;
		}

		if (_root->_col == RED)
		{
			return false;
		}

		int ref = 0;
		node* Left = _root;
		while (Left)
		{
			if (Left->_col == Black)
				ref++;//记录最左边路径上黑色结点的数量
			
			Left = Left->_left;
		}
		return check(_root, 0, ref);
	}

private:
	node* _root = nullptr;
};


//void TestRBTreee()
//{
//	//特例验证--验证了情况一二三
//	// int a[]={4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
//	//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
////	RBTree<int, int> rb;
////	for (auto e : a)
////	{
////		rb.Insert(make_pair(e,e));
////		rb.Isbalance();
////	}
////	rb.Inorder();
//
//	//随机数验证
//	srand(time(0));
//	const size_t  N = 10000;
//	RBTree<int, int> t;
//	for (size_t i = 0; i < N; ++i)
//	{
//			size_t x = rand();
//		t.Insert(make_pair(x, x));
//		t.Isbalance();
//	}
//
//	t.Inorder();
//}

//void TestRBT()
//{
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	RBTree<int, int> rb;
//	for (auto e : a)
//	{
//		rb.Insert(make_pair(e,e));
//		rb.Isbalance();
//	}
//	rb.Inorder();
//}