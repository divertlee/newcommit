#pragma once




//origin code
//template<class K>
//struct BSTreeNode
//{
//	BSTreeNode<K>* _left;
//	BSTreeNode<K>* _right;
//	K _key;
//
//	BSTreeNode(const K& key)
//		:_key(key)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//template<class K>
//class BSTree
//{
//	typedef BSTreeNode<K> Node;
//public:
//	BSTree()
//		:_root(nullptr)
//	{}
//
//	// 11:44
//	BSTree(const BSTree<K>& t)
//	{
//		_root = Copy(t._root);
//	}
//
//	BSTree<K>& operator=(BSTree<K> t)
//	{
//		swap(_root, t._root);
//		return *this;
//	}
//
//	~BSTree()
//	{
//		Destroy(_root);
//		_root = nullptr;
//	}
//
//	bool Insert(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(key);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		cur = new Node(key);
//		if (parent->_key < key)
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//
//		return true;
//	}
//
//	bool Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	bool Erase(const K& key)
//	{
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				// 1����Ϊ��
//				// 2����Ϊ��
//				// 3�����Ҷ���Ϊ�գ��滻ɾ��
//				if (cur->_left == nullptr)
//				{
//					//if (parent == nullptr)
//					if (cur == _root)
//					{
//						_root = cur->_right;
//					}
//					else
//					{
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_right;
//						}
//						else
//						{
//							parent->_right = cur->_right;
//						}
//					}
//
//					delete cur;
//				}
//				else if (cur->_right == nullptr)
//				{
//					//if (parent == nullptr)
//					if (cur == _root)
//					{
//						_root = cur->_left;
//					}
//					else
//					{
//						if (parent->_left == cur)
//						{
//							parent->_left = cur->_left;
//						}
//						else
//						{
//							parent->_right = cur->_left;
//						}
//					}
//
//					delete cur;
//				}
//				else
//				{
//					// ����������С�ڵ�
//					Node* parent = cur;
//					Node* minRight = cur->_right;
//					while (minRight->_left)
//					{
//						parent = minRight;
//						minRight = minRight->_left;
//					}
//
//					cur->_key = minRight->_key;
//					if (minRight == parent->_left)
//					{
//						parent->_left = minRight->_right;
//					}
//					else
//					{
//						parent->_right = minRight->_right;
//					}
//					delete minRight;
//				}
//
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	bool InsertR(const K& key)
//	{
//		return _InsertR(_root, key);
//	}
//
//	bool FindR(const K& key)
//	{
//		return _FindR(_root, key);
//	}
//
//	bool EraseR(const K& key)
//	{
//		return _EraseR(_root, key);
//	}
//
//private:
//	void Destroy(Node* root)
//	{
//		if (root == nullptr)
//			return;
//
//		Destroy(root->_left);
//		Destroy(root->_right);
//		delete root;
//	}
//
//	Node* Copy(Node* root)
//	{
//		if (root == nullptr)
//			return nullptr;
//
//		Node* newRoot = new Node(root->_key);
//		newRoot->_left = Copy(root->_left);
//		newRoot->_right = Copy(root->_right);
//
//		return newRoot;
//	}
//
//	bool _EraseR(Node*& root, const K& key)
//	{
//		if (root == nullptr)
//		{
//			return false;
//		}
//
//		if (root->_key < key)
//		{
//			return _EraseR(root->_right, key);
//		}
//		else if (root->_key > key)
//		{
//			return _EraseR(root->_left, key);
//		}
//		else
//		{
//			Node* del = root;
//			if (root->_right == nullptr)
//			{
//				root = root->_left;
//			}
//			else if (root->_left == nullptr)
//			{
//				root = root->_right;
//			}
//			else
//			{
//				Node* minRight = root->_right;
//				while (minRight->_left)
//				{
//					minRight = minRight->_left;
//				}
//
//				swap(root->_key, minRight->_key);
//
//				// ת������������ȥɾ���ڵ�
//				return _EraseR(root->_right, key);
//			}
//
//			delete del;
//
//			return true;
//		}
//	}
//
//	bool _InsertR(Node*& root, const K& key)
//	{
//		if (root == nullptr)
//		{
//			root = new Node(key);
//			return true;
//		}
//
//		if (root->_key < key)
//			return _InsertR(root->_right, key);
//		else if (root->_key > key)
//			return _InsertR(root->_left, key);
//		else
//			return false;
//	}
//
//	bool _FindR(Node* root, const K& key)
//	{
//		if (root == nullptr)
//			return false;
//
//		if (root->_key < key)
//			return _FindR(root->_right, key);
//		else if (root->_key > key)
//			return _FindR(root->_left, key);
//		else
//			return true;
//	}
//
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//			return;
//
//		_InOrder(root->_left);
//		cout << root->_key << " ";
//		_InOrder(root->_right);
//	}
//
//private:
//	Node* _root = nullptr;
//};
//
//
//void testtree2()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	BSTree<int> b1;
//	for (auto e : a)
//	{
//		b1.InsertR(e);
//	}
//	b1.InOrder();
//	BSTree<int> b2;
//	int a1[] = { 8,3,7,1 };
//	for (auto e : a1)
//	{
//		b2.InsertR(e);
//	}
//	b2.InOrder();
//	b2 = b1;
//	b2.InOrder();
//}

