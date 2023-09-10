# C++——类型转换

![](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309101155862.gif)

[TOC]

### C语言的类型转换

在C语言中，如果**赋值运算符左右两侧类型不同**，或者**形参与实参类型不匹配**，或者**返回值类型与接收返回值类型不一致时**，就需要发生**类型转化**。其中C语言中总共有两种形式的类型转换，隐式类型转换和显式类型转化。

* 隐式类型转化：编译器在编译阶段自动进行，能转就转，不能转就编译失败。

* 显式类型转化：需要用户自己处理。

```cpp
void test1()
{
	int a = 10;
	double b = a;//隐式类型转换
	cout << "int a= " << a << " double b= " << b << endl;

	int* p = &a;
	int c = (int)p;//显示的强制类型转换

	cout << "p= " << p << " int c= " << c << endl;
}

int main()
{
	test1();
	return 0;
}
```

![image-20230909213858374](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309092138223.png)

* 只有相近类型之间才能发生隐式类型转换，比如int 和double类型，它们只是表示的范围和精度不同。而地址类型表示的是地址编号，因此整型和地址类型之间不能发生隐式类型转换，需要通过显式类型转换。

### 为什么C++需要四种类型转换

C风格的转换格式很简单，但是有不少缺点的：

1. . 隐式类型转化有些情况下可能会出问题：比如数据精度丢失。
2. 显式类型转换将所有情况混合在一起，代码不够清晰。

因此C++提出了自己的类型转化风格，且为了提高可视性，引入了四种命名的强制类型转换操作符，分别是static_cast、reinterpret_cast、const_cast、dynamic_cast。注意因为C++要兼容C语言，所以C++中还可以使用C语言的转化风格。

## C++强制类型转换

###  static_cast

> static_cast用于非多态类型的转换（静态转换），编译器隐式执行的任何类型转换都可用 static_cast，即它可以用于任何隐式类型转换，但它不能用于两个不相关的类型进行转换

```cpp
void test1()
{
	double a = 3.1415926;
	int b = static_cast<int>(a);//
	cout << "double a= " << a << " int b= " << b << endl;
}
```

![image-20230909215458732](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309092154499.png)

### reinterpret_cast

> reinterpret_cast操作符通常为操作数的位模式提供较低层次的重新解释，用于将一种类型转换为另一种不同的类型。即reinterpret_cast用于不同类型参数之间的转换

```cpp
void test1()
{
	int a = 111;

//	int* p = static_cast<int*>(a);//这里会报错：类型转换无效
	int* p = reinterpret_cast<int*>(a);//这里会报错：类型转换无效

	cout << "int a= " << a << " int*p= " << p << endl;
}

```

* 通过reinterpret_cast把int类型转换为int*类型

![image-20230909220519547](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309092205497.png)

### const_cast

> const_cast最常用的用途就是删除变量的const属性，方便赋值

```cpp
int main()
{
	
	 const int b = 3;//用volatile修饰，表示该变量保持内存可见性
	int* pp = const_cast<int*>(&b);
	*pp = 5;
	cout << "const int b: " << b<<endl;//3
    cout<< " *pp: " << *pp << endl;//5

	return 0;
}
```

* 通过const_cast将int类型的变量b赋值給int*类型的变量pp。然后改变p指向的值由3变5。
* 实际上打印出来b的值是3，pp指向的值是5。其原因在于系统默认const变量不会被改变，因此对const变量进行优化，将const变量放入寄存器中，内存中的变量改变后不会更新到寄存器中。之后要用到都去寄存器里面取，这样const变量取到的就是改变之前的值。
* 然而在监视窗口看到b和*pp都变成了5，其原因在于监视窗口是在内存中取的数据，因此b取到的是更新后的数据。

![image-20230909221336700](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309092213877.png)

* 因此要給变量b加上volatile修饰，被volatile修饰的变量会保持内存可见性，即变量在内存中改变时都会更新到寄存器中。

