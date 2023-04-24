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
	size_t X=6,//ƽ���洢һ������Ҫ����6��ӳ��λ
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

	void testblf()
	{
		string path[] = { "�ɴ�Ѽ","�����","1�ɴ�Ѽ","��1��Ѽ","�ɴ�1Ѽ","1��1��Ѽ","�ɴ�1Ѽ1" };
		//string path[] = { "�ɴ�Ѽ","�����","������","�����","С����","��������","Ƥ����" };
		BloomFilter<10>bl;
		for (auto& e : path)
		{
			bl.Set(e);
		}
		cout << bl.Test("�ɴ�Ѽ") << endl;
		cout << bl.Test("�����") << endl;
		cout << bl.Test("1�ɴ�Ѽ") << endl;
		cout << bl.Test("��1��Ѽ") << endl;
		cout << bl.Test("�ɴ�1Ѽ") << endl;
		cout << bl.Test("��1��Ѽ") << endl;
		cout << bl.Test("1��1��Ѽ") << endl;
		cout << bl.Test("�ɴ�1Ѽ1") << endl;
	}
}