namespace KV {
	template<typename K,typename V>
	struct Bstree_Node
	{
		Bstree_Node<K,V>* _left;
		Bstree_Node<K,V>* _right;
		K _key;
		V _value;
		Bstree_Node(const K& key,const V& value)
			:_key(key)
			,_value(value)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};
	template<typename K,typename V >
	class BSTree
	{
		typedef Bstree_Node<K,V> node;
	public:

	void Inorder()//���������ӡ---������
		{
			_Inorder(_root);
			cout << endl;
		}

		node* _find(const K& key)
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
					return cur;
				}
			}
			return nullptr;
		}

		bool Insert(const K& key,const V&value)
				{
					if (_root == nullptr)
					{
						_root = new node(key,value);
						return true;
					}
					node* parent = nullptr;
					node* cur = _root;
					while (cur)
					{
						if (cur->_key < key)
						{
							parent = cur;
							cur = cur->_right;
						}
						else if (cur->_key > key)
						{
							parent = cur;
							cur = cur->_left;
						}
						else
						{
							return false;
						}
					}
			
					cur = new node(key,value);
					if (parent->_key < key)
					{
						parent->_right = cur;
					}
					else
					{
						parent->_left = cur;
					}
			
					return true;
				}

		void _Inorder(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_Inorder(root->_left);
			cout << " " << root->_key << " " << root->_value << endl;
			_Inorder(root->_right);

		}
	private:
		node* _root = nullptr;
	};
}
namespace K
{
	template<typename T>
	struct Bstree_Node
	{
		Bstree_Node<T>* _left;
		Bstree_Node<T>* _right;
		T _key;
		Bstree_Node(const T& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{}
	};
	template<typename T>
	class BSTree
	{
		typedef Bstree_Node<T> node;
	public:
		BSTree()//���캯��
			:_root(nullptr)
		{}
		~BSTree()//��������
		{
			Destory(_root);
			_root = nullptr;
		}
		BSTree(const BSTree<T>& t)//��������
		{
			_root = Copy(t._root);
		}
		BSTree<T>& operator= (BSTree<T> t)//��ֵ����
		{
			swap(t._root, _root);
			return *this;
		}
		bool insert_R(const T& key)
		{
			return _insert_R(_root, key);
		}

		bool erase_R(const T& key)
		{
			return _erase_R(_root, key);
		}

		bool insert(const T& key)
		{
			return _insert(key);
		}

		bool find(const T& key)
		{
			return _find(key);
		}

		bool erase(const T& key)
		{
			return _erase(key);
		}

