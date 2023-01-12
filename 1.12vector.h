#pragma once

#include"Iterator.h"

namespace Vect
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		vector()//���캯��
			//��ʼ���б�-��Ҫ�õ������const��Ա��û��Ĭ�Ϲ�����Զ������ͳ�Ա
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr) {}
		template<typename tyiterator>
		vector(tyiterator first, tyiterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		~vector()//��������
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		vector(const vector<T>& v)
			/*:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)*/
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity() const//����
		{
			return _endofstorage - _start;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		

		void reserve(size_t n)//����
		{

			if (n > capacity())
			{
				size_t oldsize = size();
				T* tmp = new T[n];//����һ��tmp
				//memcpy-ǳ����
				//if (_start )//��Ҫ����---�����ݲ�Ҫ����
				//{
				//	//memcpy(tmp, _start, sizeof(T) * oldsize);ǳ������1
				//	tmp = _start;
				//	delete[] _start;
				//}
				if (_start)
				{
					for (size_t i = 0; i < oldsize; i++)
					{
						tmp[i] = _start[i];

					}
					delete[] _start;
				}


				_start = tmp;
				//operator=-���
				_finish = _start + oldsize;
				_endofstorage = _start + n;
			}

		}

		void resize(size_t n, T val = T())
		{
			if (n > size())
			{
				if (n > capacity())
				{
					reserve(n);//����
				}
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else {
				_finish = _start + n;//n<size()
			}

		}

		vector& operator[](size_t pos)//operator��������
		{
			assert(pos >= _start);
			assert(pos < _finish);
			return T[pos];
		}

		const vector& operator[](size_t pos)const //const_operator��������
		{
			assert(pos >= _start);
			assert(pos < _finish);
			return T[pos];
		}

		void push_back(const T& val)//β��
		{
			if (_finish == _endofstorage)//����Ϊ0�������˶�Ҫ����
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = val;
			++_finish;
		}

		bool empty()
		{
			return _start == _finish;
		}

		void pop_back()//βɾ
		{
			assert(!empty());
			--_finish;
		}

		void clear()
		{
			assert(!empty());
			_finish = _start;

		}

		void swap(vector<T>& v)//����
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);

		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			if (_finish == _endofstorage)//����Ϊ0�������˶�Ҫ����
			{
				size_t oldsize = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + oldsize;
			}

			iterator end = _finish;
			while (end != pos)
			{
				*(end) = *(end - 1);
				--end;
			}
			*(pos) = val;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(!empty());
			assert(pos >= _start);
			assert(pos < _finish);
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *(begin);
				++begin;
			}
			--_finish;
			return pos;
		}



	private:
		iterator _start;//0��λ��
		iterator _finish;//���һ����Ա��������һ��λ��
		iterator _endofstorage;//

	};


}
