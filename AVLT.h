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
		if (_root == nullptr)//������ڵ��ǿ�
		{
			_root = new node(kv);
			return true;
		}
		node* cur = _root;
		node* parent = nullptr;
		while(cur)//û�ҵ��ղ���ȥ
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;//�ȴ����ұ���
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;//��С�������
			}
			else
			{
				return false;//�ҵ���ͬ��
			}
		}
		
		//�ҵ�λ��-����
		cur = new node(kv);
		if (cur->_kv.first < parent->_kv.first)//cur��parent�����
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else {
			parent->_right = cur;
			cur->_parent = parent;
		}
		//����ƽ������
		while (parent)//������������
		{
			if (cur == parent->_left)
			{
				parent->_bf--;//cur��parent����ߣ�ƽ������--
			}
			else
			{
				parent->_bf++;//cur��parent���ұߣ�ƽ������++
			}
			//����
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
			 if (parent->_bf == 2 && cur->_bf == 1)//��ʱcurΪ�²���ڵ��parent
			{
				//������
				RotateL(parent);//��˭��˭
			}
			else if (parent->_bf == -2 && cur->_bf == -1)//��ʱcurΪ�²���ڵ��parent
			{
				//������
				RotateR(parent);
			}
			else if (parent->_bf == -2 && cur->_bf == 1)//��������
			{
				RotateLR(parent);
			}
			else if (parent->_bf == 2 && cur->_bf == -1)//��������
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
		if (ppnode == nullptr)//�����ڵ�Ϊ��
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
	void RotateLR(node* parent)//��������
	{
		node* subL = parent->_left;
		node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);//������
		RotateR(parent);//������
		if (bf == 1)//�����ڵ���subLR���ұ�
		{
			subLR->_bf = parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)//�����ڵ���subLR�����
		{
			subLR->_bf = subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)//subLR�Լ����������ڵ�
		{
			subLR->_bf = subL->_bf = parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateRL(node* parent)//��������
	{
		node* subR = parent->_right;
		node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(subR);
		RotateL(parent);
		if (bf == 1)//�����ڵ���subRL���ұ�
		{
			subRL->_bf = subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)//�����ڵ���subRL�����
		{
			subRL->_bf = parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)//subRL�Լ����������ڵ�
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
			cout << root->_kv.first << ":" << "ƽ�������쳣" << endl;
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