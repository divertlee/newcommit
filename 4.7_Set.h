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
		struct  SetOT//����ģ�庯������Ƚ�����
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		typedef typename RBTree<K, K, SetOT>::const_iterator iterator;//typedef����һ������ڲ����ͣ���֪���Ǿ�̬�����������ͣ�typename���߱�������������
		typedef typename RBTree<K, K, SetOT>::const_iterator const_iterator;//const������



		pair<iterator,bool> Insert(const K& key)
		{
			pair< typename RBTree<K, K, SetOT>::iterator, bool> ret = _t.Insert(key);
			return pair<iterator, bool>(ret.first, ret.second);//iterator:const��������ret.first����ͨ��������
		}

		//iterator begin()
		//{
		//	return _t.begin();
		//}

		const_iterator end()const//const��Ա����ʹ��thisָ�벻�ܸ����κ������κγ�Ա
		{
			return _t.end();
		}
		 

		const_iterator begin()const
		{
			return _t.begin();
		}

		//iterator end()
		//{
		//	return _t.end();
		//}

		RBTree<K, K, SetOT>_t;//���ú����

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
		{
			cout << e << " ";
		}
		cout << endl;

		Set<int>::iterator it1 = st.begin();
		cout << *it1<<endl;
	//	++(*it1);
		cout << *it1 << endl;
		cout << endl;

	}

}