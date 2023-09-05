#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<memory>
#include<mutex>
#include<thread>
#include<stdio.h>
#include<functional>
using namespace std;
//template<class T>
//class smartptr
//{
//public:
//
//	smartptr(T* ptr=nullptr) :_ptr(ptr)
//	{}
//
//	~smartptr()
//	{
//		if (_ptr)
//		{
//			cout << "delete _ptr" << endl;
//			delete _ptr;
//		}
//	}
//	// 像指针一样
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//
//};
//
//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//	return a / b;
//}
////void func()
////{
////	int* ptr = new int;//new了一个int大小的资源
////	cout << div() << endl;
////	delete ptr;//因为抛异常导致这个int资源没有被正常释放
////
////}
//void func()
//{	//int* ptr = new int;//new了一个int大小的资源
//	smartptr<int> sma(new int);
//	cout << div() << endl;	
//}
//int main()
//{
//	smartptr<int> sm1(new int);
//	smartptr<int> sm2(sm1);//拷贝构造
//
//	smartptr<int> sm3(new int);
//	sm3 = sm1;
//	//try
//	//{
//	//	func();
//	//}
//	//catch (exception& e)
//	//{
//	//	cout << e.what() << endl;
//	//}
//	return 0;
//}


//namespace pjl_SmPtr{
//	template<class T>
//	class SmartPtr
//	{
//	public:
//		SmartPtr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{
//			cout << "构造：" << _ptr << endl;
//		}
//
//		~SmartPtr()
//		{
//			if (_ptr)
//				cout << "析构：" << _ptr << endl;
//			delete[]_ptr;
//		}
//
//		T& operator*()//取对象的内容
//		{
//			return *_ptr;
//		}
//
//		T* operator->()//取对象的地址
//		{
//			return _ptr;
//		}
//
//	private:
//		T* _ptr;
//		int num = 0;
//	};
//}
//
//namespace pjl_AutoPtr {
//	template<class T>
//	class AutoPtr
//	{
//	public:
//		AutoPtr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{
//			cout << "构造：" << _ptr << endl;
//		}
//		//一是拷贝构造后，资源的控制权被转移了，先前指向资源的指针被悬空了；二是这tmd赋值函数没有析构原来的空间？？？？
//		//所以直接auto_ptr直接把拷贝构造和拷贝赋值直接禁用
//		AutoPtr(AutoPtr<T>& Apt) = delete;
//		//AutoPtr(AutoPtr<T>& Apt)
//		//	:_ptr(Apt._ptr)
//		//{
//		//	Apt._ptr = nullptr;//把原先指向空间的指针置为空；相当于与现在的对象交换资源的控制权
//		//}
//
//		~AutoPtr()
//		{
//			if (_ptr)
//				cout << "析构：" << _ptr << endl;
//			delete[]_ptr;
//		}
//
//		AutoPtr<T>& operator=(AutoPtr<T>& Apt) = delete;
//
//		//AutoPtr<T>& operator=(AutoPtr<T>& Apt)
//		//{
//		//	if (this != &Apt)//判断是不是自己
//		//	{
//		//		if (_ptr)//如果自己指向的空间不为空，需要先析构
//		//		{
//		//			delete[] _ptr;//调用析构函数析构空间??这里只析构指针，不调用析构函数析构资源？？
//		//			_ptr = nullptr;
//		//		}
//		//		_ptr = Apt._ptr;
//		//		Apt._ptr = nullptr;
//		//	}
//		//	return *this;
//		//}
//
//		T& operator*()//取对象的内容
//		{
//			return *_ptr;
//		}
//
//		T* operator->()//取对象的地址
//		{
//			return _ptr;
//		}
//
//	private:
//		T* _ptr;
//		int num = 0;
//	};
//}
//
//namespace pjl_ShPtr {
//	template<class T>
//	class SharePtr
//	{
//	public:
//		SharePtr(T* ptr = nullptr)
//			:_ptr(ptr)
//	        ,_RefCount(new int(1))
//		{
//			
//			cout << *_RefCount << "->" << "构造：" << _ptr << endl;
//		}
//
//		SharePtr(const SharePtr<T>& Shp)
//			:_ptr(Shp._ptr)
//			,_RefCount(Shp._RefCount)
//		{
//			++(*_RefCount);
//			cout << *_RefCount << "->" << "拷贝构造" << _ptr << endl;
//		}
//
//		void ReleasE()
//		{
//			if (-- (* _RefCount)==0)
//			{
//				delete[]_ptr;
//				delete _RefCount;
//				cout <<*_RefCount<<"->" << "Release" << _ptr << endl;
//			}
//		}
//
//		~SharePtr()
//		{
//			ReleasE();
//		}
//
//		SharePtr<T>& operator=(const SharePtr<T>& shp)
//		{ if(this!=&shp)
//		{
//			ReleasE();
//			_ptr = shp._ptr;
//			_RefCount = shp._RefCount;
//			++(*_RefCount);
//			cout<< *_RefCount << "->" << "赋值重载:" <<_ptr<< endl;
//		}
//		return *this;
//		}
//
//		T& operator*()//取对象的内容
//		{
//			return *_ptr;
//		}
//
//		T* operator->()//取对象的地址
//		{
//			return _ptr;
//		}
//
//
//	private:
//		T* _ptr;
//		int* _RefCount;
//	};
//}


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

