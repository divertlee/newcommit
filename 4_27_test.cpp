#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
#include"4_19_HashTable.h"
#include"4_19_Unordered_Set.h"
int main()
{
	string str[] = { "string","sort","find" };
	pjl::Unordered_Set<string> wordset;
	for (auto& e : str)
	{
		wordset.Insert(e);
	}
	
	string s1 = "s";
 auto it1 = wordset.Find(s1);
 //cout << *it1 << endl;
	return 0;
}