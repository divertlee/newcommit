#pragma once
namespace pjl
{
	template<class K,class HashF=HashFunc<K>> 
	class Unordered_Set
	{
		
	public:

		struct KeyofSet
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		typedef typename bucketHash::HashTable<K, K, HashF, KeyofSet>::iterator iterator;
		
		iterator begin()
		{
			return _st.begin();
		}

		iterator end()
		{
			return _st.end();
		}

		pair<iterator, bool> Insert(const K& key)
		{
			return _st.Insert(key);
		}

	private:
		bucketHash::HashTable<K, K, HashF, KeyofSet> _st;
	};

	void test_unordered_set()
	{
		Unordered_Set<string> us;
		us.Insert("Æ»¹û");
		us.Insert("Ïã½¶");
		us.Insert("Æ»¹û");
		us.Insert("Î÷¹Ï");
		//us.Insert(13);
		//us.Insert(3);
		//us.Insert(23);
		//us.Insert(5);
		//us.Insert(5);
		//us.Insert(6);
		//us.Insert(15);
		//us.Insert(223342);
		//us.Insert(22);

		Unordered_Set<string>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : us)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}