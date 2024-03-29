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
			cout << "构造：" << _ptr << endl;
		}

		~SmartPtr()
		{
			if (_ptr)
				cout << "析构：" << _ptr << endl;
			delete[]_ptr;
		}

		T& operator*()//取对象的内容
		{
			return *_ptr;
		}

		T* operator->()//取对象的地址
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
			cout << "构造：" << _ptr << endl;
		}
		//一是拷贝构造后，资源的控制权被转移了，先前指向资源的指针被悬空了；二是这tmd赋值函数没有析构原来的空间？？？？
		//所以直接auto_ptr直接把拷贝构造和拷贝赋值直接禁用
		AutoPtr(AutoPtr<T>& Apt) = delete;
		//AutoPtr(AutoPtr<T>& Apt)
		//	:_ptr(Apt._ptr)
		//{
		//	Apt._ptr = nullptr;//把原先指向空间的指针置为空；相当于与现在的对象交换资源的控制权
		//}

		~AutoPtr()
		{
			if (_ptr)
				cout << "析构：" << _ptr << endl;
			delete[]_ptr;
		}

		AutoPtr<T>& operator=(AutoPtr<T>& Apt) = delete;

		//AutoPtr<T>& operator=(AutoPtr<T>& Apt)
		//{
		//	if (this != &Apt)//判断是不是自己
		//	{
		//		if (_ptr)//如果自己指向的空间不为空，需要先析构
		//		{
		//			delete[] _ptr;//调用析构函数析构空间??这里只析构指针，不调用析构函数析构资源？？
		//			_ptr = nullptr;
		//		}
		//		_ptr = Apt._ptr;
		//		Apt._ptr = nullptr;
		//	}
		//	return *this;
		//}

		T& operator*()//取对象的内容
		{
			return *_ptr;
		}

		T* operator->()//取对象的地址
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
			
			cout << *_RefCount << "->" << "构造：" << _ptr << endl;
		}

		SharePtr(const SharePtr<T>& Shp)
			:_ptr(Shp._ptr)
			,_RefCount(Shp._RefCount)
		{
			++(*_RefCount);
			cout << *_RefCount << "->" << "拷贝构造" << _ptr << endl;
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
			cout<< *_RefCount << "->" << "赋值重载:" <<_ptr<< endl;
		}
		return *this;
		}

		T& operator*()//取对象的内容
		{
			return *_ptr;
		}

		T* operator->()//取对象的地址
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
//			cout << "构造函数：" << _ptr << endl;
//		}
//		auto_ptr(auto_ptr<T>& sp)
//			:_ptr(sp._ptr)
//		{
//			// 管理权转移
//			sp._ptr = nullptr;
//		}
//		auto_ptr<T>& operator=(auto_ptr<T>& ap)
//		{
//			// 检测是否为自己给自己赋值
//			if (this != &ap)
//			{
//				// 释放当前对象中资源
//				if (_ptr)
//					delete _ptr;
//				// 转移ap中资源到当前对象中
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
//		// 像指针一样使用
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
//	pjl_ShPtr::SharePtr<int> shp2(shp1);//拷贝构造
//
//	int* ptr2 = new int[5];
//	pjl_ShPtr::SharePtr<int> shp3(ptr2);
//	shp3 = shp1;
//
//
//	//int* ptr1 = new int[10];
//	//pjl_AutoPtr::AutoPtr<int> ap1(ptr1);
//	//pjl_AutoPtr::AutoPtr<int> ap2(ap1);//拷贝构造--转移资源的控制权：ap1的控制权转移给ap2，这样析构的时候就ap2析构这块空间
//	////*ap1=10;//指针悬空
//	//int* ptr2 = new int[7];
//	//pjl_AutoPtr::AutoPtr<int> ap3(ptr2);//赋值重载--转移资源控制权
//
//	//ap3 = ap2;
//	//int k = 1;
//	//int* ptr1 = new int[10];
//	//pjl_SmPtr:: SmartPtr<int> sp1(ptr1);
//	////拷贝构造;sp1和sp2指向同一块空间，当析构时，sp2先析构，把那块空间析构了，任何退出main函数栈帧时sp1再次对那块空间析构，此时越界访问了
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
//		throw invalid_argument("除0错误");
//	return a / b;
//}
//void Func()
//{
//	// 1、如果p1这里new 抛异常会如何？
//	// 2、如果p2这里new 抛异常会如何？
//	// 3、如果div调用这里又会抛异常会如何？
//	int* p1 = new int[10];
//	SmartPtr<int> sp1(p1);
//	*sp1 = 10;
//	int* p2 = new int[10];
//	SmartPtr<int> sp2(p2);
//	cout << div() << endl;//若这里抛异常，则上面申请的空间，栈帧在这里就跳出去，后面的代码执行不了，申请的空间没有释放造成内存泄漏
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
		if (i % 2 == 1)//偶数
		{
			dp[0][i] = -prices[0];
		}
	}
	for (size_t i = 1; i < prices.size(); i++)
	{
		for (size_t j = 1; j < 2 * k + 1; j++)
		{
			if (j % 2 == 1)//奇数
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