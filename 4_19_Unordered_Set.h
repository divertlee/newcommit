#pragma once
#include"HashTable.h"

namespace pjl
{
	template<class K,class HashF=HashFunc<K>>
	class Unordered_Set
	{
	
		struct KeyofSet
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename BUCKET::BucketHash<K,K, HashF, KeyofSet>::iterator iterator;
		iterator begin()
		{
			return _st.begin();
		}

		iterator end()
		{
			return _st.end();
		}

		pair<iterator,bool> Insert(const K& key)
		{
			return _st.Insert(key);
		}


		iterator Find(const K& key)
		{
			return _st.Find(key);
		}

		bool Erase(const K& key)
		{
			return _st.Erase(key);
		}


	private:
		BUCKET::BucketHash<K, K, HashF, KeyofSet> _st;
	};

	void testHTSet2()
	{
		Unordered_Set<int> st;
		int arr[] = { 11,1,33,23,3,5,25,65,11111,111111,111,101 ,54 };
		for (auto e : arr)
		{
			st.Insert(e);
		}

		for (auto e : st)
		{
			cout << e << " ";
		}
		cout << endl;

		st.Find(1);
		st.Erase(1);
		st.Find(1);
		/*while (it != st.end())
		{

			cout << *it << " ";
			++it;
		}
		cout << endl;*/


	}

	void testHTSet1()
	{
		Unordered_Set<int> st;
	//	int arr[] = { 11,1,33,23,3,5,25,65,11111,111111,111,101 ,54};
		int arr[] = { 53,1,106,54,159 };
		for (auto e : arr)
		{
			st.Insert(e);
		}

		Unordered_Set<int>::iterator it=st.begin();
		
		while (it != st.end())
		{
			
			cout << *it << " " ;
			++it;
		}
		cout << endl;

	


	/*	for (size_t i = 1; i <= 60; i++)
		{
			
			st.Insert(i);
        }*/



		int j = 1;
	}

}