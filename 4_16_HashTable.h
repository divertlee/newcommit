#pragma once
enum State//状态
{
	EMPTY,
	EXIST,
	DELETE,
};

template<class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	State _state = EMPTY;
};
template<class K, class V>
class HashTable
{
	typedef HashNode<K,V> node;
public:
	HashTable()
		:_n(0)
	{
		_table.resize(10);
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_n * 10 / _table.size() > 7)//负载因子大于0.7时，需要扩容
		{
			HashTable<K, V> newHT;
			newHT._table.resize(2 * _table.size());//扩容二倍
			for (auto& e : _table)
			{if(e._state==EXIST)
				newHT.Insert(e._kv);
			}
		}
		size_t hashi = kv.first % _table.size();
		while (_table[hashi]._state == EXIST)
		{
			hashi++;
			hashi %= _table.size();
		}
		_table[hashi]._kv = kv;
		_table[hashi]._state = EXIST;
		_n++;
		return true;
	}

private:
	vector<node> _table;
	size_t _n = 0;
};

void TestHT1()
{
	int a[] = { 17,27,8,28,22 ,23,24,25};

	HashTable<int,int> ht;
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}


	int j = 1;


}