#pragma once
enum State
{
	EMPTY,//空
	EXIST,//已存在
	DELETE,//删除的标记位
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
struct  HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t ret = 0;
		for (auto e : key)
		{
			ret *= 131;
			ret += e;
		}
		return ret;
	}
};
namespace closeHash
{
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;//默认缺省参数给空
	};

	template<class K, class V, class HashF = HashFunc<K>>
	class HashTable
	{
		typedef HashData<K, V> Data;
	public:
		HashTable()
			:_n(0)
		{
			_Table.resize(10);//默认扩容为10个空间
		}


		Data* Find(const K& key)
		{
			HashF hf;
			size_t Hashi = hf(key) % _Table.size();//找位置
			while (_Table[Hashi]._state != EMPTY)//此时的位置不是空，就有可能是存在或者是删除；如果是存在看是不是要找的值，是的话就返回值的地址，不是的话就继续找
			{
				if (_Table[Hashi]._state == EXIST && _Table[Hashi]._kv.first == key)//找到相同的值，就返回此时表里的值的节点的地址
				{
					return &_Table[Hashi];
				}
				Hashi++;
				Hashi %= _Table.size();
			}
			//找到空都没找到值，代表表里面没有这个值，返回空
			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first)) return false;
			//如果传进来的值在表中找到了，就在Find层返回表中相同的值的节点的地址，为真，在Insert层返回false；若没有找到，在Find层返回空，为假，然后进行下面的插入操作
			if (_n * 10 % _Table.size() > 7)//负载因子大于7--扩容
			{
				HashTable<K, V> newHT;
				newHT._Table.resize(_Table.size() * 2);
				for (auto& e : _Table)
				{
					if (e._state == EMPTY)
					{
						newHT.Insert(e._kv);
					}
				}
				_Table.swap(newHT._Table);//表交换

			}
			HashF hf;
			size_t Hashi = hf(kv.first) % _Table.size();//找位置
			while (_Table[Hashi]._state == EXIST)//如果存在，往后找
			{
				Hashi++;
				Hashi %= _Table.size();
			}
			_Table[Hashi]._kv = kv;//4.10.22：18：有bug，_kv调不出来！有出现了一次，貌似是map和set头文件在写这个函数之前后包引发的？？？
			_Table[Hashi]._state = EXIST;
			_n++;

			return true;
		}

		bool Erase(const K& key)
		{
			auto e = Find(key);
			if (e)
			{
				e->_state = DELETE;
				--_n;
				return true;
			}
			return false;
		}

	private:
		vector<Data> _Table;
		size_t _n;//有效元素个数
	};


	void TestHt1()
	{
		HashTable<int, int> ht;
		int a[] = { 3,13,7,27,5,35,55 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(35, 35));
		ht.Erase(35);
		//	ht.Insert(make_pair(6,6));
		ht.Erase(6);
		int j = 0;

	}

	void TestHt2()
	{
		string a[] = { "苹果","菠萝","香蕉","菠萝","苹果","苹果" };
		HashTable<string, int> ht;
		for (auto& e : a)
		{
			auto k = ht.Find(e);
			if (k)
			{
				//找到了
				k->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}

		}
		int k = 0;
	}
}

namespace bucketHash//哈希桶：哈希碰撞的元素用单链表挂起来
{
	template<class K,class V>
	struct  HashNode//指针节点
	{
		//State _state;
		pair<K, V> _kv;
		HashNode<K, V>* _next;
	};

	template<class K,class V,class HashF = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> node;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (_n == _table.size())
			{
				//扩容
			}
			if (Find(kv.first)) return false;
			HashF hf;
			size_t hashi = hf(kv.first) % _table.size();
			node* newnode = new node(kv);
			newnode->_next =_table[hashi];
			_table[hashi] = newnode;
			++_n;
			return true;
		}
	private:
		vector<node*> _table;//这个表是指针数组
		int _n = 0;//表内有效元素个数
	};
}