#pragma once

namespace listrealize
{
	//�ڵ�
	template< typename T>
	struct listnode
	{
		listnode<T>* _prev;
		listnode<T>* _next;
		T _data;
		listnode(const T& val)
			:_prev(nullptr)
			,_next(nullptr)
			,_data(val)
		{}
	};

	//������
	template<typename T,typename ref,typename ptr> 
	struct list_iterator
	{
		typedef listnode<T> node;
		typedef list_iterator<T,ref,ptr> self;
		node* _pnode;//��Ա����-�ڵ�ָ��
		list_iterator(node* p)//���캯��
			:_pnode(p)
		{}
		
		ref operator*()
		{
			return _pnode->_data;
		}

		self& operator++()//ǰ�üӼ�
		{
			_pnode = _pnode->_next;
			return *this;
		}
		self operator++(int)//����++
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;//���ص���������Ҫ�����÷���
		}
		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
	
		ptr operator->()
		{
			return &_pnode->_data;
		}

		bool operator==(const self& it)
		{
			return _pnode == it._pnode;
		}

		bool operator!=(const self& it)
		{
			return _pnode != it._pnode;
		}

	};

	//����ṹ
	template<typename T>
	class list
	{
		typedef listnode<T> node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator< T, const T&, const T*> const_iterator;

		//list()//Ĭ�Ϲ���
		//{
		//	_head = new node(T());
		//	_head->_next = _head;
		//	_head->_prev = _head;
		//	_size = 0;
		//}
		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		size_t size()const
		{
			return _size;
		}

		bool empty()const
		{
			return _head->_next == _head;
		}
		void emptynode()//�սڵ��ʼ��
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list()//���캯��-�޲εĹ��캯��
		{
			emptynode();
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)//���������乹��
		{
			emptynode();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		
		~list()
		{
			clear();
			delete[]_head;
			_head = nullptr;
			_size = 0;

		}
		void swap( list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}
	/*	list(const list<T>& lt)
		{
			emptynode();
			for (const auto& e : lt)
			{
				push_back(e);
		}
			
		}*/
	
		list(const list<T>& lt)//�ִ�д��
		{
			emptynode();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		//list<T>& operator=(const list<T>&lt)//�����const�ͱ���
		//{
		//	if (this != &lt)
		//	{
		//		clear();
		//		for (const auto& e : lt)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

	list<T>& operator=(list<T>lt)
		{
			swap(lt);
			return *this;
		}

	void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it= erase(it);
			}
		}


		void push_back(const T& val)
		{
			insert(end(), val);
		}
		void push_front(const T& val)
		{
			insert(begin(), val);
		}
		iterator insert(iterator pos,const T& val)//��pos֮ǰ����val
		{
			node* newnode = new node(val);
			node* cur = pos._pnode;
			node* prev = cur->_prev;

			newnode->_next = cur;
			cur->_prev = newnode;
			prev->_next = newnode;
			newnode->_prev = prev;
			++_size;
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			assert(pos!=end());
			node* cur = pos._pnode;
			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete[]cur;
			--_size;
			return iterator(next);
		}
		void pop_back()
		{
			erase(--end());
		}
		void pop_front()
		{
			erase(begin());
		}
	private:
		node* _head;
		size_t _size;
	};

	struct POS
	{
		int _row;
		int _col;

		POS(int row = 0, int col = 0)
			:_row(row)
			, _col(col)
		{}
	};

	void test1()
	{
		list<POS> lt1;
		POS pos(1, 1);
		lt1.push_back(pos);
		lt1.push_back(pos);
		lt1.push_back(pos);
		lt1.push_back(pos);
		lt1.push_back(pos);
		list<POS>::iterator it = lt1.begin();
		while (it != lt1.end())
		{
			cout << it->_col << ":" << it->_row;
			++it;
		}
		cout << endl;
	}
}