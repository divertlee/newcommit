#pragma once 
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;
//int arr[100001];
int main()
{
	string str;
	cin >> str;
	int hashe[123] = { 0 };
	for (int i = 0; i < str.size(); i++)
	{
		hashe[str[i]]++;
	}
	int num = 0;
	int k = 0;
	for (int i = 0; i < 123; i++)
	{
		if (hashe[i] > num)
		{
			num = hashe[i];//���ֵĴ���
			k = i;//�ַ���Ӧ��asc��ֵ
		}
	}
	printf("%d ", num);
	printf("%c\n", k);


		
	return 0;
}
#include <iostream>
#include<string.h>
using namespace std;
int main()
{
  // ���ڴ��������Ĵ���

string str;
    cin >> str;
    int hashe[123] = { 0 };
    for (int i = 0; i < str.size(); i++)
    {
        hashe[str[i]]++;
    }
    int num = 0;
    int k = 0;
    for (int i = 0; i < 123; i++)
    {
        if (hashe[i] > num)
        {
            num = hashe[i];//���ֵĴ���
            k = i;//�ַ���Ӧ��asc��ֵ
        }
    }
    printf("%c\n", k);
    printf("%d\n", num);
  return 0;
}

//int hashe[6] = { 0 };
//int main()
//{
//    // ���ڴ��������Ĵ���
//    int N = 0;
//    cin >> N;
//
//    for (int i = 0; i < N; i++)
//    {
//        cin >> arr[i];
//    }
//    for (int i = 1; i < N; i++)
//    {
//        hashe[arr[i]]++;
//    }
//    int prev = 0;
//    int cur = 0;
//    int flag = 0;
//    for (int i = 1; i < 6; i++)
//    {
//        if (flag != 0&&hashe[i]>1)//��һ�ν���
//        {
//            flag = 1;
//            prev =i;
//       }
//
//        while (flag == 1 && hashe[i] != 0)
//        {
//            cur = i;
//            hashe[prev]--;
//            hashe[cur]++;
//        }
//    }
//
//    for (int i = 0; i < 6; i++)
//    {
//        if (hashe[i] == 1)
//        {
//            cout << i << " ";
//        }
//    }
//
//    cout << endl;
//    return 0;
//}
//int main()
//{
//	int N = 7;
//	int k = 0;
//	for (int i = 1; i <= N; i++)//1��N��λ����������
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
//		if ((pow(2, e + 1)-1) == i)//�ҵ��ϵ�
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
//	// ���ڴ��������Ĵ���
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

//��ȫ��������Ȩֵ
//#include <iostream>
//#include<math.h>
//using namespace std;
//int arr[100001];
//int main()
//{
//    int N = 0;
//    cin >> N;
//    int k = 0;
//    for (int i = 1; i <= N; i++)//1��N��λ����������
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
//        if ((pow(2, e + 1) - 1) == i)//�ҵ��ϵ�
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

 //�޸�����
//#include <iostream>
////using namespace std;
////int main()
////{
////    // ���ڴ��������Ĵ���
////    int N = 0;
////    cin >> N;
////    int arr[100001] = { 0 };
////    int hashe[1000001] = { 0 };
////    for (int i = 0; i < N; i++)
////    {
////        cin >> arr[i];
////        while (hashe[arr[i]] != 0)//��ϣ��������0���Ǹ�Ԫ���Ѿ�������
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