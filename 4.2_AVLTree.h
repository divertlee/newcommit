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
		if (_root == nullptr)//������ڵ��ǿ�
		{
			_root = new node(kv);
			return true;
		}
		node* cur = _root;
		node* parent = nullptr;

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
		//�ҵ�λ��-����
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
			else if (parent->_bf == 1|| parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if (parent->_bf == 2&&cur->_bf==1)//��ʱcurΪ�²���ڵ��parent
			{
				//������
				RotateL(parent);//��˭��˭
			}
			else if (parent->_bf == -2&&cur==-1)//��ʱcurΪ�²���ڵ��parent
			{
				//������
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
	}
private:
	node* _root = nullptr;
};

