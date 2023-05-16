# C++异常

![C++exception](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305141231737.gif)

![image-20230514123231097](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305141232913.png#pic_center)

[TOC]

## 传统的错误处理机制

C语言传统的处理错误的方式有几种

1. assert断言。当遇到错误时直接中止程序并且报错显示在第几行代码出现问题，缺陷是遇到错误会终止程序。一般而言assert对付的是非常严峻的错误，比如内存泄漏，越界访问，当遇到的错误不是非常严重时，都不会使用assert。
2. 返回错误码。系统的很多库的接口函数都是通过把错误码放到errno中，表示错误。缺陷：需要程序员自己去查找对应的错误。

基于以上问题，C++衍生了一种新的处理错误的方式。异常是一种处理错误的方式，当一个函数发现自己**无法处理的错误时**就可以抛出异常，让函数的直接或间接的调用者处理这个错误。

## 异常的概念

* 关键字**try模块里放置可能抛出异常的代码**，try块中的代码称为保护代码。
* 当问题出现时，程序会通过关键字**throw抛出一个异常**。
* throw抛出的异常，要通过**关键字catch捕获异常**，可以有多个catch进行捕获。

使用try/catch语句的语法如下所示：

```cpp
try
{
// 保护的标识代码
}catch( ExceptionName e1 )
{
// catch 块
}catch( ExceptionName e2 )
{
// catch 块
}catch( ExceptionName eN )
{
// catch 块
}
```

## 异常的使用

### 异常的抛出和捕获

#### 异常的抛出和匹配原则

1. try和catch必须配套使用，一个try模块可以对应一个或多个catch模块（捕捉不同类型的对象）。若try语句和catch语句没有配套使用则会报错

![image-20230513111748529](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305131117394.png)

2.  异常是通过抛出对象而引发的，抛出对象的类型决定了后续应该激活哪个catch的处理代码。

3. 被选择的catch模块应是调用链中与**抛出对象类型匹配**、且是**距离抛出位置最近**的那一个。

若try语句内抛出的异常对象，在后续有接收相应类型catch语句，那么后面在同一个函数体（栈帧）再有接收相同类型的catch语句则会报错。（但是允许在外层函数体内有接收同种类型异常对象的catch函数）

![image-20230513112412139](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305131124364.png)

这里有一份代码用来观察抛异常到捕获的过程。main函数try语句中调用Func函数，Func函数的try语句中调用Division函数，Division是除法操作，若除数是0则抛异常。

```cpp
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";// 若抛异常，则后续代码都不执行了
	

	cout << "this is a test" << endl;
		return ((double)a / (double)b);


}
void Func()
{
	int len, time;
	cin >> len >> time;
	try{
		cout << Division(len, time) << endl;
	}
	catch (const char* errmsg)//抛出的异常若匹配上，后续的catch就不执行了
	{
		cout << errmsg << endl;
		cout << ">>>>>" << endl;
	}
}

int main()
{
	try {
		Func();
	}
		catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
		return 0;
}
```

通过调试可以知道：

* 若没有除0操作就不会抛异常，那么运行流程就正常走，**没有抛异常则不会进入catch语句**，那么try和catch的作用就为0，不会对程序造成干扰。
* 若有除0操作，那么抛异常，后续代码都不执行了，直接跳出堆栈，寻找与抛出对象类型匹配且距离最近的catch语句。这里进入了Func函数的catch语句，执行完catch语句之后，Func函数后续的代码继续执行。

![image-20230513114523584](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305131145549.png)

* 执行完Func函数之后回到main函数，此时抛出的异常已经被捕获了，后续的catch语句都不会进入。

![image-20230513115823383](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305131158308.png)

4. 到匹配的catch子句并处理以后，会继续沿着catch子句后面继续执行。

#### 在函数调用链中异常栈展开匹配原则

![image-20230513121311345](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305131213173.png)

1. 首先检查throw本身是否在try块内部，如果是再查找匹配的catch语句。如果有匹配的，则
   调到catch的地方进行处理。
2. 没有匹配的catch则退出当前函数栈，继续在调用函数的栈中进行查找匹配的catch。
3. 如果到达main函数的栈，依旧没有匹配的，则终止程序。上述这个沿着调用链查找匹配的catch子句的过程称为栈展开。所以实际中我们最后都要加一个catch(...)捕获任意类型的异常，**否则当有异常没捕获，程序就会直接终止**。<font size=4 color="red">**catch(...)可以接收任何类型的异常对象，问题是不知道异常错误是什么。**</font>

最怕这种情况：在调用的函数里抛了异常，然而在外层的函数甚至是main函数里都没有捕获异常的catch函数，这样会直接终止程序报错。

```cpp
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "Division by zero condition!";
	cout << "this is a test" << endl;
		return ((double)a / (double)b);
}
int main()
{
	int a, b;
	cin >> a >> b;
	Division(a,b);
	return 0;
}
```

![image-20230513121017180](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305131210007.png)

* 抛出异常对象后，会生成一个异常对象的拷贝，因为抛出的异常对象可能是一个临时对象，所以会生成一个拷贝对象，这个拷贝的临时对象会在被catch使用以后销毁。（这里的处理类似于函数的传值返回），**这个对象具有常性**

![image-20230513224229404](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305132246750.png)

这里我把catch接收异常对象的类型改为非const类型，运行后发现报错，**因为const对象传参给非const参数，权限放大**

![image-20230513224653609](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305132246021.png)

上面的catch参数是值，那么就是传值返回，当catch的参数是引用时，抛异常时对象会被编译器识别成右值，然后通过移动构造参数对象，减少了消耗。

![image-20230514005018135](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305140050971.png)

##### 异常的重新抛出

有可能单个的catch不能完全处理一个异常，在进行一些矫正处理后，希望再交给更外层的调用链函数来处理，catch则可以通过重新抛出将异常传递给更上层的函数进行处理。

![image-20230514000629548](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305140006426.png)

**异常再抛出结合catch(...)接收任何类型的异常对象可以作为异常处理中转站，让后续catch再去处理异常**

#### 抛出的派生类对象，使用基类捕获

实际中抛出和捕获的匹配原则有个例外，并不都是类型完全匹配，可以抛出的派生类对象，使用基类捕获，这个在实际中非常实用。

这里写了一个服务器开发中通常使用的异常继承体系，父类Exception的what函数是虚函数，供子类去完成重写，构成多态。main函数中的catch捕获const Exception& e，用的基类的引用，可以接收派生类抛出的异常对象，然后后续调用what函数就构成了多态，传过来是哪个派生类抛出的对象，那么就调用哪个派生类的what函数，这样就能清楚的知道是哪个派生类抛出的异常。

```cpp
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}
	virtual string what() const
	{
		return _errmsg;
	}
protected:
	string _errmsg;
	int _id;
};
class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}
	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
private:
	const string _sql;
};
class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}
	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};
class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}
	virtual string what() const
	{
		string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}
private:
	const string _type;
};
void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}
	//throw "xxxxxx";
}
void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	SQLMgr();
}
void HttpServer()
{
	// ...
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
	}
	CacheMgr();
}
int main()
{
	while (1)
	{
		Sleep(1000);
		try {
			HttpServer();
		}
		catch (const Exception& e) // 这里捕获父类对象就可以
		{
			// 多态
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unkown Exception" << endl;
		}
	}
	return 0;
}
```

* 为了防止出现其他异常，在main函数后面补上一个catch(...)接收任何异常对象，这样就不会因为出现未知异常导致服务器崩溃。

![image-20230514104957048](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305141050900.png)

另外，可以用基类专门接收该基类抛出的异常，如图专门捕获HttpServerException类的异常，其余异常通过基类引用进行捕获。

![image-20230514105424790](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305141054383.png)

## 异常安全

1. 构造函数完成对象的构造和初始化，最好不要在构造函数中抛出异常，否则可能导致对象不完整或没有完全初始化。
2. 析构函数主要完成资源的清理，最好不要在析构函数内抛出异常，否则可能导致资源泄漏(内存泄漏、句柄未关闭等)。
3. C++中异常经常会导致资源泄漏的问题，比如在new和delete中抛出了异常，导致内存泄漏，在lock和unlock之间抛出了异常导致死锁，C++经常使用RAII来解决以上问题，关于RAII后续我会在智能指针篇章进行介绍。

### 异常规范

1. 异常规范说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。 在C++98中，**在函数的后面接throw(类型)，列出这个函数可能抛掷的所有异常类型**；**函数的后面接throw()，表示函数不抛异常。**相应的，若无异常接口声明，则此函数可以抛掷任何类型的异常。

```cpp
// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
void fun() throw(A，B，C，D);
// 这里表示这个函数只会抛出bad_alloc的异常
void* operator new (std::size_t size) throw (std::bad_alloc);
```

* 由于这个规范不具有强制性，且C++标准库里的异常体系较为混乱，一般而言实际中很少项目会去用库里的异常体系。而是自己定义一套异常继承体系。

若要使用库里的异常体系，我们需要去调用👉[exception](https://legacy.cplusplus.com/reference/exception/exception/?kw=exception) exception是所有标准C++异常的父类，我们常见的子类有std::bad_alloc:该异常可以通过new抛出（底层调用operator new和构造函数）

![image-20230514112859024](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305141129419.png)

在C++11中对异常规范进行了简化：**函数的后面接noexcept**，表示函数不抛异常。

```cpp
// C++11 中新增的noexcept，表示不会抛异常
thread() noexcept;
thread (thread&& x) noexcept;
```

且在函数后接throw()和noexcept在**编译阶段编译器都会检查该函数是否具有抛异常的行为**

![image-20230514113708112](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202305141137644.png)

* 意味着加了throw()或noexcept的函数（且编译阶段检查不到异常行为）的函数是正常的，没有加的函数则是有可能会抛异常。

## 异常的优缺点

### 异常的优点

1. 异常对象定义好了，相比错误码的方式可以清晰准确的展示出错误的各种信息，甚至可以包含堆栈调用的信息，这样可以帮助更好的定位程序的bug。

2. 返回错误码的传统方式有个很大的问题就是，在函数调用链中，深层的函数返回了错误，那么我们得层层返回错误，最外层才能拿到错误，具体看下面的详细解释。

```cpp
// 1.下面这段伪代码我们可以看到fun1中出错了，先返回给fun2，fun2再返回给main函数，main函数再针对问题处理具体的错误。
// 2.如果是异常体系，不管是fun1还是fun2及调用函数出错，都不用检查，因为抛出的异常异常会直接跳到main函数中catch捕获的地方，main函数直接处理错误。
int fun1()
{
// 用户名密码错误
if (...)
return 1;
// 权限不足
if (...)
return 2;
}
int fun2() {
if (int ret = fun1() < 0)
return ret;
int fd = socket()
if（fd < 0）
return errno;
}
int main()
{
if(fun2()<0)
...
return 0;
}
```

3. 很多的第三方库都包含异常，比如boost、gtest、gmock等等常用的库，那么我们使用它们也需要使用异常。

4. 部分函数使用异常更好处理，比如构造函数没有返回值，不方便使用错误码方式处理。比如T& operator这样的函数，如果pos越界了只能使用异常或者终止程序处理，**没办法通过返回值表示错误**。然而断言也有缺陷，**断言只在debug版本下才有，release版本下没有作用**。

```cpp
T& operator(size_t pos)
{
if(pos>=_size)
 throw out_of_range("越界访问");
 
 return _start[pos];
}
```

### 异常的缺点

1. 异常会导致程序的执行流乱跳，并且非常的混乱，并且是运行时出错抛异常就会乱跳。这会导致我们跟踪调试时以及分析程序时，比较困难。

2. 异常会有一些性能的开销。当然在现代硬件速度很快的情况下，这个影响基本忽略不计。如：这个消耗在catch接收传值这里会进行对临时对象的拷贝构造。

3. C++没有垃圾回收机制，资源需要自己管理。有了异常非常容易导致内存泄漏、死锁等异常安全问题。这个需要使用RAII来处理资源的管理问题。学习成本较高。

4. C++标准库的异常体系定义得不好，导致大家各自定义各自的异常体系，非常的混乱。
5. 异常尽量规范使用，否则后果不堪设想，随意抛异常，外层捕获的用户苦不堪言。所以异常规范有两点：一、**抛出异常类型都继承自一个基类**。二、函数是否抛异常、抛什么异常，都**使用throw()、noexcept的方式规范化**。

但总而言之，异常的利大于弊，在实际中还是鼓励使用，另外在别的语言（如JAVA、Python）也都是用的异常处理错误。

