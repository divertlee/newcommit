#pragma once
#include<iostream>
#include<map>
#include<string.h>
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
//	//��new��delete����������ͨ��new�ڶ��ϴ������󣬵�������ͨ��static�����ھ�̬���ϴ�������
//private:
//	StackOnly() {};//���캯��˽�С��ⲿͨ��new����Ҳ��Ҫ�߹��캯��
//	StackOnly(const StackOnly& st) = delete;//������
//
//
//};
//int main()
//{
//	//StackOnly* st = new StackOnly();//���캯��˽�л�������ͨ��new�������󼴲����ڶ��ϴ�������
//	//static StackOnly st = StackOnly::CreateObj();//????
// //StackOnly st= StackOnly::CreateObj();
//	//static StackOnly sp1;//Ҫ�߹��캯��
//	StackOnly::CreateObj().Print();
//	const StackOnly& so4 = StackOnly::CreateObj();
//	so4.Print();
//	return 0;
//}

//���һ���಻�ܱ��̳�
//����һ���ѻ���Ĺ��캯��˽�л�

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
//	Son s;//����������ʱ������û���Ĺ��캯��ȥ����̳е��Ļ����ǲ���
//	Father fe= s.getf();//����Ĺ��캯�����ڹ������������ܹ�����
//	return 0;
//}

//class Father
//{
//public:
//
//	
//private:
//	Father() { cout << "get Father" << endl; };//���캯��˽�л���û����޷����̳�
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
//������final�������ʾΪ���һһ���࣬���ܱ��̳�
//class Father final
//{
//public:
//
//	Father() { cout << "get Father" << endl; };//���캯��˽�л���û����޷����̳�
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

//����ģʽ
//����ģʽ���ࣺȫ��ֻ��һ��
//����ģʽ
//������main����֮ǰ�ʹ�������

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
//	SingalInfo() {};//���캯��˽�л�
//	SingalInfo(SingalInfo& sig) = delete;//���ÿ�������
//	SingalInfo& operator=(SingalInfo& sig) = delete;//���ÿ�����ֵ
//private:
// static	SingalInfo _sig;//��������---������ֻ��һ������
// map<string, int> _info;
//
//};
//SingalInfo SingalInfo::_sig;//���ⶨ�����ȫ�ֶ������ȫ�����ԣ�����������ȫ��

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
//	kk.Print();//��ʱkk�����ӡ�����ݺ�ǰ������������ӡ��������һ���ı�ʾȫ���ڶ���ֻ��һ��
//	return 0;
//}
//����ģʽ
class SingalInfo
{
public:
	static SingalInfo& getbody()
	{
		if (_sig == nullptr)//��һ�ν���ʱָ��Ϊ�գ��ʹ����¶��󣬷���ֱ�ӷ��ش˶���
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
	SingalInfo() {};//���캯��˽�л�
	SingalInfo(SingalInfo& sig) = delete;//���ÿ�������
	SingalInfo& operator=(SingalInfo& sig) = delete;//���ÿ�����ֵ
private:
	static	SingalInfo* _sig;//��������---������ֻ��һ������
	map<string, int> _info;

};
SingalInfo* SingalInfo::_sig=nullptr;//���ⶨ�����ȫ�ֶ������ȫ�����ԣ�����������ȫ��

int main()
{
	SingalInfo& kk = SingalInfo::getbody();
	kk.Insert("me", 10000);
	kk.Insert("you", 20000);
	kk.Insert("who", 30000);

	kk.Print();

	SingalInfo::getbody().Insert("she", 25000);
	SingalInfo::getbody().Print();

	kk.Print();//��ʱkk�����ӡ�����ݺ�ǰ������������ӡ��������һ���ı�ʾȫ���ڶ���ֻ��һ��
	return 0;
}