#pragma once
#include<iostream>
#include<map>
#include<string.h>
#include<mutex>
using namespace std;

//只能在堆上创建对象
//class HeapOnly
//{
//public:
//	static HeapOnly* Createobj()
////用static修饰的函数不再单单属于对象，而是属于类，可以通过类内函数调用。
////但如果不用static修饰，那么调用类的函数意味这先有对象，而外部调用不了构造函数就不能创建对象
//	{
//		return new HeapOnly();
//	}
//private:
//	HeapOnly() {};//禁用构造函数，防止外部调用构造函数在栈上创建对象
//	HeapOnly(const HeapOnly& hp) = delete;//防拷贝
//};
//
//int main()
//{
//	//HeapOnly* hps = new HeapOnly();//这样走需要调用构造函数，然而构造函数不能被调用
//	HeapOnly* hps = HeapOnly::Createobj();
//}

//只在栈上创建的对象
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();//
//	}
//
//	void Print()const
//	{
//		cout << "StackOnly::Print()" << endl;
//	}
//	~StackOnly() { cout << "~StackOnly()" << endl; }
//	void* operator new(size_t s) =delete;
//	void operator delete(void* p)=delete;
//	//把new和delete禁掉，不能通过new在堆上创建对象，但还是能通过static修饰在静态区上创建对象
//private:
//	StackOnly() {};//构造函数私有。外部通过new对象也需要走构造函数
//	StackOnly(const StackOnly& st) = delete;//防拷贝
//
//
//};
//int main()
//{
//	//StackOnly* st = new StackOnly();//构造函数私有化，不能通过new创建对象即不能在堆上创建对象
//	//static StackOnly st = StackOnly::CreateObj();//????
// //StackOnly st= StackOnly::CreateObj();
//	//static StackOnly sp1;//要走构造函数
//	StackOnly::CreateObj().Print();
//	const StackOnly& so4 = StackOnly::CreateObj();
//	so4.Print();
//	return 0;
//}

//设计一个类不能被继承
//方法一：把基类的构造函数私有化

//class Father
//{
//public:
//
//	Father() { cout << "get Father" << endl; };
//private:
//
//};
//
//class Son :public Father
//{
//public:
//	Son() { cout << "get son" << endl; };
//	const Father& getf()
//	{
//		return Father();
//	}
//};
//
//int main()
//{
//	Father f;
//	Son s;//创建派生类时，会调用基类的构造函数去构造继承到的基类那部分
//	Father fe= s.getf();//基类的构造函数放在公共则派生类能够调用
//	return 0;
//}

//class Father
//{
//public:
//
//	
//private:
//	Father() { cout << "get Father" << endl; };//构造函数私有化则该基类无法被继承
//};
//
//class Son :public Father
//{
//public:
//	Son() { cout << "get son" << endl; };
//	const Father& getf()
//	{
//		return Father();
//	}
//};
// 
//基类用final修饰则表示为最后一一个类，不能被继承
//class Father final
//{
//public:
//
//	Father() { cout << "get Father" << endl; };//构造函数私有化则该基类无法被继承
//private:
//	
//};
//
//class Son :public Father
//{
//public:
//	Son() { cout << "get son" << endl; };
//	const Father& getf()
//	{
//		return Father();
//	}
//};

//单例模式
//单例模式的类：全局只有一个
//饿汉模式
//对象在main函数之前就创建好了
//缺点：可能导致项目启动速度慢，若创建的1对象之间有关联性，由于是在main函数之前启动，该创建顺序无法被我们控制，因此其启动顺序由OS决定，那么会导致出错启动不起来

//class SingalInfo
//{
//public:
//	static SingalInfo&getbody()
//	{
//		return _sig;
//	}
//	void Insert(const string& name,int salary)
//	{
//		_info[name] = salary;
//	}
//	void Print()
//	{
//		for (auto& kv : _info)
//		{
//			cout << kv.first << " : " << kv.second << endl;
//		}
//		cout << endl;
//	}
//private:
//	SingalInfo() {};//构造函数私有化
//	SingalInfo(SingalInfo& sig) = delete;//禁用拷贝构造
//	SingalInfo& operator=(SingalInfo& sig) = delete;//禁用拷贝赋值
//private:
// static	SingalInfo _sig;//类内声明---整个类只有一个对象
// map<string, int> _info;
//
//};
//SingalInfo SingalInfo::_sig;//类外定义对象，全局定义具有全局属性，声明周期是全局

