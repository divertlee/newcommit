#include<iostream>

using namespace std;

//只在栈上创建的对象
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();//
//	}
//private:
//	StackOnly() {};//构造函数私有。外部通过new对象也需要走构造函数
//
//};
//
//int main()
//{
//	//StackOnly* st = new StackOnly();//构造函数私有化，不能通过new创建对象即不能在堆上创建对象
//	//static StackOnly sp1;//要走构造函数
//	//static StackOnly st = StackOnly::CreateObj();//没有封掉拷贝构造函数，这里可以通过拷贝构造函数在静态区上创建
//	//StackOnly st= StackOnly::CreateObj();//可以通过拷贝构造在栈上创建对象，但无法防止在静态区上创建
//	
//	return 0;
//}

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