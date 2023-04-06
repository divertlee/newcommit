#pragma once
namespace pjl
{
	template<class K,class V>
	class Map
	{
	public:
		struct MapofT
		{
			const K& operator()(const pair<const K,V>& kv)//±È½Ï¿´k
			{
				return kv.first ;
			}
		};
		typedef typename  RBTree<K, pair<const K, V>, MapofT>::iterator iterator;
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}


		bool Insert(const pair<const K, V>& kv)
		{
		 return	_t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K,V>,MapofT>_t;
	};
	
	void TestMap()
	{
		int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		Map<int,int> mp;
		for (auto e : a)
		{
			mp.Insert(make_pair(e,e));
		}
	
		for (auto e : mp)
		{
			cout << e.second << " ";
		}
		cout << endl;

		Map<int, int>::iterator it1 = mp.begin();
		while (it1 != mp.end())
		{
			cout << it1->second<< " ";
			++it1;
		}



		cout << endl;

	}

	

}