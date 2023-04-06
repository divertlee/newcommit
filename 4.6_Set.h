#pragma once
namespace pjl
{
	template<class K>
	class Set
	{
	public:	
		struct SetofT
		{
	const K& operator()(const K& key)
			{
				return key;
			}
		};
		typedef  typename RBTree<K, K, SetofT>::iterator iterator;

		bool Insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

	
		RBTree<K, K,SetofT>_t;
	};

	void TestSet()
	{
		int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		Set<int> st;
		for (auto e : a)
		{
			st.Insert(e);
  }
		for (auto e : st)
		{
			cout << e << " ";
		}
		cout << endl;

		Set<int>::iterator it1 = st.begin();
		while (it1 != st.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;

	}

}