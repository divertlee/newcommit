#pragma once


template<typename T>
struct Bstree_Node
{
 Bstree_Node<T>* _left;
 Bstree_Node<T>* _right;
	T _key;
	Bstree_Node(const T& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
	{}
};

template<typename T>
class BSTree
{
	typedef Bstree_Node<T> node;
public:
	bool insert(const T& key)
	{
		if (_root == nullptr)
		{
			_root = new node(key);
			return true;
		}
		node* parent = nullptr;
		node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;//�ҵ����²���ĵ��ֵ��ͬ���ӽڵ�-ֱ��false
			}
		}
		//�ҵ��ս��
		cur = new node(key);
		if (cur->_key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	bool find(const T& key)
	{
		node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key == cur->_key)
			{
				return true;
			}	
		}
		return false;
	}
	bool erase(const T& key)
	{
		node* parent = nullptr;
		node* cur = _root;
		if (_root == nullptr)
		{
			return false;
		}
		if (_root->_key == key)//ɾ�����ڵ�ʱ
		{
			//���ҿ�
			if (cur->_left == nullptr && cur->_right == nullptr)
			{
				_root = nullptr;
				return true;
			}
			//���
			else if (cur->_left == nullptr)
			{
				_root =_root->_right;
				return true;
			}
			//�ҿ�
			else if (cur->_right == nullptr)
			{
				_root = _root->_left;
				return true;
			}
			//���Ҷ�����
			else
			{
				node* right = cur->_right;
				while (right->_left)
				{
					right = right->_left;
				}
				right->_left = cur->_left;
				_root = right;
				return true;
			}
		}
		
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else//�ҵ���
			{//���ҽڵ㶼Ϊ��
				if (cur->_left == nullptr && cur->_right == nullptr)
				{
					if (parent->_left == cur)
					{
						delete cur;
						parent->_left = nullptr;
						return true;
					}
					else
					{
						delete cur;
						parent->_right = nullptr;
						return true;
					}
				}

				//��ڵ�Ϊ��
				else if (cur->_left == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
						delete cur;
						return true;
					}
					else
					{
						parent->_right = cur->_right;
						delete cur;
						return true;
					}
				}
				//�ҽڵ�Ϊ��
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
						delete cur;
						return true;
					}
					else
					{
						parent->_right = cur->_left;
						delete cur;
						return true;
					}
				}
				//���ҽڵ㶼��Ϊ��
				else
				{
				node* right = cur->_right;
				while (right->_left)
			{
				right = right->_left;
			}
				right->_left = cur->_left;
				if (parent->_left == cur)
				{
					parent->_left = right;
					delete cur;
					return true;
				}
				else
				{
					parent->_right = right;
					delete cur;
					return true;
				}
				}
			}
		}
		return false;
		//�ҵ��ս��
	}
	void Inorder()//���������ӡ---������
	{
		_Inorder(_root);
		cout << endl;
	}
private:
	void _Inorder(node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout <<" " << root->_key <<" " ;
		_Inorder(root->_right);

	}
	node* _root = nullptr;
};


void testbst1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.insert(e);
	}
	t.Inorder();
	if (t.find(6))
	{
	bool t1=t.erase(6);
	cout << t1 << endl;//1
 }
	t.Inorder();
	if (t.find(3))
	{
	bool t2= t.erase(199);
	cout << t2 << endl;//0
	}
	t.Inorder();
}
