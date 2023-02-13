#pragma once 
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
using namespace std;
int arr[100001];


int hashe[6] = { 0 };
int main()
{
    // 请在此输入您的代码
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++)
    {
        hashe[arr[i]]++;
    }
    int prev = 0;
    int cur = 0;
    int flag = 0;
    for (int i = 1; i < 6; i++)
    {
        if (flag != 0&&hashe[i]>1)//第一次进来
        {
            flag = 1;
            prev =i;
       }

        while (flag == 1 && hashe[i] != 0)
        {
            cur = i;
            hashe[prev]--;
            hashe[cur]++;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (hashe[i] == 1)
        {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
//int main()
//{
//	int N = 7;
//	int k = 0;
//	for (int i = 1; i <= N; i++)//1到N的位置上有数据
//	{
//		//scanf("%d", &arr[i]);
//		cin >> arr[i];
//	}
//	
//	int e = 1;
//	int depth = 1;
//	int ret = arr[1];
//	int sum = 0;
//	for (int i = 2; i <= N; i++)
//	{
//		sum += arr[i];
//		if ((pow(2, e + 1)-1) == i)//找到断点
//		{
//			if (sum > ret)
//			{
//				ret = sum;
//				sum = 0;
//				depth++;
//			}
//			e++;
//		}
//	}
//	cout << depth << ret<<endl;
//
//
//	//int i = 2;
//	//while (N > 0)
//	//{
//	//	int num = N % i;
//	//	vector<int> v;
//	//	for (int j = 0; j < num; j++)
//	//	{
//	//		int key = 0;
//	//		cin >> key;
//	//		v.push_back(key);
//	//	}
//	//	ret.push_back(v);
//	//	N -= num;
//	//	i *= 2;
//	//}
//	
//	/*int i = 1;
//	while (i <= N)
//	{
//		cout << i << endl;
//		i << 1;
//	}*/
//	/*for (int i = 1; i <= N; i++)
//	{
//		vector<int> tt;
//		for (int j = 0; j < i; j++)
//		{
//			
//			int k = 0;
//			cin >> k;
//			tt.push_back(k);
//		}
//		ret.push_back(tt);
//		i << 1;
//	}*/
//	// 请在此输入您的代码
//
//	return 0;
//}


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

//完全二叉树的权值
//#include <iostream>
//#include<math.h>
//using namespace std;
//int arr[100001];
//int main()
//{
//    int N = 0;
//    cin >> N;
//    int k = 0;
//    for (int i = 1; i <= N; i++)//1到N的位置上有数据
//    {
//        //scanf("%d", &arr[i]);
//        cin >> arr[i];
//    }
//
//    int e = 1;
//    int depth = 1;
//    int ret = arr[1];
//    int sum = 0;
//    for (int i = 2; i <= N; i++)
//    {
//        sum += arr[i];
//        if ((pow(2, e + 1) - 1) == i)//找到断点
//        {
//            if (sum > ret)
//            {
//                ret = sum;
//                sum = 0;
//                depth++;
//            }
//            e++;
//        }
//    }
//    cout << depth << endl;
//    return 0;
//}

 //修改数组
//#include <iostream>
////using namespace std;
////int main()
////{
////    // 请在此输入您的代码
////    int N = 0;
////    cin >> N;
////    int arr[100001] = { 0 };
////    int hashe[1000001] = { 0 };
////    for (int i = 0; i < N; i++)
////    {
////        cin >> arr[i];
////        while (hashe[arr[i]] != 0)//哈希表不等于0就是该元素已经出现了
////        {
////            hashe[arr[i]]++;
////            arr[i] += (hashe[arr[i]] - 1);
////        }
////        hashe[arr[i]]++;
////        cout << arr[i] << " ";
////    }
////    cout << endl;
////    return 0;
////}