#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n = 0;
    cin >> n;
    vector<double>num(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    /*7
        80
        92
        56
        74
        88
        100
        0*/
    double six = 0;
    double ef = 0;
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] >= 60)
        {
            six++;
        }
        if (num[i] >= 85)
        {
            ef++;
        }
    }
    double rets = (six / n) * 100;
    cout << setprecision(2) << rets << '%' << endl;
    double retef = (ef / n) * 100;
    cout << setprecision(2) << retef << '%' << endl;
    return 0;
}

//int main()
//{
//	double x = 5;
//	double y = 7;
//	double a = (x/y)*100;
//	cout << setprecision(3) << a<<'%' << endl;
//	printf("%.2lf", a);
//	return 0;
//
//}