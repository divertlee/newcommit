#pragma once
#include<assert.h>
namespace listnode
{
	

	template<typename T>
	struct list_node//�ڵ��ʼ��
	{
	
		list_node <T>* _next;
		list_node <T>* _prev;
		T _data;

		list_node(const T& val)
			:_next(nullptr)
			,_prev(nullptr)
			,_data(val)
		{}
	};

	template<typename T,typename ref>
	//template<typename T>
	struct list_iterator
	{

		typedef list_node<T> node;
		typedef list_iterator<T, ref> self;
		
		 node* _pnode;//��Ա����---��ָ��

		list_iterator(node* p)//���캯��-������
			:_pnode(p)
		{}

	ref& operator*()
		{
			return _pnode->_data;
		}

		self& operator++()//ǰ��++
		{
			_pnode = _pnode->_next;
			return *this;
		}

		self operator++(int)//����++
		{
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;//���ص�����-����Ҫ������
		}

		self& operator--()//ǰ��--
		{
			_pnode = _pnode->_prev;
			return *this;
		}

		self operator--(int)//����--
		{
			self tmp(*this);//�õ�ַ���������
			_pnode = _pnode->_prev;
			return tmp;
		}

		bool operator!=(const self& it )
		{
			return _pnode != it._pnode;
		}

		bool operator==(const self& it)
		{
			return _pnode == it._pnode;
		}

	};


	//template<typename T>
	//struct list_const_iterator
	//{

	//	typedef list_node<T> node;
	//	node* _pnode;//��Ա����---��ָ��

	//	list_const_iterator(node* p)//���캯��-������
	//		:_pnode(p)
	//	{}

	//const T& operator*()
	//	{
	//		return _pnode->_data;
	//	}

	//	list_const_iterator<T>& operator++()
	//	{
	//		_pnode = _pnode->_next;
	//		return *this;
	//	}

	//	list_const_iterator<T>& operator--()
	//	{
	//		_pnode = _pnode->_prev;
	//		return *this;
	//	}

	//	bool operator!=(const list_const_iterator<T>& it)
	//	{
	//		return _pnode != it._pnode;
	//	}

	//};

	template <typename T>
	class list//����ṹ
	{
	
		typedef list_node<T>  node;
	public:
		//typedef list_iterator<T>  iterator;
		//typedef list_const_iterator<T> const_iterator;

		typedef list_iterator<T,T&>  iterator;
		typedef list_iterator<T,const T&> const_iterator;
	
		void empty_initialize()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list()//���캯��
		{
			empty_initialize();
		
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last)//���������乹��
		{
			empty_initialize();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//list-������list<T>-list<int>-����-����ʵ���������Ķ���Ϊ����
		//lt1(lt)
		//list(const list& lt)//�����������ɵ�������
		//	��д��
		//list( const list<T>& lt)//����Ҫ��const & ûʵ��const_iterator֮ǰ��ȥ��const͵��
		//{//�Լ���ʼ��һ��
		//	empty_initialize();
		//
		//	for (const auto& e : lt)//����Ҫ������
		//	{
		//		push_back(e);
		//	}
		//}

			list(const list<T>& lt)//��������-�ִ�д��
			{//�Լ���ʼ��һ��
				empty_initialize();

				list<T> tmp(lt.begin(), lt.end());
				swap(tmp);
			}

		
		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}

		size_t size() const
		{
			return _size;
		}

		bool empty()const
		{
			return _size == 0;
		}

		~list()//����
		{
			clear();
			delete[] _head;
			_head = nullptr;
			_size = 0;
		}

		void clear()
		{
			iterator pos = begin();
			while (pos != end())
			{
			 pos=erase(pos);
			
			}
		}

		void swap( list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		void push_back(const T& val)//����������-T&
		{
			
			insert(end(), val);


		/*	node* cur = new node(val);
			node* tail = _head->_prev;
			tail->_next = cur;
			cur->_prev = tail;
			cur->_next = _head;
			_head->_prev = cur;*/
		}
		 
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		iterator insert(iterator pos, const T& val)//��pos�ڵ�ǰ�����
		{
			node* newnode = new node(val);
			node* cur = pos._pnode;
			node* prev = cur->_prev;
			//����
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;
			++_size;
			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(end());

			node* cur = pos._pnode;
			node* next = cur->_next;
			node* prev = cur->_prev;
			//����
			next->_prev = prev;
			prev->_next = next;
			delete[] cur;
			--_size;
			return iterator(next);
		}

		void pop_back()
		{
			assert(++end());
			erase(_head->_next);
		}

		void pop_front()
		{
			assert(--end());
			erase(_head->_prev);
		}

		//list<T>& operator=( const list<T>&lt)//�����const�ͱ���
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

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}


	private:
		node* _head;
		size_t _size;//����-��ߴ���Ŀ�ά����
	};

	/*void testlist1()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		lt1.push_back(5);
		list<int>::iterator it1 = lt1.begin();
		
		while (it1 != lt1.end())
		{
          cout << *it1 << " ";
		  ++it1;
		}
		cout << endl;
		for (auto e : lt1)
		{
			cout << e << " ";
		}
	}*/

}





