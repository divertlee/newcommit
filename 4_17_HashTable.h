#pragma once
enum State//状态
{
	EMPTY,
	EXIST,
	DELETE,
};

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
	

	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& s)
		{
			size_t ch = 0;
			for (auto e : s)
			{
				ch *= 131;
				ch += e;
			}
			return ch;
		}
	};
namespace close
{
template<class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	State _state = EMPTY;
};
template<class K, class V,class HashF=HashFunc<K>>
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
		auto cur = Find(kv.first);
		if (cur)
		{
			//不为空--找到了
			return false;
		}
		HashF hf;
		if (_n * 10 / _table.size() > 7)//负载因子大于0.7时，需要扩容
		{
			HashTable<K, V> newHT;
			newHT._table.resize(2 * _table.size());//扩容二倍
			for (auto& e : _table)
			{
				if(e._state==EXIST)
				newHT.Insert(e._kv);
			}
			_table.swap(newHT._table);
		}
		size_t hashi =hf( kv.first) % _table.size();
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

	node* Find(const K& key)
	{
		HashF hf;
		size_t hashi =hf( key) % _table.size();

		while (_table[hashi]._state != EMPTY)
		{
			if (_table[hashi]._state==EXIST &&_table[hashi]._kv.first == key)
			{
				return &_table[hashi];
			}else
			{
				hashi++;
				hashi %= _table.size();
			}
			
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		node* cur = Find(key);
		if (cur)
		{
			cur->_state = DELETE;
			_n--;
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	vector<node> _table;
	size_t _n = 0;
};

void TestHT1()
{
	HashTable<int, int> ht;
	int a[] = { 17,27,8,28,22 ,23,24,25 };


	for (auto e : a)
	{
		if (e == 35)
			int k = 1;

		ht.Insert(make_pair(e, e));
	}

	cout << ht.Find(17) << endl;
	ht.Erase(17);

	cout << ht.Find(17) << endl;
	cout << ht.Find(27) << endl;

	cout << ht.Find(25) << endl;

	int j = 1;
}

void TestHT2()
{
	HashTable<string, int> ht;
	string arr[] = { "苹果","香蕉","西瓜","香蕉","西瓜","西瓜" };
	for (auto& e : arr)
	{

		HashNode<string,int>* cur = ht.Find(e);
		if (cur)
		{
			cur->_kv.second++;
		}
		else

		{
			ht.Insert(make_pair(e, 1));
		}
	}
	int j = 1;
}
}

namespace BUCKET
{
	template<class K,class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K,V>& kv)
		:_kv(kv)
		,_next(nullptr)
		{}
	};

	template<class K,class V,class HashF=HashFunc<K>>
	class BucketHash
	{
		typedef HashNode<K, V> node;

	public:

		BucketHash()
			:_n(0)
		{
			_tables.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))//找到了不为空
				return false;

			//没找到则插入
			if (_n == _tables.size())//载荷因子为1---满了扩容
			{
				//旧方法
				BucketHash<K, V> newHT;
				newHT._tables.resize(2 * _tables.size());//扩容二倍
				for (auto cur : _tables)
				{
					while (cur)//桶不为空
					{
						newHT.Insert(cur->_kv);
						cur = cur->_next;
					}
				}
				_tables.swap(newHT._tables);
			}
			size_t hashi = HashF()(kv.first) % _tables.size();
			node* newnode = new node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

		}

		node* Find(const K& key)
		{
			size_t hashi = HashF()(key) % _tables.size();
			node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)//找到了--返回节点的地址
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;//没找到返回空
		}

	private:
		size_t _n = 0;
		vector<node*> _tables;
	};


	void TestHT1()
	{
		BucketHash<int, int> ht;
		int a[] = { 17,27,8,28,22 ,23,24,25 };


		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		cout << ht.Find(17) << endl;
		//ht.Erase(17);

		cout << ht.Find(17) << endl;
		cout << ht.Find(27) << endl;

		cout << ht.Find(25) << endl;

		int j = 1;
	}

}