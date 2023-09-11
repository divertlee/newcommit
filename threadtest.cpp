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
	//	mut.unlock();//锁放里面相比于锁放外面会多一个是加锁解锁的消耗二个是切换上下文的消耗
		aval++;//使得这条具备原子性
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
//	cin >> n >> m;//n是线程数，m是线程内任务循环的次数
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

