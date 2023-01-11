#pragma once

template<class iterator,class Ref,class Ptr>//
class Reverse_Iterator
{
	typedef Reverse_Iterator<iterator,Ref,Ptr> Self;
public:
	Reverse_Iterator(iterator it)//���������췴�������
		:_it(it)
	{}

	Ref operator*()
	{
		iterator tmp = it;
		return *(--tmp);
	}

	Ptr operator->()
	{
		iterator& (*operator());//�������ݵĵ�ַ�������ý���
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