#include<iostream>

using namespace std;

//ֻ��ջ�ϴ����Ķ���
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();//
//	}
//private:
//	StackOnly() {};//���캯��˽�С��ⲿͨ��new����Ҳ��Ҫ�߹��캯��
//
//};
//
//int main()
//{
//	//StackOnly* st = new StackOnly();//���캯��˽�л�������ͨ��new�������󼴲����ڶ��ϴ�������
//	//static StackOnly sp1;//Ҫ�߹��캯��
//	//static StackOnly st = StackOnly::CreateObj();//û�з���������캯�����������ͨ���������캯���ھ�̬���ϴ���
//	//StackOnly st= StackOnly::CreateObj();//����ͨ������������ջ�ϴ������󣬵��޷���ֹ�ھ�̬���ϴ���
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
	//��new��delete����������ͨ��new�ڶ��ϴ�������
private:
	StackOnly() {};//���캯��˽�С��ⲿͨ��new����Ҳ��Ҫ�߹��캯��
	StackOnly(const StackOnly& st) = delete;//������---��ֹͨ�����ÿ��������ھ�̬���ϴ�������


};
int main()
{
	//static StackOnly sp1;//Ҫ�߹��캯��
	StackOnly::CreateObj().Print();//ͨ������������ջ�ϴ�������������һ�о͵������������ͷ���������
	const StackOnly& so4 = StackOnly::CreateObj();
	//ͨ��const ���ý����������������������������ת��Ϊso4�������������,��cosnt�����ӳ�������������������ڡ�����������ջ�ϴ���
	so4.Print();
	return 0;
}