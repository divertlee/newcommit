#include<string.h>
#include<iostream>
using namespace std;

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1) return false;
        string temp = "", str = "";
        for (int i = 0; i < s.size() / 2; ++i)
        {
            temp += s[i];
            while (str.size() <= s.size())
            {
                str += temp;
                if (str.compare(s) == 0 && str.size() == s.size())
                {
                    return true;
                }
            }
            str = "";
        }
        return false;
    }

    int main()
    {
        string s = "aabaab";
        int i = repeatedSubstringPattern(s);
        return 0;
    }


//void getnext(int* next, const string& s)//开辟好next数组，也把s字符串传进来
//{
//    int j = 0;
//    next[0] = j;//初始化
//    for (int i = 1; i < s.size(); ++i)
//    {
//        while (j > 0 && s[j] != s[i])//处理前后缀不匹配的情况
//        {
//            j = next[j - 1];
//        }
//        if (s[j] == s[i])
//        {
//            j++;
//        }
//        next[i] = j;//无论前后缀相等还是不相等，i始终往后走，且前缀表一直在填充
//    }
//}
//
//int main()
//{
//	string s = "aabaabaaf";
//	string n = "aabaaf";
//	int next[6];
//    getnext(next, n);
//    int j = 0;
//    for (int i = 1; i < s.size(); ++i)
//    {
//        while (j > 0 && s[i] != n[j])
//        {
//            j = next[j - 1];
//        }
//        if (s[i] == n[j])
//        {
//            ++j;
//        }
//        if (j == n.size())
//        {
//            cout<< (i - n.size() + 1)<<endl;
//        }
//    }
//    cout << -1 << endl;//如果不匹配就返回-1
//    return 0;
//}