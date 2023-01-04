#pragma once
#include<list>
#include<queue>
namespace xxp
{
	template<typename T, class container = list<T>>
	class Queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		bool empty()
		{
			return _con.empty();
		}
		const T& front()
		{
			return _con.front();
		}
		const T& back()
		{
			return _con.back();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		container _con;
	};
}