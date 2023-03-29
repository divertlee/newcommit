#pragma once

enum Colour
{
	RED,
	BLACK,
};
template<typename K, typename V>
struct RBTreeNode
{

	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;
	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_col(RED)
	{}
};
template<typename K, typename V>
class RBTree
{
	typedef RBTreeNode<K, V> node;
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
		cur->_col = RED;
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
		//做调整


	}



private:
	node* _root;
};