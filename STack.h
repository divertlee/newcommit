#pragma once

namespace xxx
{

		template<typename T, class container=vector<T>>
class STack
{
public:
	void push( const T& val)
	{
		_con.push_back(val);
	}
	void pop()
	{
		_con.pop_back();
	}
	bool empty()
	{
		return _con.empty();
	}
	const T& top()
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