//int maxProfit(int k, vector<int>& prices) {
//	vector<vector<int>>dp(prices.size(), vector<int>(2 * k + 1, 0));
//	for (size_t i = 1; i < dp[0].size(); i++)
//	{
//		if (i % 2 == 1)//偶数
//		{
//			dp[0][i] = -prices[0];
//		}
//	}
//	for (size_t i = 1; i < prices.size(); i++)
//	{
//		for (size_t j = 1; j < 2 * k + 1; j++)
//		{
//			if (j % 2 == 1)//奇数
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
//			}
//		}
//	}
//	return dp[prices.size() - 1][2 * k - 1];
//}
//
//int main()
//{
//	vector<int>prices{ 2,4,1 };
//	cout << maxProfit(2, prices);
//	return 0;
//}
//template<class T>
//class Auto_ptr
//{
//public:
//	Auto_ptr(T* ptr=nullptr):_ptr(ptr){}
//	~Auto_ptr() { cout << "delete _ptr" << endl; delete _ptr; }
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	Auto_ptr(Auto_ptr<T>& tp)//拷贝构造
//		:_ptr(tp._ptr)
//	{
//			tp._ptr = nullptr;//悬空
//	}
//
//	Auto_ptr& operator=(Auto_ptr<T>& tp)
//	{
//		if (this!=&tp)//判断是否是自己赋值給自己
//		{
//			if (_ptr)
//			{
//				delete _ptr;
//				_ptr = nullptr;
//			}
//			_ptr = tp._ptr;//转移资源管理权
//			tp._ptr = nullptr;//悬空
//		}
//		return *this;
//	}
//private:
//	T* _ptr;
//
//};
//
//int main()
//{
//	Auto_ptr<int> apt1(new int(1));
//	*apt1 = 10;
//	Auto_ptr<int> apt2(apt1);
//
//	Auto_ptr<int> apt3(new int(3));
//	apt3 = apt2;
//	return 0;
//}

