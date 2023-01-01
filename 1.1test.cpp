#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>

using namespace std;



  //  void getNext(int* next, const string& s) {
  //      int j = 0;
  //      next[0] = 0;
  //      for (int i = 1; i < s.size(); i++) {
  //          while (j > 0 && s[i] != s[j]) {
  //              j = next[j - 1];
  //          }
  //          if (s[i] == s[j]) {
  //              j++;
  //          }
  //          next[i] = j;
  //      }
  //  }
  //  int strStr(string haystack, string needle) {
  //      if (needle.size() == 0) {
  //          return 0;
  //      }
  //     
  //      int next[k];
  //      getNext(next, needle);
  //      int j = 0;
  //      for (int i = 0; i < haystack.size(); i++) {
  //          while (j > 0 && haystack[i] != needle[j]) {
  //              j = next[j - 1];
  //          }
  //          if (haystack[i] == needle[j]) {
  //              j++;
  //          }
  //          if (j == needle.size()) {
  //              return (i - needle.size() + 1);
  //          }
  //      }
  //      return -1;
  //  }

 

  //  int main()
  //{
  //    string needle = "aabaaf";
  //    string haystack = "aabaabaaf";
  //   
  //    int ret = strStr(haystack, needle);
  //}


    void getnext(int* next, const string& s)
    {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            while (j > 0 && s[j] != s[i])//字符不相等就回退】
            {
                j = next[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
        {
            return 0;
        }
       
        int next[6] ;
        getnext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); ++i)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                ++j;
            }

            if (j == needle.size())
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }

    int main()
    {
        string needle = "aabaaf";
        string haystack = "aabaabaaf";
        int ret = strStr(haystack, needle);
        cout << ret << endl;
    }