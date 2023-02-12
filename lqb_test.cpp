#pragma once 
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
using namespace std;
int arr[100001];
int main()
{
	int N = 7;
	int k = 0;
	for (int i = 1; i <= N; i++)//1到N的位置上有数据
	{
		//scanf("%d", &arr[i]);
		cin >> arr[i];
	}
	
	int e = 1;
	int ret = arr[1];
	int sum = 0;
	for (int i = 2; i <= N; i++)
	{
		sum += arr[i];
		if ((pow(2, e + 1)-1) == i)//找到断点
		{
			if (sum > ret)
			{
				ret = sum;
				sum = 0;
				e++;
			}
		}
		
	}

	//int i = 2;
	//while (N > 0)
	//{
	//	int num = N % i;
	//	vector<int> v;
	//	for (int j = 0; j < num; j++)
	//	{
	//		int key = 0;
	//		cin >> key;
	//		v.push_back(key);
	//	}
	//	ret.push_back(v);
	//	N -= num;
	//	i *= 2;
	//}
	
	/*int i = 1;
	while (i <= N)
	{
		cout << i << endl;
		i << 1;
	}*/
	/*for (int i = 1; i <= N; i++)
	{
		vector<int> tt;
		for (int j = 0; j < i; j++)
		{
			
			int k = 0;
			cin >> k;
			tt.push_back(k);
		}
		ret.push_back(tt);
		i << 1;
	}*/
	// 请在此输入您的代码

	return 0;
}


//#include <cstdio>
//#include <cmath>
//
//using namespace std;
//const int N = 100010;
//int a[N];
//
//int main() {
//
//	int n, res, sum = 0, dep = 1;
//
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//
//	res = a[1];
//
//	int e = 1;
//	for (int i = 2; i <= n; i++) {
//		sum += a[i];
//		if (pow(2, e + 1) - 1 == i) {
//			if (sum > res) {
//				res = sum;
//				dep = e + 1;
//			}
//			sum = 0;
//			e++;
//		}
//	}
//	if (sum > res) {
//		res = sum;
//		dep = e + 1;
//	}
//	printf("%d", dep);
//	return 0;
//}