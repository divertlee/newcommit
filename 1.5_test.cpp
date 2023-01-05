class Solution {
public:
    void reverse(string& s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start++], s[end--]);
        }
    }
    string reverseWords(string s) {
        int fasti = 0;
        int slowi = 0;
        while (s.size() > 0 && fasti < s.size() && s[fasti] == ' ')//ȥ��ǰ��Ŀո�
        {
            fasti++;
        }
        for (; fasti < s.size(); ++fasti)
        {
            if (fasti - 1 > 0 && s[fasti - 1] == s[fasti] && s[fasti] == ' ')//��������ո������
        //fasti-1>0�Ǳ�֤ǰһ��λ���пո�
            {
                continue;
            }
            else {
                s[slowi++] = s[fasti];//�ѵ�����ǰ��
            }
        }
        if (slowi - 1 > 0 && s[slowi - 1] == ' ')  //slowi-1>0�Ǳ�֤ǰһ��λ���пո�
        {
            s.resize(slowi - 1);
        }
        else
        {
            s.resize(slowi);
        }
        int start = 0;
        int end = s.size() - 1;
        reverse(s, start, end);//ȫ������
        int i = 0;
        for (; start <= s.size(); start++)//�ѵ������û���
        {
            if (s[start] == ' ' || start == s.size())
            {
                reverse(s, i, start - 1);
                i = start + 1;
            }
        }
        return s;
    }
};


class Solution {
public:
    void swap(vector<char>& s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            ++i;
            --j;
        }
    }
    void reverseString(vector<char>& s) {
        swap(s);
    }
};


class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};