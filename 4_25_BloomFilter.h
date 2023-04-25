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

	template<size_t N,//���洢�����ݸ���
	size_t X=3,//ƽ���洢һ������Ҫ����6��ӳ��λ
		class K=string,//�������͵�ģ�����---ȱʡֵ��string
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
			if (!_bts.test(hashi1))//���ݲ�����ȷ����
			{
				return false;
			}
			size_t hashi2 = HashFunc2()(key) % (N * X);
			if (!_bts.test(hashi2))//���ݲ�����ȷ����
			{
				return false;
			}
			size_t hashi3 = HashFunc3()(key) % (N * X);
			if (!_bts.test(hashi3))//���ݲ�����ȷ����
			{
				return false;
			}

			return true;//���ܴ�������--ӳ��ļ���λ�ö���ͻ���ͻᷢ������
		}

	private:
		std::bitset<N* X> _bts;//�������洢�����ݸ���*ƽ���洢һ������Ҫ���ٵ�ӳ��λ
	};

	void testblf1()
	{
		string path[] = { "�ɴ�Ѽ","1�ɴ�Ѽ","1��1��Ѽ","��1��1Ѽ","��11��11Ѽ","1��1��Ѽ","��1��1Ѽ1" };
		//string path[] = { "�ɴ�Ѽ","�����","������","�����","С����","��������","Ƥ����" };
		BloomFilter<10>bl;
		for (auto& e : path)
		{
			bl.Set(e);
		}
		for (auto& s : path)
		{
			cout<<bl.Test(s) << endl;
		}
		cout << endl;
		srand(time(0));
		for (const auto& str : path)
		{
			cout << bl.Test(str + to_string(rand())) << endl;
		}
		
	}

	void testblf2()
	{
		srand(time(0));
		const size_t N = 100000;//ʮ�������
		BloomFilter<N> bf;

		std::vector<std::string> v1;
		std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";

		for (size_t i = 0; i < N; ++i)
		{
			v1.push_back(url + std::to_string(i));
		}

		for (auto& str : v1)
		{
			bf.Set(str);
		}

		// v2��v1�������ַ����������ǲ�һ��
		std::vector<std::string> v2;
		for (size_t i = 0; i < N; ++i)
		{
			std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
			url += std::to_string(999999 + i);
			v2.push_back(url);
		}

		size_t n2 = 0;
		for (auto& str : v2)
		{
			if (bf.Test(str))
			{
				++n2;
			}
		}
		cout << "�����ַ���������:" << (double)n2 / (double)N << endl;

		// �������ַ�����
		std::vector<std::string> v3;
		for (size_t i = 0; i < N; ++i)
		{
			string url = "zhihu.com";
			url += std::to_string(i + rand());
			v3.push_back(url);
		}

		size_t n3 = 0;
		for (auto& str : v3)
		{
			if (bf.Test(str))
			{
				++n3;
			}
		}
		cout << "�������ַ���������:" << (double)n3 / (double)N << endl;
	}
}