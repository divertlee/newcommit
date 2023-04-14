#pragma once
#include"HashTable.h"
namespace pjl
{
	template<class K,class V,class HashF= HashFunc<K>>
	class UnordererMap
	{
		
		public:

			struct KeyofMap
			{
				const K& operator()(const pair<const K, V>& kv)
				{
					return kv.first;
				}
			};
			
			

			typedef typename bucketHash::HashTable<K, pair<const K, V>, HashF, KeyofMap>::iterator iterator;

			iterator begin()
			{
				return _mp.begin();
			}

			iterator end()
			{
				return _mp.end();
			}

			pair<iterator, bool> Insert(const pair<const K, V>& kv)
			{
				return _mp.Insert(kv);
			}

			V& operator[](const K& key)
			{
				pair<iterator, bool>ret = _mp.Insert(make_pair( key, V()));
			return 	ret.first->second;
			}

		private:
			bucketHash::HashTable<K, pair<const K,V>, HashF, KeyofMap> _mp;
		
	};

	void test_unordered_map()
	{
		string arr[] = { "西瓜", "苹果", "香蕉", "草莓", "西瓜", "西瓜", "西瓜", "香蕉", "苹果", "苹果", "香蕉", "香蕉", "苹果" };

		UnordererMap<string, int> mp;
		//for (auto& e : arr)
		//{
		//	mp.Insert(make_pair(e, 1));
		//}
		for (auto& e : arr)
		{
			mp[e]++;
		}

		//auto it = mp.begin();
		//while (it!=mp.end())
		//{
		//	if (it->first == "苹果")
		//	{
		//		
		//	}
		//	++it;
		//}

		int j = 0;
		//for ( auto& kv : mp)
		//{
		//	cout<<kv.
		//}
	}

}