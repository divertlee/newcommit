#include<iostream>
#include<vector>
using namespace std;

namespace pjl_SmPtr{
	template<class T>
	class SmartPtr
	{
	public:
		SmartPtr(T* ptr = nullptr)
			:_ptr(ptr)
		{
			cout << "���죺" << _ptr << endl;
		}

		~SmartPtr()
		{
			if (_ptr)
				cout << "������" << _ptr << endl;
			delete[]_ptr;
		}

		T& operator*()//ȡ���������
		{
			return *_ptr;
		}

		T* operator->()//ȡ����ĵ�ַ
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int num = 0;
	};
}

namespace pjl_AutoPtr {
	template<class T>
	class AutoPtr
	{
	public:
		AutoPtr(T* ptr = nullptr)
			:_ptr(ptr)
		{
			cout << "���죺" << _ptr << endl;
		}
		//һ�ǿ����������Դ�Ŀ���Ȩ��ת���ˣ���ǰָ����Դ��ָ�뱻�����ˣ�������tmd��ֵ����û������ԭ���Ŀռ䣿������
		//����ֱ��auto_ptrֱ�Ӱѿ�������Ϳ�����ֱֵ�ӽ���
		AutoPtr(AutoPtr<T>& Apt) = delete;
		//AutoPtr(AutoPtr<T>& Apt)
		//	:_ptr(Apt._ptr)
		//{
		//	Apt._ptr = nullptr;//��ԭ��ָ��ռ��ָ����Ϊ�գ��൱�������ڵĶ��󽻻���Դ�Ŀ���Ȩ
		//}

		~AutoPtr()
		{
			if (_ptr)
				cout << "������" << _ptr << endl;
			delete[]_ptr;
		}

		AutoPtr<T>& operator=(AutoPtr<T>& Apt) = delete;

		//AutoPtr<T>& operator=(AutoPtr<T>& Apt)
		//{
		//	if (this != &Apt)//�ж��ǲ����Լ�
		//	{
		//		if (_ptr)//����Լ�ָ��Ŀռ䲻Ϊ�գ���Ҫ������
		//		{
		//			delete[] _ptr;//�����������������ռ�??����ֻ����ָ�룬��������������������Դ����
		//			_ptr = nullptr;
		//		}
		//		_ptr = Apt._ptr;
		//		Apt._ptr = nullptr;
		//	}
		//	return *this;
		//}

		T& operator*()//ȡ���������
		{
			return *_ptr;
		}

		T* operator->()//ȡ����ĵ�ַ
		{
			return _ptr;
		}

	private:
		T* _ptr;
		int num = 0;
	};
}

namespace pjl_ShPtr {
	template<class T>
	class SharePtr
	{
	public:
		SharePtr(T* ptr = nullptr)
			:_ptr(ptr)
	        ,_RefCount(new int(1))
		{
			
			cout << *_RefCount << "->" << "���죺" << _ptr << endl;
		}

		SharePtr(const SharePtr<T>& Shp)
			:_ptr(Shp._ptr)
			,_RefCount(Shp._RefCount)
		{
			++(*_RefCount);
			cout << *_RefCount << "->" << "��������" << _ptr << endl;
		}

		void ReleasE()
		{
			if (-- (* _RefCount)==0)
			{
				delete[]_ptr;
				delete _RefCount;
				cout <<*_RefCount<<"->" << "Release" << _ptr << endl;
			}
		}

		~SharePtr()
		{
			ReleasE();
		}

		SharePtr<T>& operator=(const SharePtr<T>& shp)
		{ if(this!=&shp)
		{
			ReleasE();
			_ptr = shp._ptr;
			_RefCount = shp._RefCount;
			++(*_RefCount);
			cout<< *_RefCount << "->" << "��ֵ����:" <<_ptr<< endl;
		}
		return *this;
		}

		T& operator*()//ȡ���������
		{
			return *_ptr;
		}

