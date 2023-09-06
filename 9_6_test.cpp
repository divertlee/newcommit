#pragma once
#include<iostream>

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
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();//
	}
private:
	StackOnly() {};//构造函数私有。外部通过new对象也需要走构造函数
	//StackOnly(const StackOnly& st) = delete;//防拷贝
};
int main()
{
	//StackOnly* st = new StackOnly();//构造函数私有化，不能通过new创建对象即不能在堆上创建对象
	//static StackOnly st = StackOnly::CreateObj();//????
 	StackOnly st= StackOnly::CreateObj();
	//static StackOnly sp1;//要走构造函数

	return 0;
}
