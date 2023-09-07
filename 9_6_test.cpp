#pragma once
#include<iostream>
#include<map>
#include<string.h>
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
class SingalInfo
{
public:
	static SingalInfo& getbody()
	{
		if (_sig == nullptr)//第一次进来时指针为空，就创建新对象，否则直接返回此对象
		{
			_sig = new SingalInfo();
		
		}
		return *_sig;
	}
	void Insert(const string& name, int salary)
	{
		_info[name] = salary;
	}
	void Print()
	{
		for (auto& kv : _info)
		{
			cout << kv.first << " : " << kv.second << endl;
		}
		cout << endl;
	}
private:
	SingalInfo() {};//构造函数私有化
	SingalInfo(SingalInfo& sig) = delete;//禁用拷贝构造
	SingalInfo& operator=(SingalInfo& sig) = delete;//禁用拷贝赋值
private:
	static	SingalInfo* _sig;//类内声明---整个类只有一个对象
	map<string, int> _info;

};
SingalInfo* SingalInfo::_sig=nullptr;//类外定义对象，全局定义具有全局属性，声明周期是全局

int main()
{
	SingalInfo& kk = SingalInfo::getbody();
	kk.Insert("me", 10000);
	kk.Insert("you", 20000);
	kk.Insert("who", 30000);

	kk.Print();

	SingalInfo::getbody().Insert("she", 25000);
	SingalInfo::getbody().Print();

	kk.Print();//此时kk对象打印的内容和前面的匿名对象打印的内容是一样的表示全局内对象只有一份
	return 0;
}