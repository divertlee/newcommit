#include<iostream>
#include<string.h>
using namespace std;

void reverse(string& s, int start, int end)
{
    while (start < end)
    {
        swap(s[start++], s[end--]);
    }
}

int main()
{
	string s = "the sky is blue";
    int fast = 0;
    int slow = 0;
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ')//删除前面的空格
    {
        fast++;
    }
    for (; fast < s.size(); ++fast)
    {
        if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ')
        {
            continue;
        }
        else
        {
            s[slow++] = s[fast];
        }

    }
    if (slow - 1 > 0 && s[slow - 1] == ' ')
    {
        s.resize(slow - 1);

    }
    else {
        s.resize(slow);
    }
    int start = 0;
    int end = s.size()-1;
    reverse(s, start, end);
    for (int mod=0; mod <= s.size(); ++mod)
    {
        if (s[mod] == ' '|| mod==s.size())
        {
            reverse(s, start, mod-1);
            start = mod + 1;
        }
    }
    cout << s << << endl;
	return 0;
}