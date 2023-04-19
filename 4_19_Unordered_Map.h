#pragma once
#include"HashTable.h"

namespace pjl
{
	

	template<class K,class V,class HashF= HashFunc<K>>
	class Unordered_Map
	{
		struct KeyofMap
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename BUCKET::BucketHash<K, pair<const K, V>, HashF, KeyofMap>::iterator iterator;
	public:
		iterator begin()
		{
			return _mp.begin();
		}

		iterator end()
		{
			return _mp.end();
		}

		pair<iterator,bool> Insert(const pair<K, V>& kv)
		{
			return _mp.Insert(kv);
			
		}

		iterator Find(const K& key)
		{
			return _mp.Find(key);
		}

		bool Erase(const K& key)
		{
			return _mp.Erase(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _mp.Insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
	 BUCKET::BucketHash<K,pair<const K,V> , HashF ,KeyofMap> _mp;
	};

	void 	testHTMap1()
	{
		Unordered_Map<int, int> mp;
		int arr[] = { 11,1,33,23,3,5,25,65,11111,111111,111,101,1,1 ,54 };
		for (auto e : arr)
		{
			mp.Insert(make_pair(e, e));
		}

		for (auto e : mp)
		{
			cout << e.first << ":" << e.second << endl;
		}
		cout << endl;
 }

	void testHTMap2()
	{
		Unordered_Map<string, int> s;
		string arr[] = { "苹果","香蕉","西瓜","香蕉","西瓜","西瓜","草莓" };
		
		for (auto& e : arr)
		{
			if (s.Find(e) != s.end())
			{
				s[e]++;
			}else
			{
				s.Insert(make_pair(e, 1));
			}
			
		}
		/*for (auto& e : arr)
		{
			s[e]++;
		}*/
		for (auto e : s)
		{
			cout << e.first << " :" << e.second << endl;
		}
	/*	s.Find("苹果");
		cout << s.Erase("苹果") << endl;
		s.Find("苹果");
	
		
		cout << s.Erase("西瓜") << endl;
		cout << s.Erase("西瓜") << endl;
		cout << s.Erase("西瓜") << endl;
		cout << s.Erase("西瓜") << endl;
		cout << s.Erase("西瓜") << endl;

		for (auto e : s)
		{
			cout << e.first << " :" << e.second << endl;
		}*/
	}

}