//int main()
//{
//	SingalInfo& kk = SingalInfo::getbody();
//	kk.Insert("me", 10000);
//	kk.Insert("you", 20000);
//	kk.Insert("who", 30000);
//
//	kk.Print();
//
//	SingalInfo::getbody().Insert("she", 25000);
//	SingalInfo::getbody().Print();
//
//	kk.Print();//此时kk对象打印的内容和前面的匿名对象打印的内容是一样的表示全局内对象只有一份
//	return 0;
//}
//懒汉模式
//对象在main函数之后创建，其创建顺序可以由我们制定
//template<class lock>
//class LockGuard
//{
//public:
//	LockGuard(lock& lk) :_lk(lk)
//	{
//		_lk.lock();
//	}
//
//	~LockGuard()
//	{
//		_lk.unlock();
//	}
//		lock& _lk;
//};
//
//class SingalInfo
//{
//public:
//
//	static SingalInfo& GetInstance()
//	{
//		static SingalInfo instance;//静态的局部变量是在main函数之后创建的
//		//C++11之后能够保证创建静态对象是线程安全的
//		return instance;
//	}
//
////	static SingalInfo& getbody()
////	{//当多个线程进来时，会new多个对象，因此需要加锁保护
////		if (_sig == nullptr)//第一次进来时指针为空，就创建新对象，否则直接返回此对象
////		{
////			LockGuard<mutex> lg(_mut);
////		//	_mut.lock();//双重检查：第一次进来且只有一个线程能够new对象
////			if (_sig == nullptr)
////			{
////				_sig = new SingalInfo();
////			}
////		//	_mut.unlock();//这样出现new对象失败抛异常导致解锁失败
////		}
////		return *_sig;
////	}
////
////	static void DeleteInstance()
////	{
////		//...保存数据
////
////		LockGuard<mutex> lg(_mut);
////		if (_sig)
////		{
////			cout << "~ _sig" << endl;
////			delete _sig;
////			_sig = nullptr;
////		}
////	}
////
////	class GC//内部类相当于友元，直接拿外类的成员
////	{
////	public:
////		~GC()
//////定义一个内部类，可以在main函数随处位置调用释放外部类，或者当外部类的声明周期结束时自动调用该内部类的析构函数释放外部类。而不是让创建当前外部类的父进程回收外部类
////		{
////			
////			DeleteInstance();
////		}
////	};
//
//	void Insert(const string& name, int salary)
//	{
//		_info[name] = salary;
//	}
//	void Print()
//	{
//		for (auto& kv : _info)
//		{
//			cout << kv.first << " : " << kv.second << endl;
//		}
//		cout << endl;
//	}
//private:
//	SingalInfo() { cout << "touch SingalInfo" << endl; };//构造函数私有化
//	SingalInfo(SingalInfo& sig) = delete;//禁用拷贝构造
//	SingalInfo& operator=(SingalInfo& sig) = delete;//禁用拷贝赋值
//private:
//	static	SingalInfo* _sig;//类内声明---整个类只有一个对象
//	map<string, int> _info;
////	static mutex _mut;
////	static GC _gc;//内部类声明
//
//};
//SingalInfo* SingalInfo::_sig=nullptr;//类外定义对象，全局定义具有全局属性，声明周期是全局
////mutex SingalInfo::_mut;
////SingalInfo::GC SingalInfo::_gc;
////int main()
////{
////	SingalInfo& kk = SingalInfo::getbody();
////	kk.Insert("me", 10000);
////	kk.Insert("you", 20000);
////	kk.Insert("who", 30000);
////
////	kk.Print();
////
////	SingalInfo::getbody().Insert("she", 25000);
////	SingalInfo::getbody().Print();
////
////	kk.Print();//此时kk对象打印的内容和前面的匿名对象打印的内容是一样的表示全局内对象只有一份
////	//SingalInfo::DeleteInstance();
////	return 0;
////}
//
//int main()
//{
//		SingalInfo& kk = SingalInfo::GetInstance();
//	kk.Insert("me", 10000);
//	kk.Insert("you", 20000);
//	kk.Insert("who", 30000);
//
//	kk.Print();
//
//	SingalInfo::GetInstance().Insert("she", 25000);
//	SingalInfo::GetInstance().Print();
//
//	kk.Print();//此时kk对象打印的内容和前面的匿名对象打印的内容是一样的表示全局内对象只有一份
//	return 0;
//}

//const 属性的变量存在与栈帧，属于常变量
int main()
{

	return 0;
}