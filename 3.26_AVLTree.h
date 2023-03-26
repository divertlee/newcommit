#pragma once
#include<assert.h>
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
		while (cur)
		{
			if (cur->_kv.first<kv.first)//���������ұ���
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)//����С���������
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//�ҵ���ͬԪ�ء�return false
				return false;
			}

			cur = new node(kv);
			if (parent->_kv.first < cur.first)//�����������ұ�
			{
				parent->_right = cur;
				cur->_parent = parent;
			}
			else
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
		}
			
			//��������ƽ������������
			while (parent)//�������������ڵ�
			{
				if (cur = parent->_left)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
				//������ƽ�����ӣ������ڵ�Ҫ��Ҫ�����ϴ�������
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
					//�β�--��ת
					if (parent->_bf == -2 && cur->_bf == -1)//����
					{
						RotateR(parent);
					}
					else if (parent->_bf = 2 && cur->_bf = 1)//����
					{
						RotateL(parent);
					}
					else if (parent->_bf == -2 && cur->_bf == 1)//��������
					{
						RotateLR(parent);
					}
					else if (parent->_bf == 2 && cur->_bf == -1)//��������
					{
						RotateRL(parent);
					}
					
				}
				else
				{
					assert(false);
				}
			}
			return true;
		}
	void  RotateR(node*parent)//����
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
		subL->_bf = parent->_bf = 0;
	}

	void RotateL(node* parent)//����
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
		subR->_bf = parent->_bf = 0;
	}

	void RotateLR(node* parent)
	{
		node* subL = parent->_left;
		node* subLR = subL->_right;
		int bf = subLR->_bf;
		RotateL(subL);
		RotateR(parent);
		if (bf == -1)//�����ڵ���subLR�����
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)//�����ڵ���subLR���ұ�
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 0)//subLR�Լ�����
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
		void RotateRL(node* parent);
		{
			node* subR = parent->_right;
			node* subRL = subR->_left;
			int bf = subRL->_bf;
			RotateR(subR);
			RotateL(parent);
			if (bf == -1)//subRL��������ӽڵ�
			{
				subR->_bf = 1;
				subRL->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == 1)//subRL���ұ����ӽڵ�
			{
				subR->_bf = 0;
				subRL->_bf = 0;
				parent->_bf = -1;
			}
			else if (bf == 0)//subRL����
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
		//�����ִ꣬��bug��--3.26������10��
		void Inorder()
		{
			_Inorder(_root);
		}
		void _Inorder(node* root)
		{
			if (root == nullptr)
			{
				return true;
			}
			
		}
}
private:
	node _root = nullptr;
};