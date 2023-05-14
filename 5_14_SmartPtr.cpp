#include<iostream>

using namespace std;

template<class T>
class SmartPtr
{
public:
	SmartPtr(T*ptr=nullptr)
		:_ptr(ptr)
	{
		cout << "���죺" << _ptr << endl;
	}

	~SmartPtr()
	{
		if (_ptr)
			cout << "������" << _ptr << endl;
		delete[]_ptr;
	}

	T& operator*()//ȡ���������
	{
		return *_ptr;
	}

	T* operator->()//ȡ����ĵ�ַ
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
		throw invalid_argument("��0����");
	return a / b;
}
void Func()
{
	// 1�����p1����new ���쳣����Σ�
	// 2�����p2����new ���쳣����Σ�
	// 3�����div���������ֻ����쳣����Σ�
	int* p1 = new int[10];
	SmartPtr<int> sp1(p1);
	*sp1 = 10;
	int* p2 = new int[10];
	SmartPtr<int> sp2(p2);
	cout << div() << endl;//���������쳣������������Ŀռ䣬ջ֡�����������ȥ������Ĵ���ִ�в��ˣ�����Ŀռ�û���ͷ�����ڴ�й©
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