#pragma once
#include<iostream>
#include<map>
#include<string.h>
#include<mutex>
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
//
//	~HeapOnly() { cout << "~HeapOnly" << endl; }
//private:
//	HeapOnly() {};//���ù��캯������ֹ�ⲿ���ù��캯����ջ�ϴ�������
//	HeapOnly(const HeapOnly& hp) = delete;//������
//};
//
//int main()
//{
//	//HeapOnly* hps = new HeapOnly();//��������Ҫ���ù��캯����Ȼ�����캯�����ܱ�����
//	HeapOnly* hps = HeapOnly::Createobj();
//
//	HeapOnly* hp2 = HeapOnly::Createobj();
//	
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
//	��new��delete����������ͨ��new�ڶ��ϴ������󣬵�������ͨ��static�����ھ�̬���ϴ�������
//private:
//	StackOnly() {};//���캯��˽�С��ⲿͨ��new����Ҳ��Ҫ�߹��캯��
//	StackOnly(const StackOnly& st) = delete;//������
//
//
//};
//int main()
//{
//	StackOnly* st = new StackOnly();//���캯��˽�л�������ͨ��new�������󼴲����ڶ��ϴ�������
//	static StackOnly st = StackOnly::CreateObj();//????
// StackOnly st= StackOnly::CreateObj();
//	static StackOnly sp1;//Ҫ�߹��캯��
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
//	
//private:
//	Father() { cout << "get Father" << endl; };
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
//ȱ�㣺���ܵ�����Ŀ�����ٶ�������������1����֮���й����ԣ���������main����֮ǰ�������ô���˳���޷������ǿ��ƣ����������˳����OS��������ô�ᵼ�³�������������

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
//
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
//������main����֮�󴴽����䴴��˳������������ƶ�
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

//class SingalInfo
//{
//public:
//
//	static SingalInfo& GetInstance()
//	{
//		static SingalInfo instance;//��̬�ľֲ���������main����֮�󴴽���
//		//C++11֮���ܹ���֤������̬�������̰߳�ȫ��
//		return instance;
//	}
//   
//	static SingalInfo& getbody()
//	{//������߳̽���ʱ����new������������Ҫ��������
//		if (_sig == nullptr)//��һ�ν���ʱָ��Ϊ�գ��ʹ����¶��󣬷���ֱ�ӷ��ش˶���
//		{
//			LockGuard<mutex> lg(_mut);
//		//	_mut.lock();//˫�ؼ�飺��һ�ν�����ֻ��һ���߳��ܹ�new����
//			if (_sig == nullptr)
//			{
//				_sig = new SingalInfo();
//			}
//		//	_mut.unlock();//��������new����ʧ�����쳣���½���ʧ��
//		}
//		return *_sig;
//	}
////
//	static void DeleteInstance()
//	{
//		//...��������
//
//		LockGuard<mutex> lg(_mut);
//		if (_sig)
//		{
//			cout << "~ _sig" << endl;
//			delete _sig;
//			_sig = nullptr;
//		}
//	}
////
//	class GC//�ڲ����൱����Ԫ��ֱ��������ĳ�Ա
//	{
//	public:
//		~GC()
////����һ���ڲ��࣬������main�����洦λ�õ����ͷ��ⲿ�࣬���ߵ��ⲿ����������ڽ���ʱ�Զ����ø��ڲ�������������ͷ��ⲿ�ࡣ�������ô�����ǰ�ⲿ��ĸ����̻����ⲿ��
//		{
//			
//			DeleteInstance();
//		}
//	};

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
//	SingalInfo() { cout << "touch SingalInfo" << endl; };//���캯��˽�л�
//	SingalInfo(SingalInfo& sig) = delete;//���ÿ�������
//	SingalInfo& operator=(SingalInfo& sig) = delete;//���ÿ�����ֵ
//private:
//	//static	SingalInfo* _sig;//��������---������ֻ��һ������
//	map<string, int> _info;
//	//static mutex _mut;
//	//static GC _gc;//�ڲ�������
//
//};
////SingalInfo* SingalInfo::_sig=nullptr;//���ⶨ�����ȫ�ֶ������ȫ�����ԣ�����������ȫ��
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
////	kk.Print();//��ʱkk�����ӡ�����ݺ�ǰ������������ӡ��������һ���ı�ʾȫ���ڶ���ֻ��һ��
////	//SingalInfo::DeleteInstance();
////	return 0;
////}
////
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
//	kk.Print();//��ʱkk�����ӡ�����ݺ�ǰ������������ӡ��������һ���ı�ʾȫ���ڶ���ֻ��һ��
//	return 0;
//}

