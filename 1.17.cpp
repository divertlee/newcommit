#include<iostream>
#include<string.h>
using namespace std;
    void killblank(string& s)//去除多余空格
    {
        int cur = 0;
        int prev = 0;
        while (cur < s.size())//去除前面的空格
        {
            if (s[cur] != ' ')
            {
                break;
            }
            cur++;
        }
        while (cur < s.size())
        {
            if (cur > 0 && s[cur - 1] == ' ' && s[cur] == s[cur - 1])//去除中间多余的空格
            {
                cur++;
            }
            else
            {
                s[prev++] = s[cur++];
            }
        }

        if (prev > 0 && s[prev - 1] == ' ')
        {
            s.resize(prev - 1);
        }
        else
        {
            s.resize(prev);
        }
    }
    string reverseWords(string&s) {
        killblank(s);//去除多余空格

        reverse(s.begin(), s.end());//全逆置
        int prev = 0;
        for (int cur = 0; cur <= s.size(); cur++)
        {
            if (s[cur] == ' ' || cur == s.size())
            {
                reverse(s.begin() + prev, s.begin() + cur);
                prev = cur + 1;
            }

        }
        return s;
    }

    int main()
    {
        string s = "  hello  world  ";
        reverseWords(s);
        cout << s << endl;
        return 0;
    }
