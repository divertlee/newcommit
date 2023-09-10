# C++——特殊类设计

![布隆过滤器 (2)](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309091712514.gif)

[TOC]

## 特殊类

### 设计一个类不能被拷贝

> 拷贝只会放在两个场景，其一是拷贝构造函数，其二是赋值运算符重载，因此想让一个类不能被拷贝，只需要让该类不能调用拷贝构造函数以及赋值运算符重载，即禁用拷贝构造函数以及赋值运算符重载

> * C++98的做法

```cpp
class CopyBan
{
    // ...
private:
    CopyBan(const CopyBan&);
    CopyBan& operator=(const CopyBan&);
    //...
};
```

* 把拷贝构造和拷贝赋值设置成私有成员，防止在类外调用。
* 只声明不定义，防止成员函数内部进行拷贝。

> * C++11的做法

```cpp
class CopyBan
{
    // ...
    CopyBan(const CopyBan&)=delete;
    CopyBan& operator=(const CopyBan&)=delete;
    //...
};
```

* C++11扩展delete的用法，delete除了释放new申请的资源外，如果在默认成员函数后跟上 =delete，表示让编译器删除掉该默认成员函数。

### 设计一个类只能在堆上创建

> 将构造函数私有化，禁用拷贝构造函数

```cpp
//只能在堆上创建对象
class HeapOnly
{
public:
	static HeapOnly* Createobj()
//用static修饰的函数不再单单属于对象，而是属于类，可以通过类内函数调用。
//但如果不用static修饰，那么调用类的函数意味这先有对象，而外部调用不了构造函数就不能创建对象
	{
		return new HeapOnly();
	}
private:
	HeapOnly() {};//禁用构造函数，防止外部调用构造函数在栈上创建对象
	HeapOnly(const HeapOnly& hp) = delete;//防拷贝
};

int main()
{
	//HeapOnly* hps = new HeapOnly();//这样走需要调用构造函数，然而构造函数不能被调用
	HeapOnly* hps = HeapOnly::Createobj();
	
}
```

* 构造函数私有化，防止外部调用构造函数在栈上、在静态区上创建对象。
* 拷贝构造用delete修饰，防止通过拷贝构造在栈上、在静态区上创建对象。
* Createobj函数返回一个new 出来的HeapOnly的匿名对象，用HeapOnly指针接收；
* Createobj函数用static修饰表示该函数不属于对象，而是属于类，可以通过类内函数调用。否则调用对象的函数前需要先有对象，而调用Createobj函数的作用是获取一个对象，这样就出现问题。

### 设计一个类只能在栈上创建

方法一

> 构造函数私有化，通过拷贝构造在栈上创建对象

```cpp
//只在栈上创建的对象
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();//
	}
private:
	StackOnly() {};//构造函数私有。外部通过new对象也需要走构造函数

};

int main()
{
	//StackOnly* st = new StackOnly();//构造函数私有化，不能通过new创建对象即不能在堆上创建对象
	//static StackOnly sp1;//要走构造函数
	static StackOnly st1 = StackOnly::CreateObj();//没有封掉拷贝构造函数，这里可以通过拷贝构造函数在静态区上创建
	StackOnly st2= StackOnly::CreateObj();//可以通过拷贝构造在栈上创建对象，但无法防止在静态区上创建
	return 0;
}
```

* 构造函数私有化，防止调用构造函数在堆上、在静态区上创建对象。
* 调用类内函数获取对象，然后通过拷贝构造在栈上创建对象，**但不能防止通过拷贝构造在静态区上创建对象**。

方法二

> 将构造函数私有化，禁用拷贝构造函数

```cpp
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();//
	}

	void Print()const
	{
		cout << "StackOnly::Print()" << endl;
	}
	~StackOnly() { cout << "~StackOnly()" << endl; }
	void* operator new(size_t s) = delete;
	void operator delete(void* p) = delete;
	//把new和delete禁掉，不能通过new在堆上创建对象
private:
	StackOnly() {};//构造函数私有。外部通过new对象也需要走构造函数
	StackOnly(const StackOnly& st) = delete;//防拷贝---防止通过调用拷贝构造在静态区上创建对象


};
int main()
{
	//static StackOnly sp1;//要走构造函数
	StackOnly::CreateObj().Print();//通过匿名对象在栈上创建对象，走完这一行就调用析构函数释放匿名对象
	const StackOnly& so4 = StackOnly::CreateObj();
	//通过const 引用接收匿名对象，匿名对象的生命周期转化为so4对象的生命周期,即cosnt引用延迟了匿名对象的生命周期。匿名对象在栈上创建
	so4.Print();
	return 0;
}
```

