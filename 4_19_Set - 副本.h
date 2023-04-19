#pragma once
namespace pjl
{
	//template<class K>
	//class Set
	//{
	//public:	
	//	struct SetofT
	//	{
	//const K& operator()(const K& key)
	//		{
	//			return key;
	//		}
	//	};
	//	typedef  typename RBTree<K, K, SetofT>::iterator iterator;

	//	bool Insert(const K& key)
	//	{
	//		return _t.Insert(key);
	//	}

	//	iterator begin()
	//	{
	//		return _t.begin();
	//	}

	//	iterator end()
	//	{
	//		return _t.end();
	//	}

	//
	//	RBTree<K, K,SetofT>_t;
	//};

	template<class K>
	class Set
	{
	public:
		struct  SetOT//构造模板函数处理比较问题
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		//typedef的是一个类的内部类型，不知道是静态变量还是类型，typename告诉编译器这是类型
		typedef typename RBTree<K, K, SetOT>::const_iterator iterator;//都是const迭代器，key不能指针修改
		typedef typename RBTree<K, K, SetOT>::const_iterator const_iterator;//const迭代器

		//typedef typename RBTree<K, K, SetOT>::iterator iterator;

		//pair<iterator,bool> Insert(const K& key)
		//{
		//	pair< typename RBTree<K, K, SetOT>::iterator, bool> ret = _t.Insert(key);
		//	return pair<iterator, bool>(ret.first, ret.second);//iterator:const迭代器，ret.first是普通迭代器，
		//}
		pair<iterator, bool> Insert(const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(key);
			return make_pair(ret.first,ret.second);
		}
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()const//const成员函数使得this指针不能更改任何类中任何成员
		{
			return _t.end();
		}
		 

		iterator begin()const
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		RBTree<K, K, SetOT>_t;//套用红黑树

	};

	void TestSet()
	{
		//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		int a[]={1, 2,3,4,5};
		Set<int> st;
		for (auto e : a)
		{
			st.Insert(e);
  }
		for (auto e : st)
//调用迭代器时，先去用结点构造迭代器，构造完后，
//然后根据这里要什么样迭代器，RBTree根据这个什么样构造一个临时变量，然后给这里的迭代器
		{
			
			cout << e << " ";
		}
		cout << endl;

	/*	Set<int>::iterator it1 = st.begin();
		cout << *it1<<endl;
		++(*it1);
		cout << *it1 << endl;
		cout << endl;*/

		//Set<int>::iterator it = st.begin();
//while (it != st.end())
//{
////	++*it;//Set里面的迭代器都更改为const迭代器后就不能用迭代器去更改值了
//	cout << *it << " ";
//	++it;
//}
//cout << endl;
//这里要const迭代器，那么在RBTree那里，根据普通迭代器构造一个const迭代器传过来使用

	}

}