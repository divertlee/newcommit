#pragma once
namespace pjl
{
	struct BKDRHash
	{
		size_t operator()(const string& key)
		{
			size_t hash = 0;
			for (auto ch : key)
			{
				hash *= 131;
				hash += ch;
			}
			return hash;
		}
	};

	struct APHash
	{
		size_t operator()(const string& key)
		{
			unsigned int hash = 0;
			int i = 0;

			for (auto ch : key)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ (ch) ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ (ch) ^ (hash >> 5)));
				}

				++i;
			}

			return hash;
		}
	};

	struct DJBHash
	{
		size_t operator()(const string& key)
		{
			unsigned int hash = 5381;

			for (auto ch : key)
			{
				hash += (hash << 5) + ch;
			}

			return hash;
		}
	};

	struct JSHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 1315423911;
			for (auto ch : s)
			{
				hash ^= ((hash << 5) + ch + (hash >> 2));
			}
			return hash;
		}
	};

	template<size_t N,//最多存储的数据个数
	size_t X=6,//平均存储一个数据要开辟6个映射位
		class K=string,//数据类型的模板参数---缺省值给string
	    class HashFunc1=BKDRHash,
		class HashFunc2 = APHash,
		class HashFunc3 = DJBHash>
		//class HashFunc4 = JSHash>
	class BloomFilter
	{
	public:
		void Set(const K&key)
		{
			size_t hashi1 = HashFunc1()(key) %(N * X);
			
			size_t hashi2 = HashFunc2()(key) % (N * X);
			
			size_t hashi3 = HashFunc3()(key) % (N * X);
			_bts.set(hashi1);
			_bts.set(hashi2);
			_bts.set(hashi3);
			//size_t hashi4 = HashFunc4()(key) % (N * X);

   }

		bool Test(const K& key)
		{
			size_t hashi1 = HashFunc1()(key) % (N * X);
			if (!_bts.test(hashi1))//数据不在是确定的
			{
				return false;
			}
			size_t hashi2 = HashFunc2()(key) % (N * X);
			if (!_bts.test(hashi2))//数据不在是确定的
			{
				return false;
			}
			size_t hashi3 = HashFunc3()(key) % (N * X);
			if (!_bts.test(hashi3))//数据不在是确定的
			{
				return false;
			}

			return true;//可能存在误判--映射的几个位置都冲突，就会发生误判
		}

	private:
		std::bitset<N* X> _bts;//开辟最多存储的数据个数*平均存储一个数据要开辟的映射位
	};

	void testblf()
	{
		string path[] = { "可达鸭","杰尼龟","1可达鸭","可1达鸭","可达1鸭","1可1达鸭","可达1鸭1" };
		//string path[] = { "可达鸭","杰尼龟","阿柏蛇","大针蜂","小火龙","妙蛙种子","皮卡丘" };
		BloomFilter<10>bl;
		for (auto& e : path)
		{
			bl.Set(e);
		}
		cout << bl.Test("可达鸭") << endl;
		cout << bl.Test("杰尼龟") << endl;
		cout << bl.Test("1可达鸭") << endl;
		cout << bl.Test("可1达鸭") << endl;
		cout << bl.Test("可达1鸭") << endl;
		cout << bl.Test("可1达鸭") << endl;
		cout << bl.Test("1可1达鸭") << endl;
		cout << bl.Test("可达1鸭1") << endl;
	}
}