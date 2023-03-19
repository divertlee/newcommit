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
//				// 1、左为空
//				// 2、右为空
//				// 3、左右都不为空，替换删除
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
//					// 右子树的最小节点
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
//				// 转换成在子树中去删除节点
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

	void Inorder()//中序遍历打印---左中右
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
		BSTree()//构造函数
			:_root(nullptr)
		{}
		~BSTree()//析构函数
		{
			Destory(_root);
			_root = nullptr;
		}
		BSTree(const BSTree<T>& t)//拷贝构造
		{
			_root = Copy(t._root);
		}
		BSTree<T>& operator= (BSTree<T> t)//赋值重载
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

		void Inorder()//中序遍历打印---左中右
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

		void Destory(node* root)//后序遍历删除节点
		{
			if (root == nullptr)
				return;
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}

		bool _erase_R(node*& root, const T& key)//递归实现erase函数
		{
			if (root == nullptr)//没找到或者直接传了一个空节点进来
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
				//找到了要删除的节点
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else//左右子节点都不为空
				{
					node* minright = root->_right;
					while (minright->_left)
					{
						minright = minright->_left;
					}
					//minright为右子树最左最底下子节点
					swap(root->_key, minright->_key);//跟要删除的节点交换
					//转换到右子树去删除节点，此时要删除的节点的左子树为空，到该节点时，要该节点的右节点代替要删除的节点
					return  _erase_R(root->_right, key);
				}
				delete del;
				return true;
			}
		}

		bool _erase(const T& key)//方法二：交换值
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
					//找到了
				{
					//1.左为空
					//2.右为空
					//3.左右都不为空
					if (cur->_left == nullptr)
					{
						if (cur == _root)//要删的节点为根节点
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
						if (cur == _root)//要删的节点为根节点
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
						//两边都不为空
					{
						node* parent = cur;
						node* right = cur->_right;
						while (right->_left)
						{
							parent = right;
							right = right->_left;
						}
						cur->_key = right->_key;//交换值
						if (right == parent->_left)//左
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
					return false;//找到与新插入的点的值相同的子节点-直接false
				}
			}
			//找到空结点
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
			if (root == nullptr)//走到空--即找到位置存放含key的节点
			{
				root = new node(key);//因为用的是引用，此时这个空节点就是父节点的子节点别名，相当于new了一个新的子节点，此时已经链接上了父节点
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
				return false;//遇到与key相同的节点，返回false
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

		//bool _erase(const T& key)//方法一
		//{
		//	node* parent = nullptr;
		//	node* cur = _root;
		//	if (_root == nullptr)
		//	{
		//		return false;
		//	}
		//	if (_root->_key == key)//删除根节点时
		//	{
		//		//左右空
		//		if (cur->_left == nullptr && cur->_right == nullptr)
		//		{
		//			_root = nullptr;
		//			return true;
		//		}
		//		//左空
		//		else if (cur->_left == nullptr)
		//		{
		//			_root =_root->_right;
		//			return true;
		//		}
		//		//右空
		//		else if (cur->_right == nullptr)
		//		{
		//			_root = _root->_left;
		//			return true;
		//		}
		//		//左右都不空
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
		//		else//找到了
		//		{//左右节点都为空
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

		//			//左节点为空
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
		//			//右节点为空
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
		//			//左右节点都不为空
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
		//	//找到空结点
		//}
	};
}

void testbst2()
{
	KV::BSTree<string, int> kv1;
	kv1.Insert("陈立农", 1);
	kv1.Insert("范丞丞", 2);
	kv1.Insert("朱正廷", 3);
	kv1.Insert("cxk", 25);
	kv1.Inorder();
	string name;
	cout << "请输入学生名字: " << endl;
	while (cin >>name )
	{
		KV::Bstree_Node<string, int>* ret = kv1._find(name);
		if (ret == nullptr)
		{
			cout << "不存在此人"  << endl;
		}
		else
		{
			
			cout << "名字是: " << " " << name << "缺课次数是: "  << " " <<ret->_value << " 次" << endl;
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
