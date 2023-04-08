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
//struct __RBTreeIterator//������ĵ�����
//{
//	typedef RBTreeNode<T> node;//��������
//	typedef __RBTreeIterator<T> self;//����������
//	node* _node;
//	
//	__RBTreeIterator(node* node)
//		:_node(node)
//	{}
//
//	T& operator*()//���ض�������ã�ĳ�����ݵ�����--���������ݱ���
//	{
//		return _node->_data;
//	}
//
//	T* operator->()// ���ض���ĳ�����ݵĵ�ַ
//	{
//		return &_node->_data ;
//	}
//
//	self& operator++()
//	{
//		//����������� ����
//		//��ʱbegin�Ѿ��Ǻ�������������ˣ�++�ص�������������
//		if (_node->_right)
//		{
//			node* min = _node->_right;
//			while ( min->_left)
//			{
//				min = min->_left;//����������������
//			}
//			_node = min;//�ҵ�
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


template<class T,class Self,class Ptr>//������T��T&��T*
class __RBTreeIterator
{	
	typedef RBTreeNode<T> node;
public:
	typedef __RBTreeIterator<T,Self,Ptr> self;//typedef����������
	typedef __RBTreeIterator<T, T&, T*> iterator;//typedef����������
	node* _node;

	__RBTreeIterator( node* node)//���������캯��---��㹹�������
		:_node(node)
	{}

	__RBTreeIterator(const iterator & s)
//�ϲ�Ҫconst������ʱ�����Ǵ�����ͨ����������const��������
//���ϲ�Ҫ��ͨ������ʱ�����������ͨ�������Ĺ���
		:_node(s._node)
	{}

	Self operator*()const
	{
		return _node->_data;//�����÷������ݱ���
	}

	Ptr operator->()const
	{
		return &(_node->_data);//����ȡ��ַ--�������ݵĵ�ַ
	}
	
	self operator++()//������++
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
		else//�ҿ��ˣ���parent
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
		else//�����˻ؿ�
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
	typedef __RBTreeIterator<T,T&,T*> iterator;//���ⲿʹ�ã��÷Ž�����
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
	//��һ�������Ƿ��ص����������ý�㹹��������ٷ��أ���������ڸ�ֵ�Ľ�㣬�Ͳ����½�㣬���ҷ�������½��ĵ��������ڶ�����������true
		}
		node* parent = nullptr;
		node* cur = _root;
		KeyofT kot;//����ģ�庯����������
		while (cur)//������λ��
		{
			if ( kot(cur->_data)<kot(data))//���������ұ���
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))//����С���������
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//�ҵ���ͬԪ�ء���������Ѵ��ڽڵ�ĵ�����������false
				return make_pair(iterator(cur),false);
			}
		}
		//����--cur�ҵ��յ�λ��
		cur = new node(data);
		cur->_col = RED;
		node* newnode = cur;//����cur��ָ���仯���ȼ�¼�½����ĵ�ַ
		if (kot(parent->_data) < kot(cur->_data))//�����������ұ�
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//������
		while (parent && parent->_col == RED)//��ɫ
		{
			
			node* grandparent = parent->_parent;
			if (grandparent)//g��Ϊ��
			{
				if (parent == grandparent->_left)//parent����uncle���ң�
				{
					node* uncle = grandparent->_right;
					//���һ:uncle������Ϊ��
					if (uncle && uncle->_col == RED)
					{
						parent->_col = uncle->_col = Black;//p��u���
						grandparent->_col = RED;//g���
						cur = grandparent;
						parent = cur->_parent;//���ϵ���
					}
					else 
					{
						if (cur == parent->_left)//�����,��ʱ����Ҫ����uncle�����
						{
							RotateR(grandparent);
							parent->_col = Black;
							grandparent->_col = RED;
						}
						else//cur��parent���Һ��ӣ�����������ʽ�������
						{
							RotateL(parent);
							RotateR(grandparent);
							cur->_col = Black;
							grandparent->_col = RED;
						}
						break;
					}
				}
				else//parent���ң�uncle����
				{
					node* uncle = grandparent->_left;
					if (uncle && uncle->_col == RED)//���һ
					{
						parent->_col = uncle->_col = Black;
						grandparent->_col = RED;
						cur = grandparent;
						parent=cur->_parent;
					}
					else
					{
						if (cur == parent->_right)//�����
						{
							RotateL(grandparent);
							parent->_col = Black;
							grandparent->_col = RED;
						}
						else//�����
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
//��һ�������Ƿ��ص����������ý�㹹��������ٷ��أ���������ڸ�ֵ�Ľ�㣬�Ͳ����½�㣬���ҷ�������½��ĵ��������ڶ�����������true
	}

	void  RotateR(node* parent)//����
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
		if (ppnode == nullptr)//���ڵ�ĸ��ڵ�Ϊ��
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else//���ڵ�ĸ��ڵ㲻Ϊ��
		{
			if (parent == ppnode->_left)//parentΪ�����ڵ����
			{
				ppnode->_left = subL;
			}
			else//parentΪ�����ڵ����
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}

	}

	void RotateL(node* parent)//����
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
		if (ppnode == nullptr)//�����ڵ�Ϊ��
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else//�����ڵ㲻Ϊ��
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
	void _Inorder(node* root)//���������ӡ
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
				cout << "ÿ��·���ϵĺ�ɫ�����������ͬ��Υ���˹���4" << endl;
				return false;
			}
			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "��ɫ����������֣�Υ���˹���3" << endl;
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
				ref++;//��¼�����·���Ϻ�ɫ��������
			
			Left = Left->_left;
		}
		return check(_root, 0, ref);
	}

private:
	node* _root = nullptr;
};


//void TestRBTreee()
//{
//	//������֤--��֤�����һ����
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
//	//�������֤
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