		void Inorder()//���������ӡ---������
		{
			_Inorder(_root);
			cout << endl;
		}
	private:

		node* Copy(node* root)
		{
			if (root == nullptr)
				return nullptr;
			node* Newroot = new node(root->_key);
			Newroot->_left = Copy(root->_left);
			Newroot->_right = Copy(root->_right);
			return Newroot;
		}

		void Destory(node* root)//�������ɾ���ڵ�
		{
			if (root == nullptr)
				return;
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}

		bool _erase_R(node*& root, const T& key)//�ݹ�ʵ��erase����
		{
			if (root == nullptr)//û�ҵ�����ֱ�Ӵ���һ���սڵ����
			{
				return false;
			}

			if (root->_key > key)
			{
				return _erase_R(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _erase_R(root->_right, key);
			}
			else
			{
				node* del = root;
				//�ҵ���Ҫɾ���Ľڵ�
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else//�����ӽڵ㶼��Ϊ��
				{
					node* minright = root->_right;
					while (minright->_left)
					{
						minright = minright->_left;
					}
					//minrightΪ����������������ӽڵ�
					swap(root->_key, minright->_key);//��Ҫɾ���Ľڵ㽻��
					//ת����������ȥɾ���ڵ㣬��ʱҪɾ���Ľڵ��������Ϊ�գ����ýڵ�ʱ��Ҫ�ýڵ���ҽڵ����Ҫɾ���Ľڵ�
					return  _erase_R(root->_right, key);
				}
				delete del;
				return true;
			}
		}

		bool _erase(const T& key)//������������ֵ
		{
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
					//�ҵ���
				{
					//1.��Ϊ��
					//2.��Ϊ��
					//3.���Ҷ���Ϊ��
					if (cur->_left == nullptr)
					{
						if (cur == _root)//Ҫɾ�Ľڵ�Ϊ���ڵ�
						{
							_root = _root->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)//Ҫɾ�Ľڵ�Ϊ���ڵ�
						{
							_root = _root->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
						//���߶���Ϊ��
					{
						node* parent = cur;
						node* right = cur->_right;
						while (right->_left)
						{
							parent = right;
							right = right->_left;
						}
						cur->_key = right->_key;//����ֵ
						if (right == parent->_left)//��
						{
							parent->_left = right->_right;
						}
						else
						{
							parent->_right = right->_right;
						}
						delete right;
					}
					return true;
				}
			}
			return false;
		}

		bool _find(const T& key)
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

		bool _insert(const T& key)
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

		bool _insert_R(node*& root, const T& key)
		{
			if (root == nullptr)//�ߵ���--���ҵ�λ�ô�ź�key�Ľڵ�
			{
				root = new node(key);//��Ϊ�õ������ã���ʱ����սڵ���Ǹ��ڵ���ӽڵ�������൱��new��һ���µ��ӽڵ㣬��ʱ�Ѿ��������˸��ڵ�
				return true;
			}
			if (root->_key < key)
			{
				return (_insert_R(root->_right, key));
			}
			else if (root->_key > key)
			{
				return (_insert_R(root->_left, key));
			}
			else
			{
				return false;//������key��ͬ�Ľڵ㣬����false
			}
		}

		void _Inorder(node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_Inorder(root->_left);
			cout << " " << root->_key << " ";
			_Inorder(root->_right);

		}
		node* _root = nullptr;

		//bool _erase(const T& key)//����һ
		//{
		//	node* parent = nullptr;
		//	node* cur = _root;
		//	if (_root == nullptr)
		//	{
		//		return false;
		//	}
		//	if (_root->_key == key)//ɾ�����ڵ�ʱ
		//	{
		//		//���ҿ�
		//		if (cur->_left == nullptr && cur->_right == nullptr)
		//		{
		//			_root = nullptr;
		//			return true;
		//		}
		//		//���
		//		else if (cur->_left == nullptr)
		//		{
		//			_root =_root->_right;
		//			return true;
		//		}
		//		//�ҿ�
		//		else if (cur->_right == nullptr)
		//		{
		//			_root = _root->_left;
		//			return true;
		//		}
		//		//���Ҷ�����
		//		else
		//		{
		//			node* right = cur->_right;
		//			while (right->_left)
		//			{
		//				right = right->_left;
		//			}
		//			right->_left = cur->_left;
		//			_root = right;
		//			return true;
		//		}
		//	}
		//	
		//	while (cur)
		//	{
		//		if (key > cur->_key)
		//		{
		//			parent = cur;
		//			cur = cur->_right;
		//		}
		//		else if (key < cur->_key)
		//		{
		//			parent = cur;
		//			cur = cur->_left;
		//		}
		//		else//�ҵ���
		//		{//���ҽڵ㶼Ϊ��
		//			if (cur->_left == nullptr && cur->_right == nullptr)
		//			{
		//				if (parent->_left == cur)
		//				{
		//					delete cur;
		//					parent->_left = nullptr;
		//					return true;
		//				}
		//				else
		//				{
		//					delete cur;
		//					parent->_right = nullptr;
		//					return true;
		//				}
		//			}

		//			//��ڵ�Ϊ��
		//			else if (cur->_left == nullptr)
		//			{
		//				if (parent->_left == cur)
		//				{
		//					parent->_left = cur->_right;
		//					delete cur;
		//					return true;
		//				}
		//				else
		//				{
		//					parent->_right = cur->_right;
		//					delete cur;
		//					return true;
		//				}
		//			}
		//			//�ҽڵ�Ϊ��
		//			else if (cur->_right == nullptr)
		//			{
		//				if (parent->_left == cur)
		//				{
		//					parent->_left = cur->_left;
		//					delete cur;
		//					return true;
		//				}
		//				else
		//				{
		//					parent->_right = cur->_left;
		//					delete cur;
		//					return true;
		//				}
		//			}
		//			//���ҽڵ㶼��Ϊ��
		//			else
		//			{
		//			node* right = cur->_right;
		//			while (right->_left)
		//		{
		//			right = right->_left;
		//		}
		//			right->_left = cur->_left;
		//			if (parent->_left == cur)
		//			{
		//				parent->_left = right;
		//				delete cur;
		//				return true;
		//			}
		//			else
		//			{
		//				parent->_right = right;
		//				delete cur;
		//				return true;
		//			}
		//			}
		//		}
		//	}
		//	return false;
		//	//�ҵ��ս��
		//}
	};
}

void testbst2()
{
	KV::BSTree<string, int> kv1;
	kv1.Insert("����ũ", 1);
	kv1.Insert("��ةة", 2);
	kv1.Insert("����͢", 3);
	kv1.Insert("cxk", 25);
	kv1.Inorder();
	string name;
	cout << "������ѧ������: " << endl;
	while (cin >>name )
	{
		KV::Bstree_Node<string, int>* ret = kv1._find(name);
		if (ret == nullptr)
		{
			cout << "�����ڴ���"  << endl;
		}
		else
		{
			
			cout << "������: " << " " << name << "ȱ�δ�����: "  << " " <<ret->_value << " ��" << endl;
		}
	}
}


//void testbst1()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//K::	BSTree<int> t;
//	for (auto e : a)
//	{
//		t.insert(e);
//	}
//	t.Inorder();
//	if (t.find(1))
//	{
//	bool t1=t.erase(1);
//	cout << t1 << endl;//1
// }
//	t.Inorder();
//	if (t.find(6))
//	{
//		bool t1 = t.erase(6);
//		cout << t1 << endl;//1
//	}
//	t.Inorder();
////K::	BSTree<int> b;
////	/*b = t;
////	b.Inorder();*/
////	int b1[] = { 8, 3, 1 };
////	for (auto e : b1)
////	{
////		b.insert_R(e);
////	}
////	b = t;
////	b.Inorder();
//	
//}