* 构造函数私有化，防止调用构造函数在堆上、在静态区上创建对象。
* 拷贝构造用delete修饰，防止通过拷贝构造在栈上、在静态区上创建对象。
* 把new和delete禁掉，不能通过new在堆上创建对象。
* CreateObj获取一个匿名对象，通过匿名对象调用成员函数Print完成在栈上创建对象。但不好的是该匿名对象的声明周期只有一行，即调用完Print函数对象就立即被销毁。
* 通过const引用接收匿名对象，匿名对象的生命周期转化为so4对象的生命周期,即cosnt引用延迟了匿名对象的生命周期。匿名对象在栈上创建。

### 设计一个类不能被继承

> C++98方式

```cpp
class Father
{
public:

	
private:
	Father() { cout << "get Father" << endl; };
};

class Son :public Father
{
public:
	Son() { cout << "get son" << endl; };
	const Father& getf()
	{
		return Father();
	}
};

```

* 将基类的构造函数私有化，派生类无法调用基类的构造函数，就无法继承。

> C++11方法

```cpp
//基类用final修饰则表示为最后一一个类，不能被继承
class Father final
{
public:

	Father() { cout << "get Father" << endl; };//构造函数私有化则该基类无法被继承
private:
	
};

class Son :public Father
{
public:
	Son() { cout << "get son" << endl; };
	const Father& getf()
	{
		return Father();
	}
};

```

* 用final修饰基类表示该类为最后一个类，该类无法被继承。

## 单例模式

> 设计模式

设计模式（Design Pattern）是**一套被反复使用、多数人知晓的、经过分类的、代码设计经验的总结**。

使用设计模式的目的：**为了代码可重用性、让代码更容易被他人理解、保证代码可靠性**。 设计模式使代码编写真正工程化；设计模式是软件工程的基石脉络，如同大厦的结构一样。

> 单例模式

**一个类只能创建一个对象且全局内该类只能有这一个对象**，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享。

例如在某个服务器程序中，该服务器的配置信息存放在一个文件中，这些配置数据由一个单例对象统一读取，然后服务进程中的其他对象再通过这个单例对象获取这些配置信息，这种方式简化了在复杂环境下的配置管理。单例模式有两种常用的实现模式，其一是饿汉模式，其二是懒汉模式。

### 饿汉模式

> * 饿汉模式较为简单。
> * 无论后续程序使不使用，在main函数之前就创建好该对象。
> * 缺点在于：一是若饿汉模式的对象诸多，可能导致项目启动速度慢；二是创建的对象顺序由OS决定，若创建的对象之间存在顺序性可能导致出错。例如创建A对象前需要B对象提供接口，那么在饿汉模式下OS先创建的A对象后创建的B对象，会导致A对象创建时B对象不存而调用不到接口而创建A对象失败。

```cpp

#pragma once
#include<iostream>
#include<map>
#include<string.h>
#include<mutex>
using namespace std;
class SingalInfo
{
public:
	static SingalInfo&getbody()
	{
		return _sig;
	}
	void Insert(const string& name,int salary)
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
 static	SingalInfo _sig;//类内声明---整个类只有一个对象
 map<string, int> _info;

};
SingalInfo SingalInfo::_sig;//类外定义对象，全局定义具有全局属性，声明周期是全局


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
```

* 构造函数私有化，防止外部调用构造函数创建对象。
* 拷贝构造、拷贝赋值用delete修饰，禁止通过拷贝创建对象。
* 类内成员_sig的类型是SingalInfo，表示该成员的类型是当前类。
* 类内成员_sig用static修饰，表示该成员不单单属于对象，而是属于整个类，表示一个类内只有一个对象。
* 类内成员_sig在类中声明，在类外全局定义，表示该成员具有全局属性。
* 通过getbody函数获取_sig成员，用SingalInfo引用接收。外部通过调用getbody函数获取类对象用引用接收。
* 类内有一份map，用来储存数据。

![image-20230909154437081](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309091544997.png)

注意一下：如果这个单例对象在多线程高并发环境下频繁使用，性能要求较高，那么显然使用饿汉模式来避免资源竞争，提高响应速度更好。

### 懒汉模式

如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊， 初始化网络连接啊，读取文件啊等等，而有可能该对象程序运行时不会用到，那么也要在程序一开始就进行初始化， 就会导致程序启动时非常的缓慢。 所以这种情况使用懒汉模式（延迟加载）更好。

> * 懒汉模式下是在main函数启动后创建对象的。
> * 启动顺序可以由我们决定。
> * 缺点在于实现比较复杂。

