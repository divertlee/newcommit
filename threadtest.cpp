#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<atomic>
using namespace std;

int gval = 0;
atomic<int> aval = 0;
mutex mut;
void func1(int val)
{	//	mut.lock();
	for (int i = 0; i < val; i++)
	{
	//	mut.lock();
	//	gval++;
	//	mut.unlock();//�����������������������һ���Ǽ������������Ķ������л������ĵ�����
		aval++;//ʹ�������߱�ԭ����
	}
	//	mut.unlock();
	
}

int main()
{
	int m = 10000000;
	thread t1(func1,m);
	thread t2(func1,2*m);
	t1.join();
	t2.join();
	
	cout << "val: " << aval << endl;
	return 0;
}

//int main()
//{
//	int n, m;
//	cin >> n >> m;//n���߳�����m���߳�������ѭ���Ĵ���
//
//	vector<thread> v;
//	v.resize(n);
//
//	for (auto& th : v)
//	{
//		th = thread([m] {
//			for (size_t i = 0; i < m; i++)
//			{
//				cout << this_thread::get_id() << " i " << i << endl;
//			}
//			});
//	}
//
//	for (auto& th : v)
//	{
//		th.join();
//	}
//	return 0;
//}

