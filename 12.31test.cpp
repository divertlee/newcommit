#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	string s = "abcdefg";
	int k = 2;
	reverse(s.begin(), s.end());
	int tip = s.size() - k;
	reverse(s.begin(), s.begin() + tip);
	reverse(s.begin() + tip,s.end());
	cout << s << endl;
	return 0;
}