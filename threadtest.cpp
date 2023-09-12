#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<atomic>
using namespace std;

void Add(int left, int right)
{
	cout <<"left+right: " << left + right << endl;
}

class ADD
{
public:
	int operator()()
	{
		int x = 20, y = 10;
		return x + y;
	}
};


int main()
{
	int x = 10;
	int y = 20;
	thread t1(Add,x,y);//可调用对象为函数指针
	thread t2([x, y] {cout <<"x+y: " << x + y << endl; });//可调用对象为lambda表达式
	ADD dd;
	thread t3(dd);//可调用对象为函数对象
	t1.join();
	t2.join();
	t3.join();
	return 0;
}

//int gval = 0;
//atomic<int> aval = 0;
//mutex mut;
//void func1(int val)
//{	//	mut.lock();
//	for (int i = 0; i < val; i++)
//	{
//	//	mut.lock();
//	//	gval++;
//	//	mut.unlock();//锁放里面相比于锁放外面会多一个是加锁解锁的消耗二个是切换上下文的消耗
//		aval++;//使得这条具备原子性
//	}
//	//	mut.unlock();
//	
//}
//
//int main()
//{
//	int m = 10000000;
//	thread t1(func1,m);
//	thread t2(func1,2*m);
//	t1.join();
//	t2.join();
//	
//	cout << "val: " << aval << endl;
//	return 0;
//}

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

