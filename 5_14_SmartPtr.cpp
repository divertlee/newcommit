#include<iostream>

using namespace std;

template<class T>
class SmartPtr
{
public:
	SmartPtr(T*ptr=nullptr)
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


int div()
{
	int a, b;
	cin >> a >> b;
	if (b == 0)
		throw invalid_argument("除0错误");
	return a / b;
}
void Func()
{
	// 1、如果p1这里new 抛异常会如何？
	// 2、如果p2这里new 抛异常会如何？
	// 3、如果div调用这里又会抛异常会如何？
	int* p1 = new int[10];
	SmartPtr<int> sp1(p1);
	*sp1 = 10;
	int* p2 = new int[10];
	SmartPtr<int> sp2(p2);
	cout << div() << endl;//若这里抛异常，则上面申请的空间，栈帧在这里就跳出去，后面的代码执行不了，申请的空间没有释放造成内存泄漏
	delete[] p1;
	delete[] p2;
}
int main()
{
	try
	{
		Func();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}