```cpp
#pragma once
#include<iostream>
#include<map>
#include<string.h>
#include<mutex>
using namespace std;

template<class lock>
class LockGuard
{
public:
	LockGuard(lock& lk) :_lk(lk)
	{
		_lk.lock();
	}

	~LockGuard()
	{
		_lk.unlock();
	}
		lock& _lk;
};

class SingalInfo
{
public:
	static SingalInfo& getbody()
	{//当多个线程进来时，会new多个对象，因此需要加锁保护
		if (_sig == nullptr)//第一次进来时指针为空，就创建新对象，否则直接返回此对象
		{
			LockGuard<mutex> lg(_mut);
		//	_mut.lock();//双重检查：第一次进来且只有一个线程能够new对象
			if (_sig == nullptr)
			{
				_sig = new SingalInfo();
			}
		//	_mut.unlock();//这样出现new对象失败抛异常导致解锁失败
		}
		return *_sig;
	}
//
	static void DeleteInstance()
	{
		//...保存数据
		LockGuard<mutex> lg(_mut);
		if (_sig)
		{
			cout << "~ _sig" << endl;
			delete _sig;
			_sig = nullptr;
		}
	}
//
	class GC//内部类相当于友元，直接拿外类的成员
	{
	public:
		~GC()
//定义一个内部类，可以在main函数随处位置调用释放外部类，或者当外部类的声明周期结束时自动调用该内部类的析构函数释放外部类。而不是让创建当前外部类的父进程回收外部类
		{
			
			DeleteInstance();
		}
	};

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
	SingalInfo() { cout << "touch SingalInfo" << endl; };//构造函数私有化
	SingalInfo(SingalInfo& sig) = delete;//禁用拷贝构造
	SingalInfo& operator=(SingalInfo& sig) = delete;//禁用拷贝赋值
private:
	static	SingalInfo* _sig;//类内声明---整个类只有一个对象
	map<string, int> _info;
	static mutex _mut;
	static GC _gc;//内部类声明

};
SingalInfo* SingalInfo::_sig=nullptr;//类外定义对象，全局定义具有全局属性，声明周期是全局
mutex SingalInfo::_mut;
SingalInfo::GC SingalInfo::_gc;
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
```

* 类内声明成员_sig是SingalInfo指针类型，且用static修饰，表示该成员属于整个类。在类外定义为全局属性，表示具有全局性，声明周期为全局。
* _mut是互斥锁，用于保护临界区。在加锁和解锁之间的代码称为临界区。加锁后同个时间内只能有一个线程进入临界区，维持了线程安全。
* map是一个键值对类型的数据结构，用来存储数据。
* _gc为内部类，内部类相当于友元函数，可以调用外部类内成员DeleteInstance函数，负责释放对象 _sig和释放锁 _mut。可以不调用DeleteInstance函数进行释放资源，当该进程解锁后由父进程进行回收释放。也可在程序解锁时，内部类GC的周期结束自动调用析构函数，进而调用DeleteInstance函数进行释放资源。

* LockGuard类负责加锁解锁工作，该类为RAII型，外部传互斥锁进来，构造函数对该锁进行加锁，析构函数对该锁进行解锁。

* getbody函数用于获取对象。用static修饰表示可以通过类内函数进行调用。
* getbody函数进行双重检查成员_sig==nullptr的的作用在于：第一次检查是否是第一次调用getbody函数，第一次调用说明当前还未创建对象。第二次检查用于加锁限制一个线程进入获取对象。
* 互斥锁 _mut用LockGuard包装作用在于当退出外层if函数时自动调用LockGuard对象的析构函数，去解锁，避免了因为new失败进行抛异常导致退出当前栈帧而解锁失败的问题。

![image-20230909164043447](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309091640327.png)

其实在获取对象时是通过new对象，构造函数创建对象，指针接收，势必可能存在线程安全问题，因此需要加锁保护，双重检查，后续解锁释放锁资源等等工作。在C++11中，保证了创建静态对象是线程安全的，因此可以通过**获取静态对象，避免线程安全问题的同时摒弃掉互斥锁等等资源的调用和释放**。

```cpp
class SingalInfo
{
public:
	static SingalInfo& GetInstance()
	{
		static SingalInfo instance;//静态的局部变量是在main函数之后创建的
		//C++11之后能够保证创建静态对象是线程安全的
		return instance;
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
	SingalInfo() { cout << "touch SingalInfo" << endl; };//构造函数私有化
	SingalInfo(SingalInfo& sig) = delete;//禁用拷贝构造
	SingalInfo& operator=(SingalInfo& sig) = delete;//禁用拷贝赋值
private:
	map<string, int> _info;
};
```

