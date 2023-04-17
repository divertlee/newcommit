#pragma once
enum State//״̬
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
			//��Ϊ��--�ҵ���
			return false;
		}
		HashF hf;
		if (_n * 10 / _table.size() > 7)//�������Ӵ���0.7ʱ����Ҫ����
		{
			HashTable<K, V> newHT;
			newHT._table.resize(2 * _table.size());//���ݶ���
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
	string arr[] = { "ƻ��","�㽶","����","�㽶","����","����" };
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
			if (Find(kv.first))//�ҵ��˲�Ϊ��
				return false;

			//û�ҵ������
			if (_n == _tables.size())//�غ�����Ϊ1---��������
			{
				//�ɷ���
				BucketHash<K, V> newHT;
				newHT._tables.resize(2 * _tables.size());//���ݶ���
				for (auto cur : _tables)
				{
					while (cur)//Ͱ��Ϊ��
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
				if (cur->_kv.first == key)//�ҵ���--���ؽڵ�ĵ�ַ
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;//û�ҵ����ؿ�
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