//template<class T>
//class Unique_ptr
//{
//public:
//	Unique_ptr(T* ptr):_ptr(ptr){}
//	~Unique_ptr()
//	{
//		if (_ptr)
//		{
//			cout << "delete _ptr" << endl;
//			delete _ptr;
//		}
//		
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	Unique_ptr<T>& operator=(const Unique_ptr<T>& upt) = delete;//禁用拷贝构造
//	Unique_ptr(const Unique_ptr<T>& upt) = delete;//禁用拷贝赋值
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	Unique_ptr<int> upt1(new int(1));
//	cout << *(upt1) << endl;
//
//	Unique_ptr<int> upt2(upt1);
//	Unique_ptr<int> upt3(new int(3));
//	upt3 = upt1;
//	return 0;
//}
//using namespace std;
//namespace s
//{
//	template<class T>
//	class Share_ptr
//	{
//	public:
//		Share_ptr(T* ptr = nullptr) :_ptr(ptr), _pcount(new int(1)), _mut(new mutex) {}
//
//		Share_ptr<T>& operator=(const Share_ptr<T>& spt)//赋值重载
//		{
//			if (_ptr!=spt._ptr)
//			{
//				Release();
//				_ptr = spt._ptr;
//				_pcount = spt._pcount;
//				_mut = spt._mut;
//				Addpcount();
//			}
//			return *this;
//		}
//
//		int use_count()
//		{
//			return *_pcount;
//		}
//		void Addpcount()
//		{
//			_mut->lock();
//			(*_pcount)++;
//			_mut->unlock();
//		}
//		Share_ptr(const Share_ptr<T>& spt)//拷贝构造
//			:_ptr(spt._ptr)
//			, _pcount(spt._pcount)
//			,_mut(spt._mut)
//		{
//			Addpcount();
//		}
//		void Release()
//		{
//			_mut->lock();//加锁
//			bool flag = false;
//			if (--(*_pcount) == 0 && _ptr)
//			{
//				//计数为0，释放资源
//				cout << "delete _ptr" << endl;
//				delete _ptr;
//				delete _pcount;
//				flag = true;
//			}
//			_mut->unlock();//解锁
//			if (flag)
//			{
//				cout << "delete mutex" << endl;
//				delete _mut;
//			}
//
//		}
//		~Share_ptr()
//		{
//			Release();
//		}
//
//		T* operator->()
//		{
//			return &_ptr;
//		}
//
//		T* get() const
//		{
//			return _ptr;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//	private:
//		T* _ptr;
//		int* _pcount;
//		mutex* _mut;
//
//	};
//}

//int main()
//{
//	s::Share_ptr<int> spt1(new int(1));
//	cout << "spt1 pcount: " << spt1.use_count() << endl;
//	s::Share_ptr<int> spt2(spt1);
//	cout << "spt2 pcount: " << spt2.use_count() << endl;
//
//	s::Share_ptr<int> spt3(new int(3));
//	spt3 = spt1;
//	cout << "spt3 pcount: " << spt3.use_count() << endl;
//
//	return 0;
//}


namespace s
{
	template<class T>
	class default_delete
	{
	public:
		void operator()(T* ptr)
		{
			cout << "delete ptr" << endl;
			delete ptr;
		}
	};


	template<class T>
	class Delarry
	{
	public:
		void operator()( T* arr)
		{
			cout << "delete[]" << arr << endl;
			delete[]arr;
		}
	};

	template<class T,class D=default_delete<T>>
	class Share_ptr
	{
	public:
		Share_ptr(T* ptr ,D del) :_ptr(ptr), _pcount(new int(1)),_mut(new mutex),_del(del) {}

		Share_ptr<T>& operator=(const Share_ptr<T>& spt)//赋值重载
		{
			if (_ptr != spt._ptr)
			{
				Release();
				_ptr = spt._ptr;
				_pcount = spt._pcount;
				_mut = spt._mut;
				Addpcount();
			}
			return *this;
		}