![image-20230909221630814](https://non1.oss-cn-guangzhou.aliyuncs.com/write1/202309092216539.png)

### dynamic_cast

> dynamic_cast用于将一个父类对象的指针/引用转换为子类对象的指针或引用(动态转换)

父类和子类的指针和引用可以相互转化。

* 子类对象指针/引用转换为父类指针/引用，可以通过子类继承父类，然后子类以切片的方式取到父类的资源，这种方式是语法支持的，因此是安全的，不需要借助其他方式进行转换。这种转换叫作向上转型。

* 父类对象指针/引用转换为子类指针/引用，这种转换是语法所不支持的，当以强制类型转换，将父类指针转换为子类指针时，**拿到子类的内容是父类所没有的，因此是不安全的**。所以安全的方式是父类转子类要用dynamic_cast。这种转换叫作向下转型。

> dynamic_cast特性
>
> 1.  dynamic_cast只能用于父类含有虚函数的类，因为运行时类型检查需要运行时的类型信息，而这个信息是存储在虚函数表中的，只有定义了虚函数的类才有虚函数表。
> 2. dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回nullptr。

```cpp
class A
{
public:
	virtual void fun(){}

	int _a = 10;
};

class B : public A
{
public:
	int _b = 20;
};

void func(A* ap)
{
	B* toson1 = (B*)ap;//转子类---当父类指针转换为子类指针时不安全
	B* toson2 =dynamic_cast<B*>(ap);//安全
	
	cout << "toson1: " << toson1 << endl;
//使用dynamic_cast后，父类转子类是要被检查的，若转换失败则返回空給指针，后续调用该指针会直接中断程序
	toson1->_a = 40;//这里父类转子类，理应子类指针不能拿到父类的成员变量,因此这种转换是不安全的
	toson1->_b = 50;
	cout << "toson1->_a: " << toson1->_a << " toson1->_b: " << toson1->_b << endl;

	cout << "toson2: " << toson1 << endl;
	toson2->_a = 40;
	toson2->_b = 50;
	cout << "toson2->_a: " << toson1->_a << " toson2->_b: " << toson1->_b << endl;
}


int main()
{
	A a;
	B b;
	func(&a);//传父类指针过去转换
	func(&b);//传子类指针过去转换
	return 0;
}
```

* main函数中传参父类地址給func函数，用于转换为子类指针。
* 用强制类型转换时，能够拿到子类的成员，这部分成员是父类所没有的，因此是不安全的。
* 用dynamic_cast进行转换时，父类转子类是要被检查的，若转换失败则返回空給指针，后续调用指针取数据时会由于指针越界访问数据直接中断程序。

### RTTI

> RTTI：Run-time Type identification的简称，即：运行时类型识别。

C++通过以下方式来支持RTTI：

1. typeid运算符。C++ 中的 `typeid()` 运算符用于获取一个对象的类型信息，它通常用于在运行时检查对象的实际类型。要注意的是`typeid` 只能用于具有多态性的类（至少一个虚函数的类），以确保正确的运行时类型识别。

```cpp
int main()
{
	int num = 10;
	cout << typeid(num).name() << endl;//int
	return 0;
}
```

* 通过使用其 `name()` 方法来获取类型的名称

2. dynamic_cast运算符

3. decltype。`decltype`是C++11新增的一个关键字，和auto的功能一样，用来在**编译时期**进行自动类型推导。auto要求变量必须初始化，而decltype不要求，因此可以写成如下形式。

```cpp
decltype(exp) varName;
```

* 通过推导exp的类型或者exp返回值类型，所得的类型赋值給varname。

例如：

```cpp
int main()
{
	int a = 0;
	decltype(a) b = 1; // b -> int
	decltype(a + b) c = 0; // c -> int
	const int& d = a;  
	decltype(d)e = c; //e -> const int&
	return 0;
}
```

