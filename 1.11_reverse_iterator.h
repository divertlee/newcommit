#pragma once

template<class iterator,class Ref,class Ptr>//
class Reverse_Iterator
{
	typedef Reverse_Iterator<iterator,Ref,Ptr> Self;
public:
	Reverse_Iterator(iterator it)//迭代器构造反向迭代器
		:_it(it)
	{}

	Ref operator*()
	{
		iterator tmp = it;
		return *(--tmp);
	}

	Ptr operator->()
	{
		iterator& (*operator());//返回数据的地址，用引用接受
	}

	Self operator++()
	{
		--it;
		return *this;
	}

	Self operator--()
	{
		++it;
		return *this;
	}



private:
	iterator _it;
};