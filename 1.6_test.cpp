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


//void getnext(int* next, const string& s)//���ٺ�next���飬Ҳ��s�ַ���������
//{
//    int j = 0;
//    next[0] = j;//��ʼ��
//    for (int i = 1; i < s.size(); ++i)
//    {
//        while (j > 0 && s[j] != s[i])//����ǰ��׺��ƥ������
//        {
//            j = next[j - 1];
//        }
//        if (s[j] == s[i])
//        {
//            j++;
//        }
//        next[i] = j;//����ǰ��׺��Ȼ��ǲ���ȣ�iʼ�������ߣ���ǰ׺��һֱ�����
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
//    cout << -1 << endl;//�����ƥ��ͷ���-1
//    return 0;
//}