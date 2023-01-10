#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<stdio.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int* arr = new int[n*n];
    int tmp = 0;
    for (int i = 0; i < n * n; i++)
    {
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
    int sum = 0;
    for (int i = 0; i < n*n; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
    return 0;
}