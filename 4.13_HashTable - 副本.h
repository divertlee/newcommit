#pragma once
enum State
{
	EMPTY,//��
	EXIST,//�Ѵ���
	DELETE,//ɾ���ı��λ
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
		State _state = EMPTY;//Ĭ��ȱʡ��������
	};

	template<class K, class V, class HashF = HashFunc<K>>
	class HashTable
	{
		typedef HashData<K, V> Data;
	public:
		HashTable()
			:_n(0)
		{
			_Table.resize(10);//Ĭ������Ϊ10���ռ�
		}


		Data* Find(const K& key)
		{
			HashF hf;
			size_t Hashi = hf(key) % _Table.size();//��λ��
			while (_Table[Hashi]._state != EMPTY)//��ʱ��λ�ò��ǿգ����п����Ǵ��ڻ�����ɾ��������Ǵ��ڿ��ǲ���Ҫ�ҵ�ֵ���ǵĻ��ͷ���ֵ�ĵ�ַ�����ǵĻ��ͼ�����
			{
				if (_Table[Hashi]._state == EXIST && _Table[Hashi]._kv.first == key)//�ҵ���ͬ��ֵ���ͷ��ش�ʱ�����ֵ�Ľڵ�ĵ�ַ
				{
					return &_Table[Hashi];
				}
				Hashi++;
				Hashi %= _Table.size();
			}
			//�ҵ��ն�û�ҵ�ֵ�����������û�����ֵ�����ؿ�
			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first)) return false;
			//�����������ֵ�ڱ����ҵ��ˣ�����Find�㷵�ر�����ͬ��ֵ�Ľڵ�ĵ�ַ��Ϊ�棬��Insert�㷵��false����û���ҵ�����Find�㷵�ؿգ�Ϊ�٣�Ȼ���������Ĳ������
			if (_n * 10 % _Table.size() > 7)//�������Ӵ���7--����
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
				_Table.swap(newHT._Table);//����

			}
			HashF hf;
			size_t Hashi = hf(kv.first) % _Table.size();//��λ��
			while (_Table[Hashi]._state == EXIST)//������ڣ�������
			{
				Hashi++;
				Hashi %= _Table.size();
			}
			_Table[Hashi]._kv = kv;//4.10.22��18����bug��_kv�����������г�����һ�Σ�ò����map��setͷ�ļ���д�������֮ǰ��������ģ�����
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
		size_t _n;//��ЧԪ�ظ���
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
		string a[] = { "ƻ��","����","�㽶","����","ƻ��","ƻ��" };
		HashTable<string, int> ht;
		for (auto& e : a)
		{
			auto k = ht.Find(e);
			if (k)
			{
				//�ҵ���
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

namespace bucketHash//��ϣͰ����ϣ��ײ��Ԫ���õ����������
{
	template<class K,class V>
	struct  HashNode//ָ��ڵ�
	{
		//State _state;
		pair<K, V> _kv;
		HashNode<K, V>* _next;
		HashNode(const pair<K,V>&kv)
			:_kv(kv)
		{}
	};

	template<class K,class V,class HashF = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> node;
	public:
		HashTable()
			:_n(0)
		{
			//_table.resize(10);
			_table.resize(__stl_next_prime(0));
		}
		~HashTable()//Ĭ�ϵ���������ֻ������vector��������������������ŵĹ�ϣͰ�ϵĽڵ�Ϳռ䣬���Ե��ֶ�����
		{
			
			for (int i = 0; i < _table.size(); i++)
			{
				node* cur = _table[i];
				while (cur)
				{
					node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}
		bool Insert(const pair<K, V>& kv)
		{
			HashF hf;
			if (_n == _table.size())
			{
				//����
				vector<node*> newtable(__stl_next_prime(_n), nullptr);
				//vector<node*> newtable(_n*2, nullptr);
				for (size_t i = 0; i < _table.size(); i++)
				{
					node* cur = _table[i];
					
					while (cur)
					{
						size_t hashi = hf(cur->_kv.first) % newtable.size();
						node* next = cur->_next;
						cur->_next = newtable[hashi];
						newtable[hashi] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newtable);
			}
			if (Find(kv.first)) return false;
			
			size_t hashi = hf(kv.first) % _table.size();
			node* newnode = new node(kv);
			newnode->_next =_table[hashi];
			_table[hashi] = newnode;
			++_n;
			return true;
		}
		
		inline unsigned long __stl_next_prime(unsigned long n)
		{
			
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};
			for (int i = 0; i < __stl_num_primes; i++)
			{
				if (__stl_prime_list[i] > n)//�ҵ��ȵ�ǰ��ЧԪ�ظ��������������
				{
					return __stl_prime_list[i];
				}
			}
			return __stl_prime_list[__stl_num_primes - 1];//û�ҵ��ͷ�������--���ڲ�������
		}
		
			node* Find(const K & key)
			{
				HashF hf;
				size_t hashi = hf(key) % _table.size();
				node* cur = _table[hashi];
				while (cur)
				{
					if (cur->_kv.first == key)//�ҵ���
					{
						return cur;
					}
					else
					{
						cur = cur->_next;
					}
				}
				return nullptr;
			}
			bool Erase(const K& key)
			{
				HashF hf;
				size_t hashi = hf(key) % _table.size();
				node* cur = _table[hashi];
				node* prev = nullptr;
				while (cur)
				{
					if (cur->_kv.first == key)//�ҵ���
					{
						if (cur==_table[hashi])//ͷɾ
						{
							_table[hashi] = cur->_next;
						}
						else
						{
							prev->_next = cur->_next;
						}
						delete cur;
						--_n;
						return true;
					}
					else//û�ҵ���
					{
						prev = cur;
						cur = cur->_next;
					}
				}
				return false;
			}
	private:
		vector<node*> _table;//�������ָ������
		int _n = 0;//������ЧԪ�ظ���
	};

	void testht()
	{
		HashTable<int, int> ht;
		//int a[] = { 3,63,73,83,7,27,5,35,85,93,103,113 ,123};
		int a[] = { 3,63,73,83,7,27,5,35 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		HashNode<int, int>* cur = ht.Find(73);
		if (cur)
		{
			ht.Erase(cur->_kv.first);
		}
		int j = 0;
	}

	void testht1()
	{
		string arr[] = { "ƻ��", "����", "�㽶", "��ݮ", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };

		//HashTable<string, int, HashFuncString> countHT;
		HashTable<string, int> countHT;
		for (auto& e : arr)
		{
			auto ret = countHT.Find(e);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				countHT.Insert(make_pair(e, 1));
			}
		}
		int j = 0;
	}
}