		T* operator->()//ȡ����ĵ�ַ
		{
			return _ptr;
		}


	private:
		T* _ptr;
		int* _RefCount;
	};
}


//namespace bit
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr)
//			:_ptr(ptr)
//		{
//			cout << "���캯����" << _ptr << endl;
//		}
//		auto_ptr(auto_ptr<T>& sp)
//			:_ptr(sp._ptr)
//		{
//			// ����Ȩת��
//			sp._ptr = nullptr;
//		}
//		auto_ptr<T>& operator=(auto_ptr<T>& ap)
//		{
//			// ����Ƿ�Ϊ�Լ����Լ���ֵ
//			if (this != &ap)
//			{
//				// �ͷŵ�ǰ��������Դ
//				if (_ptr)
//					delete _ptr;
//				// ת��ap����Դ����ǰ������
//				_ptr = ap._ptr;
//				ap._ptr = NULL;
//			}
//			return *this;
//		}
//		~auto_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//
//			}
//		}
//		// ��ָ��һ��ʹ��
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//}

//int main()
//{
//	int* ptr1 = new int[10];
//	pjl_ShPtr::SharePtr<int> shp1(ptr1);
//	pjl_ShPtr::SharePtr<int> shp2(shp1);//��������
//
//	int* ptr2 = new int[5];
//	pjl_ShPtr::SharePtr<int> shp3(ptr2);
//	shp3 = shp1;
//
//
//	//int* ptr1 = new int[10];
//	//pjl_AutoPtr::AutoPtr<int> ap1(ptr1);
//	//pjl_AutoPtr::AutoPtr<int> ap2(ap1);//��������--ת����Դ�Ŀ���Ȩ��ap1�Ŀ���Ȩת�Ƹ�ap2������������ʱ���ap2�������ռ�
//	////*ap1=10;//ָ������
//	//int* ptr2 = new int[7];
//	//pjl_AutoPtr::AutoPtr<int> ap3(ptr2);//��ֵ����--ת����Դ����Ȩ
//
//	//ap3 = ap2;
//	//int k = 1;
//	//int* ptr1 = new int[10];
//	//pjl_SmPtr:: SmartPtr<int> sp1(ptr1);
//	////��������;sp1��sp2ָ��ͬһ��ռ䣬������ʱ��sp2�����������ǿ�ռ������ˣ��κ��˳�main����ջ֡ʱsp1�ٴζ��ǿ�ռ���������ʱԽ�������
//	//pjl_SmPtr::SmartPtr<int> sp2(sp1);
//
//
//
//
//return 0;
//}

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("��0����");
//	return a / b;
//}
//void Func()
//{
//	// 1�����p1����new ���쳣����Σ�
//	// 2�����p2����new ���쳣����Σ�
//	// 3�����div���������ֻ����쳣����Σ�
//	int* p1 = new int[10];
//	SmartPtr<int> sp1(p1);
//	*sp1 = 10;
//	int* p2 = new int[10];
//	SmartPtr<int> sp2(p2);
//	cout << div() << endl;//���������쳣������������Ŀռ䣬ջ֡�����������ȥ������Ĵ���ִ�в��ˣ�����Ŀռ�û���ͷ�����ڴ�й©
//	delete[] p1;
//	delete[] p2;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

int maxProfit(int k, vector<int>& prices) {
	vector<vector<int>>dp(prices.size(), vector<int>(2 * k + 1, 0));
	for (size_t i = 1; i < dp[0].size(); i++)
	{
		if (i % 2 == 1)//ż��
		{
			dp[0][i] = -prices[0];
		}
	}
	for (size_t i = 1; i < prices.size(); i++)
	{
		for (size_t j = 1; j < 2 * k + 1; j++)
		{
			if (j % 2 == 1)//����
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
			}
		}
	}
	return dp[prices.size() - 1][2 * k - 1];
}

int main()
{
	vector<int>prices{ 2,4,1 };
	cout << maxProfit(2, prices);
	return 0;
}