//const ���Եı���������ջ֡�����ڳ�����
int main()
{
	
	volatile const int b = 3;//��volatile���Σ���ʾ�ñ��������ڴ�ɼ���
	int* pp = const_cast<int*>(&b);
//��ӡʱ��b=3��*pp=5����ԭ������ϵͳĬ��const�������ᱻ�ı䣬��˶�const���������Ż���
//��const��������Ĵ����У�֮��Ҫ�õ���ȥ�Ĵ�������ȡ,������ڴ��иı�󲻻���µ��Ĵ����У�����const����ȡ���ľ��Ǹı�֮ǰ��ֵ
//���ڼ��Ӵ��ڿ���b��*pp�������5����ԭ�����ڼ��Ӵ��������ڴ���ȡ�����ݣ����bȡ�����Ǹ��º������
	*pp = 5;
	cout << "const int b: " << b << endl;//3
	cout << " *pp: " << *pp << endl;//5

	return 0;
}

//class A
//{
//public:
//	virtual void fun(){}
//
//	int _a = 10;
//};
//
//class B : public A
//{
//public:
//	int _b = 20;
//};
//
//void func(A* ap)
//{
//	//B* pb1 = static_cast<B*>(ap);//ת����
//	B* pb1 = dynamic_cast<B*>(ap);//ת����
//	A* pb2 = static_cast<A*>(ap);//ת����
//	
//	cout << "pb1: " << pb1 << endl;
////ʹ��dynamic_cast�󣬸���ת������Ҫ�����ģ���ת��ʧ���򷵻ؿսoָ�룬�������ø�ָ���ֱ���жϳ���
//	pb1->_a = 40;//���︸��ת���࣬��Ӧ����ָ�벻���õ�����ĳ�Ա����,�������ת���ǲ���ȫ��
//	pb1->_b = 50;
//	cout << "pb1->_a: " << pb1->_a << " pb1->_b: " << pb1->_b << endl;
//	cout << "pb2: " << pb2 << endl;
//
//	pb2->_a = 100;
//}
//
//
//int main()
//{
//	A a;
//	B b;
//	func(&a);//������ָ���ȥת��
//	func(&b);//������ָ���ȥת��
//	return 0;
//}

//���Ľ�����C++��������ƣ����һ���಻�ܱ����������һ����ֻ���ڶ��ϴ�����ֻ����ջ�ϴ��������һ���಻�ܱ��̳С�����ģʽ�ĸ���ͳ����Ķ���ģʽ������ģʽԭ����ʵ��


//void test1()
//{
//	int a = 10;
//	double b = a;//��ʽ����ת��
//	cout << "int a= " << a << " double b= " << b << endl;
//
//	int* p = &a;
//	int c = (int)p;//��ʾ��ǿ������ת��
//
//	cout << "p= " << p << " int c= " << c << endl;
//}
//
//void test1()
//{
//	double a = 3.1415926;
//	int b = static_cast<int>(a);//
//	cout << "double a= " << a << " int b= " << b << endl;
//}

//void test1()
//{
//	int a = 111;
//
////	int* p = static_cast<int*>(a);//����ᱨ������ת����Ч
//	int* p = reinterpret_cast<int*>(a);//����ᱨ������ת����Ч
//
//	cout << "int a= " << a << " int*p= " << p << endl;
//}
//
//int main()
//{
//	test1();
//	return 0;
//}