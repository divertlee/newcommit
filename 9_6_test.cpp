#pragma once
#include<iostream>

using namespace std;

//ֻ���ڶ��ϴ�������
//class HeapOnly
//{
//public:
//	static HeapOnly* Createobj()
////��static���εĺ������ٵ������ڶ��󣬶��������࣬����ͨ�����ں������á�
////���������static���Σ���ô������ĺ�����ζ�����ж��󣬶��ⲿ���ò��˹��캯���Ͳ��ܴ�������
//	{
//		return new HeapOnly();
//	}
//private:
//	HeapOnly() {};//���ù��캯������ֹ�ⲿ���ù��캯����ջ�ϴ�������
//	HeapOnly(const HeapOnly& hp) = delete;//������
//};
//
//int main()
//{
//	//HeapOnly* hps = new HeapOnly();//��������Ҫ���ù��캯����Ȼ�����캯�����ܱ�����
//	HeapOnly* hps = HeapOnly::Createobj();
//}

//ֻ��ջ�ϴ����Ķ���
class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		return StackOnly();//
	}
private:
	StackOnly() {};//���캯��˽�С��ⲿͨ��new����Ҳ��Ҫ�߹��캯��
	//StackOnly(const StackOnly& st) = delete;//������
};
int main()
{
	//StackOnly* st = new StackOnly();//���캯��˽�л�������ͨ��new�������󼴲����ڶ��ϴ�������
	//static StackOnly st = StackOnly::CreateObj();//????
 	StackOnly st= StackOnly::CreateObj();
	//static StackOnly sp1;//Ҫ�߹��캯��

	return 0;
}
