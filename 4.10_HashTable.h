#pragma once
enum State
{
	EMPTY,//��
	EXIST,//�Ѵ���
	DELETE,//ɾ���ı��λ
};

template<class K,class V>
struct HashData
{
	pair<K, V> _kv;
	State _state = EMPTY;//Ĭ��ȱʡ��������
};

template<class K,class V>
class HashTable
{
	typedef HashData<K, V> Data;
public:
	HashTable()
		:_n(0)
	{
		_Table.resize(10);//Ĭ������Ϊ10���ռ�
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_n * 10 % _Table.size() > 7)//�������Ӵ���7--����
		{
			HashTable<K, V> newHT;
			newHT._Table.resize(_Table.size()* 2);
			for (auto& e : _Table)
			{
				if(e.)
			}
			
		}
		size_t Hashi = kv.first % _Table.size();//��λ��
		if (_Table[Hashi] == EXIST)//������ڣ�������
		{
			Hashi++;
			Hashi %= _Table.size();
		}
		_Table[Hashi]._kv = kv;//4.10.22��18����bug��_kv�����������г�����һ�Σ�ò����map��setͷ�ļ���д�������֮ǰ��������ģ�����
		_n++;
		
	}

private:
	vector<Data> _Table;
	size_t _n;//��ЧԪ�ظ���
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