		int use_count()
		{
			return *_pcount;
		}
		void Addpcount()
		{
			_mut->lock();
			(*_pcount)++;
			_mut->unlock();
		}
		Share_ptr(const Share_ptr<T>& spt)//拷贝构造
			:_ptr(spt._ptr)
			, _pcount(spt._pcount)
			,_mut(spt._mut)
		{
			Addpcount();
		}
		void Release()
		{
			bool flag = false;
			_mut->lock();
			if (--(*_pcount) == 0 && _ptr)
			{
				//计数为0，释放资源
				cout << "delete _ptr" << endl;
				_del( _ptr);//调用对应制定删除器释放资源
				delete _pcount;
				flag = true;
			}
			_mut->unlock();
			if (flag == true)
			{
				delete _mut;
			}
		}
		~Share_ptr()
		{
			Release();
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _mut;
		D _del;
	};
}

//int main()
//{
//	s::Share_ptr<int> spt1(new int(1));
//	cout << "spt1 pcount: " << spt1.use_count() << endl;
//	s::Share_ptr<int> spt2(spt1);
//	cout << "spt2 pcount: " << spt2.use_count() << endl;
//
//	s::Share_ptr<int> spt3(new int(3));
//	spt3 = spt1;
//	cout << "spt3 pcount: " << spt3.use_count() << endl;
//
//	return 0;
//}


struct Date
{
public:
	int _year = 0;
	int _month = 0;
	int _day = 0;
};

//void func(std::shared_ptr<int>& sp, size_t n)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		std::shared_ptr<int> sp2(sp);
//	}
//}
//
//void test_shared_ptr1()
//{
//	int n = 50000;
//	mutex mtx;
//	s::Share_ptr<Date> sp1(new Date());
//
//	thread t1([&]()
//		{
//			for (int i = 0; i < n; ++i)
//			{
//				s::Share_ptr<Date> sp2(sp1);
//		//		mtx.lock();
//				sp2->_year++;
//				sp2->_day++;
//				sp2->_month++;
//		//		mtx.unlock();
//			}
//		});
//
//	thread t2([&]()
//		{
//			for (int i = 0; i < n; ++i)
//			{
//				s::Share_ptr<Date> sp3(sp1);
//			//	mtx.lock();
//				sp3->_year++;
//				sp3->_day++;
//				sp3->_month++;
//			//	mtx.unlock();
//			}
//		});
//
//	t1.join();
//	t2.join();
//
//	cout << sp1.use_count() << endl;
//	cout << sp1.get() << endl;
//
//	cout <<"sp1->_year: " << sp1->_year << endl;
//	cout <<"sp1->_month: " << sp1->_month << endl;
//	cout <<"sp1->_year: " << sp1->_day << endl;
//}
//
//int main()
//{
//	test_shared_ptr1();
//}

//int main()
//{
//	//s::Share_ptr<int> sp1(new int(0));
//	std::shared_ptr<int> sp1(new int(1));
//	const size_t n = 1000000;
//	thread t1(func,std::ref(sp1), n);
//	thread t2(func,std::ref(sp1), n);
//
//	t1.join();
//	t2.join();
//
//	cout << sp1.use_count() << endl; //预期：1
//
//	return 0;
//}

//void SharePtrFunc(s::Share_ptr<Date>& sp, size_t n, mutex& mtx)
//{
//	cout << sp.get() << endl;
//	for (size_t i = 0; i < n; ++i)
//	{
//		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
//		s::Share_ptr<Date> copy(sp);
//		{
//		unique_lock<mutex> lk(mtx);
//		copy->_year++;
//		copy->_month++;
//		copy->_day++;
//		}
//	}
//}
//int main()
//{
//	std::shared_ptr<Date> spt(new Date());
//	cout << spt.get() << endl;//打印指针
//
//
//	return 0;
//}


namespace t
{template<class T>
class weak_ptr
{
public:

	weak_ptr() :_ptr(nullptr) {}



	weak_ptr<T>& operator=( s::Share_ptr<T>& spt)//赋值重载
	{
		_ptr = spt.get();
		return *this;
	}

	weak_ptr(const s::Share_ptr<T>& spt)//拷贝构造
		:_ptr(spt.get())
	{}

	T* operator->()
	{
		return _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

private:
	T* _ptr;
};
}

class Fclose
{
public:
	void operator()(FILE* ptr)
	{
		cout << "fclose ptr" << endl;
		fclose(ptr);
	}
};

int main()
{
	s::Share_ptr<int,s::Delarry<int>> sp(new int[10],s::Delarry<int>());
	s::Share_ptr<FILE, function<void(FILE*)>> sp2(fopen("test.cpp", "r"), [](FILE* ptr) {
		cout << "fclose: " << ptr << endl;
		fclose(ptr); });
	return 0;
}

//struct ListNode
//{
//	int _data = 0;
//	t::weak_ptr<ListNode> _prev;
//	t::weak_ptr<ListNode> _next;
//	~ListNode() { cout << "~ListNode()" << endl; }
//};
//int main()
//{
//	s::Share_ptr<ListNode> node1(new ListNode);
//	s::Share_ptr<ListNode> node2(new ListNode);
//	cout << " node1.use_count: " << node1.use_count() << endl;
//	cout << " node2.use_count: " << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << " node1.use_count: " << node1.use_count() << endl;
//	cout << " node2.use_count: " << node2.use_count() << endl;
//	return 0;
//}
