#pragma once
enum State
{
	EMPTY,//空
	EXIST,//已存在
	DELETE,//删除的标记位
};

template<class K,class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;//默认缺省参数给空
};

template<class K,class V>
class HashTable
{
	typedef HashData<K, V> Data;
public:
	HashTable()
		:_n(0)
	{
		_Table.resize(10);//默认扩容为10个空间
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_n * 10 % _Table.size() > 7)//负载因子大于7--扩容
		{
			HashTable<K, V> newHT;
			newHT._Table.resize(_Table.size()* 2);
			for (auto& e : _Table)
			{
				if(e.)
			}
			
		}
		size_t Hashi = kv.first % _Table.size();//找位置
		if (_Table[Hashi] == EXIST)//如果存在，往后找
		{
			Hashi++;
			Hashi %= _Table.size();
		}
		_Table[Hashi]._kv = kv;//4.10.22：18：有bug，_kv调不出来！有出现了一次，貌似是map和set头文件在写这个函数之前后包引发的？？？
		_n++;
		
	}

private:
	vector<Data> _Table;
	size_t _n;//有效元素个数
};

void TestHt()
{
	HashTable<int, int> ht;
	int a[] = { 3,13,7,27,5,35,55 };
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}

}