#pragma once
namespace pjl
{
	template<class K, class V>
	//class Map
	//{
	//public:
	//	struct MapofT
	//	{
	//		const K& operator()(const pair<const K,V>& kv)//�ȽϿ�k
	//		{
	//			return kv.first ;
	//		}
	//	};
	//	typedef typename  RBTree<K, pair<const K, V>, MapofT>::iterator iterator;//û��ʵ������ģ���������֪�����Ǿ�̬�����������ͣ���typename���߱�������������
	//	iterator begin()
	//	{
	//		return _t.begin();
	//	}

	//	iterator end()
	//	{
	//		return _t.end();
	//	}


	//	bool Insert(const pair<const K, V>& kv)
	//	{
	//	 return	_t.Insert(kv);
	//	}

	//private:
	//	RBTree<K, pair<const K,V>,MapofT>_t;
	//};

	class Map
	{
	public:
		struct MapofT
		{
			const K& operator()(const pair<const K, V>& kv)const
			{
				return kv.first;
			}
		};
		typedef typename RBTree<K, pair<const K, V>, MapofT>::iterator iterator;//�����������֪�������о�̬�����������ͣ�typename���߱���������������
		typedef typename RBTree<K, pair<const K, V>, MapofT>::const_iterator const_iterator;//const������
		iterator begin()
		{
			return _mp.begin();
		}

		iterator end()
		{
			return _mp.end();
		}

		const_iterator begin()const
		{
			return _mp.begin();
		}

		const_iterator end()const
		{
			return _mp.end();
		}

		 pair<iterator,bool> Insert(const pair<const K, V>& kv)
		{
			 return _mp.Insert(kv);
		}
		 V& operator[](const K& key)
		 {
			 pair<iterator, bool> ret = _mp.Insert(make_pair(key, V()));
			 return ret.first->second;
		 }
		//pair<iterator,bool> Insert(const pair<const K, V>& kv)
		//{
		//	return _mp.Insert(kv);
		//}

		//V& operator[](const K& key)
		//{
		//	pair<iterator, bool> ret = _mp.Insert(make_pair(key, V()));
		//	return ret.first->second;
		//}

		RBTree<K, pair<const K, V>, MapofT> _mp;
	};

	void TestMap()
	{
	//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//	int a[] = { 1,2,3 };
		//Map<int, int> mp;
		//for (auto e : a)
		//{
		//	mp.Insert(make_pair(e, e));
		//}

		//for (auto e : mp)
		//{
		//	//++e.first;
		//	//++e.second;
		//	cout <<e.first<<":" << e.second << " ";
		//}
		//cout << endl;



	//	Map<int, int>::iterator it1 = mp.begin();
	//	cout << it1->second << endl;
	//	++it1->second;
	//	cout << it1->second << endl;
	//	++it1;
	////	++it1->first;//���ܸ���key
	//	cout << it1->second << endl;

		string arr[] = { "����","ƻ��","����", "ƻ��","����" };
		Map<string,int> mp1;
		for (auto& e : arr)
		{
			
			mp1[e]++;
		}
		for (auto e : mp1)
		{
			
			e.second++;
			cout << e.first << ":" << e.second << endl;
		}

	}
}