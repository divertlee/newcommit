#include <iostream>
#include<string>
using namespace std;

int main()
{
    // 请在此输入您的代码
    int ret = 2021;
    for (int i=1; ret >= 0; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1')
            {
                ret--;
                if (ret == 0)
                {
                    cout << i << endl;
                    return 0;
                }
               
            }
        }
    }
   
    return 0;
}
//int main()
//{
//    // 请在此输入您的代码
//    int ret = 0;
//    for (int i = 1; i <= 2020; i++)
//    {
//        string s = to_string(i);
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (s[i] == '2')
//            {
//                ret++;
//            }
//
//        }
//    }
//    cout << ret << endl;
//}

//#include <iostream>
//using namespace std;
//#include <iostream>
//using namespace std;
//int main()
//{
//    // 请在此输入您的代码
//    int num = 0;
//    for (int i = 1; i <= 2020; i++) {
//        if (i % 10 == 2) num++;
//        if (i / 10 % 10 == 2) num++;
//        if (i / 100 % 10 == 2) num++;
//        if (i / 1000 == 2) num++;
//    }
//    cout << num;
//    return 0;
//}
//int main()
//{
//    // 请在此输入您的代码
//    int ret = 0;
//    for (int i = 1; i <= 2020; i++)
//    {
//        int sum = i;
//        while (sum / 10)
//        {
//            int tmp = i % 10;
//            if (tmp == 2)
//            {
//                ret++;
//            }
//            sum /= 10;
//        }
//        if (sum == 2)
//        {
//            ret++;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}